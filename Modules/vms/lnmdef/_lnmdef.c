#include <Python.h>

PyDoc_STRVAR(doc__lnmdef,
"LNM definitions");

static struct PyModuleDef _lnmdef_module = {
    PyModuleDef_HEAD_INIT,
    "_lnmdef",
    doc__lnmdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__lnmdef(void) {
    PyObject *m = PyModule_Create(&_lnmdef_module);
    PyModule_AddIntConstant(m, "LNM_M_NO_ALIAS", 0x1L);
    PyModule_AddIntConstant(m, "LNM_M_CONFINE", 0x2L);
    PyModule_AddIntConstant(m, "LNM_M_CRELOG", 0x4L);
    PyModule_AddIntConstant(m, "LNM_M_TABLE", 0x8L);
    PyModule_AddIntConstant(m, "LNM_M_CONCEALED", 0x100L);
    PyModule_AddIntConstant(m, "LNM_M_TERMINAL", 0x200L);
    PyModule_AddIntConstant(m, "LNM_M_EXISTS", 0x400L);
    PyModule_AddIntConstant(m, "LNM_M_SHAREABLE", 0x10000L);
    PyModule_AddIntConstant(m, "LNM_M_CLUSTERWIDE", 0x20000L);
    PyModule_AddIntConstant(m, "LNM_M_DCL_REQUEST", 0x40000L);
    PyModule_AddIntConstant(m, "LNM_M_CREATE_IF", 0x1000000L);
    PyModule_AddIntConstant(m, "LNM_M_CASE_BLIND", 0x2000000L);
    PyModule_AddIntConstant(m, "LNM_M_INTERLOCKED", 0x4000000L);
    PyModule_AddIntConstant(m, "LNM_M_LOCAL_ACTION", 0x8000000L);
    PyModule_AddIntConstant(m, "LNM_S_LNMDEF", 4);
    PyModule_AddIntConstant(m, "LNM_C_TABNAMLEN", 31);
    PyModule_AddIntConstant(m, "LNM_C_NAMLENGTH", 255);
    PyModule_AddIntConstant(m, "LNM_C_MAXDEPTH", 10);
    PyModule_AddIntConstant(m, "LNM__INDEX", 1);
    PyModule_AddIntConstant(m, "LNM__STRING", 2);
    PyModule_AddIntConstant(m, "LNM__ATTRIBUTES", 3);
    PyModule_AddIntConstant(m, "LNM__TABLE", 4);
    PyModule_AddIntConstant(m, "LNM__LENGTH", 5);
    PyModule_AddIntConstant(m, "LNM__ACMODE", 6);
    PyModule_AddIntConstant(m, "LNM__MAX_INDEX", 7);
    PyModule_AddIntConstant(m, "LNM__PARENT", 8);
    PyModule_AddIntConstant(m, "LNM__LNMB_ADDR", 9);
    PyModule_AddIntConstant(m, "LNM__AGENT_ACMODE", 10);
    PyModule_AddIntConstant(m, "LNM__CHAIN", -1);
    return m;
}