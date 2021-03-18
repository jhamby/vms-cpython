#include <Python.h>

PyDoc_STRVAR(doc__brkdef,
"BRK definitions");

static struct PyModuleDef _brkdef_module = {
    PyModuleDef_HEAD_INIT,
    "_brkdef",
    doc__brkdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__brkdef(void) {
    PyObject *m = PyModule_Create(&_brkdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "BRK_C_DEVICE", 1);
    PyModule_AddIntConstant(m, "BRK_C_USERNAME", 2);
    PyModule_AddIntConstant(m, "BRK_C_ALLUSERS", 3);
    PyModule_AddIntConstant(m, "BRK_C_ALLTERMS", 4);
    PyModule_AddIntConstant(m, "BRK_C_MAXSENDTYPE", 4);
    PyModule_AddIntConstant(m, "BRK_C_GENERAL", 0);
    PyModule_AddIntConstant(m, "BRK_C_PHONE", 1);
    PyModule_AddIntConstant(m, "BRK_C_MAIL", 2);
    PyModule_AddIntConstant(m, "BRK_C_QUEUE", 3);
    PyModule_AddIntConstant(m, "BRK_C_SHUTDOWN", 4);
    PyModule_AddIntConstant(m, "BRK_C_URGENT", 5);
    PyModule_AddIntConstant(m, "BRK_C_DCL", 6);
    PyModule_AddIntConstant(m, "BRK_C_OPCOM", 7);
    PyModule_AddIntConstant(m, "BRK_C_USER1", 32);
    PyModule_AddIntConstant(m, "BRK_C_USER2", 33);
    PyModule_AddIntConstant(m, "BRK_C_USER3", 34);
    PyModule_AddIntConstant(m, "BRK_C_USER4", 35);
    PyModule_AddIntConstant(m, "BRK_C_USER5", 36);
    PyModule_AddIntConstant(m, "BRK_C_USER6", 37);
    PyModule_AddIntConstant(m, "BRK_C_USER7", 38);
    PyModule_AddIntConstant(m, "BRK_C_USER8", 39);
    PyModule_AddIntConstant(m, "BRK_C_USER9", 40);
    PyModule_AddIntConstant(m, "BRK_C_USER10", 41);
    PyModule_AddIntConstant(m, "BRK_C_USER11", 42);
    PyModule_AddIntConstant(m, "BRK_C_USER12", 43);
    PyModule_AddIntConstant(m, "BRK_C_USER13", 44);
    PyModule_AddIntConstant(m, "BRK_C_USER14", 45);
    PyModule_AddIntConstant(m, "BRK_C_USER15", 46);
    PyModule_AddIntConstant(m, "BRK_C_USER16", 47);
    PyModule_AddUnsignedLongConstant(m, "BRK_M_SCREEN", 0x100UL);
    PyModule_AddUnsignedLongConstant(m, "BRK_M_BOTTOM", 0x200UL);
    PyModule_AddUnsignedLongConstant(m, "BRK_M_NOREFRESH", 0x400UL);
    PyModule_AddUnsignedLongConstant(m, "BRK_M_CLUSTER", 0x800UL);
    PyModule_AddIntConstant(m, "BRK_S_FLAGS_INPUT", 2);
    PyModule_AddIntConstant(m, "BRK_S_ERASE_LINES", 8);
    return m;
}