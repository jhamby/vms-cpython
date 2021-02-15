#include <Python.h>

PyDoc_STRVAR(doc__cvtfnmdef,
"CVTFNM definitions");

static struct PyModuleDef _cvtfnmdef_module = {
    PyModuleDef_HEAD_INIT,
    "_cvtfnmdef",
    doc__cvtfnmdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__cvtfnmdef(void) {
    PyObject *m = PyModule_Create(&_cvtfnmdef_module);
    PyModule_AddIntConstant(m, "CVTFNM_M_WORD_CHARS",  0x1L);
    PyModule_AddIntConstant(m, "CVTFNM_M_NO_DELIMITERS",  0x2L);
    PyModule_AddIntConstant(m, "CVTFNM_M_FORCE_UPCASE",  0x4L);
    PyModule_AddIntConstant(m, "CVTFNM_S_INOUTFLAGS",  4);
    PyModule_AddIntConstant(m, "CVTFNM_C_RMS_TO_ACPQIO",  1);
    PyModule_AddIntConstant(m, "CVTFNM_C_ACPQIO_TO_RMS",  2);
    PyModule_AddIntConstant(m, "CVTFNM_K_RMS_TO_ACPQIO",  1);
    PyModule_AddIntConstant(m, "CVTFNM_K_ACPQIO_TO_RMS",  2);
    return m;
}