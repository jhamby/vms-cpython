#include <Python.h>

PyDoc_STRVAR(doc__efndef,
"EFN definitions");

static struct PyModuleDef _efndef_module = {
    PyModuleDef_HEAD_INIT,
    "efndef",
    doc__efndef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__efndef(void) {
    PyObject *m = PyModule_Create(&_efndef_module);
    PyModule_AddIntConstant(m, "EFN_C_ENF", 128);
    PyModule_AddIntConstant(m, "EFN_C_CTX", 129);
    return m;
}