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
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddUnsignedLongConstant(m, "DMT_M_NOUNLOAD", 0x1UL);
    PyModule_AddUnsignedLongConstant(m, "DMT_M_UNIT", 0x2UL);
    PyModule_AddUnsignedLongConstant(m, "DMT_M_ABORT", 0x4UL);
    PyModule_AddUnsignedLongConstant(m, "DMT_M_CLUSTER", 0x8UL);
    PyModule_AddUnsignedLongConstant(m, "DMT_M_UNLOAD", 0x10UL);
    PyModule_AddUnsignedLongConstant(m, "DMT_M_OVR_CHECKS", 0x20UL);
    PyModule_AddUnsignedLongConstant(m, "DMT_M_CHECK_ONLY", 0x40UL);
    PyModule_AddUnsignedLongConstant(m, "DMT_M_REMOTE", 0x80UL);
    PyModule_AddUnsignedLongConstant(m, "DMT_M_MINICOPY_REQUIRED", 0x100UL);
    PyModule_AddUnsignedLongConstant(m, "DMT_M_MINICOPY_OPTIONAL", 0x200UL);
    PyModule_AddUnsignedLongConstant(m, "DMT_M_FORCE", 0x400UL);
    PyModule_AddIntConstant(m, "DMT_S_DMTDEF", 2);
    return m;
}