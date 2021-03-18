/* File: VMS_POLL_SELECT_HACK.C */
/* Hack to make poll() and select() appear to work on pipes and terminals */

/* This file is included in gmain.c to easily add it into the build */

#include <dcdef>
#include <descrip.h>
#include <dvidef>
#include <efndef.h>
#include <errno.h>
#include <inttypes.h>
#include <iodef.h>
#include <iosbdef.h>
#include <poll.h>
#include <socket.h>
#include <ssdef.h>
#include <stdlib.h>
#include <string.h>
#include <stsdef.h>
#include <unistd.h>
#include <unixio.h>
#include <unixlib.h>
#include <time.h>
/*
#include "python_root:[include]Python.h"
#include "python_root:[include]floatobject.h"
#include "python_root:[include]object.h"
#include "python_root:[include]pyport.h"
*/

int LIB$SIGNAL(int);

int SYS$ASSIGN(const struct dsc$descriptor_s *devnam, unsigned short *chan,
               unsigned long acmode, const struct dsc$descriptor_s *mbxnam,
               unsigned long flags);

int SYS$DASSGN(unsigned short chan);

unsigned long SYS$QIOW(unsigned long efn, unsigned short chan,
                       unsigned long func, void *iosb, void (*astadr)(void *),
                       ...);

int SYS$READEF(unsigned long efn, unsigned long *state);

int SYS$GETDVIW(unsigned int efn, unsigned short int chan, void *devnam,
                void *itmlst, void *iosb, void (*astadr)(void *), int astprm,
                void *nullarg, ...);

static int g_vms_channel_lookup(int fd, unsigned short *channel) {
  int status;
  char devicename[256];
  char *retname;
  struct dsc$descriptor_s dev_desc;
  int call_stat;
  unsigned short chan;

  status = -1;

  /* get the name */
  /*--------------*/
  retname = getname(fd, devicename, 1);
  if (retname != NULL) {
    /* Assign the channel */
    /*--------------------*/
    dev_desc.dsc$a_pointer = devicename;
    dev_desc.dsc$w_length = strlen(devicename);
    dev_desc.dsc$b_dtype = DSC$K_DTYPE_T;
    dev_desc.dsc$b_class = DSC$K_CLASS_S;
    call_stat = SYS$ASSIGN(&dev_desc, &chan, 0, 0, 0);
    if ($VMS_STATUS_SUCCESS(call_stat)) {
      *channel = chan;
      status = 0;
    }
  }
  return status;
}

static int g_vms_channelname_lookup(int fd, char *channel) {
  int status;
  char devicename[256];
  char *retname;
  struct dsc$descriptor_s dev_desc;
  int call_stat;
  unsigned short chan;

  status = -1;

  /* get the name */
  /*--------------*/
  retname = getname(fd, devicename, 1);
  if (retname != NULL) {
    strcpy(channel, devicename);
    status = 0;
  } else
    status = 1;
  return status;
}

unsigned long read_pipe_bytes(int fd, char *buf, int size, int *pid_ptr) {
  unsigned short channel;
  int nbytes = 0;
  if (g_vms_channel_lookup(fd, &channel) == 0) {
    struct {
      unsigned short sts;
      unsigned short bytes_read;
      unsigned long pid;
    } mbx_iosb_read;

    int status = SYS$QIOW(EFN$C_ENF, channel, IO$_READVBLK, &mbx_iosb_read,
                          NULL, NULL, buf, size, 0, 0, 0, 0);
    if ($VMS_STATUS_SUCCESS(status)) {
      if (mbx_iosb_read.sts == SS$_ENDOFFILE) {
        nbytes = 0;
      } else {
        nbytes = mbx_iosb_read.bytes_read;
        if (nbytes == 0) {
          nbytes = 1;
          buf[0] = '\n';
        }
      }
    }    SYS$DASSGN(channel);
    if (pid_ptr) {
      *pid_ptr = mbx_iosb_read.pid;
    }
  }
  return nbytes;
}

struct vms_pollfd_st {
  struct pollfd *fd_desc_ptr;
  unsigned short channel;
  unsigned short pad;
};

