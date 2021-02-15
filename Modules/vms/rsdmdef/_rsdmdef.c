#include <Python.h>

PyDoc_STRVAR(doc__rsdmdef,
"RSDM definitions");

static struct PyModuleDef _rsdmdef_module = {
    PyModuleDef_HEAD_INIT,
    "_rsdmdef",
    doc__rsdmdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__rsdmdef(void) {
    PyObject *m = PyModule_Create(&_rsdmdef_module);
    PyModule_AddIntConstant(m, "RSDM__JOIN_SYSTEM", 1);
    PyModule_AddIntConstant(m, "RSDM__JOIN_DEFAULT", 2);
    PyModule_AddIntConstant(m, "RSDM__JOIN_DOMAIN", 3);
    PyModule_AddIntConstant(m, "RSDM__LEAVE", 4);
    PyModule_AddIntConstant(m, "RSDM_K_SYSTEM_RSDM_ID", 1);
    PyModule_AddIntConstant(m, "RSDM_K_PROCESS_RSDM_ID", 2);
    PyModule_AddIntConstant(m, "RSDM_M_READ", 0x1L);
    PyModule_AddIntConstant(m, "RSDM_M_WRITE", 0x2L);
    PyModule_AddIntConstant(m, "RSDM_M_LOCK", 0x4L);
    PyModule_AddIntConstant(m, "RSDM_S_RSDMBITS", 4);
   return m;
}