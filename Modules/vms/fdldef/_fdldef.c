#include <Python.h>

PyDoc_STRVAR(doc__fdldef,
"FDL definitions");

static struct PyModuleDef _fdldef_module = {
    PyModuleDef_HEAD_INIT,
    "_fdldef",
    doc__fdldef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__fdldef(void) {
    PyObject *m = PyModule_Create(&_fdldef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "FDL_C_VERSION", 2);
    PyModule_AddIntConstant(m, "FDL_K_VERSION", 2);
    PyModule_AddUnsignedLongConstant(m, "FDL_M_SIGNAL", 0x1UL);
    PyModule_AddUnsignedLongConstant(m, "FDL_M_FDL_STRING", 0x2UL);
    PyModule_AddUnsignedLongConstant(m, "FDL_M_DEFAULT_STRING", 0x4UL);
    PyModule_AddUnsignedLongConstant(m, "FDL_M_FULL_OUTPUT", 0x8UL);
    PyModule_AddUnsignedLongConstant(m, "FDL_M__CALLBACK", 0x10UL);
    PyModule_AddUnsignedLongConstant(m, "FDL_M_LONG_NAMES", 0x20UL);
    PyModule_AddIntConstant(m, "FDL_S_FDLDEF", 1);
    return m;
}