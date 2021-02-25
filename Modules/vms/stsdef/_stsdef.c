#include <Python.h>

PyDoc_STRVAR(doc__stsdef,
"STS definitions");

static struct PyModuleDef _stsdef_module = {
    PyModuleDef_HEAD_INIT,
    "_stsdef",
    doc__stsdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__stsdef(void) {
    PyObject *m = PyModule_Create(&_stsdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "STS_M_SEVERITY", 0x7L);
    PyModule_AddIntConstant(m, "STS_M_COND_ID", 0xFFFFFF8L);
    PyModule_AddIntConstant(m, "STS_M_CONTROL", 0xF0000000L);
    PyModule_AddIntConstant(m, "STS_M_SUCCESS", 0x1L);
    PyModule_AddIntConstant(m, "STS_M_MSG_NO", 0xFFF8L);
    PyModule_AddIntConstant(m, "STS_M_CODE", 0x7FF8L);
    PyModule_AddIntConstant(m, "STS_M_FAC_SP", 0x8000L);
    PyModule_AddIntConstant(m, "STS_M_CUST_DEF", 0x8000000L);
    PyModule_AddIntConstant(m, "STS_M_INHIB_MSG", 0x10000000L);
    PyModule_AddIntConstant(m, "STS_M_FAC_NO", 0xFFF0000L);
    PyModule_AddIntConstant(m, "STS_K_WARNING", 0);
    PyModule_AddIntConstant(m, "STS_K_SUCCESS", 1);
    PyModule_AddIntConstant(m, "STS_K_ERROR", 2);
    PyModule_AddIntConstant(m, "STS_K_INFO", 3);
    PyModule_AddIntConstant(m, "STS_K_SEVERE", 4);
    PyModule_AddIntConstant(m, "STS_S_STSDEF", 4);
    PyModule_AddIntConstant(m, "STS_S_SEVERITY", 3);
    PyModule_AddIntConstant(m, "STS_S_COND_ID", 25);
    PyModule_AddIntConstant(m, "STS_S_CONTROL", 4);
    PyModule_AddIntConstant(m, "STS_S_MSG_NO", 13);
    PyModule_AddIntConstant(m, "STS_S_CODE", 12);
    PyModule_AddIntConstant(m, "STS_S_FAC_NO", 12);
    return m;
}