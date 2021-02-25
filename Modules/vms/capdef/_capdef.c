#include <Python.h>

PyDoc_STRVAR(doc__capdef,
"CAP definitions");

static struct PyModuleDef _capdef_module = {
    PyModuleDef_HEAD_INIT,
    "_capdef",
    doc__capdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__capdef(void) {
    PyObject *m = PyModule_Create(&_capdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "CAP_K_ALL_USER", -1);
    PyModule_AddIntConstant(m, "CAP_K_ALL_USER_ADD", -1);
    PyModule_AddIntConstant(m, "CAP_K_ALL_CPU_ADD", -1);
    PyModule_AddIntConstant(m, "CAP_K_ALL_ACTIVE_CPUS", -1);
    PyModule_AddIntConstant(m, "CAP_K_ALL_USER_REMOVE", 0);
    PyModule_AddIntConstant(m, "CAP_K_ALL_CPU_REMOVE", 0);
    PyModule_AddIntConstant(m, "CAP_K_GET_FREE_CAP", 0);
    PyModule_AddIntConstant(m, "CAP_M_USER1", 0x1L);
    PyModule_AddIntConstant(m, "CAP_M_USER2", 0x2L);
    PyModule_AddIntConstant(m, "CAP_M_USER3", 0x4L);
    PyModule_AddIntConstant(m, "CAP_M_USER4", 0x8L);
    PyModule_AddIntConstant(m, "CAP_M_USER5", 0x10L);
    PyModule_AddIntConstant(m, "CAP_M_USER6", 0x20L);
    PyModule_AddIntConstant(m, "CAP_M_USER7", 0x40L);
    PyModule_AddIntConstant(m, "CAP_M_USER8", 0x80L);
    PyModule_AddIntConstant(m, "CAP_M_USER9", 0x100L);
    PyModule_AddIntConstant(m, "CAP_M_USER10", 0x200L);
    PyModule_AddIntConstant(m, "CAP_M_USER11", 0x400L);
    PyModule_AddIntConstant(m, "CAP_M_USER12", 0x800L);
    PyModule_AddIntConstant(m, "CAP_M_USER13", 0x1000L);
    PyModule_AddIntConstant(m, "CAP_M_USER14", 0x2000L);
    PyModule_AddIntConstant(m, "CAP_M_USER15", 0x4000L);
    PyModule_AddIntConstant(m, "CAP_M_USER16", 0x8000L);
    PyModule_AddIntConstant(m, "CAP_S_CAP", 4);
    PyModule_AddIntConstant(m, "CAP_M_CPU0", 0x1L);
    PyModule_AddIntConstant(m, "CAP_M_CPU1", 0x2L);
    PyModule_AddIntConstant(m, "CAP_M_CPU2", 0x4L);
    PyModule_AddIntConstant(m, "CAP_M_CPU3", 0x8L);
    PyModule_AddIntConstant(m, "CAP_M_CPU4", 0x10L);
    PyModule_AddIntConstant(m, "CAP_M_CPU5", 0x20L);
    PyModule_AddIntConstant(m, "CAP_M_CPU6", 0x40L);
    PyModule_AddIntConstant(m, "CAP_M_CPU7", 0x80L);
    PyModule_AddIntConstant(m, "CAP_M_CPU8", 0x100L);
    PyModule_AddIntConstant(m, "CAP_M_CPU9", 0x200L);
    PyModule_AddIntConstant(m, "CAP_M_CPU10", 0x400L);
    PyModule_AddIntConstant(m, "CAP_M_CPU11", 0x800L);
    PyModule_AddIntConstant(m, "CAP_M_CPU12", 0x1000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU13", 0x2000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU14", 0x4000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU15", 0x8000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU16", 0x10000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU17", 0x20000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU18", 0x40000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU19", 0x80000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU20", 0x100000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU21", 0x200000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU22", 0x400000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU23", 0x800000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU24", 0x1000000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU25", 0x2000000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU26", 0x4000000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU27", 0x8000000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU28", 0x10000000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU29", 0x20000000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU30", 0x40000000L);
    PyModule_AddIntConstant(m, "CAP_M_CPU31", 0x80000000L);
    PyModule_AddIntConstant(m, "CAP_S_CAP_CPUS", 4);
    PyModule_AddIntConstant(m, "CAP_M_IMPLICIT_AFFINITY_CLEAR", 0x1L);
    PyModule_AddIntConstant(m, "CAP_M_IMPLICIT_AFFINITY_SET", 0x2L);
    PyModule_AddIntConstant(m, "CAP_M_IMPLICIT_DEFAULT_ONLY", 0x4L);
    PyModule_AddIntConstant(m, "CAP_M_IMPLICIT_ALL_THREADS", 0x8L);
    PyModule_AddIntConstant(m, "CAP_S_IMP_FLAGS", 1);
    PyModule_AddIntConstant(m, "CAP_M_FLAG_CHECK_CPU", 0x1L);
    PyModule_AddIntConstant(m, "CAP_M_FLAG_PERMANENT", 0x2L);
    PyModule_AddIntConstant(m, "CAP_M_FLAG_CHECK_CPU_ACTIVE", 0x8L);
    PyModule_AddIntConstant(m, "CAP_M_FLAG_DEFAULT_ONLY", 0x10L);
    PyModule_AddIntConstant(m, "CAP_M_ALL_THREADS", 0x20L);
    PyModule_AddIntConstant(m, "CAP_M_PURGE_WS_IF_NEW_RAD", 0x40L);
    PyModule_AddIntConstant(m, "CAP_S_CAP_FLAGS", 1);
    return m;
}