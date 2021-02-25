#include <Python.h>

PyDoc_STRVAR(doc__sdvdef,
"SDV definitions");

static struct PyModuleDef _sdvdef_module = {
    PyModuleDef_HEAD_INIT,
    "_sdvdef",
    doc__sdvdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__sdvdef(void) {
    PyObject *m = PyModule_Create(&_sdvdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "SDV__MP_SWITCH_PATH", 1);
    PyModule_AddIntConstant(m, "SDV__MP_ENABLE_PATH", 2);
    PyModule_AddIntConstant(m, "SDV__MP_DISABLE_PATH", 3);
    return m;
}