static int vms_select_terminal(const struct vms_pollfd_st *term_array, int ti) {
  int i;
  int ret_stat;
  int count;
  int status;
#pragma member_alignment save
#pragma nomember_alignment
  struct term_mode_iosb_st {
    unsigned short sts;
    unsigned short speed;
    unsigned long other;
  } mode_iosb;

  struct typeahead_st {
    unsigned short numchars;
    unsigned char firstchar;
    unsigned char reserved0;
    unsigned long reserved1;
  } typeahead;
#pragma member_alignment restore

  ret_stat = 0;

  /* Loop through the terminal channels */
  for (i = 0; i < ti; i++) {

    term_array[i].fd_desc_ptr->revents = 0;

    /* assume output is always available */
    term_array[i].fd_desc_ptr->revents =
        term_array[i].fd_desc_ptr->events & POLL_OUT;

    /* Poll input status */
    if (term_array[i].fd_desc_ptr->events & POLL_IN) {
      status = SYS$QIOW(EFN$C_ENF, term_array[i].channel,
                        IO$_SENSEMODE | IO$M_TYPEAHDCNT, &mode_iosb, NULL, NULL,
                        &typeahead, 8, 0, 0, 0, 0);
      if ($VMS_STATUS_SUCCESS(status) && $VMS_STATUS_SUCCESS(mode_iosb.sts)) {
        if (typeahead.numchars != 0) {
          term_array[i].fd_desc_ptr->revents =
              term_array[i].fd_desc_ptr->events & POLL_IN;
        }
      } else {
        /* Something really wrong */
        ret_stat = -1;
        errno = EIO;
        break;
      }
    }
    /* Increment the return status */
    if (term_array[i].fd_desc_ptr->revents != 0)
      ret_stat++;
  }

  return ret_stat;
}

static int vms_select_pipe(const struct vms_pollfd_st *pipe_array, int pi) {
    int i;
    int ret_stat;
    int status;
#pragma member_alignment save
#pragma nomember_alignment
  struct mbx_gmif_iosb_st {
    unsigned short sts;
    unsigned short num_msg;
    unsigned long num_bytes;
  } mbx_iosb_pipe;
#pragma member_alignment restore


    ret_stat = 0;

    /* Loop through the pipes */
    for (i = 0; i < pi; i++) {

        pipe_array[i].fd_desc_ptr->revents = 0;
        mbx_iosb_pipe.num_msg = 0;
        mbx_iosb_pipe.num_bytes = 0;

        /* Check the mailbox status */
        if (pipe_array[i].fd_desc_ptr->events & (POLL_IN | POLL_OUT)) {
            status = SYS$QIOW(EFN$C_ENF, pipe_array[i].channel, IO$_SENSEMODE,
                &mbx_iosb_pipe, NULL, NULL, 0, 0, 0, 0, 0, 0);
            if ($VMS_STATUS_SUCCESS(status) && $VMS_STATUS_SUCCESS(mbx_iosb_pipe.sts)) {
                /* Got some information */
                if (mbx_iosb_pipe.num_msg != 0) {
                    /* There is data to read */
                    pipe_array[i].fd_desc_ptr->revents =
                    pipe_array[i].fd_desc_ptr->events & POLL_IN;
                } else {
                    /* Pipe is empty, ok to write */
                    pipe_array[i].fd_desc_ptr->revents =
                    pipe_array[i].fd_desc_ptr->events & POLL_OUT;
                }
            } else {
                /* Something really wrong */
                ret_stat = -1;
                errno = EIO;
                break;
            }
        }
        /* Increment the return status */
        if (pipe_array[i].fd_desc_ptr->revents != 0) {
            ret_stat++;
        }
    }
    return ret_stat;
}

