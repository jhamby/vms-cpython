#include <Python.h>

PyDoc_STRVAR(doc__acldef,
"ACL definitions");

static struct PyModuleDef _acldef_module = {
    PyModuleDef_HEAD_INIT,
    "_acldef",
    doc__acldef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__acldef(void) {
    PyObject *m = PyModule_Create(&_acldef_module);
    PyModule_AddIntConstant(m, "ACL_K_LENGTH", 12);
    PyModule_AddIntConstant(m, "ACL_C_LENGTH", 12);
    PyModule_AddIntConstant(m, "ACL_C_FILE", 1);
    PyModule_AddIntConstant(m, "ACL_C_DEVICE", 2);
    PyModule_AddIntConstant(m, "ACL_C_JOBCTL_QUEUE", 3);
    PyModule_AddIntConstant(m, "ACL_C_COMMON_EF_CLUSTER", 4);
    PyModule_AddIntConstant(m, "ACL_C_LOGICAL_NAME_TABLE", 5);
    PyModule_AddIntConstant(m, "ACL_C_PROCESS", 6);
    PyModule_AddIntConstant(m, "ACL_C_GROUP_GLOBAL_SECTION", 7);
    PyModule_AddIntConstant(m, "ACL_C_SYSTEM_GLOBAL_SECTION", 8);
    PyModule_AddIntConstant(m, "ACL_C_CAPABILITY", 9);
    PyModule_AddIntConstant(m, "ACL_C_EVENT_FACILITY", 10);
    PyModule_AddIntConstant(m, "ACL_C_LOCK", 11);
    PyModule_AddIntConstant(m, "ACL_C_VOLUME", 12);
    PyModule_AddIntConstant(m, "ACL_C_MAX_OBJECT", 13);
    PyModule_AddIntConstant(m, "ACL_C_NUM_OBJECTS", 12);
    PyModule_AddIntConstant(m, "ACL_K_NUM_OBJECTS", 12);
    PyModule_AddIntConstant(m, "ACL_C_ADDACLENT", 1);
    PyModule_AddIntConstant(m, "ACL_C_DELACLENT", 2);
    PyModule_AddIntConstant(m, "ACL_C_MODACLENT", 3);
    PyModule_AddIntConstant(m, "ACL_C_FNDACLENT", 4);
    PyModule_AddIntConstant(m, "ACL_C_FNDACETYP", 5);
    PyModule_AddIntConstant(m, "ACL_C_DELETEACL", 6);
    PyModule_AddIntConstant(m, "ACL_C_READACL", 7);
    PyModule_AddIntConstant(m, "ACL_C_ACLLENGTH", 8);
    PyModule_AddIntConstant(m, "ACL_C_READACE", 9);
    PyModule_AddIntConstant(m, "ACL_C_RLOCK_ACL", 10);
    PyModule_AddIntConstant(m, "ACL_C_WLOCK_ACL", 11);
    PyModule_AddIntConstant(m, "ACL_C_UNLOCK_ACL", 12);
    PyModule_AddIntConstant(m, "ACL_C_GRANT_ACE", 13);
    PyModule_AddIntConstant(m, "ACL_C_NEXT_ACE", 14);
    PyModule_AddIntConstant(m, "ACL_C_DELETE_ALL", 15);
    PyModule_AddIntConstant(m, "ACL_C_RESERVED_ITEM_2", 16);
    PyModule_AddIntConstant(m, "ACL_C_RESERVED_ITEM_3", 17);
    PyModule_AddIntConstant(m, "ACL_S_ADDACLENT", 255);
    PyModule_AddIntConstant(m, "ACL_S_DELACLENT", 255);
    PyModule_AddIntConstant(m, "ACL_S_MODACLENT", 255);
    PyModule_AddIntConstant(m, "ACL_S_FNDACLENT", 255);
    PyModule_AddIntConstant(m, "ACL_S_FNDACETYP", 255);
    PyModule_AddIntConstant(m, "ACL_S_DELETEACL", 255);
    PyModule_AddIntConstant(m, "ACL_S_READACL", 512);
    PyModule_AddIntConstant(m, "ACL_S_ACLLENGTH", 4);
    PyModule_AddIntConstant(m, "ACL_S_READACE", 255);
    PyModule_AddIntConstant(m, "ACL_S_RLOCK_ACL", 4);
    PyModule_AddIntConstant(m, "ACL_S_WLOCK_ACL", 4);
    PyModule_AddIntConstant(m, "ACL_S_UNLOCK_ACL", 4);
    PyModule_AddIntConstant(m, "ACL_S_GRANT_ACE", 255);
    PyModule_AddIntConstant(m, "ACL_S_NEXT_ACE", 4);
    PyModule_AddIntConstant(m, "ACL_S_DELETE_ALL", 255);
    PyModule_AddIntConstant(m, "ACL_S_RESERVED_ITEM_2", 255);
    PyModule_AddIntConstant(m, "ACL_S_RESERVED_ITEM_3", 255);
    PyModule_AddIntConstant(m, "ACL_C_MAX_SEGMENT_SIZE", 512);
    PyModule_AddIntConstant(m, "ACL_K_MAX_SEGMENT_SIZE", 512);
    PyModule_AddIntConstant(m, "ACL_S_ACLDEF", 16);
    return m;
}