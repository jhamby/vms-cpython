#include <Python.h>

PyDoc_STRVAR(doc__ciadef,
"CIA definitions");

static struct PyModuleDef _ciadef_module = {
    PyModuleDef_HEAD_INIT,
    "_ciadef",
    doc__ciadef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__ciadef(void) {
    PyObject *m = PyModule_Create(&_ciadef_module);
    PyModule_AddIntConstant(m, "CIA_K_SCAN", 1);
    PyModule_AddIntConstant(m, "CIA_K_DELETE", 2);
    PyModule_AddIntConstant(m, "CIA_K_SHOW", 3);
    PyModule_AddIntConstant(m, "CIA_K_PERFORMANCE", 4);
    PyModule_AddIntConstant(m, "CIA_K_ZERO_PERFORMANCE", 5);
    PyModule_AddIntConstant(m, "CIA_K_SCAN_EXTENDED", 6);
    PyModule_AddIntConstant(m, "CIA_K_DELETE_EXTENDED", 7);
    PyModule_AddIntConstant(m, "CIA_K_SHOW_EXTENDED", 8);
    PyModule_AddIntConstant(m, "CIA_K_MAX_CIA_CODE", 9);
    PyModule_AddIntConstant(m, "CIA_K_PERFORMANCE_LENGTH", 40);
    PyModule_AddIntConstant(m, "CIA_S_PERFORMANCE", 40);
    PyModule_AddIntConstant(m, "CIA_K_SOURCE_TERMINAL_LENGTH", 64);
    PyModule_AddIntConstant(m, "CIA_K_SOURCE_NODE_MAX_LENGTH", 1024);
    PyModule_AddIntConstant(m, "CIA_K_USER_SPEC_MAX_LENGTH", 1058);
    PyModule_AddIntConstant(m, "CIA_K_USER_STRING_MAX_LENGTH", 32);
    PyModule_AddIntConstant(m, "CIA_K_PASSWORD_MAX_LENGTH", 32);
    PyModule_AddIntConstant(m, "CIA_K_SOURCE_ADDRESS_MAX_LENGTH", 128);
    PyModule_AddIntConstant(m, "CIA_K_SCSNODE_LENGTH", 8);
    PyModule_AddIntConstant(m, "CIA_K_SCSNODE_REPLY_LENGTH", 12);
    PyModule_AddIntConstant(m, "CIA_K_USERDATA_LENGTH", 256);
    PyModule_AddIntConstant(m, "CIA_S_CIA_GENERIC_DESC", 5);
    PyModule_AddIntConstant(m, "CIAEXT_S_PACKET", 4);
    PyModule_AddIntConstant(m, "CIAEXT_S_EXTENSION_PACKET", 4);
    PyModule_AddIntConstant(m, "CIAEXT__USER_DATA", 100);
    PyModule_AddIntConstant(m, "CIAEXT__SCSNODE", 101);
    PyModule_AddIntConstant(m, "CIAEXT__SCSNODE_REPLY", 102);
    PyModule_AddIntConstant(m, "CIAEXT__IMAGE_NAME", 103);
    PyModule_AddIntConstant(m, "CIAEXT__MAX_CIAEXT_CODE", 104);
    PyModule_AddIntConstant(m, "CIA__SCSNODE_LIST", 200);
    PyModule_AddIntConstant(m, "CIA__SCSNODE", 201);
    PyModule_AddIntConstant(m, "CIA__OUTPUT_LIST", 202);
    PyModule_AddIntConstant(m, "CIA__USER_DATA", 203);
    PyModule_AddIntConstant(m, "CIA__USER_CRITERIAL", 204);
    PyModule_AddIntConstant(m, "CIA__FAILED_USERNAME", 205);
    PyModule_AddIntConstant(m, "CIA__IMAGE_NAME", 206);
    PyModule_AddIntConstant(m, "CIA__MAX_CIA_ITEM", 207);
    PyModule_AddIntConstant(m, "CIA_K_IMAGE_NAME_MAX_SIZE", 4096);
    PyModule_AddIntConstant(m, "CIA_S_IMAGE_NAME", 4100);
    PyModule_AddIntConstant(m, "CIA_S_IMAGE_STRING", 4096);
    PyModule_AddIntConstant(m, "CIA_M_IGNORE_RETURN", 0x1L);
    PyModule_AddIntConstant(m, "CIA_M_RESERVED_1", 0xFEL);
    PyModule_AddIntConstant(m, "CIA_M_SUSPECTS", 0x100L);
    PyModule_AddIntConstant(m, "CIA_M_INTRUDERS", 0x200L);
    PyModule_AddIntConstant(m, "CIA_M_SECONDARY_PASSWORD", 0x400L);
    PyModule_AddIntConstant(m, "CIA_M_NOAUDIT", 0x800L);
    PyModule_AddIntConstant(m, "CIA_M_REAL_USERNAME", 0x1000L);
    PyModule_AddIntConstant(m, "CIA_M_SHOW_NODE", 0x2000L);
    PyModule_AddIntConstant(m, "CIA_M_ITEMLIST", 0x4000L);
    PyModule_AddIntConstant(m, "CIA_M_FILL_1", 0xFFFF8000L);
    PyModule_AddIntConstant(m, "CIA_K_HEADER_LENGTH", 8);
    PyModule_AddIntConstant(m, "CIA_S_HEADER", 8);
    PyModule_AddIntConstant(m, "CIA_S_RESERVED_1", 7);
    PyModule_AddIntConstant(m, "CIA_S_FILL_1", 17);
    PyModule_AddIntConstant(m, "CIA_K_SHOW_INPUT_LENGTH", 1062);
    PyModule_AddIntConstant(m, "CIA_K_DELETE_INPUT_LENGTH", 1062);
    PyModule_AddIntConstant(m, "CIA_S_CONTENTS", 1062);
    PyModule_AddIntConstant(m, "CIA_S_NAME", 1058);
    PyModule_AddIntConstant(m, "CIA_K_SCAN_CONTENTS_LENGTH", 1386);
    PyModule_AddIntConstant(m, "CIA_S_SCAN_CONTENTS", 1386);
    PyModule_AddIntConstant(m, "CIA_S_SOURCE_TERMINAL", 68);
    PyModule_AddIntConstant(m, "CIA_S_SOURCE_TERM_NAME", 64);
    PyModule_AddIntConstant(m, "CIA_S_SOURCE_USER", 36);
    PyModule_AddIntConstant(m, "CIA_S_SOURCE_USER_NAME", 32);
    PyModule_AddIntConstant(m, "CIA_S_SOURCE_ADDRESS", 132);
    PyModule_AddIntConstant(m, "CIA_S_SOURCE_ADDRESS_NAME", 128);
    PyModule_AddIntConstant(m, "CIA_S_FAILED_USER", 36);
    PyModule_AddIntConstant(m, "CIA_S_FAILED_USER_NAME", 32);
    PyModule_AddIntConstant(m, "CIA_S_FAILED_PASSWORD", 36);
    PyModule_AddIntConstant(m, "CIA_S_FAILED_PASS_NAME", 32);
    PyModule_AddIntConstant(m, "CIA_S_PARENT_USER", 36);
    PyModule_AddIntConstant(m, "CIA_S_PARENT_USER_NAME", 32);
    PyModule_AddIntConstant(m, "CIA_S_SOURCE_NODE", 1028);
    PyModule_AddIntConstant(m, "CIA_S_SOURCE_NODE_NAME", 1024);
    PyModule_AddIntConstant(m, "CIA_M_INTRUDER", 0x1L);
    PyModule_AddIntConstant(m, "CIA_M_SUSPECT", 0x2L);
    PyModule_AddIntConstant(m, "CIA_M_NETWORK", 0x4L);
    PyModule_AddIntConstant(m, "CIA_M_TERM_USER", 0x8L);
    PyModule_AddIntConstant(m, "CIA_M_TERMINAL", 0x10L);
    PyModule_AddIntConstant(m, "CIA_M_USERNAME", 0x20L);
    PyModule_AddIntConstant(m, "CIA_M_FILL_2", 0xFFFFFFC0L);
    PyModule_AddIntConstant(m, "CIA_K_SHOW_OUTPUT_LENGTH", 1086);
    PyModule_AddIntConstant(m, "CIA_S_SHOW_OUTPUT", 1086);
    PyModule_AddIntConstant(m, "CIA_S_EXPIRATION_TIME", 8);
    PyModule_AddIntConstant(m, "CIA_S_USER_SPEC", 1062);
    PyModule_AddIntConstant(m, "CIA_S_USER_SPEC_NAME", 1058);
    PyModule_AddIntConstant(m, "CIA_S_BREAKIN_BLOCK", 16);
    PyModule_AddIntConstant(m, "CIA_S_BREAK_TIME", 8);
    PyModule_AddIntConstant(m, "CIA_S_CIA_GENERIC_REPLY", 4);
    return m;
}