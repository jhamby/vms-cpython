#include <Python.h>

PyDoc_STRVAR(doc__fscndef,
"FSCN definitions");

static struct PyModuleDef _fscndef_module = {
    PyModuleDef_HEAD_INIT,
    "_fscndef",
    doc__fscndef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__fscndef(void) {
    PyObject *m = PyModule_Create(&_fscndef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddUnsignedLongConstant(m, "FSCN_M_NODE", 0x1UL);
    PyModule_AddUnsignedLongConstant(m, "FSCN_M_DEVICE", 0x2UL);
    PyModule_AddUnsignedLongConstant(m, "FSCN_M_ROOT", 0x4UL);
    PyModule_AddUnsignedLongConstant(m, "FSCN_M_DIRECTORY", 0x8UL);
    PyModule_AddUnsignedLongConstant(m, "FSCN_M_NAME", 0x10UL);
    PyModule_AddUnsignedLongConstant(m, "FSCN_M_TYPE", 0x20UL);
    PyModule_AddUnsignedLongConstant(m, "FSCN_M_VERSION", 0x40UL);
    PyModule_AddUnsignedLongConstant(m, "FSCN_M_NODE_PRIMARY", 0x80UL);
    PyModule_AddUnsignedLongConstant(m, "FSCN_M_NODE_ACS", 0x100UL);
    PyModule_AddUnsignedLongConstant(m, "FSCN_M_NODE_SECONDARY", 0x200UL);
    PyModule_AddIntConstant(m, "FSCN_S_FLDFLAGS", 4);
    PyModule_AddIntConstant(m, "FSCN__FILESPEC", 1);
    PyModule_AddIntConstant(m, "FSCN__NODE", 2);
    PyModule_AddIntConstant(m, "FSCN__DEVICE", 3);
    PyModule_AddIntConstant(m, "FSCN__ROOT", 4);
    PyModule_AddIntConstant(m, "FSCN__DIRECTORY", 5);
    PyModule_AddIntConstant(m, "FSCN__NAME", 6);
    PyModule_AddIntConstant(m, "FSCN__TYPE", 7);
    PyModule_AddIntConstant(m, "FSCN__VERSION", 8);
    PyModule_AddIntConstant(m, "FSCN__NODE_PRIMARY", 9);
    PyModule_AddIntConstant(m, "FSCN__NODE_ACS", 10);
    PyModule_AddIntConstant(m, "FSCN__NODE_SECONDARY", 11);
    PyModule_AddIntConstant(m, "FSCN_S_ITEM_LEN", 8);
    PyModule_AddIntConstant(m, "FSCN_S_FSCNDEF", 8);
    return m;
}