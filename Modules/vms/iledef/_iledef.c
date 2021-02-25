#include <Python.h>

PyDoc_STRVAR(doc__iledef,
"ILE definitions");

static struct PyModuleDef _iledef_module = {
    PyModuleDef_HEAD_INIT,
    "_iledef",
    doc__iledef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__iledef(void) {
    PyObject *m = PyModule_Create(&_iledef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "ILE3_S_ILE3", 12);
    PyModule_AddIntConstant(m, "ILE3_K_LENGTH", 12);
    PyModule_AddIntConstant(m, "ILE3_C_LENGTH", 12);
    PyModule_AddIntConstant(m, "ILEB_64_S_ILEB_64", 32);
    PyModule_AddIntConstant(m, "ILEB_64_S_LENGTH", 8);
    PyModule_AddIntConstant(m, "ILEB_64_S_BUFADDR", 8);
    PyModule_AddIntConstant(m, "ILEB_64_S_RETLEN_ADDR", 8);
    PyModule_AddIntConstant(m, "ILEB_64_K_LENGTH", 32);
    PyModule_AddIntConstant(m, "ILEB_64_C_LENGTH", 32);
    PyModule_AddIntConstant(m, "ILE2_S_ILE2", 8);
    PyModule_AddIntConstant(m, "ILE2_K_LENGTH", 8);
    PyModule_AddIntConstant(m, "ILE2_C_LENGTH", 8);
    PyModule_AddIntConstant(m, "ILEA_64_S_ILEA_64", 24);
    PyModule_AddIntConstant(m, "ILEA_64_S_LENGTH", 8);
    PyModule_AddIntConstant(m, "ILEA_64_S_BUFADDR", 8);
    PyModule_AddIntConstant(m, "ILEA_64_K_LENGTH", 24);
    PyModule_AddIntConstant(m, "ILEA_64_C_LENGTH", 24);
    return m;
}