static int vms_select_x11_efn(const struct vms_pollfd_st *efn_array, int xi) {
  int i;
  int ret_stat;
  int status;
  unsigned long state;

  ret_stat = 0;

  /* Loop through the event flags */
  for (i = 0; i < xi; i++) {
    efn_array[i].fd_desc_ptr->revents = 0;

    /* assume output is always available */
    efn_array[i].fd_desc_ptr->revents =
        efn_array[i].fd_desc_ptr->events & POLL_OUT;

    /* Check the mailbox status */
    if (efn_array[i].fd_desc_ptr->events & (POLL_IN | POLL_OUT)) {
      status = SYS$READEF(efn_array[i].fd_desc_ptr->fd, &state);
      if ($VMS_STATUS_SUCCESS(status)) {

        /* Got some information */
        if (status == SS$_WASSET) {
          /* There is data to read */
          efn_array[i].fd_desc_ptr->revents =
              efn_array[i].fd_desc_ptr->events & POLL_IN;
        }
      } else {
        /* Something really wrong */
        ret_stat = -1;
        errno = EIO;
        break;
      }
    }
    /* Increment the return status */
    if (efn_array[i].fd_desc_ptr->revents != 0)
      ret_stat++;
  }
  return ret_stat;
}

/*******************************************************************
 OpenVMS Open Source Community select hack...

 this code acts as a wrapper for poll() and supports:
        pipes
        mailboxes
        terminals
        sockets

 *******************************************************************/

