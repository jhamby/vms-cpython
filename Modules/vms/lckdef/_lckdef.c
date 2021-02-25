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
    PyModule_AddIntConstant(m, "LCK_M_VALBLK", 0x1L);
    PyModule_AddIntConstant(m, "LCK_M_CONVERT", 0x2L);
    PyModule_AddIntConstant(m, "LCK_M_NOQUEUE", 0x4L);
    PyModule_AddIntConstant(m, "LCK_M_SYNCSTS", 0x8L);
    PyModule_AddIntConstant(m, "LCK_M_SYSTEM", 0x10L);
    PyModule_AddIntConstant(m, "LCK_M_NOQUOTA", 0x20L);
    PyModule_AddIntConstant(m, "LCK_M_CVTSYS", 0x40L);
    PyModule_AddIntConstant(m, "LCK_M_RECOVER", 0x80L);
    PyModule_AddIntConstant(m, "LCK_M_PROTECT", 0x100L);
    PyModule_AddIntConstant(m, "LCK_M_NODLCKWT", 0x200L);
    PyModule_AddIntConstant(m, "LCK_M_NODLCKBLK", 0x400L);
    PyModule_AddIntConstant(m, "LCK_M_EXPEDITE", 0x800L);
    PyModule_AddIntConstant(m, "LCK_M_QUECVT", 0x1000L);
    PyModule_AddIntConstant(m, "LCK_M_BYPASS", 0x2000L);
    PyModule_AddIntConstant(m, "LCK_M_NOIOLOCK8", 0x4000L);
    PyModule_AddIntConstant(m, "LCK_M_NOFORK", 0x8000L);
    PyModule_AddIntConstant(m, "LCK_M_XVALBLK", 0x10000L);
    PyModule_AddIntConstant(m, "LCK_M_DEQALL", 0x1L);
    PyModule_AddIntConstant(m, "LCK_M_CANCEL", 0x2L);
    PyModule_AddIntConstant(m, "LCK_M_INVVALBLK", 0x4L);
    PyModule_AddIntConstant(m, "LCK_M_RESV_NOIOLOCK8", 0x4000L);
    PyModule_AddIntConstant(m, "LCK_M_RESV_NOFORK", 0x8000L);
    PyModule_AddIntConstant(m, "LCK_M_RESV_XVALBLK", 0x10000L);
    PyModule_AddIntConstant(m, "LCK_K_NLMODE", 0);
    PyModule_AddIntConstant(m, "LCK_K_CRMODE", 1);
    PyModule_AddIntConstant(m, "LCK_K_CWMODE", 2);
    PyModule_AddIntConstant(m, "LCK_K_PRMODE", 3);
    PyModule_AddIntConstant(m, "LCK_K_PWMODE", 4);
    PyModule_AddIntConstant(m, "LCK_K_EXMODE", 5);
    PyModule_AddIntConstant(m, "LCK_S_LCKDEF", 3);
    return m;
}