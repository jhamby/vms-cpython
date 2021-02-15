#define PY_SSIZE_T_CLEAN
#include "Python.h"

#include <descrip.h>
#include <lib$routines.h>
#include <ssdef.h>
#include <stsdef.h>

#define ConvertArgToStr(arg, value, size, func_name)            \
    if (PyUnicode_CheckExact(arg)) {                            \
        (value) = (char*)PyUnicode_AsUTF8AndSize(arg, &(size)); \
    } else if (PyBytes_CheckExact(arg)) {                       \
        PyBytes_AsStringAndSize(arg, &(value), &(size));        \
    }                                                           \
    if (!(value) || !(size)) {                                  \
        _PyArg_BadArgument(func_name, #arg, "str", arg);        \
        Py_RETURN_NONE;                                         \
    }

#define ConvertArgToLong(arg, value, func_name)             \
    if (!PyLong_Check(arg)) {                               \
        _PyArg_BadArgument(func_name, #arg, "long", arg);   \
        Py_RETURN_NONE;                                     \
    }                                                       \
    value = PyLong_AsLong(arg);                             \
    p##value = &value


// unsigned int _date_time(char **dt)
// {
//     char val[32];
//     struct dsc$descriptor_s val_dsc;
//     unsigned int status;

//     assert(dt);

//     val_dsc.dsc$w_length = sizeof(val) - 1;
//     val_dsc.dsc$b_class = DSC$K_CLASS_S;
//     val_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
//     val_dsc.dsc$a_pointer = val;

//     status = lib$date_time(&val_dsc);

//     if (OKAY(status)) {
//         val[23] = '\0';
//         *dt = strdup(val);
//         assert(*dt);
//     } else {
//         *dt = strdup(nil);
//     	assert(*dt);
//     }

//     return (status);
// }


// unsigned int _free_ef(unsigned int efn)
// {
//     return (lib$free_ef(&efn));
// }


// unsigned int _get_ef(unsigned int *efn)
// {
//     assert(efn);
//     return (lib$get_ef(efn));
// }


// unsigned int _get_hostname(char **hostname, unsigned int flags)
// {
//     char val[256];
//     struct dsc$descriptor_s val_dsc;
//     unsigned int status;
//     unsigned short len;

//     assert(hostname);

//     val_dsc.dsc$w_length = sizeof(val) - 1;
//     val_dsc.dsc$b_class = DSC$K_CLASS_S;
//     val_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
//     val_dsc.dsc$a_pointer = val;

//     status = lib$get_hostname(&val_dsc, &len, flags);

//     if (OKAY(status)) {
//         val[len] = '\0';
//         *hostname = strdup(val);
//         assert(*hostname);
//     } else {
//         *hostname = strdup(nil);
// 	    assert(*hostname);
//     }

//     return (status);
// }


// unsigned int _getjpi(int item, unsigned int *pid, char *prn, char **ret)
static PyObject*
LIB_getjpi(
    PyObject *self,
    PyObject *const *args,
    Py_ssize_t nargs)
{

    if (!_PyArg_CheckPositional("getjpi", nargs, 1, 3)) {
        Py_RETURN_NONE;
    }

    unsigned long item = 0, *pitem = NULL;
    ConvertArgToLong(args[0], item, "getsyi");

    unsigned long pid = 0, *ppid = NULL;
    if (nargs > 1 && args[1] != Py_None) {
        ConvertArgToLong(args[1], pid, "getsyi");
    }

    char *proc_name = NULL;
    Py_ssize_t proc_size = 0;
    if (nargs > 2 && args[2] != Py_None) {
        ConvertArgToStr(args[2], proc_name, proc_size, "getsyi");
    }

    char buffer[256];
    struct dsc$descriptor_s prn_dsc, val_dsc;
    struct dsc$descriptor_s *pprn_dsc = NULL;

    if (proc_name && proc_size) {
        prn_dsc.dsc$w_length = proc_size;
        prn_dsc.dsc$b_class = DSC$K_CLASS_S;
        prn_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
        prn_dsc.dsc$a_pointer = proc_name;
        pprn_dsc = &prn_dsc;
    }

    val_dsc.dsc$w_length = sizeof(buffer) - 1;
    val_dsc.dsc$b_class = DSC$K_CLASS_S;
    val_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
    val_dsc.dsc$a_pointer = buffer;

    int status = 0;
    int result_len = 0;

    Py_BEGIN_ALLOW_THREADS

    status = lib$getjpi(&item, &pid, pprn_dsc, 0, &val_dsc, &result_len);

    Py_END_ALLOW_THREADS

    if (!$VMS_STATUS_SUCCESS(status)) {
        result_len = 0;
    }

    buffer[result_len] = 0;

    PyObject *pResultList = PyList_New(2);
    if (!pResultList) {
        Py_RETURN_NONE;
    }
    if (PyList_SetItem(pResultList, 0, PyLong_FromLong(status))) {
        Py_DECREF(pResultList);
        Py_RETURN_NONE;
    }
    if (PyList_SetItem(pResultList, 1, PyUnicode_FromString(buffer))) {
        Py_DECREF(pResultList);
        Py_RETURN_NONE;
    }
    if (!ppid) {
        PyObject *pPid = PyLong_FromLong(pid);
        if (PyList_Append(pResultList, pPid)) {
            Py_DECREF(pPid);
            Py_DECREF(pResultList);
            Py_RETURN_NONE;
        }
        Py_DECREF(pPid);
    }

    return pResultList;
}


// unsigned int _getsyi(int item, char **ret, unsigned int *csid, char *node)
static PyObject*
LIB_getsyi(
    PyObject *self,
    PyObject *const *args,
    Py_ssize_t nargs)
{

    if (!_PyArg_CheckPositional("getsyi", nargs, 1, 2)) {
        Py_RETURN_NONE;
    }

    unsigned long item = 0, *pitem = NULL;
    ConvertArgToLong(args[0], item, "getsyi");

    char *node = NULL;
    Py_ssize_t node_size = 0;
    if (nargs > 1 && args[1] != Py_None) {
        ConvertArgToStr(args[1], node, node_size, "getsyi");
    }

    char buffer[256];
    struct dsc$descriptor_s node_dsc, val_dsc;
    struct dsc$descriptor_s *pnode_dsc = NULL;

    long csid = 0;

    val_dsc.dsc$w_length = sizeof(buffer) - 1;
    val_dsc.dsc$b_class = DSC$K_CLASS_S;
    val_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
    val_dsc.dsc$a_pointer = buffer;

    if (node && node_size) {
        node_dsc.dsc$w_length = node_size;
        node_dsc.dsc$b_class = DSC$K_CLASS_S;
        node_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
        node_dsc.dsc$a_pointer = node;
        pnode_dsc = &node_dsc;
    }

    int status = 0;
    int result_len = 0;

    Py_BEGIN_ALLOW_THREADS

    status = lib$getsyi(&item, NULL, &val_dsc, &result_len, &csid, pnode_dsc);

    Py_END_ALLOW_THREADS

    if (!$VMS_STATUS_SUCCESS(status)) {
        result_len = 0;
    }

    buffer[result_len] = 0;

    PyObject *pResultList = PyList_New(3);
    if (!pResultList) {
        Py_RETURN_NONE;
    }
    if (PyList_SetItem(pResultList, 0, PyLong_FromLong(status))) {
        Py_DECREF(pResultList);
        Py_RETURN_NONE;
    }
    if (PyList_SetItem(pResultList, 1, PyUnicode_FromString(buffer))) {
        Py_DECREF(pResultList);
        Py_RETURN_NONE;
    }
    if (PyList_SetItem(pResultList, 2, PyLong_FromLong(csid))) {
        Py_DECREF(pResultList);
        Py_RETURN_NONE;
    }

    return pResultList;

}

// unsigned int _spawn(char *cmd, char *in, char *out, unsigned int flags,
// 		    char *prn, unsigned int *pid)
static PyObject*
LIB_spawn(
    PyObject *self,
    PyObject *const *args,
    Py_ssize_t nargs)
{

    if (!_PyArg_CheckPositional("spawn", nargs, 0, 5)) {
        Py_RETURN_NONE;
    }

    char *cmd = NULL;
    Py_ssize_t cmd_size = 0;

    if (nargs > 0 && args[0] != Py_None) {
        ConvertArgToStr(args[0], cmd, cmd_size, "spawn");
    }

    char *in_file = NULL;
    Py_ssize_t in_size = 0;

    if (nargs > 1 && args[1] != Py_None) {
        ConvertArgToStr(args[1], in_file, in_size, "spawn");
    }

    char *out_file = NULL;
    Py_ssize_t out_size = 0;

    if (nargs > 2 && args[2] != Py_None) {
        ConvertArgToStr(args[2], out_file, out_size, "spawn");
    }

    unsigned int flags = 0, *pflags = NULL;
    if (nargs > 3 && args[3] != Py_None) {
        ConvertArgToLong(args[3], flags, "spawn");
    }

    char *proc_name = NULL;
    Py_ssize_t proc_size = 0;

    if (nargs > 2 && args[2] != Py_None) {
        ConvertArgToStr(args[2], proc_name, proc_size, "spawn");
    }

    struct dsc$descriptor_s cmd_dsc, in_dsc, out_dsc, prn_dsc;
    struct dsc$descriptor_s *pcmd_dsc = NULL, *pin_dsc = NULL, *pout_dsc = NULL, *pprn_dsc = NULL;

    if (cmd && cmd_size) {
        cmd_dsc.dsc$w_length = cmd_size;
        cmd_dsc.dsc$b_class = DSC$K_CLASS_S;
        cmd_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
        cmd_dsc.dsc$a_pointer = cmd;
        pcmd_dsc = &cmd_dsc;
    }

    if (in_file && in_size) {
        in_dsc.dsc$w_length = in_size;
        in_dsc.dsc$b_class = DSC$K_CLASS_S;
        in_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
        in_dsc.dsc$a_pointer = in_file;
        pin_dsc = &in_dsc;
    }

    if (out_file && out_size) {
        out_dsc.dsc$w_length = out_size;
        out_dsc.dsc$b_class = DSC$K_CLASS_S;
        out_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
        out_dsc.dsc$a_pointer = out_file;
        pout_dsc = &out_dsc;
    }

    if (proc_name && proc_size) {
        prn_dsc.dsc$w_length = proc_size;
        prn_dsc.dsc$b_class = DSC$K_CLASS_S;
        prn_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
        prn_dsc.dsc$a_pointer = proc_name;
        pprn_dsc = &prn_dsc;
    }

    int pid = 0;
    int status = 0;

    Py_BEGIN_ALLOW_THREADS

    status = lib$spawn(
        pcmd_dsc,
        pin_dsc,
        pout_dsc,
        pflags,
        pprn_dsc,
        &pid,
        NULL, 0, NULL, NULL, NULL, NULL, NULL);

    Py_END_ALLOW_THREADS

    PyObject *pResultList = PyList_New(2);
    if (!pResultList) {
        Py_RETURN_NONE;
    }
    if (PyList_SetItem(pResultList, 0, PyLong_FromLong(status))) {
        Py_DECREF(pResultList);
        Py_RETURN_NONE;
    }
    if (PyList_SetItem(pResultList, 1, PyLong_FromLong(pid))) {
        Py_DECREF(pResultList);
        Py_RETURN_NONE;
    }

    return pResultList;
}

// unsigned int _do_command(char *cmd)

static PyObject*
LIB_do_command(
    PyObject * self,
    PyObject * args)
{
    char *value = NULL;
    Py_ssize_t size = 0;

    ConvertArgToStr(args, value, size, "do_command");

    struct dsc$descriptor_s cmd_dsc;
    cmd_dsc.dsc$w_length = size;
    cmd_dsc.dsc$b_class = DSC$K_CLASS_S;
    cmd_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
    cmd_dsc.dsc$a_pointer = value;

    int status = 0;

    Py_BEGIN_ALLOW_THREADS

    status = lib$do_command(&cmd_dsc);

    Py_END_ALLOW_THREADS

    return PyLong_FromLong(status);
}



// unsigned int _put_common(char *str)

static PyObject*
LIB_put_common(
    PyObject * self,
    PyObject * args)
{
    char *value = NULL;
    Py_ssize_t size = 0;

    ConvertArgToStr(args, value, size, "put_common");

    struct dsc$descriptor_s str_dsc;

    str_dsc.dsc$w_length = size;
    str_dsc.dsc$b_class = DSC$K_CLASS_S;
    str_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
    str_dsc.dsc$a_pointer = value;

    int status = 0;

    Py_BEGIN_ALLOW_THREADS

    status = lib$put_common(&str_dsc);

    Py_END_ALLOW_THREADS

    return PyLong_FromLong(status);
}

// unsigned int _get_common(char **str)

static PyObject*
LIB_get_common(
    PyObject * self,
    PyObject * args)
{
    #undef MAX_GET_COMMON_SIZE
    #define MAX_GET_COMMON_SIZE 252

    char buffer[MAX_GET_COMMON_SIZE + 1];

    struct dsc$descriptor_s str_dsc;
    str_dsc.dsc$w_length = MAX_GET_COMMON_SIZE;
    str_dsc.dsc$b_class = DSC$K_CLASS_S;
    str_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
    str_dsc.dsc$a_pointer = buffer;

    unsigned short len = 0;

    int status = 0;

    Py_BEGIN_ALLOW_THREADS

    status = lib$get_common(&str_dsc, &len);

    Py_END_ALLOW_THREADS

    if (!$VMS_STATUS_SUCCESS(status)) {
        len = 0;
    }

    buffer[len] = 0;

    PyObject *pResultList = PyList_New(2);
    if (!pResultList) {
        Py_RETURN_NONE;
    }
    if (PyList_SetItem(pResultList, 0, PyLong_FromLong(status))) {
        Py_DECREF(pResultList);
        Py_RETURN_NONE;
    }
    if (PyList_SetItem(pResultList, 1, PyUnicode_FromString(buffer))) {
        Py_DECREF(pResultList);
        Py_RETURN_NONE;
    }

    return pResultList;

}

// unsigned int _create_dir(char *spec, unsigned int *uic, unsigned short pe, unsigned short pv)

static PyObject*
LIB_create_dir(
    PyObject *self,
    PyObject *const *args,
    Py_ssize_t nargs)
{

    if (!_PyArg_CheckPositional("create_dir", nargs, 1, 4)) {
        Py_RETURN_NONE;
    }

    char *spec = NULL;
    Py_ssize_t spec_size = 0;

    ConvertArgToStr(args[0], spec, spec_size, "create_dir");

    unsigned long uic = 0, *puic = NULL;
    if (nargs > 1 && args[1] != Py_None) {
        ConvertArgToLong(args[1], uic, "create_dir");
    }

    unsigned short pe = 0, *ppe = NULL;
    if (nargs > 2) {
        ConvertArgToLong(args[2], pe, "create_dir");
    }

    unsigned short pv = 0, *ppv = NULL;
    if (nargs > 3) {
        ConvertArgToLong(args[3], pv, "create_dir");
    }

    struct dsc$descriptor_s spec_dsc;

    spec_dsc.dsc$w_length = spec_size;
    spec_dsc.dsc$b_class = DSC$K_CLASS_S;
    spec_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
    spec_dsc.dsc$a_pointer = spec;

    int status = 0;

    Py_BEGIN_ALLOW_THREADS

    status = lib$create_dir(&spec_dsc, puic, ppe, ppv, NULL, NULL, NULL);

    Py_END_ALLOW_THREADS

    return PyLong_FromLong(status);
}


/********************************************************************
  DCL Symbol routines
*/

static PyObject*
LIB_set_symbol(
    PyObject *self,
    PyObject *const *args,
    Py_ssize_t nargs)
{
    if (!_PyArg_CheckPositional("set_symbol", nargs, 2, 2)) {
        Py_RETURN_NONE;
    }

    PyObject *nameObj = args[0];
    PyObject *valueObj = args[1];
    char *name = NULL;
    Py_ssize_t name_size = 0;
    char *value = NULL;
    Py_ssize_t value_size = 0;

    ConvertArgToStr(args[0], name, name_size, "set_symbol");

    ConvertArgToStr(args[1], value, value_size, "set_symbol");

    struct dsc$descriptor_s sym_dsc, val_dsc;

    sym_dsc.dsc$w_length = name_size;
    sym_dsc.dsc$b_class = DSC$K_CLASS_S;
    sym_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
    sym_dsc.dsc$a_pointer = name;

    val_dsc.dsc$w_length = value_size;
    val_dsc.dsc$b_class = DSC$K_CLASS_S;
    val_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
    val_dsc.dsc$a_pointer = value;

    int status = 0;

    Py_BEGIN_ALLOW_THREADS

    status = lib$set_symbol(&sym_dsc, &val_dsc, NULL);

    Py_END_ALLOW_THREADS

    return PyLong_FromLong(status);
}

static PyObject*
LIB_get_symbol(
    PyObject * self,
    PyObject * args)
{
    char *name = NULL;
    Py_ssize_t size = 0;

    ConvertArgToStr(args, name, size, "get_symbol");

    struct dsc$descriptor_s symbol_name;
    symbol_name.dsc$w_length = size;
    symbol_name.dsc$b_class = DSC$K_CLASS_S;
    symbol_name.dsc$b_dtype = DSC$K_DTYPE_T;
    symbol_name.dsc$a_pointer = name;

    char buffer[256];
    buffer[0] = 0;
    struct dsc$descriptor_s symbol_value;
    symbol_value.dsc$w_length = 255;
    symbol_value.dsc$b_class = DSC$K_CLASS_S;
    symbol_value.dsc$b_dtype = DSC$K_DTYPE_T;
    symbol_value.dsc$a_pointer = buffer;

    short result_len = 0;
    int status = 0;

    Py_BEGIN_ALLOW_THREADS

    status = lib$get_symbol(&symbol_name, &symbol_value, &result_len);

    Py_END_ALLOW_THREADS

    if (!$VMS_STATUS_SUCCESS(status)) {
        result_len = 0;
    }
    buffer[result_len] = 0;

    PyObject *pResultList = PyList_New(2);
    if (!pResultList) {
        Py_RETURN_NONE;
    }
    if (PyList_SetItem(pResultList, 0, PyLong_FromLong(status))) {
        Py_DECREF(pResultList);
        Py_RETURN_NONE;
    }
    if (PyList_SetItem(pResultList, 1, PyUnicode_FromString(buffer))) {
        Py_DECREF(pResultList);
        Py_RETURN_NONE;
    }

    return pResultList;
}

static PyObject*
LIB_delete_symbol(
    PyObject * self,
    PyObject * args)
{
    char *name = NULL;
    Py_ssize_t size = 0;

    ConvertArgToStr(args, name, size, "delete_symbol");

    struct dsc$descriptor_s symbol_name;
    symbol_name.dsc$w_length = size;
    symbol_name.dsc$b_class = DSC$K_CLASS_S;
    symbol_name.dsc$b_dtype = DSC$K_DTYPE_T;
    symbol_name.dsc$a_pointer = name;

    int status = 0;

    Py_BEGIN_ALLOW_THREADS

    status = lib$delete_symbol(&symbol_name, NULL);

    Py_END_ALLOW_THREADS

    return PyLong_FromLong(status);
}


/********************************************************************
  Module
*/

static PyMethodDef _module_methods[] = {
    {"getjpi", (PyCFunction) LIB_getjpi, METH_FASTCALL,
        PyDoc_STR("getjpi(item: number, ?pid: number, ?name: str)->[status: number, value: str, ?pid: number]   Gets system wide information")},
    {"getsyi", (PyCFunction) LIB_getsyi, METH_FASTCALL,
        PyDoc_STR("getsyi(item: number, ?node: str)->[status: number, value: str, csid: number]   Gets system wide information")},
    {"spawn", (PyCFunction) LIB_spawn, METH_FASTCALL,
        PyDoc_STR("spawn(?cmd: str, ?input: str, ?output: str, ?flags: number, ?name: str)->[status: number, pid: number]   Spawn a process")},
    {"do_command", (PyCFunction) LIB_do_command, METH_O,
        PyDoc_STR("do_command(cmd: str)->status: number   Do a command and exit")},
    {"put_common", (PyCFunction) LIB_put_common, METH_O,
        PyDoc_STR("put_common(value: str)->status: number   Sets common string")},
    {"get_common", (PyCFunction) LIB_get_common, METH_O,
        PyDoc_STR("get_common()->[status: number, common: str]   Returns common string")},
    {"create_dir", (PyCFunction) LIB_create_dir, METH_FASTCALL,
        PyDoc_STR("create_dir(spec: str, ?own_uic: number, ?prot_en: number, ?prot_v: number)->status: number   Create directory")},
    {"get_symbol", (PyCFunction) LIB_get_symbol, METH_O,
        PyDoc_STR("get_symbol(name: str)->[status: number, symbol: str]   Returns DCL symbol")},
    {"set_symbol", (PyCFunction) LIB_set_symbol, METH_FASTCALL,
        PyDoc_STR("set_symbol(name: str, value: str)->status: number   Sets DCL local symbol")},
    {"delete_symbol", (PyCFunction) LIB_delete_symbol, METH_O,
        PyDoc_STR("delete_symbol(name: str)->status: number   Returns DCL symbol")},
    {NULL, NULL}
};

static struct PyModuleDef _module_definition = {
    PyModuleDef_HEAD_INIT,
    "_lib",
    PyDoc_STR("OpenVMS LIB$ wrapper"),
    -1,
    _module_methods,
    NULL,
    NULL,
    NULL,
    NULL,
};

PyMODINIT_FUNC PyInit__lib(void)
{
    PyObject *m = PyModule_Create(&_module_definition);
    PyModule_AddIntConstant(m, "LIB_FACILITY", 21);
    PyModule_AddIntConstant(m, "LIB_NORMAL", 1409025);
    PyModule_AddIntConstant(m, "LIB_STRTRU", 1409041);
    PyModule_AddIntConstant(m, "LIB_ONEENTQUE", 1409049);
    PyModule_AddIntConstant(m, "LIB_KEYALRINS", 1409057);
    PyModule_AddIntConstant(m, "LIB_ERRROUCAL", 1409065);
    PyModule_AddIntConstant(m, "LIB_RESTART", 1409073);
    PyModule_AddIntConstant(m, "LIB_BADSTA", 1409540);
    PyModule_AddIntConstant(m, "LIB_FATERRLIB", 1409548);
    PyModule_AddIntConstant(m, "LIB_INSVIRMEM", 1409556);
    PyModule_AddIntConstant(m, "LIB_INPSTRTRU", 1409564);
    PyModule_AddIntConstant(m, "LIB_INVSTRDES", 1409572);
    PyModule_AddIntConstant(m, "LIB_INTLOGERR", 1409580);
    PyModule_AddIntConstant(m, "LIB_INVARG", 1409588);
    PyModule_AddIntConstant(m, "LIB_AMBKEY", 1409596);
    PyModule_AddIntConstant(m, "LIB_UNRKEY", 1409604);
    PyModule_AddIntConstant(m, "LIB_PUSSTAOVE", 1409612);
    PyModule_AddIntConstant(m, "LIB_USEFLORES", 1409620);
    PyModule_AddIntConstant(m, "LIB_SIGNO_ARG", 1409628);
    PyModule_AddIntConstant(m, "LIB_BADBLOADR", 1409636);
    PyModule_AddIntConstant(m, "LIB_BADBLOSIZ", 1409644);
    PyModule_AddIntConstant(m, "LIB_NOTFOU", 1409652);
    PyModule_AddIntConstant(m, "LIB_ATTCONSTO", 1409660);
    PyModule_AddIntConstant(m, "LIB_SYNTAXERR", 1409668);
    PyModule_AddIntConstant(m, "LIB_INVTYPE", 1409676);
    PyModule_AddIntConstant(m, "LIB_INSEF", 1409684);
    PyModule_AddIntConstant(m, "LIB_EF_ALRFRE", 1409692);
    PyModule_AddIntConstant(m, "LIB_EF_ALRRES", 1409700);
    PyModule_AddIntConstant(m, "LIB_EF_RESSYS", 1409708);
    PyModule_AddIntConstant(m, "LIB_INSLUN", 1409716);
    PyModule_AddIntConstant(m, "LIB_LUNALRFRE", 1409724);
    PyModule_AddIntConstant(m, "LIB_LUNRESSYS", 1409732);
    PyModule_AddIntConstant(m, "LIB_SCRBUFOVF", 1409740);
    PyModule_AddIntConstant(m, "LIB_INVSCRPOS", 1409748);
    PyModule_AddIntConstant(m, "LIB_SECINTFAI", 1409756);
    PyModule_AddIntConstant(m, "LIB_INVCHA", 1409764);
    PyModule_AddIntConstant(m, "LIB_QUEWASEMP", 1409772);
    PyModule_AddIntConstant(m, "LIB_STRIS_INT", 1409780);
    PyModule_AddIntConstant(m, "LIB_KEYNOTFOU", 1409788);
    PyModule_AddIntConstant(m, "LIB_INVCVT", 1409796);
    PyModule_AddIntConstant(m, "LIB_INVDTYDSC", 1409804);
    PyModule_AddIntConstant(m, "LIB_INVCLADSC", 1409812);
    PyModule_AddIntConstant(m, "LIB_INVCLADTY", 1409820);
    PyModule_AddIntConstant(m, "LIB_INVNBDS", 1409828);
    PyModule_AddIntConstant(m, "LIB_DESSTROVF", 1409836);
    PyModule_AddIntConstant(m, "LIB_INTOVF", 1409844);
    PyModule_AddIntConstant(m, "LIB_DECOVF", 1409852);
    PyModule_AddIntConstant(m, "LIB_FLTOVF", 1409860);
    PyModule_AddIntConstant(m, "LIB_FLTUND", 1409868);
    PyModule_AddIntConstant(m, "LIB_ROPRAND", 1409876);
    PyModule_AddIntConstant(m, "LIB_WRONUMARG", 1409884);
    PyModule_AddIntConstant(m, "LIB_NOSUCHSYM", 1409892);
    PyModule_AddIntConstant(m, "LIB_INSCLIMEM", 1409900);
    PyModule_AddIntConstant(m, "LIB_AMBSYMDEF", 1409908);
    PyModule_AddIntConstant(m, "LIB_NOCLI", 1409916);
    PyModule_AddIntConstant(m, "LIB_UNECLIERR", 1409924);
    PyModule_AddIntConstant(m, "LIB_INVSYMNAM", 1409932);
    PyModule_AddIntConstant(m, "LIB_ATTREQREF", 1409940);
    PyModule_AddIntConstant(m, "LIB_INVFILSPE", 1409948);
    PyModule_AddIntConstant(m, "LIB_INVXAB", 1409956);
    PyModule_AddIntConstant(m, "LIB_NO_STRACT", 1409964);
    PyModule_AddIntConstant(m, "LIB_BADTAGVAL", 1409972);
    PyModule_AddIntConstant(m, "LIB_INVOPEZON", 1409980);
    PyModule_AddIntConstant(m, "LIB_PAGLIMEXC", 1409988);
    PyModule_AddIntConstant(m, "LIB_NOTIMP", 1409996);
    PyModule_AddIntConstant(m, "LIB_BADZONE", 1410004);
    PyModule_AddIntConstant(m, "LIB_IVTIME", 1410012);
    PyModule_AddIntConstant(m, "LIB_ONEDELTIM", 1410020);
    PyModule_AddIntConstant(m, "LIB_NEGTIM", 1410028);
    PyModule_AddIntConstant(m, "LIB_INVARGORD", 1410036);
    PyModule_AddIntConstant(m, "LIB_ABSTIMREQ", 1410044);
    PyModule_AddIntConstant(m, "LIB_DELTIMREQ", 1410052);
    PyModule_AddIntConstant(m, "LIB_INVOPER", 1410060);
    PyModule_AddIntConstant(m, "LIB_REENTRANCY", 1410068);
    PyModule_AddIntConstant(m, "LIB_UNRFORCOD", 1410076);
    PyModule_AddIntConstant(m, "LIB_ILLINISTR", 1410084);
    PyModule_AddIntConstant(m, "LIB_NUMELEMENTS", 1410092);
    PyModule_AddIntConstant(m, "LIB_ELETOOLON", 1410100);
    PyModule_AddIntConstant(m, "LIB_ILLCOMPONENT", 1410108);
    PyModule_AddIntConstant(m, "LIB_AMBDATTIM", 1410116);
    PyModule_AddIntConstant(m, "LIB_INCDATTIM", 1410124);
    PyModule_AddIntConstant(m, "LIB_ILLFORMAT", 1410132);
    PyModule_AddIntConstant(m, "LIB_UNSUPVER", 1410140);
    PyModule_AddIntConstant(m, "LIB_BADFORMAT", 1410148);
    PyModule_AddIntConstant(m, "LIB_NODTOOLNG", 1410156);
    PyModule_AddIntConstant(m, "LIB_NOHOSNAM", 1410164);
    PyModule_AddIntConstant(m, "LIB_OUTSTRTRU", 1413120);
    PyModule_AddIntConstant(m, "LIB_FILFAIMAT", 1413128);
    PyModule_AddIntConstant(m, "LIB_NEGANS", 1413136);
    PyModule_AddIntConstant(m, "LIB_QUIPRO", 1413144);
    PyModule_AddIntConstant(m, "LIB_QUICONACT", 1413152);
    PyModule_AddIntConstant(m, "LIB_ENGLUSED", 1413160);
    PyModule_AddIntConstant(m, "LIB_DEFFORUSE", 1413168);
    PyModule_AddIntConstant(m, "LIB_MEMALRFRE", 1413176);
    PyModule_AddIntConstant(m, "LIB_BADCCC", 1425408);
    PyModule_AddIntConstant(m, "LIB_EOMERROR", 1425416);
    PyModule_AddIntConstant(m, "LIB_EOMFATAL", 1425424);
    PyModule_AddIntConstant(m, "LIB_EOMWARN", 1425432);
    PyModule_AddIntConstant(m, "LIB_GSDTYP", 1425440);
    PyModule_AddIntConstant(m, "LIB_ILLFMLCNT", 1425448);
    PyModule_AddIntConstant(m, "LIB_ILLMODNAM", 1425456);
    PyModule_AddIntConstant(m, "LIB_ILLPSCLEN", 1425464);
    PyModule_AddIntConstant(m, "LIB_ILLRECLEN", 1425472);
    PyModule_AddIntConstant(m, "LIB_ILLRECLN2", 1425480);
    PyModule_AddIntConstant(m, "LIB_ILLRECTYP", 1425488);
    PyModule_AddIntConstant(m, "LIB_ILLRECTY2", 1425496);
    PyModule_AddIntConstant(m, "LIB_ILLSYMLEN", 1425504);
    PyModule_AddIntConstant(m, "LIB_NOEOM", 1425512);
    PyModule_AddIntConstant(m, "LIB_RECTOOSML", 1425520);
    PyModule_AddIntConstant(m, "LIB_SEQUENCE", 1425528);
    PyModule_AddIntConstant(m, "LIB_SEQUENCE2", 1425536);
    PyModule_AddIntConstant(m, "LIB_STRLVL", 1425544);
    PyModule_AddIntConstant(m, "LIB_NOWILD", 1380650);
    PyModule_AddIntConstant(m, "LIB_ACTIMAGE", 1381050);
    PyModule_AddIntConstant(m, "LIB_OPENIN", 1380506);
    PyModule_AddIntConstant(m, "LIB_CLOSEIN", 1380432);
    PyModule_AddIntConstant(m, "LIB_READERR", 1380530);

    return (m);
}
