#include <Python.h>

PyDoc_STRVAR(doc__uaidef,
"UAI definitions");

static struct PyModuleDef _uaidef_module = {
    PyModuleDef_HEAD_INIT,
    "_uaidef",
    doc__uaidef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__uaidef(void) {
    PyObject *m = PyModule_Create(&_uaidef_module);
    PyModule_AddIntConstant(m, "UAI__RTYPE", 1);
    PyModule_AddIntConstant(m, "UAI__VERSION", 2);
    PyModule_AddIntConstant(m, "UAI__USRDATOFF", 3);
    PyModule_AddIntConstant(m, "UAI__USERNAME", 4);
    PyModule_AddIntConstant(m, "UAI__USERNAME_TAG", 5);
    PyModule_AddIntConstant(m, "UAI__UIC", 6);
    PyModule_AddIntConstant(m, "UAI__MEM", 7);
    PyModule_AddIntConstant(m, "UAI__GRP", 8);
    PyModule_AddIntConstant(m, "UAI__SUB_ID", 9);
    PyModule_AddIntConstant(m, "UAI__PARENT_ID", 10);
    PyModule_AddIntConstant(m, "UAI__ACCOUNT", 11);
    PyModule_AddIntConstant(m, "UAI__OWNER", 12);
    PyModule_AddIntConstant(m, "UAI__DEFDEV", 13);
    PyModule_AddIntConstant(m, "UAI__DEFDIR", 14);
    PyModule_AddIntConstant(m, "UAI__LGICMD", 15);
    PyModule_AddIntConstant(m, "UAI__DEFCLI", 16);
    PyModule_AddIntConstant(m, "UAI__CLITABLES", 17);
    PyModule_AddIntConstant(m, "UAI__PWD", 18);
    PyModule_AddIntConstant(m, "UAI__PWD2", 19);
    PyModule_AddIntConstant(m, "UAI__LOGFAILS", 20);
    PyModule_AddIntConstant(m, "UAI__SALT", 21);
    PyModule_AddIntConstant(m, "UAI__ENCRYPT", 22);
    PyModule_AddIntConstant(m, "UAI__ENCRYPT2", 23);
    PyModule_AddIntConstant(m, "UAI__PWD_LENGTH", 24);
    PyModule_AddIntConstant(m, "UAI__EXPIRATION", 25);
    PyModule_AddIntConstant(m, "UAI__PWD_LIFETIME", 26);
    PyModule_AddIntConstant(m, "UAI__PWD_DATE", 27);
    PyModule_AddIntConstant(m, "UAI__PWD2_DATE", 28);
    PyModule_AddIntConstant(m, "UAI__LASTLOGIN_I", 29);
    PyModule_AddIntConstant(m, "UAI__LASTLOGIN_N", 30);
    PyModule_AddIntConstant(m, "UAI__PRIV", 31);
    PyModule_AddIntConstant(m, "UAI__DEF_PRIV", 32);
    PyModule_AddIntConstant(m, "UAI__MIN_CLASS", 33);
    PyModule_AddIntConstant(m, "UAI__MAX_CLASS", 34);
    PyModule_AddIntConstant(m, "UAI__FLAGS", 35);
    PyModule_AddIntConstant(m, "UAI__NETWORK_ACCESS_P", 36);
    PyModule_AddIntConstant(m, "UAI__NETWORK_ACCESS_S", 37);
    PyModule_AddIntConstant(m, "UAI__BATCH_ACCESS_P", 38);
    PyModule_AddIntConstant(m, "UAI__BATCH_ACCESS_S", 39);
    PyModule_AddIntConstant(m, "UAI__LOCAL_ACCESS_P", 40);
    PyModule_AddIntConstant(m, "UAI__LOCAL_ACCESS_S", 41);
    PyModule_AddIntConstant(m, "UAI__DIALUP_ACCESS_P", 42);
    PyModule_AddIntConstant(m, "UAI__DIALUP_ACCESS_S", 43);
    PyModule_AddIntConstant(m, "UAI__REMOTE_ACCESS_P", 44);
    PyModule_AddIntConstant(m, "UAI__REMOTE_ACCESS_S", 45);
    PyModule_AddIntConstant(m, "UAI__PRIMEDAYS", 46);
    PyModule_AddIntConstant(m, "UAI__PRI", 47);
    PyModule_AddIntConstant(m, "UAI__QUEPRI", 48);
    PyModule_AddIntConstant(m, "UAI__MAXJOBS", 49);
    PyModule_AddIntConstant(m, "UAI__MAXACCTJOBS", 50);
    PyModule_AddIntConstant(m, "UAI__MAXDETACH", 51);
    PyModule_AddIntConstant(m, "UAI__PRCCNT", 52);
    PyModule_AddIntConstant(m, "UAI__BIOLM", 53);
    PyModule_AddIntConstant(m, "UAI__DIOLM", 54);
    PyModule_AddIntConstant(m, "UAI__TQCNT", 55);
    PyModule_AddIntConstant(m, "UAI__ASTLM", 56);
    PyModule_AddIntConstant(m, "UAI__ENQLM", 57);
    PyModule_AddIntConstant(m, "UAI__FILLM", 58);
    PyModule_AddIntConstant(m, "UAI__SHRFILLM", 59);
    PyModule_AddIntConstant(m, "UAI__WSQUOTA", 60);
    PyModule_AddIntConstant(m, "UAI__DFWSCNT", 61);
    PyModule_AddIntConstant(m, "UAI__WSEXTENT", 62);
    PyModule_AddIntConstant(m, "UAI__PGFLQUOTA", 63);
    PyModule_AddIntConstant(m, "UAI__CPUTIM", 64);
    PyModule_AddIntConstant(m, "UAI__BYTLM", 65);
    PyModule_AddIntConstant(m, "UAI__PBYTLM", 66);
    PyModule_AddIntConstant(m, "UAI__JTQUOTA", 67);
    PyModule_AddIntConstant(m, "UAI__PROXY_LIM", 68);
    PyModule_AddIntConstant(m, "UAI__PROXIES", 69);
    PyModule_AddIntConstant(m, "UAI__ACCOUNT_LIM", 70);
    PyModule_AddIntConstant(m, "UAI__ACCOUNTS", 71);
    PyModule_AddIntConstant(m, "UAI__USER_DATA", 72);
    PyModule_AddIntConstant(m, "UAI__PASSWORD", 73);
    PyModule_AddIntConstant(m, "UAI__PASSWORD2", 74);
    PyModule_AddIntConstant(m, "UAI__DEF_CLASS", 75);
    PyModule_AddIntConstant(m, "UAI__AUDIT_FLAGS", 76);
    PyModule_AddIntConstant(m, "UAI__MAX_ITEM_CODE", 77);
    PyModule_AddIntConstant(m, "UAI__DEFCHARGE_CODE", 11);
    PyModule_AddIntConstant(m, "UAI_C_AD_II", 0);
    PyModule_AddIntConstant(m, "UAI_C_PURDY", 1);
    PyModule_AddIntConstant(m, "UAI_C_PURDY_V", 2);
    PyModule_AddIntConstant(m, "UAI_C_PURDY_S", 3);
    PyModule_AddIntConstant(m, "UAI_C_PREFERED_ALGORITHM", 127);
    PyModule_AddIntConstant(m, "UAI_C_PREFERRED_ALGORITHM", 127);
    PyModule_AddIntConstant(m, "UAI_C_CUST_ALGORITHM", 128);
    PyModule_AddIntConstant(m, "UAI_C_MAX_PWD_LENGTH", 32);
    PyModule_AddIntConstant(m, "UAI_M_DISCTLY", 0x1L);
    PyModule_AddIntConstant(m, "UAI_M_DEFCLI", 0x2L);
    PyModule_AddIntConstant(m, "UAI_M_LOCKPWD", 0x4L);
    PyModule_AddIntConstant(m, "UAI_M_RESTRICTED", 0x8L);
    PyModule_AddIntConstant(m, "UAI_M_DISACNT", 0x10L);
    PyModule_AddIntConstant(m, "UAI_M_DISWELCOM", 0x20L);
    PyModule_AddIntConstant(m, "UAI_M_DISMAIL", 0x40L);
    PyModule_AddIntConstant(m, "UAI_M_NOMAIL", 0x80L);
    PyModule_AddIntConstant(m, "UAI_M_GENPWD", 0x100L);
    PyModule_AddIntConstant(m, "UAI_M_PWD_EXPIRED", 0x200L);
    PyModule_AddIntConstant(m, "UAI_M_PWD2_EXPIRED", 0x400L);
    PyModule_AddIntConstant(m, "UAI_M_AUDIT", 0x800L);
    PyModule_AddIntConstant(m, "UAI_M_DISREPORT", 0x1000L);
    PyModule_AddIntConstant(m, "UAI_M_DISRECONNECT", 0x2000L);
    PyModule_AddIntConstant(m, "UAI_M_AUTOLOGIN", 0x4000L);
    PyModule_AddIntConstant(m, "UAI_M_DISFORCE_PWD_CHANGE", 0x8000L);
    PyModule_AddIntConstant(m, "UAI_M_CAPTIVE", 0x10000L);
    PyModule_AddIntConstant(m, "UAI_M_DISIMAGE", 0x20000L);
    PyModule_AddIntConstant(m, "UAI_M_DISPWDDIC", 0x40000L);
    PyModule_AddIntConstant(m, "UAI_M_DISPWDHIS", 0x80000L);
    PyModule_AddIntConstant(m, "UAI_M_DEFCLSVAL", 0x100000L);
    PyModule_AddIntConstant(m, "UAI_M_EXTAUTH", 0x200000L);
    PyModule_AddIntConstant(m, "UAI_M_MIGRATEPWD", 0x400000L);
    PyModule_AddIntConstant(m, "UAI_M_VMSAUTH", 0x800000L);
    PyModule_AddIntConstant(m, "UAI_M_DISPWDSYNCH", 0x1000000L);
    PyModule_AddIntConstant(m, "UAI_M_PWDMIX", 0x2000000L);
    PyModule_AddIntConstant(m, "UAI_S_FLAGS", 4);
    PyModule_AddIntConstant(m, "UAI_S_PRIMEDAYS", 1);
    return m;
}