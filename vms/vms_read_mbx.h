#ifndef VMS_READ_MBX_H
#define VMS_READ_MBX_H

#ifdef __cplusplus
extern "C" {
#endif

int vms_read_mbx(int fd, char *buf, int size);
int vms_fetch_output(int fd_out, int fd_err, PyObject *pOutList, PyObject *pErrList);
unsigned short vms_get_mbx_size(unsigned short channel);
unsigned int vms_cur_pid();
unsigned int vms_get_target_pid(int fd);
int vms_set_target_pid(int fd, unsigned int pid);
unsigned int vms_get_writer_pid(int fd);

#ifdef __cplusplus
}
#endif

#endif
