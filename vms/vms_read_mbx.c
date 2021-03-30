#define PY_SSIZE_T_CLEAN
#include "Python.h"

#define __NEW_STARLET 1
#include <dcdef.h>
#include <descrip.h>
#include <dvidef.h>
#include <efndef.h>
#include <errno.h>
#include <iledef.h>
#include <iodef.h>
#include <iosbdef.h>
#include <jpidef.h>
#include <starlet.h>
#include <stsdef.h>
#include <time.h>

#include "vms/vms_spawn_helper.h"

extern int vms_channel_lookup(int fd, unsigned short *channel);

unsigned int vms_cur_pid() {
    static unsigned int _pid = 0;
    if (_pid == 0) {
        unsigned int jpi_proc_id = 0;
        unsigned short jpi_proc_id_len = 0;
        ILE3 item_list[2];
        item_list[0].ile3$w_length = 4;
        item_list[0].ile3$w_code = JPI$_PID;
        item_list[0].ile3$ps_bufaddr = &jpi_proc_id;
        item_list[0].ile3$ps_retlen_addr = &jpi_proc_id_len;
        memset(item_list + 1, 0, sizeof(item_list[1]));
        sys$getjpiw(EFN$C_ENF, &_pid, NULL, &item_list, NULL, NULL, 0);
    }
    return _pid;
}

unsigned short vms_get_mbx_size(unsigned short channel) {
    unsigned short mbx_buffer_size = 0;
    unsigned short mbx_buffer_size_len = 0;
    unsigned int   mbx_char;
    unsigned short mbx_char_len;
    ILE3 item_list[3];
    item_list[0].ile3$w_length = 4;
    item_list[0].ile3$w_code = DVI$_DEVBUFSIZ;
    item_list[0].ile3$ps_bufaddr = &mbx_buffer_size;
    item_list[0].ile3$ps_retlen_addr = &mbx_buffer_size_len;
    item_list[1].ile3$w_length = 4;
    item_list[1].ile3$w_code = DVI$_DEVCLASS;
    item_list[1].ile3$ps_bufaddr = &mbx_char;
    item_list[1].ile3$ps_retlen_addr = &mbx_char_len;
    memset(item_list + 2, 0, sizeof(ILE3));
    int status = SYS$GETDVIW(0, channel, 0, &item_list, 0, 0, 0, 0);
    if ($VMS_STATUS_SUCCESS(status) && (mbx_char & DC$_MAILBOX)) {
        return mbx_buffer_size;
    }
    return 0;
}

static unsigned int _target_pid[256] = {0};

int vms_set_target_pid(int fd, unsigned int pid) {
    if (2 < fd && fd < 256) {
        _target_pid[fd] = pid;
        return 0;
    }
    return 1;
}

unsigned int vms_get_target_pid(int fd) {
    if (2 < fd && fd < 256) {
        return _target_pid[fd];
    }
    return 0;
}

static unsigned int _writer_pid[256] = {0};

int _save_writer_pid(int fd, unsigned int pid) {
    if (2 < fd && fd < 256) {
        _writer_pid[fd] = pid;
        return 0;
    }
    return 1;
}

unsigned int vms_get_writer_pid(int fd) {
    if (2 < fd && fd < 256) {
        return _writer_pid[fd];
    }
    return 0;
}

int vms_read_mbx(int fd, char *buf, int size) {
    unsigned short channel;
    int nbytes = -1;

    if (vms_channel_lookup(fd, &channel) == 0) {
        // get information about this MBX buffer size
        unsigned short mbx_size = vms_get_mbx_size(channel);
        if (mbx_size) {
            if (size > mbx_size) {
                size = mbx_size;
            }
            // read MBX
            IOSB iosb = {0};
            int status = SYS$QIOW(EFN$C_ENF, channel,
                IO$_READVBLK,
                &iosb, NULL, 0,
                buf, size,
                0, 0, 0, 0);
            if (!$VMS_STATUS_SUCCESS(status)) {
                // error while QIOW
                nbytes = -1;
            } else {
                _save_writer_pid(fd, iosb.iosb$l_pid);
                if (iosb.iosb$w_status == SS$_NORMAL) {
                    nbytes = iosb.iosb$w_bcnt;
                    // test if iosb.iosb$l_pid is spawned by lib$spawn
                    if (nbytes == 0 ||
                        (vms_spawn_status(iosb.iosb$l_pid, NULL, 0) == 0 &&
                            nbytes < size))
                    {
                        // add EOL if spawned or buffer is empty
                        buf[nbytes] = '\n';
                        ++nbytes;
                    }
                } else if (iosb.iosb$w_status == SS$_ENDOFFILE) {
                    // unsigned int target_pid = vms_get_target_pid(fd);
                    // if (target_pid && target_pid != iosb.iosb$l_pid) {
                    //     // not a target PID, just add an empty line
                    //     buf[0] = '\n';
                    //     nbytes = 1;
                    // } else {
                        // MBX is closed
                        nbytes = 0;
                    // }
                } else {
                    // error in IOSB
                    nbytes = -1;
                }
            }
        }
        SYS$DASSGN(channel);
    }
    return nbytes;
}

