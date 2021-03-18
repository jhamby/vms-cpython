#include <Python.h>

PyDoc_STRVAR(doc__fpdef,
"FP definitions");

static struct PyModuleDef _fpdef_module = {
    PyModuleDef_HEAD_INIT,
    "_fpdef",
    doc__fpdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__fpdef(void) {
    PyObject *m = PyModule_Create(&_fpdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "FP_K_BALANCE_PORTS", 1);
    PyModule_AddIntConstant(m, "FP_K_CPU_CONFIGURED", 2);
    PyModule_AddIntConstant(m, "FP_K_CPU_STARTING", 3);
    PyModule_AddIntConstant(m, "FP_K_CPU_STOPPING", 4);
    PyModule_AddIntConstant(m, "FP_K_CPU_STOP_FAILED", 5);
    PyModule_AddUnsignedLongConstant(m, "HWINT_M_CPU_SELECTED", 0x1UL);
    PyModule_AddUnsignedLongConstant(m, "HWINT_M_CPU_NOT_IN_RAD", 0x2UL);
    PyModule_AddUnsignedLongConstant(m, "HWINT_M_PRIMARY", 0x4UL);
    PyModule_AddIntConstant(m, "HWINT_S_HWINT_FLAGS", 8);
    PyModule_AddIntConstant(m, "FPRAD_S_FPRAD", 16);
    PyModule_AddUnsignedLongConstant(m, "FP_M_SPL_HOLD", 0x1UL);
    PyModule_AddIntConstant(m, "FP_K_LENGTH", 96);
    PyModule_AddIntConstant(m, "FP_C_LENGTH", 96);
    PyModule_AddIntConstant(m, "FP_S_FP", 96);
    PyModule_AddIntConstant(m, "FP_S_SIZE", 8);
    PyModule_AddIntConstant(m, "FP_S_USEABLE_CPUS", 8);
    PyModule_AddIntConstant(m, "FP_S_FAVORED_CPUS", 8);
    return m;
}