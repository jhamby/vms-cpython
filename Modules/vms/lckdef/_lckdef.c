#include <Python.h>

PyDoc_STRVAR(doc__lckdef,
"LCK definitions");

static struct PyModuleDef _lckdef_module = {
    PyModuleDef_HEAD_INIT,
    "_lckdef",
    doc__lckdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__lckdef(void) {
    PyObject *m = PyModule_Create(&_lckdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddUnsignedLongConstant(m, "LCK_M_VALBLK", 0x1UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_CONVERT", 0x2UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_NOQUEUE", 0x4UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_SYNCSTS", 0x8UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_SYSTEM", 0x10UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_NOQUOTA", 0x20UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_CVTSYS", 0x40UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_RECOVER", 0x80UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_PROTECT", 0x100UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_NODLCKWT", 0x200UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_NODLCKBLK", 0x400UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_EXPEDITE", 0x800UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_QUECVT", 0x1000UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_BYPASS", 0x2000UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_NOIOLOCK8", 0x4000UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_NOFORK", 0x8000UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_XVALBLK", 0x10000UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_DEQALL", 0x1UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_CANCEL", 0x2UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_INVVALBLK", 0x4UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_RESV_NOIOLOCK8", 0x4000UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_RESV_NOFORK", 0x8000UL);
    PyModule_AddUnsignedLongConstant(m, "LCK_M_RESV_XVALBLK", 0x10000UL);
    PyModule_AddIntConstant(m, "LCK_K_NLMODE", 0);
    PyModule_AddIntConstant(m, "LCK_K_CRMODE", 1);
    PyModule_AddIntConstant(m, "LCK_K_CWMODE", 2);
    PyModule_AddIntConstant(m, "LCK_K_PRMODE", 3);
    PyModule_AddIntConstant(m, "LCK_K_PWMODE", 4);
    PyModule_AddIntConstant(m, "LCK_K_EXMODE", 5);
    PyModule_AddIntConstant(m, "LCK_S_LCKDEF", 3);
    return m;
}