static int _has_messages(unsigned short channel) {
    IOSB iosb = {0};
    int status = SYS$QIOW(EFN$C_ENF, channel, IO$_SENSEMODE,
        &iosb, NULL,0,
        0, 0,
        0, 0, 0, 0);
    if ($VMS_STATUS_SUCCESS(status) &&
        $VMS_STATUS_SUCCESS(iosb.iosb$w_status))
    {
        return iosb.iosb$w_bcnt;
    }
    return 0;
}

static int _fetch_message(unsigned short channel, char *buf, unsigned short size) {
    IOSB iosb = {0};
    int status = SYS$QIOW(EFN$C_ENF, channel, IO$_READVBLK,
        &iosb, NULL, 0,
        buf, size,
        0, 0, 0, 0);
    if ($VMS_STATUS_SUCCESS(status) &&
        $VMS_STATUS_SUCCESS(iosb.iosb$w_status)) 
    {
        if (iosb.iosb$w_bcnt == 0) {
            buf[iosb.iosb$w_bcnt] = '\n';
            ++iosb.iosb$w_bcnt;
        }
        return iosb.iosb$w_bcnt;
    }
    return 0;
}

int vms_fetch_output(int fd_out, int fd_err, PyObject *pOut, PyObject *pErr) {
    unsigned short channel_out = 0, channel_err = 0;
    char *buf_out = NULL, *buf_err = NULL;
    int messages = 0;
    unsigned short size_out = 0, size_err = 0;
    int status = 0;
    int wait_out = 0;
    int wait_err = 0;
    struct timespec delay_tm, remain_tm;
    int nbytes;

    if (!PyList_Check(pOut)) {
        pOut = NULL;
    }

    if (!PyList_Check(pErr)) {
        pErr = NULL;
    }

    if (fd_out > 0) {
        if (vms_channel_lookup(fd_out, &channel_out) != 0) {
            goto fetch_clean;
        }
        size_out = vms_get_mbx_size(channel_out);
        if (!size_out) {
            goto fetch_clean;
        }
        buf_out = PyMem_Malloc(size_out);
        if (!buf_out) {
            goto fetch_clean;
        }
        wait_out = _has_messages(channel_out);
    }

    if (fd_err > 0) {
        if (vms_channel_lookup(fd_err, &channel_err) != 0) {
            goto fetch_clean;
        }
        size_err = vms_get_mbx_size(channel_err);
        if (!size_err) {
            goto fetch_clean;
        }
        buf_err = PyMem_Malloc(size_err);
        if (!buf_err) {
            goto fetch_clean;
        }
        wait_err = _has_messages(channel_err);
    }

    delay_tm.tv_sec = 0;
    delay_tm.tv_nsec = 10000000;    // 1/10 sec
    
    while(1) {
        nanosleep(&delay_tm, &remain_tm);
        wait_out = _has_messages(channel_out);
        wait_err = _has_messages(channel_err);
        if (wait_out) {
            nbytes = _fetch_message(channel_out, buf_out, size_out);
            if (nbytes) {
                if (pOut) {
                    PyObject *bytes = PyBytes_FromStringAndSize(buf_out, nbytes);
                    PyList_Append(pOut, bytes);
                    Py_DECREF(bytes);
                }
                ++messages;
            }
            continue;
        }
        if (wait_err) {
            nbytes = _fetch_message(channel_err, buf_err, size_err);
            if (nbytes) {
                if (pErr) {
                    PyObject *bytes = PyBytes_FromStringAndSize(buf_out, nbytes);
                    PyList_Append(pErr, bytes);
                    Py_DECREF(bytes);
                }
                ++messages;
            }
            continue;
        }
        break;
    }

fetch_clean:
    if (channel_err) {
        sys$dassgn(channel_err);
        channel_err = 0;
    }
    if (channel_out) {
        sys$dassgn(channel_out);
        channel_out = 0;
    }
    if (buf_err) {
        PyMem_Free(buf_err);
        buf_err = NULL;
    }
    if (buf_out) {
        PyMem_Free(buf_out);
        buf_out = NULL;
    }
    return messages;
}
