#include <Python.h>

PyDoc_STRVAR(doc__chpdef,
"CHP definitions");

static struct PyModuleDef _chpdef_module = {
    PyModuleDef_HEAD_INIT,
    "_chpdef",
    doc__chpdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__chpdef(void) {
    PyObject *m = PyModule_Create(&_chpdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "CHP__END", 0);
    PyModule_AddIntConstant(m, "CHP__ACCESS", 1);
    PyModule_AddIntConstant(m, "CHP__FLAGS", 2);
    PyModule_AddIntConstant(m, "CHP__PRIV", 3);
    PyModule_AddIntConstant(m, "CHP__ACMODE", 4);
    PyModule_AddIntConstant(m, "CHP__ACCLASS", 5);
    PyModule_AddIntConstant(m, "CHP__RIGHTS", 6);
    PyModule_AddIntConstant(m, "CHP__ADD_RIGHTS", 7);
    PyModule_AddIntConstant(m, "CHP__MODE", 8);
    PyModule_AddIntConstant(m, "CHP__MODES", 9);
    PyModule_AddIntConstant(m, "CHP__MIN_CLASS", 10);
    PyModule_AddIntConstant(m, "CHP__MAX_CLASS", 11);
    PyModule_AddIntConstant(m, "CHP__OWNER", 12);
    PyModule_AddIntConstant(m, "CHP__PROT", 13);
    PyModule_AddIntConstant(m, "CHP__ACL", 14);
    PyModule_AddIntConstant(m, "CHP__AUDIT_NAME", 15);
    PyModule_AddIntConstant(m, "CHP__ALARM_NAME", 16);
    PyModule_AddIntConstant(m, "CHP__MATCHED_ACE", 17);
    PyModule_AddIntConstant(m, "CHP__PRIVUSED", 18);
    PyModule_AddIntConstant(m, "CHP__AUDIT_LIST", 19);
    PyModule_AddIntConstant(m, "CHP__OBJECT_NAME", 20);
    PyModule_AddIntConstant(m, "CHP__OBJECT_CLASS", 21);
    PyModule_AddIntConstant(m, "CHP__UIC", 22);
    PyModule_AddIntConstant(m, "CHP__OBJECT_SPECIFIC", 23);
    PyModule_AddIntConstant(m, "CHP__MAX_CODE", 24);
    PyModule_AddIntConstant(m, "CHP__ADDRIGHTS", 7);
    PyModule_AddIntConstant(m, "CHP__MINCLASS", 10);
    PyModule_AddIntConstant(m, "CHP__MAXCLASS", 11);
    PyModule_AddIntConstant(m, "CHP__AUDITNAME", 15);
    PyModule_AddIntConstant(m, "CHP__ALARMNAME", 16);
    PyModule_AddIntConstant(m, "CHP__MATCHEDACE", 17);
    PyModule_AddIntConstant(m, "CHP__CLASS", 5);
    PyModule_AddIntConstant(m, "CHP_K_MATCHED_ACE_LENGTH", 255);
    PyModule_AddIntConstant(m, "CHP_K_ALARM_LENGTH", 768);
    PyModule_AddIntConstant(m, "CHP_K_AUDIT_LENGTH", 1560);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_SYSPRV", 0x1UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_BYPASS", 0x2UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_UPGRADE", 0x4UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_DOWNGRADE", 0x8UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_GRPPRV", 0x10UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_READALL", 0x20UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_OPER", 0x40UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_GRPNAM", 0x80UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_SYSNAM", 0x100UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_GROUP", 0x200UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_WORLD", 0x400UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_PRMCEB", 0x800UL);
    PyModule_AddIntConstant(m, "CHP_K_NUMBER_OF_PRIVS", 12);
    PyModule_AddIntConstant(m, "CHP_S_PRIVS_USED_BITS", 2);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_OBSERVE", 0x1UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_ALTER", 0x2UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_READ", 0x1UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_WRITE", 0x2UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_USEREADALL", 0x4UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_AUDIT", 0x8UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_NOFAILAUD", 0x10UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_NOSUCCAUD", 0x20UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_DELETE", 0x40UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_MANDATORY", 0x80UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_FLUSH", 0x100UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_CREATE", 0x200UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_INTERNAL", 0x400UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_SERVER", 0x800UL);
    PyModule_AddIntConstant(m, "CHP_S_FLAG_BITS", 2);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_NOACCESS", 0x1UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_REMDUPID", 0x2UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_INCSYSID", 0x4UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_INCIMGID", 0x8UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_DEFPRIV", 0x10UL);
    PyModule_AddUnsignedLongConstant(m, "CHP_M_DEFCLASS", 0x20UL);
    PyModule_AddIntConstant(m, "CHP_S_PROFILE_FLAGS", 1);
    return m;
}