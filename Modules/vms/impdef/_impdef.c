#include <Python.h>

PyDoc_STRVAR(doc__impdef,
"IMP definitions");

static struct PyModuleDef _impdef_module = {
    PyModuleDef_HEAD_INIT,
    "_impdef",
    doc__impdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__impdef(void) {
    PyObject *m = PyModule_Create(&_impdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "IMP_C_ASYEFN", 30);
    PyModule_AddIntConstant(m, "IMP_C_IOREFN", 30);
    PyModule_AddIntConstant(m, "IMP_C_ASYQIOEFN", 31);
    PyModule_AddIntConstant(m, "IMP_C_SYNCEFN", 27);
    PyModule_AddIntConstant(m, "IMP_C_MBXEFN", 26);
    PyModule_AddIntConstant(m, "IMP_C_NPIOFILES", 63);
    PyModule_AddIntConstant(m, "IMP_C_ENTPERSEG", 15);
    PyModule_AddIntConstant(m, "IMP_S_IMPDEF", 112);
    PyModule_AddIntConstant(m, "IMP_S_IMP", 112);
    PyModule_AddIntConstant(m, "IMP_S_FREEPGLH", 8);
    PyModule_AddIntConstant(m, "IMP_S_ASB_LOOKASIDE_LIST", 8);
    return m;
}