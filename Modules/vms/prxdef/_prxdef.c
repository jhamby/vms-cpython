#include <Python.h>

PyDoc_STRVAR(doc__prxdef,
"PRX definitions");

static struct PyModuleDef _prxdef_module = {
    PyModuleDef_HEAD_INIT,
    "_prxdef",
    doc__prxdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__prxdef(void) {
    PyObject *m = PyModule_Create(&_prxdef_module);
    PyModule_AddIntConstant(m, "PRX_K_ADD", 1);
    PyModule_AddIntConstant(m, "PRX_K_DELETE", 2);
    PyModule_AddIntConstant(m, "PRX_K_SHOW", 3);
    PyModule_AddIntConstant(m, "PRX_K_VERIFY", 4);
    PyModule_AddIntConstant(m, "PRX_K_PERFORMANCE", 5);
    PyModule_AddIntConstant(m, "PRX_K_ZERO_PERFORMANCE", 6);
    PyModule_AddIntConstant(m, "PRX_K_CREATE", 7);
    PyModule_AddIntConstant(m, "PRX_K_STOP", 8);
    PyModule_AddIntConstant(m, "PRX_K_START", 9);
    PyModule_AddIntConstant(m, "PRX_K_MAX_PROXY_CODE", 10);
    PyModule_AddIntConstant(m, "PRX_K_PERFORMANCE_LENGTH", 48);
    PyModule_AddIntConstant(m, "PRX_S_PERFORMANCE", 48);
    PyModule_AddIntConstant(m, "PRX_M_IGNORE_RETURN", 0x1L);
    PyModule_AddIntConstant(m, "PRX_M_BYPASS_EXPAND", 0x2L);
    PyModule_AddIntConstant(m, "PRX_M_RESERVE_1", 0xFCL);
    PyModule_AddIntConstant(m, "PRX_M_DEFAULT", 0x100L);
    PyModule_AddIntConstant(m, "PRX_M_EXACT", 0x200L);
    PyModule_AddIntConstant(m, "PRX_M_DELETE_ALLOWED", 0x400L);
    PyModule_AddIntConstant(m, "PRX_M_FILL_1", 0xFFFFF800L);
    PyModule_AddIntConstant(m, "PRX_K_HEADER_LENGTH", 8);
    PyModule_AddIntConstant(m, "PRX_S_HEADER", 8);
    PyModule_AddIntConstant(m, "PRX_S_FILL_1", 21);
    PyModule_AddIntConstant(m, "PRX_S_PRX_GENERIC_DESC1", 5);
    PyModule_AddIntConstant(m, "PRX_K_USER_NAME_LENGTH", 32);
    PyModule_AddIntConstant(m, "PRX_K_REMOTE_NODE_NAME_LENGTH", 1024);
    PyModule_AddIntConstant(m, "PRX_K_MAX_LOCAL_USERS", 16);
    PyModule_AddIntConstant(m, "PRX_K_LOCAL_USER_ENTRY", 36);
    PyModule_AddIntConstant(m, "PRX_S_DATA", 1100);
    PyModule_AddIntConstant(m, "PRX_S_LOCAL_USER_NAME", 32);
    PyModule_AddIntConstant(m, "PRX_S_REMOTE_USER_NAME", 32);
    PyModule_AddIntConstant(m, "PRX_S_REMOTE_NODE_NAME", 1024);
    PyModule_AddIntConstant(m, "PRX_K_DATA_LENGTH", 1100);
    PyModule_AddIntConstant(m, "PRX_S_BUFSIZ_SUMMARY", 8);
    PyModule_AddIntConstant(m, "PRX_K_MAX_REPLY", 1692);
    PyModule_AddIntConstant(m, "PRX_S_REPLY_UNION", 88);
    PyModule_AddIntConstant(m, "PRX_S_VALID_USER", 32);
    PyModule_AddIntConstant(m, "PRX_S_SHOW_DEF_USER", 32);
    PyModule_AddIntConstant(m, "PRX_S_SHOW_REM_USER", 32);
    PyModule_AddIntConstant(m, "PRX_S_SHOW_LOCAL_DATA", 4);
    PyModule_AddIntConstant(m, "PRX_K_MAX_LENGTH", 1108);
    return m;
}