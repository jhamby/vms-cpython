#include <Python.h>

PyDoc_STRVAR(doc__prcdef,
"PRC definitions");

static struct PyModuleDef _prcdef_module = {
    PyModuleDef_HEAD_INIT,
    "_prcdef",
    doc__prcdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__prcdef(void) {
    PyObject *m = PyModule_Create(&_prcdef_module);
    PyModule_AddIntConstant(m, "PRC_M_SSRWAIT", 0x1L);
    PyModule_AddIntConstant(m, "PRC_M_SSFEXCU", 0x2L);
    PyModule_AddIntConstant(m, "PRC_M_PSWAPM", 0x4L);
    PyModule_AddIntConstant(m, "PRC_M_NOACNT", 0x8L);
    PyModule_AddIntConstant(m, "PRC_M_BATCH", 0x10L);
    PyModule_AddIntConstant(m, "PRC_M_HIBER", 0x20L);
    PyModule_AddIntConstant(m, "PRC_M_NOUAF", 0x40L);
    PyModule_AddIntConstant(m, "PRC_M_NETWRK", 0x80L);
    PyModule_AddIntConstant(m, "PRC_M_DISAWS", 0x100L);
    PyModule_AddIntConstant(m, "PRC_M_DETACH", 0x200L);
    PyModule_AddIntConstant(m, "PRC_M_INTER", 0x400L);
    PyModule_AddIntConstant(m, "PRC_M_IMGDMP", 0x800L);
    PyModule_AddIntConstant(m, "PRC_M_CLISPEC", 0x1000L);
    PyModule_AddIntConstant(m, "PRC_M_NOPASSWORD", 0x2000L);
    PyModule_AddIntConstant(m, "PRC_M_DEBUG", 0x4000L);
    PyModule_AddIntConstant(m, "PRC_M_DBGTRU", 0x8000L);
    PyModule_AddIntConstant(m, "PRC_M_SUBSYSTEM", 0x10000L);
    PyModule_AddIntConstant(m, "PRC_M_TCB", 0x20000L);
    PyModule_AddIntConstant(m, "PRC_M_NO_IMAGE_PRIVS", 0x40000L);
    PyModule_AddIntConstant(m, "PRC_M_PERM_SUBSYSTEM", 0x80000L);
    PyModule_AddIntConstant(m, "PRC_M_PARSE_EXTENDED", 0x100000L);
    PyModule_AddIntConstant(m, "PRC_M_INHERIT_PERSONA", 0x200000L);
    PyModule_AddIntConstant(m, "PRC_M_HOME_RAD", 0x400000L);
    PyModule_AddIntConstant(m, "PRC_M_CASE_SENSITIVE", 0x800000L);
    PyModule_AddIntConstant(m, "PRC_M_SPAWN_DETACHED", 0x1000000L);
    PyModule_AddIntConstant(m, "PRC_M_SSLOG_ENABLE", 0x2000000L);
    PyModule_AddIntConstant(m, "PRC_M_KT_LIMIT", 0x4000000L);
    PyModule_AddIntConstant(m, "PRC_M_LOGIN", 0x40L);
    PyModule_AddIntConstant(m, "PRC_S_PRCDEF", 4);
    PyModule_AddIntConstant(m, "PRC_M_IMPERSONATE", 512);
    PyModule_AddIntConstant(m, "PRC__LISTEND", 0);
    PyModule_AddIntConstant(m, "PRC__PGFLCHAR", 1);
    PyModule_AddIntConstant(m, "PRC__PGFLINDEX", 2);
    PyModule_AddIntConstant(m, "PRC__INPUT_ATT", 3);
    PyModule_AddIntConstant(m, "PRC__OUTPUT_ATT", 4);
    PyModule_AddIntConstant(m, "PRC__ERROR_ATT", 5);
    PyModule_AddIntConstant(m, "PRC__CLASS", 6);
    PyModule_AddIntConstant(m, "PRC__SSLOG_FLAGS", 7);
    PyModule_AddIntConstant(m, "PRC__SSLOG_BUFSIZE", 8);
    PyModule_AddIntConstant(m, "PRC__SSLOG_BUFCNT", 9);
    return m;
}