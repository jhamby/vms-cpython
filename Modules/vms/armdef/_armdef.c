#include <Python.h>

PyDoc_STRVAR(doc__armdef,
"ARM definitions");

static struct PyModuleDef _armdef_module = {
    PyModuleDef_HEAD_INIT,
    "_armdef",
    doc__armdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__armdef(void) {
    PyObject *m = PyModule_Create(&_armdef_module);
    PyModule_AddIntConstant(m, "ARM_M_READ", 0x1L);
    PyModule_AddIntConstant(m, "ARM_M_WRITE", 0x2L);
    PyModule_AddIntConstant(m, "ARM_M_EXECUTE", 0x4L);
    PyModule_AddIntConstant(m, "ARM_M_DELETE", 0x8L);
    PyModule_AddIntConstant(m, "ARM_M_CONTROL", 0x10L);
    PyModule_AddIntConstant(m, "ARM_M_CREATE", 0x4L);
    PyModule_AddIntConstant(m, "ARM_M_LOCK", 0x4L);
    PyModule_AddIntConstant(m, "ARM_M_PHYSICAL", 0x4L);
    PyModule_AddIntConstant(m, "ARM_M_LOGICAL", 0x8L);
    PyModule_AddIntConstant(m, "ARM_M_ASSOCIATE", 0x1L);
    PyModule_AddIntConstant(m, "ARM_M_SUBMIT", 0x2L);
    PyModule_AddIntConstant(m, "ARM_M_MANAGE", 0x4L);
    PyModule_AddIntConstant(m, "ARM_S_ARMDEF", 4);
    PyModule_AddIntConstant(m, "ARM_S_FILL", 27);
    return m;
}