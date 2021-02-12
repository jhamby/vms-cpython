#include <Python.h>

PyDoc_STRVAR(doc__issdef,
"ISS definitions");

static struct PyModuleDef _issdef_module = {
    PyModuleDef_HEAD_INIT,
    "issdef",
    doc__issdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__issdef(void) {
    PyObject *m = PyModule_Create(&_issdef_module);
    PyModule_AddIntConstant(m, "ISS__FLAGS", 1);
    PyModule_AddIntConstant(m, "ISS__ARBFLAGS", 2);
    PyModule_AddIntConstant(m, "ISS__WORKPRIV", 3);
    PyModule_AddIntConstant(m, "ISS__MODE", 4);
    PyModule_AddIntConstant(m, "ISS__WORKCLASS", 5);
    PyModule_AddIntConstant(m, "ISS__RIGHTS", 6);
    PyModule_AddIntConstant(m, "ISS__ADD_RIGHTS", 7);
    PyModule_AddIntConstant(m, "ISS__ADD_AUTHRIGHTS", 8);
    PyModule_AddIntConstant(m, "ISS__USERNAME", 9);
    PyModule_AddIntConstant(m, "ISS__ACCOUNT", 10);
    PyModule_AddIntConstant(m, "ISS__NOAUDIT", 11);
    PyModule_AddIntConstant(m, "ISS__AUTHPRIV", 12);
    PyModule_AddIntConstant(m, "ISS__PERMPRIV", 13);
    PyModule_AddIntConstant(m, "ISS__IMAGE_WORKPRIV", 14);
    PyModule_AddIntConstant(m, "ISS__ENABLED", 15);
    PyModule_AddIntConstant(m, "ISS__AUTHRIGHTS", 16);
    PyModule_AddIntConstant(m, "ISS__MINCLASS", 17);
    PyModule_AddIntConstant(m, "ISS__MAXCLASS", 18);
    PyModule_AddIntConstant(m, "ISS__UID", 19);
    PyModule_AddIntConstant(m, "ISS__PERSONA_ID", 20);
    PyModule_AddIntConstant(m, "ISS__PRINCIPAL", 21);
    PyModule_AddIntConstant(m, "ISS__UIC", 22);
    PyModule_AddIntConstant(m, "ISS__SWITCH_EXTENSION", 23);
    PyModule_AddIntConstant(m, "ISS__PRIMARY_EXTENSION", 24);
    PyModule_AddIntConstant(m, "ISS__EXTENSION_COUNT", 25);
    PyModule_AddIntConstant(m, "ISS__EXTENSION_ARRAY", 26);
    PyModule_AddIntConstant(m, "ISS__RIGHTS_INDEX", 27);
    PyModule_AddIntConstant(m, "ISS__INPUT_DATA", 28);
    PyModule_AddIntConstant(m, "ISS__POSIX_UID", 29);
    PyModule_AddIntConstant(m, "ISS__POSIX_GID", 30);
    PyModule_AddIntConstant(m, "ISS__MIN_ITEM_CODE", 1);
    PyModule_AddIntConstant(m, "ISS__MAX_ITEM_CODE", 30);
    PyModule_AddIntConstant(m, "ISS_M_FLAG_PERMANENT", 0x1L);
    PyModule_AddIntConstant(m, "ISS_M_FLAG_SECAUDIT", 0x2L);
    PyModule_AddIntConstant(m, "ISS_S_ISSFLAGSDEF", 4);
    PyModule_AddIntConstant(m, "ISS__COMMON_FLAGS", 1024);
    PyModule_AddIntConstant(m, "ISS__COMMON_USERNAME", 1025);
    PyModule_AddIntConstant(m, "ISS__COMMON_ACCOUNT", 1026);
    PyModule_AddIntConstant(m, "ISS__DOMAIN", 1027);
    PyModule_AddIntConstant(m, "ISS__COMMON_PRINCIPAL", 1028);
    PyModule_AddIntConstant(m, "ISS__DOI", 1029);
    PyModule_AddIntConstant(m, "ISS__EXTENSION", 1030);
    PyModule_AddIntConstant(m, "ISS__MAKE_TLV", 1031);
    PyModule_AddIntConstant(m, "ISS__MIN_COMMON_ITEM_CODE", 1024);
    PyModule_AddIntConstant(m, "ISS__MAX_COMMON_ITEM_CODE", 1031);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN", 8192);
    PyModule_AddIntConstant(m, "ISS__NT_SECURITY_SUBJECT", 8193);
    PyModule_AddIntConstant(m, "ISS__NT_FLAGS", 8194);
    PyModule_AddIntConstant(m, "ISS__NT_USER_REFCOUNT", 8195);
    PyModule_AddIntConstant(m, "ISS__NT_PRINCIPAL", 8196);
    PyModule_AddIntConstant(m, "ISS__NT_CREDENTIALS", 8197);
    PyModule_AddIntConstant(m, "ISS__NT_NT_OWF_PASSWORD", 8198);
    PyModule_AddIntConstant(m, "ISS__NT_LM_OWF_PASSWORD", 8199);
    PyModule_AddIntConstant(m, "ISS__NT_UNPACK_CRED_SIZE", 8200);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_TOKENID", 8201);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_IMPERSONATELEVEL", 8202);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_AUTHENTICATIONID", 8203);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_USERANDGROUPCOUNT", 8204);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_VARIABLELENGTH", 8205);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_USERANDGROUPS", 8206);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_USERANDGROUPS_SID", 8207);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_PRIMARYGROUP", 8208);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_PRIVILEGES", 8209);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_DEFAULTDACL", 8210);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_UNIXUID", 8211);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_UNIXGID", 8212);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_GIDINFO", 8213);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_GIDINFO_GIDS", 8214);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_UNIXNAME", 8215);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_DOMAINNAME", 8216);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_USERNAME", 8217);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_USERSESSIONKEY", 8218);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_LMSESSIONKEY", 8219);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_VARIABLEPART", 8220);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_GROUP_LIST", 8221);
    PyModule_AddIntConstant(m, "ISS__NT_TOKEN_PRIVILEGES_LIST", 8222);
    PyModule_AddIntConstant(m, "ISS__NT_SECURITY_SIGNATURE", 8223);
    PyModule_AddIntConstant(m, "ISS__NT_SECURITY_SMBUID", 8224);
    PyModule_AddIntConstant(m, "ISS__NT_SECURITY_PROCESSAUDITID", 8225);
    PyModule_AddIntConstant(m, "ISS__NT_SECURITY_PROCESSID", 8226);
    PyModule_AddIntConstant(m, "ISS__NT_SECURITY_LOGONID", 8227);
    PyModule_AddIntConstant(m, "ISS__NT_SECURITY_LOGONTYPE", 8228);
    PyModule_AddIntConstant(m, "ISS__NT_SECURITY_SUBJECTFLAGS", 8229);
    PyModule_AddIntConstant(m, "ISS__NT_SECURITY_CONTEXT_OTHER", 8230);
    PyModule_AddIntConstant(m, "ISS__MIN_NT_ITEM_CODE", 8192);
    PyModule_AddIntConstant(m, "ISS__MAX_NT_ITEM_CODE", 8230);
    PyModule_AddIntConstant(m, "ISS_M_ENABLED_PERSONA", 0x1L);
    PyModule_AddIntConstant(m, "ISS_M_ENABLED_SUBSYSTEM", 0x2L);
    PyModule_AddIntConstant(m, "ISS_M_ENABLED_IMAGE", 0x4L);
    PyModule_AddIntConstant(m, "ISS_M_ENABLED_SYSTEM", 0x8L);
    PyModule_AddIntConstant(m, "ISS_M_ENABLED_TEMPORARY", 0x10L);
    PyModule_AddIntConstant(m, "ISS_S_ISSENABLEDDEF", 4);
    PyModule_AddIntConstant(m, "ISS_C_ARB_UNSPECIFIED", -1);
    PyModule_AddIntConstant(m, "ISS_C_ARB_NONE", 0);
    PyModule_AddIntConstant(m, "ISS_C_ARB_CLEAR", 1);
    PyModule_AddIntConstant(m, "ISS_C_ARB_READ_ONLY", 2);
    PyModule_AddIntConstant(m, "ISS_C_ARB_FULL", 3);
    PyModule_AddIntConstant(m, "ISS_C_ARB_FORCE", 4);
    PyModule_AddIntConstant(m, "ISS_C_ARB_MAX_CODE", 4);
    PyModule_AddIntConstant(m, "ISS_C_ARB_MIN_CODE", 0);
    PyModule_AddIntConstant(m, "ISS_C_ID_NATURAL", 1);
    PyModule_AddIntConstant(m, "ISS_C_ID_POSIX_REAL", -2);
    PyModule_AddIntConstant(m, "ISS_C_ID_IMAGE_PERSONA", -2);
    PyModule_AddIntConstant(m, "ISS_M_IMP_FLAGS", 0x7FL);
    PyModule_AddIntConstant(m, "ISS_M_ASSUME_NODEREF_OLD", 0x10000L);
    PyModule_AddIntConstant(m, "ISS_M_ASSUME_NOREF_NEW", 0x20000L);
    PyModule_AddIntConstant(m, "ISS_M_CREATE_DEFPRIV", 0x8L);
    PyModule_AddIntConstant(m, "ISS_M_CREATE_DEFCLASS", 0x10L);
    PyModule_AddIntConstant(m, "ISS_M_CREATE_AUTHPRIV", 0x20L);
    PyModule_AddIntConstant(m, "ISS_M_NOACCESS", 0x100000L);
    PyModule_AddIntConstant(m, "ISS_S_ISSSRVCFLG", 4);
    PyModule_AddIntConstant(m, "ISS_S_IMP_FLAGS", 7);
    PyModule_AddIntConstant(m, "ISS_S_ASSUME_FLAGS", 4);
    PyModule_AddIntConstant(m, "ISS_S_CREATE_FLAGS", 4);
    PyModule_AddIntConstant(m, "ISS_K_NT_VERSION_1", 1);
    return m;
}