int g_vms_select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds,
                 struct timeval *timeout) {
  int ret_stat;
  int siif_index;
  int old_siif_value;
  int new_siif_value;
  int i;

  struct {
    short int buf_len;
    short int item;
    char *buf_addr;
    unsigned short int *ret_len;
    int end;
  } item_list;

  int mbx_len;
  unsigned int mbx_char;

  const char *select_ignores_invalid_fd = "DECC$SELECT_IGNORES_INVALID_FD";

  /* Get old ignore setting and enable new */
  /* threaded applications need this setting enabled before this routine */
  siif_index = decc$feature_get_index(select_ignores_invalid_fd);
  if (siif_index >= 0)
    old_siif_value = decc$feature_set_value(siif_index, 1, 1);

  if (nfds != 0) {
    int i;
    struct pollfd *select_array;
    struct vms_pollfd_st *term_array;
    struct vms_pollfd_st *pipe_array;
    struct vms_pollfd_st *xefn_array;
    int ti;
    int si;
    int pi;
    int xi;
    int status;

    /* Need structures to separate terminals and pipes */
    select_array = malloc(sizeof(struct pollfd) * nfds);
    if (select_array == NULL) {
      return -1;
    }
    term_array = malloc(sizeof(struct vms_pollfd_st) * nfds);
    if (term_array == NULL) {
      free(select_array);
      return -1;
    }
    pipe_array = malloc(sizeof(struct vms_pollfd_st) * nfds);
    if (pipe_array == NULL) {
      free(term_array);
      free(select_array);
      return -1;
    }
    xefn_array = malloc(sizeof(struct vms_pollfd_st) * nfds);
    if (xefn_array == NULL) {
      free(pipe_array);
      free(term_array);
      free(select_array);
      return -1;
    }

    /* printf (" in g_vms_select\n"); */

    /* Find all of the terminals and pipe fds  for polling */
    for (i = 0, pi = 0, ti = 0, xi = 0, si = 0; i < nfds; i++) {
      /* printf ("fds : %d\n", i); */
      /* Copy file descriptor arrays into a poll structure */
      select_array[i].fd = i;
      select_array[i].events = 0;
      select_array[i].revents = 0;

      /* Now separate out the pipes */
      if (isapipe(i) == 1) {
        /* printf ("pipe\n"); */
        pipe_array[pi].fd_desc_ptr = &select_array[i];
        if (readfds != NULL) {
          /* printf ("pipe array read: %d\n", i); */
          if (FD_ISSET(i, readfds))
            select_array[i].events |= POLL_IN;
        }
        if (writefds != NULL) {
          /* printf ("pipe array write: %d\n", i); */
          if (FD_ISSET(i, writefds))
            select_array[i].events |= POLL_OUT;
        }
        /* Only care about something with read/write events */
        if (select_array[i].events != 0) {
          status = g_vms_channel_lookup(i, &pipe_array[pi].channel);
          if (status == 0) {
            /* printf ("pipe array accepted\n"); */
            pi++;
          }
        }
      }
      /* Not a pipe, see if a terminal */
      else if (isatty(i) == 1) {
        /* printf ("terminal\n"); */
        term_array[ti].fd_desc_ptr = &select_array[i];
        if (readfds != NULL) {
          if (FD_ISSET(i, readfds))
            select_array[i].events |= POLL_IN;
        }
        if (writefds != NULL) {
          if (FD_ISSET(i, writefds))
            select_array[i].events |= POLL_OUT;
        }
        /* Only care about something with read/write events */
        if (select_array[i].events != 0) {
          status = g_vms_channel_lookup(i, &term_array[ti].channel);
          if (status == 0) {
            ti++;
          }
        }
      } else if (decc$get_sdc(i) != 0) {
        /* printf ("socket\n"); */
        /* Not pipe or terminal, use built in select on this */
        si++;
      } else {
        /* see if it is a mailbox and then treat as a pipe or X11 event if not
         * mailbox */
        /* printf ("mailbox\n"); */
        pipe_array[pi].fd_desc_ptr = &select_array[i];
        if (readfds != NULL) {
          if (FD_ISSET(i, readfds))
            select_array[i].events |= POLL_IN;
        }
        if (writefds != NULL) {
          if (FD_ISSET(i, writefds))
            select_array[i].events |= POLL_OUT;
        }
        /* Only care about something with read/write events */
        mbx_char = 0;
        if (select_array[i].events != 0) {
          status = g_vms_channel_lookup(i, &pipe_array[pi].channel);
          if (status == 0) {
            item_list.buf_len = 4;
            item_list.item = DVI$_DEVCLASS;
            item_list.buf_addr = (void *)&mbx_char;
            item_list.ret_len = (void *)&mbx_len;
            item_list.end = 0;

            SYS$GETDVIW(0, pipe_array[pi].channel, 0, &item_list, 0, 0, 0, 0);
            if ((mbx_char & DC$_MAILBOX) != 0) {
              pi++;
            } else {
              select_array[i].events = 0;
              SYS$DASSGN(pipe_array[pi].channel);
            }
          } else {
            select_array[i].events = 0;
          }
        }
        /* What's left? X11 event flags */
        else if ((mbx_char & DC$_MAILBOX) == 0) {
          /* printf ("X11\n"); */
          xefn_array[xi].fd_desc_ptr = &select_array[i];
          if (readfds != NULL) {
            if (FD_ISSET(i, readfds))
              select_array[i].events |= POLL_IN;
          }
          if (writefds != NULL) {
            if (FD_ISSET(i, writefds))
              select_array[i].events |= POLL_OUT;
          }
          /* Only care about something with read/write events */
          if (select_array[i].events != 0) {
            xi++;
          }
        }
      }
    }
    if ((pi == 0) && (ti == 0) && (xi == 0)) {
      /* printf ("socket select\n"); */
      /* All sockets, let select do everything */
      ret_stat = select(nfds, readfds, writefds, exceptfds, timeout);
    } else {
      int utimeleft;    /* Microseconds left */
      int ti_stat;
      int pi_stat;
      int si_stat;
      int xi_stat;
      struct timespec end_time;

      ti_stat = 0;
      pi_stat = 0;
      si_stat = 0;
      xi_stat = 0;
      end_time.tv_sec = 0;
      end_time.tv_nsec = 0;
      #define FULL_NSEC 1000000000
      #define FULL_USEC 1000000
      utimeleft = FULL_USEC;
      if (timeout != NULL) {
        if (clock_gettime(CLOCK_REALTIME, &end_time)) {
          end_time.tv_sec = 0;
          end_time.tv_nsec = 0;
        } else {
          end_time.tv_sec += timeout->tv_sec;
          end_time.tv_nsec += timeout->tv_usec * (FULL_NSEC / FULL_USEC);
          while (end_time.tv_nsec >= FULL_NSEC) {
            ++end_time.tv_sec;
            end_time.tv_nsec -= FULL_NSEC;
          }

        }
      }
      ret_stat = 0;

      /* Terminals and or pipes (and or MBXs) and or sockets  */
      /* Now we have to periodically poll everything with timeout */
      while (ret_stat == 0) {
        int sleeptime;

        if (ti != 0) {
          /* printf ("terminal poll\n"); */
          ti_stat = vms_select_terminal(term_array, ti);
        }
        if (pi != 0) {
          /* printf ("pipe poll\n");  */
          pi_stat = vms_select_pipe(pipe_array, pi);
        }
        if (xi != 0) {
          xi_stat = vms_select_x11_efn(xefn_array, xi);
        }

        if (ti_stat != 0 || pi_stat != 0 || xi_stat != 0) {
          /* printf ("ti_stat: %d pi_stat: %d xi_stat: %d\n", ti_stat, pi_stat,
           * xi_stat);  */
          sleeptime = 0;
        } else {
          sleeptime = 100 * 1000;
          if (utimeleft < sleeptime) {
            sleeptime = utimeleft;
          }
        }
        if (si == 0) {
          /* sleep for shorter of 100 Ms or timeout and retry */
          if (sleeptime > 0)
            usleep(sleeptime);
        } else {
            struct timeval sleep_timeout;
            sleep_timeout.tv_sec = 0;
            sleep_timeout.tv_usec = sleeptime;
            si_stat = select(nfds, readfds, writefds, exceptfds, &sleep_timeout);
        }
        /* one last poll of terminals and pipes */
        if ((sleeptime > 0) || (si_stat > 0)) {
          if ((ti != 0) && (ti_stat == 0)) {
            ti_stat = vms_select_terminal(term_array, ti);
          }
          if ((pi != 0) && (pi_stat == 0)) {
            pi_stat = vms_select_pipe(pipe_array, pi);
          }
          if ((xi != 0) && (xi_stat == 0)) {
            xi_stat = vms_select_x11_efn(xefn_array, xi);
          }
        }

        /* Gather up any results */
        if ((ti_stat == -1) || (pi_stat == -1) || (si_stat == -1) || (xi_stat == -1)) {
          ret_stat = -1;
        } else {
          ret_stat = ti_stat + pi_stat + si_stat + xi_stat;
        }

        /* Copy the pipe and terminal information */
        // if ((ti_stat > 0) || (pi_stat > 0) || (xi_stat > 0)) {
          for (int j = 0; j < nfds; j++) {
            if (select_array[j].events != 0) {
              if (readfds != NULL) {
                if (select_array[j].revents & POLL_IN)
                  FD_SET(select_array[j].fd, readfds);
                else
                  FD_CLR(select_array[j].fd, readfds);
              }
              if (writefds != NULL) {
                if (select_array[j].revents & POLL_OUT)
                  FD_SET(select_array[j].fd, writefds);
                else
                  FD_CLR(select_array[j].fd, writefds);
              }
            }
          }
        // }
        /* Timed out? */
        if (timeout != NULL) {
          struct timespec cur_time;
          if (clock_gettime(CLOCK_REALTIME, &cur_time)) {
            // failed to obtain current time
            break;
          } else {
            if (cur_time.tv_sec > end_time.tv_sec ||
                cur_time.tv_sec == end_time.tv_sec && cur_time.tv_nsec >= end_time.tv_nsec) {
                // time out
                break;
            } else {
              if (end_time.tv_sec - cur_time.tv_sec <= 1) {
                utimeleft = (end_time.tv_sec - cur_time.tv_sec) * FULL_USEC;
                utimeleft += (end_time.tv_nsec - cur_time.tv_nsec) / (FULL_NSEC / FULL_USEC);
                if (utimeleft < 0) {
                  // something wrong
                  break;
                }
              }
            }
          }
        }
      }
    }
    while (pi > 0) {
      pi--;
      SYS$DASSGN(pipe_array[pi].channel);
    }
    free(select_array);
    while (ti > 0) {
      ti--;
      SYS$DASSGN(term_array[ti].channel);
    }
    free(term_array);
    free(pipe_array);
    free(xefn_array);
  } else {
    ret_stat = select(nfds, readfds, writefds, exceptfds, timeout);
  }

  /* Restore old setting */
  if (siif_index >= 0)
    new_siif_value = decc$feature_set_value(siif_index, 1, old_siif_value);

  return ret_stat;
}

#define poll g_vms_poll
#define select(__v, __w, __x, __y, __z) g_vms_select(__v, __w, __x, __y, __z)
