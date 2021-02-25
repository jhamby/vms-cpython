#include <Python.h>

PyDoc_STRVAR(doc__libclidef,
"LIBCLI definitions");

static struct PyModuleDef _libclidef_module = {
    PyModuleDef_HEAD_INIT,
    "_libclidef",
    doc__libclidef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__libclidef(void) {
    PyObject *m = PyModule_Create(&_libclidef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "LIB_K_CLI_LOCAL_SYM", 1);
    PyModule_AddIntConstant(m, "LIB_K_CLI_GLOBAL_SYM", 2);
    PyModule_AddIntConstant(m, "LIB_M_CLI_CTRLT", 0x100000L);
    PyModule_AddIntConstant(m, "LIB_M_CLI_CTRLY", 0x2000000L);
    PyModule_AddIntConstant(m, "LIB_S_CLI_CTRL_FIELDS", 4);
    return m;
}