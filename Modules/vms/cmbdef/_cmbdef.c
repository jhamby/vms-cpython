#include <Python.h>

PyDoc_STRVAR(doc__cmbdef,
"CMB definitions");

static struct PyModuleDef _cmbdef_module = {
    PyModuleDef_HEAD_INIT,
    "_cmbdef",
    doc__cmbdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__cmbdef(void) {
    PyObject *m = PyModule_Create(&_cmbdef_module);
    PyModule_AddIntConstant(m, "CMB_M_READONLY",  0x1L);
    PyModule_AddIntConstant(m, "CMB_M_WRITEONLY",  0x2L);
    PyModule_AddIntConstant(m, "CMB_S_CMBDEF",  4);
    return m;
}