#define PY_SSIZE_T_CLEAN
#include "Python.h"

#include <descrip.h>
#include <lib$routines.h>
#include <dlfcn.h>

// extern unsigned int decc$fix_time(long long *);

// unsigned int _fix_time(long long vms_time)
// {
//     return (decc$fix_time(&vms_time));
// }


// static long long epoch = 0;

// #define UNIX_EPOCH "01-JAN-1970 00:00:00.00"
// #define FAC 10000000L

// static int offset()
// {
//     time_t gmt, rawtime = time(NULL);
//     struct tm *ptm;

//     struct tm gbuf;
//     ptm = gmtime_r(&rawtime, &gbuf);
//     ptm->tm_isdst = -1;
//     gmt = mktime(ptm);

//     return ((int) difftime(rawtime, gmt));
// }

// unsigned int _unixtime(long long dt)
// {
//     unsigned int sec;
//     __int64 diff;

//     if (epoch == 0)  {
//         struct dsc$descriptor_s epoch_dsc;

//         epoch_dsc.dsc$w_length = strlen(UNIX_EPOCH);
//         epoch_dsc.dsc$b_class = DSC$K_CLASS_S;
//         epoch_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
//         epoch_dsc.dsc$a_pointer = UNIX_EPOCH;

//         sys$bintim(&epoch_dsc, (struct _generic_64 *) &epoch);
//     }

//     diff = dt - epoch;
//     sec = diff / FAC - offset();
//     return (sec);
// }



// long long _vmstime(unsigned int dt)
// {
//     long long val;
//     long long tmp;

//     if (epoch == 0)  {
//         struct dsc$descriptor_s epoch_dsc;

//         epoch_dsc.dsc$w_length = strlen(UNIX_EPOCH);
//         epoch_dsc.dsc$b_class = DSC$K_CLASS_S;
//         epoch_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
//         epoch_dsc.dsc$a_pointer = UNIX_EPOCH;

//         sys$bintim(&epoch_dsc, (struct _generic_64 *) &epoch);
//     }

//     tmp = dt;
//     val = epoch + (tmp * FAC);

//     return (val);
// }


// extern int decc$from_vms(const char *, int (*)(char *, void *), int, ...);
// extern int decc$to_vms(const char *, int (*)(char *, int, void *), int, int, ...);

// typedef struct {
//     int     len;
//     int     cap;
//     char**  buf;
// } _simple_arr;

// static int cb_from_vms(char *name, void *user_data)
// {
//     _simple_arr *parr = (_simple_arr *) user_data;
//     assert(parr);
//     if (parr->len + 1 >= parr->cap ) {
//         parr->cap += 8;
//         parr->buf = realloc(parr->buf, parr->cap * sizeof(char*));
//     }
//     parr->buf[parr->len] = strdup(name);
//     assert(parr->buf[parr->len]);
//     ++parr->len;
//     parr->buf[parr->len] = NULL;
//     return (1);
// }


// char **_from_vms(char *path, int wild_flag)
// {
//     _simple_arr arr;
//     arr.len = 0;
//     arr.cap = 8;
//     arr.buf = malloc(arr.cap * sizeof(char*));
//     arr.buf[arr.len] = NULL;

//     assert(path);
//     int num_files = decc$from_vms(path, cb_from_vms, wild_flag, &arr);
//     return (arr.buf);
// }


// static int cb_to_vms(char *name, int flag, void *user_data)
// {
//     _simple_arr *parr = (_simple_arr *) user_data;
//     assert(parr);
//     if (parr->len + 1 >= parr->cap ) {
//         parr->cap += 8;
//         parr->buf = realloc(parr->buf, parr->cap * sizeof(char*));
//     }
//     parr->buf[parr->len] = strdup(name);
//     assert(parr->buf[parr->len]);
//     ++parr->len;
//     parr->buf[parr->len] = NULL;
//     return (1);
// }

