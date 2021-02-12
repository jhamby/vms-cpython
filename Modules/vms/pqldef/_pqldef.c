#include <Python.h>

PyDoc_STRVAR(doc__pqldef,
"PQL definitions");

static struct PyModuleDef _pqldef_module = {
    PyModuleDef_HEAD_INIT,
    "pqldef",
    doc__pqldef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__pqldef(void) {
    PyObject *m = PyModule_Create(&_pqldef_module);
    PyModule_AddIntConstant(m, "PQL__LISTEND", 0);
    PyModule_AddIntConstant(m, "PQL__ASTLM", 1);
    PyModule_AddIntConstant(m, "PQL__BIOLM", 2);
    PyModule_AddIntConstant(m, "PQL__BYTLM", 3);
    PyModule_AddIntConstant(m, "PQL__CPULM", 4);
    PyModule_AddIntConstant(m, "PQL__DIOLM", 5);
    PyModule_AddIntConstant(m, "PQL__FILLM", 6);
    PyModule_AddIntConstant(m, "PQL__PGFLQUOTA", 7);
    PyModule_AddIntConstant(m, "PQL__PRCLM", 8);
    PyModule_AddIntConstant(m, "PQL__TQELM", 9);
    PyModule_AddIntConstant(m, "PQL__WSQUOTA", 10);
    PyModule_AddIntConstant(m, "PQL__WSDEFAULT", 11);
    PyModule_AddIntConstant(m, "PQL__ENQLM", 12);
    PyModule_AddIntConstant(m, "PQL__WSEXTENT", 13);
    PyModule_AddIntConstant(m, "PQL__JTQUOTA", 14);
    PyModule_AddIntConstant(m, "PQL__LENGTH", 15);
    return m;
}