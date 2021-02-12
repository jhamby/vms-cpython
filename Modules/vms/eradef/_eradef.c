#include <Python.h>

PyDoc_STRVAR(doc__eradef,
"ERA definitions");

static struct PyModuleDef _eradef_module = {
    PyModuleDef_HEAD_INIT,
    "eradef",
    doc__eradef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__eradef(void) {
    PyObject *m = PyModule_Create(&_eradef_module);
    PyModule_AddIntConstant(m, "ERA_K_LODUMMY", 0);
    PyModule_AddIntConstant(m, "ERA_K_MEMORY", 1);
    PyModule_AddIntConstant(m, "ERA_K_DISK", 2);
    PyModule_AddIntConstant(m, "ERA_K_TAPE", 3);
    PyModule_AddIntConstant(m, "ERA_K_HIDUMMY", 4);
    PyModule_AddIntConstant(m, "ERA_K_MINTYPE", 1);
    PyModule_AddIntConstant(m, "ERA_K_MAXTYPE", 3);
    return m;
}