#include <Python.h>

PyDoc_STRVAR(doc__dmtdef,
"DMT definitions");

static struct PyModuleDef _dmtdef_module = {
    PyModuleDef_HEAD_INIT,
    "_dmtdef",
    doc__dmtdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__dmtdef(void) {
    PyObject *m = PyModule_Create(&_dmtdef_module);
    PyModule_AddIntConstant(m, "DMT_M_NOUNLOAD", 0x1L);
    PyModule_AddIntConstant(m, "DMT_M_UNIT", 0x2L);
    PyModule_AddIntConstant(m, "DMT_M_ABORT", 0x4L);
    PyModule_AddIntConstant(m, "DMT_M_CLUSTER", 0x8L);
    PyModule_AddIntConstant(m, "DMT_M_UNLOAD", 0x10L);
    PyModule_AddIntConstant(m, "DMT_M_OVR_CHECKS", 0x20L);
    PyModule_AddIntConstant(m, "DMT_M_CHECK_ONLY", 0x40L);
    PyModule_AddIntConstant(m, "DMT_M_REMOTE", 0x80L);
    PyModule_AddIntConstant(m, "DMT_M_MINICOPY_REQUIRED", 0x100L);
    PyModule_AddIntConstant(m, "DMT_M_MINICOPY_OPTIONAL", 0x200L);
    PyModule_AddIntConstant(m, "DMT_M_FORCE", 0x400L);
    PyModule_AddIntConstant(m, "DMT_S_DMTDEF", 2);
    return m;
}