// char **_to_vms(char *path, int allow_wild, int no_directory)
// {
//     _simple_arr arr;
//     arr.len = 0;
//     arr.cap = 8;
//     arr.buf = malloc(arr.cap * sizeof(char*));
//     arr.buf[arr.len] = NULL;

//     assert(path);
//     decc$to_vms(path, cb_to_vms, allow_wild, no_directory, &arr);
//     return (arr.buf);
// }


// char *_getenv(char *name, char *def)
// {
//     char *tmp, *val = NULL;

//     assert(name);
//     val = getenv(name);

//     if (val == NULL && def != NULL) {
//        val = def;
//     }

//     if (val) {
//         tmp = strdup(val);
// 	    assert(tmp);
//     } else {
// 	    tmp = NULL;
//     }

//     return (tmp);
// }


// long _sysconf(int name)
// {
//     return (sysconf(name));
// }


// int _sleep(unsigned int nsec)
// {
//     return (sleep(nsec));
// }

// int _dlopen_test(char *name) {
//     void *handle = dlopen(name, 0);
//     if (handle) {
//         dlclose(handle);
//         return 1;
//     }
//     return 0;
// }

static PyObject*
DECC_dlopen_test(
    PyObject * self,
    PyObject * args)
{
    char *name = NULL;
    Py_ssize_t size = 0;

    if (PyUnicode_CheckExact(args)) {
        name = (char*)PyUnicode_AsUTF8AndSize(args, &size);
    } else if (PyBytes_CheckExact(args)) {
        PyBytes_AsStringAndSize(args, &name, &size);
    }
    if (!name || !size) {
        _PyArg_BadArgument("DECC_dlopen_test", "argument 1", "str", args);
        Py_RETURN_NONE;
    }

    int status = 0;
    void *handle = dlopen(name, 0);
    if (handle) {
        dlclose(handle);
        status = 1;
    }

    return PyLong_FromLong(status);
}



/********************************************************************
  Module
*/

static PyMethodDef _module_methods[] = {
    {"dlopen_test", (PyCFunction) DECC_dlopen_test, METH_O,
        PyDoc_STR("dlopen_test(name: str)->status: number   Returns 1 on success")},
    {NULL, NULL}
};

static struct PyModuleDef _module_definition = {
    PyModuleDef_HEAD_INIT,
    "_decc",
    PyDoc_STR("OpenVMS DECC wrapper"),
    -1,
    _module_methods,
    NULL,
    NULL,
    NULL,
    NULL,
};

