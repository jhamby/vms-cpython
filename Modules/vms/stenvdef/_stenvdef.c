#include <Python.h>

PyDoc_STRVAR(doc__stenvdef,
"STENV definitions");

static struct PyModuleDef _stenvdef_module = {
    PyModuleDef_HEAD_INIT,
    "_stenvdef",
    doc__stenvdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__stenvdef(void) {
    PyObject *m = PyModule_Create(&_stenvdef_module);
    PyModule_AddIntConstant(m, "STENV_K_AUTO_ACTION", 1);
    PyModule_AddIntConstant(m, "STENV_K_BOOT_DEV", 2);
    PyModule_AddIntConstant(m, "STENV_K_BOOTDEF_DEV", 3);
    PyModule_AddIntConstant(m, "STENV_K_BOOTED_DEV", 4);
    PyModule_AddIntConstant(m, "STENV_K_BOOT_FILE", 5);
    PyModule_AddIntConstant(m, "STENV_K_BOOTED_FILE", 6);
    PyModule_AddIntConstant(m, "STENV_K_BOOT_OSFLAGS", 7);
    PyModule_AddIntConstant(m, "STENV_K_BOOTED_OSFLAGS", 8);
    PyModule_AddIntConstant(m, "STENV_K_BOOT_RESET", 9);
    PyModule_AddIntConstant(m, "STENV_K_DUMP_DEV", 10);
    PyModule_AddIntConstant(m, "STENV_K_ENABLE_AUDIT", 11);
    PyModule_AddIntConstant(m, "STENV_K_LICENSE", 12);
    PyModule_AddIntConstant(m, "STENV_K_CHAR_SET", 13);
    PyModule_AddIntConstant(m, "STENV_K_LANGUAGE", 14);
    PyModule_AddIntConstant(m, "STENV_K_TTY_DEV", 15);
    PyModule_AddIntConstant(m, "STENV_K_SYSROOT", 16);
    PyModule_AddIntConstant(m, "STENV_K_BTFLAGS", 17);
    PyModule_AddIntConstant(m, "STENV_K_FRU_EEROM", 18);
    PyModule_AddIntConstant(m, "STENVDEF_S_ItemType", 24);
    PyModule_AddIntConstant(m, "STENVDEF_S_BUF_ADDR", 8);
    PyModule_AddIntConstant(m, "STENVDEF_S_RET_ADDR", 8);
    PyModule_AddIntConstant(m, "STENVDEF__K_FREE_FORM", 0);
    PyModule_AddIntConstant(m, "STENVDEF__K_SDD_LOG", 25);
    return m;
}