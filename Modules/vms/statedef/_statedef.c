#include <Python.h>

PyDoc_STRVAR(doc__statedef,
"STATE definitions");

static struct PyModuleDef _statedef_module = {
    PyModuleDef_HEAD_INIT,
    "statedef",
    doc__statedef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__statedef(void) {
    PyObject *m = PyModule_Create(&_statedef_module);
    PyModule_AddIntConstant(m, "SCH_C_COLPG", 1);
    PyModule_AddIntConstant(m, "SCH_C_MWAIT", 2);
    PyModule_AddIntConstant(m, "SCH_C_CEF", 3);
    PyModule_AddIntConstant(m, "SCH_C_PFW", 4);
    PyModule_AddIntConstant(m, "SCH_C_LEF", 5);
    PyModule_AddIntConstant(m, "SCH_C_LEFO", 6);
    PyModule_AddIntConstant(m, "SCH_C_HIB", 7);
    PyModule_AddIntConstant(m, "SCH_C_HIBO", 8);
    PyModule_AddIntConstant(m, "SCH_C_SUSP", 9);
    PyModule_AddIntConstant(m, "SCH_C_SUSPO", 10);
    PyModule_AddIntConstant(m, "SCH_C_FPG", 11);
    PyModule_AddIntConstant(m, "SCH_C_COM", 12);
    PyModule_AddIntConstant(m, "SCH_C_COMO", 13);
    PyModule_AddIntConstant(m, "SCH_C_CUR", 14);
    return m;
}