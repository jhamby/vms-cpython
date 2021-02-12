#include <Python.h>

PyDoc_STRVAR(doc__dvsdef,
"DVS definitions");

static struct PyModuleDef _dvsdef_module = {
    PyModuleDef_HEAD_INIT,
    "dvsdef",
    doc__dvsdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__dvsdef(void) {
    PyObject *m = PyModule_Create(&_dvsdef_module);
    PyModule_AddIntConstant(m, "DVS__DEVCLASS", 1);
    PyModule_AddIntConstant(m, "DVS__DEVTYPE", 2);
    return m;
}