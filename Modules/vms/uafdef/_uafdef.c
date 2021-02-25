#include <Python.h>

PyDoc_STRVAR(doc__uafdef,
"UAF definitions");

static struct PyModuleDef _uafdef_module = {
    PyModuleDef_HEAD_INIT,
    "_uafdef",
    doc__uafdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__uafdef(void) {
    PyObject *m = PyModule_Create(&_uafdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "UAF_C_USER_ID", 1);
    PyModule_AddIntConstant(m, "UAF_C_VERSION1", 1);
    PyModule_AddIntConstant(m, "UAF_C_KEYED_PART", 52);
    PyModule_AddIntConstant(m, "UAF_C_MAX_PWD_LENGTH", 32);
    PyModule_AddIntConstant(m, "UAF_K_MAX_PWD_LENGTH", 32);
    PyModule_AddIntConstant(m, "UAF_C_AD_II", 0);
    PyModule_AddIntConstant(m, "UAF_C_PURDY", 1);
    PyModule_AddIntConstant(m, "UAF_C_PURDY_V", 2);
    PyModule_AddIntConstant(m, "UAF_C_PURDY_S", 3);
    PyModule_AddIntConstant(m, "UAF_K_CURRENT_ALGORITHM", 3);
    PyModule_AddIntConstant(m, "UAF_C_CURRENT_ALGORITHM", 3);
    PyModule_AddIntConstant(m, "UAF_C_PREFERED_ALGORITHM", 127);
    PyModule_AddIntConstant(m, "UAF_K_PREFERED_ALGORITHM", 127);
    PyModule_AddIntConstant(m, "UAF_C_PREFERRED_ALGORITHM", 127);
    PyModule_AddIntConstant(m, "UAF_K_PREFERRED_ALGORITHM", 127);
    PyModule_AddIntConstant(m, "UAF_C_CUST_ALGORITHM", 128);
    PyModule_AddIntConstant(m, "UAF_K_CUST_ALGORITHM", 128);
    PyModule_AddIntConstant(m, "UAF_K_FIXED", 644);
    PyModule_AddIntConstant(m, "UAF_C_FIXED", 644);
    PyModule_AddIntConstant(m, "UAF_K_LENGTH", 1412);
    PyModule_AddIntConstant(m, "UAF_C_LENGTH", 1412);
    PyModule_AddIntConstant(m, "UAF_S_UAFDEF", 1412);
    PyModule_AddIntConstant(m, "UAF_S_UAF", 1412);
    PyModule_AddIntConstant(m, "UAF_S_USERNAME", 32);
    PyModule_AddIntConstant(m, "UAF_S_PARENT_ID", 8);
    PyModule_AddIntConstant(m, "UAF_S_ACCOUNT", 32);
    PyModule_AddIntConstant(m, "UAF_S_OWNER", 32);
    PyModule_AddIntConstant(m, "UAF_S_DEFDEV", 32);
    PyModule_AddIntConstant(m, "UAF_S_DEFDIR", 64);
    PyModule_AddIntConstant(m, "UAF_S_LGICMD", 64);
    PyModule_AddIntConstant(m, "UAF_S_DEFCLI", 32);
    PyModule_AddIntConstant(m, "UAF_S_CLITABLES", 32);
    PyModule_AddIntConstant(m, "UAF_S_PWD", 8);
    PyModule_AddIntConstant(m, "UAF_S_PWD2", 8);
    PyModule_AddIntConstant(m, "UAF_S_EXPIRATION", 8);
    PyModule_AddIntConstant(m, "UAF_S_PWD_LIFETIME", 8);
    PyModule_AddIntConstant(m, "UAF_S_PWD_DATE", 8);
    PyModule_AddIntConstant(m, "UAF_S_PWD2_DATE", 8);
    PyModule_AddIntConstant(m, "UAF_S_LASTLOGIN_I", 8);
    PyModule_AddIntConstant(m, "UAF_S_LASTLOGIN_N", 8);
    PyModule_AddIntConstant(m, "UAF_S_PRIV", 8);
    PyModule_AddIntConstant(m, "UAF_S_DEF_PRIV", 8);
    PyModule_AddIntConstant(m, "UAF_S_MIN_CLASS", 20);
    PyModule_AddIntConstant(m, "UAF_S_MAX_CLASS", 20);
    PyModule_AddIntConstant(m, "UAF_S_NETWORK_ACCESS_P", 3);
    PyModule_AddIntConstant(m, "UAF_S_NETWORK_ACCESS_S", 3);
    PyModule_AddIntConstant(m, "UAF_S_BATCH_ACCESS_P", 3);
    PyModule_AddIntConstant(m, "UAF_S_BATCH_ACCESS_S", 3);
    PyModule_AddIntConstant(m, "UAF_S_LOCAL_ACCESS_P", 3);
    PyModule_AddIntConstant(m, "UAF_S_LOCAL_ACCESS_S", 3);
    PyModule_AddIntConstant(m, "UAF_S_DIALUP_ACCESS_P", 3);
    PyModule_AddIntConstant(m, "UAF_S_DIALUP_ACCESS_S", 3);
    PyModule_AddIntConstant(m, "UAF_S_REMOTE_ACCESS_P", 3);
    PyModule_AddIntConstant(m, "UAF_S_REMOTE_ACCESS_S", 3);
    PyModule_AddIntConstant(m, "UAF_S_DEF_CLASS", 20);
    return m;
}