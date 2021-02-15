#include <Python.h>

PyDoc_STRVAR(doc__psldef,
"PSL definitions");

static struct PyModuleDef _psldef_module = {
    PyModuleDef_HEAD_INIT,
    "_psldef",
    doc__psldef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__psldef(void) {
    PyObject *m = PyModule_Create(&_psldef_module);
    PyModule_AddIntConstant(m, "PSL_M_PRVMOD", 0x3L);
    PyModule_AddIntConstant(m, "PSL_M_CURMOD", 0x18L);
    PyModule_AddIntConstant(m, "PSL_M_IPL", 0x1F00L);
    PyModule_AddIntConstant(m, "PSL_V_MAX_PS_REG_BIT", 13);
    PyModule_AddIntConstant(m, "PSL_C_KERNEL", 0);
    PyModule_AddIntConstant(m, "PSL_C_EXEC", 1);
    PyModule_AddIntConstant(m, "PSL_C_SUPER", 2);
    PyModule_AddIntConstant(m, "PSL_C_USER", 3);
    PyModule_AddIntConstant(m, "PSL_S_PSLDEF", 2);
    PyModule_AddIntConstant(m, "PSL_S_PRVMOD", 2);
    PyModule_AddIntConstant(m, "PSL_S_CURMOD", 2);
    PyModule_AddIntConstant(m, "PSL_S_IPL", 5);
    return m;
}