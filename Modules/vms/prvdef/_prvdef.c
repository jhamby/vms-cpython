#include <Python.h>

PyDoc_STRVAR(doc__prvdef,
"PRV definitions");

static struct PyModuleDef _prvdef_module = {
    PyModuleDef_HEAD_INIT,
    "_prvdef",
    doc__prvdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__prvdef(void) {
    PyObject *m = PyModule_Create(&_prvdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddUnsignedLongConstant(m, "PRV_M_CMKRNL", 0x1UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_CMEXEC", 0x2UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_SYSNAM", 0x4UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_GRPNAM", 0x8UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_ALLSPOOL", 0x10UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_IMPERSONATE", 0x20UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_DIAGNOSE", 0x40UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_LOG_IO", 0x80UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_GROUP", 0x100UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_NOACNT", 0x200UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_PRMCEB", 0x400UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_PRMMBX", 0x800UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_PSWAPM", 0x1000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_SETPRI", 0x2000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_SETPRV", 0x4000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_TMPMBX", 0x8000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_WORLD", 0x10000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_MOUNT", 0x20000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_OPER", 0x40000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_EXQUOTA", 0x80000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_NETMBX", 0x100000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_VOLPRO", 0x200000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_PHY_IO", 0x400000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_BUGCHK", 0x800000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_PRMGBL", 0x1000000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_SYSGBL", 0x2000000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_PFNMAP", 0x4000000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_SHMEM", 0x8000000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_SYSPRV", 0x10000000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_BYPASS", 0x20000000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_SYSLCK", 0x40000000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_SHARE", 0x80000000UL);
    PyModule_AddUnsignedLongLongConstant(m, "PRV_M_UPGRADE", 0x100000000UL);
    PyModule_AddUnsignedLongLongConstant(m, "PRV_M_DOWNGRADE", 0x200000000UL);
    PyModule_AddUnsignedLongLongConstant(m, "PRV_M_GRPPRV", 0x400000000UL);
    PyModule_AddUnsignedLongLongConstant(m, "PRV_M_READALL", 0x800000000UL);
    PyModule_AddUnsignedLongLongConstant(m, "PRV_M_IMPORT", 0x1000000000UL);
    PyModule_AddUnsignedLongLongConstant(m, "PRV_M_AUDIT", 0x2000000000UL);
    PyModule_AddUnsignedLongLongConstant(m, "PRV_M_SECURITY", 0x4000000000UL);
    PyModule_AddIntConstant(m, "PRV_K_NUMBER_OF_PRIVS", 39);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_ACNT", 0x200UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_ALTPRI", 0x2000UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_DETACH", 0x20UL);
    PyModule_AddIntConstant(m, "PRV_S_PRVDEF", 8);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_SORTED", 0x1UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_BRIEF", 0x2UL);
    PyModule_AddUnsignedLongConstant(m, "PRV_M_FILLED", 0x4UL);
    PyModule_AddIntConstant(m, "PRV_S_PRVDSP_BITS", 1);
    PyModule_AddIntConstant(m, "PRV_K_PRVMASK_WORKING", 0);
    PyModule_AddIntConstant(m, "PRV_K_PRVMASK_PERMANENT", 1);
    PyModule_AddIntConstant(m, "PRV_K_PRVMASK_IMAGE", 2);
    return m;
}