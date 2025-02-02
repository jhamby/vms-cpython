#include <Python.h>

PyDoc_STRVAR(doc__libfisdef,
"LIBFIS definitions");

static struct PyModuleDef _libfisdef_module = {
    PyModuleDef_HEAD_INIT,
    "_libfisdef",
    doc__libfisdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__libfisdef(void) {
    PyObject *m = PyModule_Create(&_libfisdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddUnsignedLongConstant(m, "LIB_M_FIS_PARANOID", 0x1UL);
    PyModule_AddUnsignedLongConstant(m, "LIB_M_FIS_NOTRANSLOG", 0x8UL);
    PyModule_AddUnsignedLongConstant(m, "LIB_M_FIS_MIXEDCASE", 0x10UL);
    PyModule_AddUnsignedLongConstant(m, "LIB_M_FIS_TV_AV", 0x20UL);
    PyModule_AddIntConstant(m, "LIB_S_LIB_FIS_FLAGS", 1);
    return m;
}