#include <Python.h>

PyDoc_STRVAR(doc__pscandef,
"PSCAN definitions");

static struct PyModuleDef _pscandef_module = {
    PyModuleDef_HEAD_INIT,
    "_pscandef",
    doc__pscandef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__pscandef(void) {
    PyObject *m = PyModule_Create(&_pscandef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "PSCAN__BEGIN", 0);
    PyModule_AddIntConstant(m, "PSCAN__ACCOUNT", 1);
    PyModule_AddIntConstant(m, "PSCAN__AUTHPRI", 2);
    PyModule_AddIntConstant(m, "PSCAN__CURPRIV", 3);
    PyModule_AddIntConstant(m, "PSCAN__GRP", 4);
    PyModule_AddIntConstant(m, "PSCAN__HW_MODEL", 5);
    PyModule_AddIntConstant(m, "PSCAN__HW_NAME", 6);
    PyModule_AddIntConstant(m, "PSCAN__JOBPRCCNT", 7);
    PyModule_AddIntConstant(m, "PSCAN__JOBTYPE", 8);
    PyModule_AddIntConstant(m, "PSCAN__MASTER_PID", 9);
    PyModule_AddIntConstant(m, "PSCAN__MEM", 10);
    PyModule_AddIntConstant(m, "PSCAN__MODE", 11);
    PyModule_AddIntConstant(m, "PSCAN__NODE_CSID", 12);
    PyModule_AddIntConstant(m, "PSCAN__NODENAME", 13);
    PyModule_AddIntConstant(m, "PSCAN__OWNER", 14);
    PyModule_AddIntConstant(m, "PSCAN__PRCCNT", 15);
    PyModule_AddIntConstant(m, "PSCAN__PRCNAM", 16);
    PyModule_AddIntConstant(m, "PSCAN__PRI", 17);
    PyModule_AddIntConstant(m, "PSCAN__PRIB", 18);
    PyModule_AddIntConstant(m, "PSCAN__STATE", 19);
    PyModule_AddIntConstant(m, "PSCAN__STS", 20);
    PyModule_AddIntConstant(m, "PSCAN__TERMINAL", 21);
    PyModule_AddIntConstant(m, "PSCAN__UIC", 22);
    PyModule_AddIntConstant(m, "PSCAN__USERNAME", 23);
    PyModule_AddIntConstant(m, "PSCAN__GETJPI_BUFFER_SIZE", 24);
    PyModule_AddIntConstant(m, "PSCAN__PSCAN_CONTROL_FLAGS", 25);
    PyModule_AddIntConstant(m, "PSCAN__KT_COUNT", 26);
    PyModule_AddIntConstant(m, "PSCAN__MULTITHREAD", 27);
    PyModule_AddIntConstant(m, "PSCAN__SCHED_CLASS_NAME", 28);
    PyModule_AddIntConstant(m, "PSCAN__END", 29);
    PyModule_AddIntConstant(m, "PSCAN_K_TYPE", 129);
    PyModule_AddIntConstant(m, "PSCAN_M_THREAD", 0x1L);
    PyModule_AddIntConstant(m, "PSCAN_S_PSCANCTLDEF", 4);
    PyModule_AddIntConstant(m, "PSCAN_M_OR", 0x1L);
    PyModule_AddIntConstant(m, "PSCAN_M_BIT_ALL", 0x2L);
    PyModule_AddIntConstant(m, "PSCAN_M_BIT_ANY", 0x4L);
    PyModule_AddIntConstant(m, "PSCAN_M_GEQ", 0x8L);
    PyModule_AddIntConstant(m, "PSCAN_M_GTR", 0x10L);
    PyModule_AddIntConstant(m, "PSCAN_M_LEQ", 0x20L);
    PyModule_AddIntConstant(m, "PSCAN_M_LSS", 0x40L);
    PyModule_AddIntConstant(m, "PSCAN_M_PREFIX_MATCH", 0x80L);
    PyModule_AddIntConstant(m, "PSCAN_M_WILDCARD", 0x100L);
    PyModule_AddIntConstant(m, "PSCAN_M_CASE_BLIND", 0x200L);
    PyModule_AddIntConstant(m, "PSCAN_M_EQL", 0x400L);
    PyModule_AddIntConstant(m, "PSCAN_M_NEQ", 0x800L);
    PyModule_AddIntConstant(m, "PSCAN_S_ITEM_SPECIFIC_FLAGS", 2);
    return m;
}