PyMODINIT_FUNC PyInit__decc(void)
{
    PyObject *m = PyModule_Create(&_module_definition);
    PyModule_AddIntConstant(m, "_SC_ARG_MAX", 100);
    PyModule_AddIntConstant(m, "_SC_CHILD_MAX", 101);
    PyModule_AddIntConstant(m, "_SC_CLK_TCK", 102);
    PyModule_AddIntConstant(m, "_SC_NGROUPS_MAX", 103);
    PyModule_AddIntConstant(m, "_SC_OPEN_MAX", 104);
    PyModule_AddIntConstant(m, "_SC_STREAM_MAX", 105);
    PyModule_AddIntConstant(m, "_SC_TZNAME_MAX", 106);
    PyModule_AddIntConstant(m, "_SC_JOB_CONTROL", 107);
    PyModule_AddIntConstant(m, "_SC_SAVED_IDS", 108);
    PyModule_AddIntConstant(m, "_SC_VERSION", 109);
    PyModule_AddIntConstant(m, "_SC_BC_BASE_MAX", 121);
    PyModule_AddIntConstant(m, "_SC_BC_DIM_MAX", 122);
    PyModule_AddIntConstant(m, "_SC_BC_SCALE_MAX", 123);
    PyModule_AddIntConstant(m, "_SC_BC_STRING_MAX", 124);
    PyModule_AddIntConstant(m, "_SC_COLL_WEIGHTS_MAX", 125);
    PyModule_AddIntConstant(m, "_SC_EXPR_NEST_MAX", 126);
    PyModule_AddIntConstant(m, "_SC_LINE_MAX", 127);
    PyModule_AddIntConstant(m, "_SC_RE_DUP_MAX", 128);
    PyModule_AddIntConstant(m, "_SC_2_VERSION", 129);
    PyModule_AddIntConstant(m, "_SC_2_C_BIND", 130);
    PyModule_AddIntConstant(m, "_SC_2_C_DEV", 131);
    PyModule_AddIntConstant(m, "_SC_2_FORT_DEV", 132);
    PyModule_AddIntConstant(m, "_SC_2_SW_DEV", 133);
    PyModule_AddIntConstant(m, "_SC_2_FORT_RUN", 134);
    PyModule_AddIntConstant(m, "_SC_2_LOCALEDEF", 135);
    PyModule_AddIntConstant(m, "_SC_2_UPE", 136);
    PyModule_AddIntConstant(m, "_SC_GETGR_R_SIZE_MAX", 150);
    PyModule_AddIntConstant(m, "_SC_GETPW_R_SIZE_MAX", 151);
    PyModule_AddIntConstant(m, "_SC_THREAD_DESTRUCTOR_ITERATIONS", 140);
    PyModule_AddIntConstant(m, "_SC_THREAD_KEYS_MAX", 141);
    PyModule_AddIntConstant(m, "_SC_THREAD_STACK_MIN", 142);
    PyModule_AddIntConstant(m, "_SC_THREAD_THREADS_MAX", 143);
    PyModule_AddIntConstant(m, "_SC_THREAD_SAFE_FUNCTIONS", 144);
    PyModule_AddIntConstant(m, "_SC_THREADS", 145);
    PyModule_AddIntConstant(m, "_SC_THREAD_ATTR_STACKSIZE", 146);
    PyModule_AddIntConstant(m, "_SC_THREAD_PRIORITY_SCHEDULING", 147);
    PyModule_AddIntConstant(m, "_SC_XOPEN_VERSION", 110);
    PyModule_AddIntConstant(m, "_SC_PASS_MAX", 111);
    PyModule_AddIntConstant(m, "_SC_XOPEN_CRYPT", 118);
    PyModule_AddIntConstant(m, "_SC_XOPEN_ENH_I18N", 119);
    PyModule_AddIntConstant(m, "_SC_XOPEN_SHM", 120);
    PyModule_AddIntConstant(m, "_SC_PAGESIZE", 117);
    PyModule_AddIntConstant(m, "_SC_PAGE_SIZE", 117); 		/* _SC_PAGESIZE */
    PyModule_AddIntConstant(m, "_SC_ATEXIT_MAX", 138); 		/* not in POSIX, but in XPG4 */
    PyModule_AddIntConstant(m, "_SC_IOV_MAX", 139); 		/* not in POSIX, but in XPG4 */
    PyModule_AddIntConstant(m, "_SC_XOPEN_UNIX", 148);
    PyModule_AddIntConstant(m, "_SC_NPROC_CONF", 200);
    PyModule_AddIntConstant(m, "_SC_NPROCESSORS_CONF", 200);	/* _SC_NPROC_CONF */
    PyModule_AddIntConstant(m, "_SC_NPROC_ONLN", 201);
    PyModule_AddIntConstant(m, "_SC_NPROCESSORS_ONLN", 201);	/* _SC_NPROC_ONLN */
    PyModule_AddIntConstant(m, "_SC_2_C_VERSION", 129);		/* _SC_2_VERSION  */
    PyModule_AddIntConstant(m, "_SC_2_CHAR_TERM", 137);
    PyModule_AddIntConstant(m, "_SC_DELAYTIMER_MAX", 112);
    PyModule_AddIntConstant(m, "_SC_TIMER_MAX", 113);
    PyModule_AddIntConstant(m, "_SC_MAPPED_FILES", 114);
    PyModule_AddIntConstant(m, "_SC_FSYNC", 115);
    PyModule_AddIntConstant(m, "_SC_TIMERS", 116);
    PyModule_AddIntConstant(m, "_SC_CPU_CHIP_TYPE", 160);

    return (m);
}
