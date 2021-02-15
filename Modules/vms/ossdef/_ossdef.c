#include <Python.h>

PyDoc_STRVAR(doc__ossdef,
"OSS definitions");

static struct PyModuleDef _ossdef_module = {
    PyModuleDef_HEAD_INIT,
    "_ossdef",
    doc__ossdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__ossdef(void) {
    PyObject *m = PyModule_Create(&_ossdef_module);
    PyModule_AddIntConstant(m, "OSS_M_WLOCK", 0x1L);
    PyModule_AddIntConstant(m, "OSS_M_RELCTX", 0x2L);
    PyModule_AddIntConstant(m, "OSS_M_LOCAL", 0x4L);
    PyModule_AddIntConstant(m, "OSS_S_OSSDEF", 1);
    PyModule_AddIntConstant(m, "OSS__ACCESS_NAMES", 1);
    PyModule_AddIntConstant(m, "OSS__ACCESS_NAMES_LENGTH", 2);
    PyModule_AddIntConstant(m, "OSS__ACL_ADD_ENTRY", 3);
    PyModule_AddIntConstant(m, "OSS__ACL_DELETE_ENTRY", 4);
    PyModule_AddIntConstant(m, "OSS__ACL_DELETE", 5);
    PyModule_AddIntConstant(m, "OSS__ACL_DELETE_ALL", 6);
    PyModule_AddIntConstant(m, "OSS__ACL_FIND_ENTRY", 7);
    PyModule_AddIntConstant(m, "OSS__ACL_FIND_NEXT", 8);
    PyModule_AddIntConstant(m, "OSS__ACL_FIND_TYPE", 9);
    PyModule_AddIntConstant(m, "OSS__ACL_GRANT_ACE", 10);
    PyModule_AddIntConstant(m, "OSS__ACL_LENGTH", 11);
    PyModule_AddIntConstant(m, "OSS__ACL_MODIFY_ENTRY", 12);
    PyModule_AddIntConstant(m, "OSS__ACL_POSITION", 13);
    PyModule_AddIntConstant(m, "OSS__ACL_POSITION_TOP", 14);
    PyModule_AddIntConstant(m, "OSS__ACL_POSITION_BOTTOM", 15);
    PyModule_AddIntConstant(m, "OSS__ACL_READ_ENTRY", 16);
    PyModule_AddIntConstant(m, "OSS__ACL_READ", 17);
    PyModule_AddIntConstant(m, "OSS__MAX_CLASS", 18);
    PyModule_AddIntConstant(m, "OSS__MIN_CLASS", 19);
    PyModule_AddIntConstant(m, "OSS__NEXT_OBJECT", 20);
    PyModule_AddIntConstant(m, "OSS__OWNER", 21);
    PyModule_AddIntConstant(m, "OSS__PROTECTION", 22);
    PyModule_AddIntConstant(m, "OSS__SYS_PROT", 23);
    PyModule_AddIntConstant(m, "OSS__OWN_PROT", 24);
    PyModule_AddIntConstant(m, "OSS__GRP_PROT", 25);
    PyModule_AddIntConstant(m, "OSS__WOR_PROT", 26);
    PyModule_AddIntConstant(m, "OSS__CLASS_NAME", 27);
    PyModule_AddIntConstant(m, "OSS__FIRST_TEMPLATE", 28);
    PyModule_AddIntConstant(m, "OSS__NEXT_TEMPLATE", 29);
    PyModule_AddIntConstant(m, "OSS__OBJECT_NAME", 30);
    PyModule_AddIntConstant(m, "OSS__ACCESS_CLASS_NAME", 31);
    PyModule_AddIntConstant(m, "OSS__DAMAGED_ACL", 32);
    PyModule_AddIntConstant(m, "OSS__IN_TRANSITION", 33);
    PyModule_AddIntConstant(m, "OSS__TRANQUILITY_COUNT", 34);
    PyModule_AddIntConstant(m, "OSS__POSIX_GID", 35);
    PyModule_AddIntConstant(m, "OSS__POSIX_GRP_MODE", 36);
    PyModule_AddIntConstant(m, "OSS__POSIX_MODE", 37);
    PyModule_AddIntConstant(m, "OSS__POSIX_SGID", 38);
    PyModule_AddIntConstant(m, "OSS__POSIX_SUID", 39);
    PyModule_AddIntConstant(m, "OSS__ACCESS_BITNAMES", 1);
    PyModule_AddIntConstant(m, "OSS__ACCESS_BITNAMES_LENGTH", 2);
    PyModule_AddIntConstant(m, "OSS__ACL_ADDACE", 3);
    PyModule_AddIntConstant(m, "OSS__ACL_DELACE", 4);
    PyModule_AddIntConstant(m, "OSS__ACL_FNDACE", 7);
    PyModule_AddIntConstant(m, "OSS__ACL_FNDNXT", 8);
    PyModule_AddIntConstant(m, "OSS__ACL_FNDTYP", 9);
    PyModule_AddIntConstant(m, "OSS__ACL_MODACE", 12);
    PyModule_AddIntConstant(m, "OSS__ACL_READACE", 16);
    return m;
}