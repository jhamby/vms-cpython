#include <Python.h>

PyDoc_STRVAR(doc__dpsdef,
"DPS definitions");

static struct PyModuleDef _dpsdef_module = {
    PyModuleDef_HEAD_INIT,
    "_dpsdef",
    doc__dpsdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__dpsdef(void) {
    PyObject *m = PyModule_Create(&_dpsdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "DPS__MP_PATHNAME", 1);
    return m;
}