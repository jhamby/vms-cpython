#include <Python.h>

PyDoc_STRVAR(doc__kgbdef,
"KGB definitions");

static struct PyModuleDef _kgbdef_module = {
    PyModuleDef_HEAD_INIT,
    "_kgbdef",
    doc__kgbdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__kgbdef(void) {
    PyObject *m = PyModule_Create(&_kgbdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "KGB_M_RESOURCE", 0x1L);
    PyModule_AddIntConstant(m, "KGB_M_DYNAMIC", 0x2L);
    PyModule_AddIntConstant(m, "KGB_M_NOACCESS", 0x4L);
    PyModule_AddIntConstant(m, "KGB_M_SUBSYSTEM", 0x8L);
    PyModule_AddIntConstant(m, "KGB_M_IMPERSONATE", 0x10L);
    PyModule_AddIntConstant(m, "KGB_M_HOLDER_HIDDEN", 0x20L);
    PyModule_AddIntConstant(m, "KGB_M_NAME_HIDDEN", 0x40L);
    PyModule_AddIntConstant(m, "KGB_K_HOLD_RECORD", 16);
    PyModule_AddIntConstant(m, "KGB_K_IDENT_RECORD", 48);
    PyModule_AddIntConstant(m, "KGB_K_LEVEL1", 257);
    PyModule_AddIntConstant(m, "KGB_K_MAINT_RECORD", 64);
    PyModule_AddIntConstant(m, "KGB_K_NUMBER_OF_ATTRIBUTES", 7);
    PyModule_AddIntConstant(m, "KGB_S_KGBDEF", 64);
    PyModule_AddIntConstant(m, "KGB_S_HOLDER", 8);
    PyModule_AddIntConstant(m, "KGB_S_NAME", 32);
    PyModule_AddIntConstant(m, "KGB_S_SYS_ID", 8);
    PyModule_AddIntConstant(m, "KGB_K_BATCH_ID", -2147483647);
    PyModule_AddIntConstant(m, "KGB_K_DIALUP_ID", -2147483646);
    PyModule_AddIntConstant(m, "KGB_K_INTERACTIVE_ID", -2147483645);
    PyModule_AddIntConstant(m, "KGB_K_LOCAL_ID", -2147483644);
    PyModule_AddIntConstant(m, "KGB_K_NETWORK_ID", -2147483643);
    PyModule_AddIntConstant(m, "KGB_K_REMOTE_ID", -2147483642);
    PyModule_AddIntConstant(m, "KGB_K_DECWINDOWS_ID", -2147483641);
    PyModule_AddIntConstant(m, "KGB_K_BOBUSER_ID", -2147483640);
    PyModule_AddIntConstant(m, "KGB_K_MRES_USER_ID", -2147483639);
    PyModule_AddIntConstant(m, "KGB_K_SAT_ACCESS_ID", -2147483638);
    PyModule_AddIntConstant(m, "KGB_K_LAST_ENV_ID", -2147483637);
    PyModule_AddIntConstant(m, "KGB_K_BASE_ENV_ID", -2147483647);
    PyModule_AddIntConstant(m, "KGB_K_NUMBER_OF_ENV_IDS", 10);
    PyModule_AddIntConstant(m, "KGB_K_RESTRICTED_RANGE", -2147418112);
    PyModule_AddIntConstant(m, "KGB_K_SEC_LEVEL_BASE", -2147482648);
    PyModule_AddIntConstant(m, "KGB_K_INT_LEVEL_BASE", -2147482392);
    PyModule_AddIntConstant(m, "KGB_K_SEC_CATEGORY_BASE", -2147482136);
    PyModule_AddIntConstant(m, "KGB_K_INT_CATEGORY_BASE", -2147482072);
    PyModule_AddIntConstant(m, "KGB_K_SEC_ACCESS_CLASS_BASE", -2147482648);
    PyModule_AddIntConstant(m, "KGB_K_SEC_ACCESS_CLASS_END", -2147482008);
    PyModule_AddIntConstant(m, "KGB_K_PROCESS", 0);
    PyModule_AddIntConstant(m, "KGB_K_SYSTEM", 1);
    PyModule_AddIntConstant(m, "KGB_K_EXTENDED", 2);
    PyModule_AddIntConstant(m, "KGB_K_IMAGE", 3);
    PyModule_AddIntConstant(m, "KGB_K_MAX_SEG", 4);
    PyModule_AddIntConstant(m, "KGB_K_SUBSYSTEM", 3);
    return m;
}