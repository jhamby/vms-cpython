#include <Python.h>

PyDoc_STRVAR(doc__pxbdef,
"PXB definitions");

static struct PyModuleDef _pxbdef_module = {
    PyModuleDef_HEAD_INIT,
    "_pxbdef",
    doc__pxbdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__pxbdef(void) {
    PyObject *m = PyModule_Create(&_pxbdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "PXB_S_PXB", 12);
    PyModule_AddIntConstant(m, "PXB_K_LENGTH", 12);
    PyModule_AddIntConstant(m, "PXB_ARRAY_ELEMENTS", 16);
    PyModule_AddIntConstant(m, "PXB_ARRAY_K_PXB_ARRAY_HEADER", 12);
    PyModule_AddIntConstant(m, "PXB_ARRAY_S_PXB_ARRAY", 76);
    PyModule_AddIntConstant(m, "PXB_ARRAY_S_ELEMENTS", 64);
    PyModule_AddIntConstant(m, "DELBK_S_DELBK", 40);
    PyModule_AddIntConstant(m, "DELBK_C_DELEGATE_BLOCK_SIZE", 40);
    PyModule_AddIntConstant(m, "PXRB_S_PXRB", 88);
    PyModule_AddIntConstant(m, "PXRB_S_NAME_DESC", 8);
    PyModule_AddIntConstant(m, "PXRB_S_NAME", 32);
    PyModule_AddIntConstant(m, "PXRB_K_LENGTH", 88);
    PyModule_AddIntConstant(m, "PXDV_K_version", 1);
    PyModule_AddIntConstant(m, "PXDV_K_min_version", 1);
    PyModule_AddIntConstant(m, "PXDV_K_max_version", 1);
    PyModule_AddIntConstant(m, "PXDV_S_PXDV", 40);
    PyModule_AddIntConstant(m, "PXBNT_K_VERSION_1", 1);
    PyModule_AddIntConstant(m, "PXBNT_K_CURRENT_VERSION", 1);
    PyModule_AddIntConstant(m, "PXBNT_M_CLONE", 0x1L);
    PyModule_AddIntConstant(m, "PXBNT_M_DELEGATE", 0x2L);
    PyModule_AddIntConstant(m, "PXBNT_M_FILL_3", 0x4L);
    PyModule_AddIntConstant(m, "PXBNT_M_FILL_4", 0x8L);
    PyModule_AddIntConstant(m, "PXBNT_M_FILL_5", 0x10L);
    PyModule_AddIntConstant(m, "PXBNT_M_FILL_6", 0x20L);
    PyModule_AddIntConstant(m, "PXBNT_M_FILL_7", 0x40L);
    PyModule_AddIntConstant(m, "PXBNT_M_DEBIT", 0x80L);
    PyModule_AddIntConstant(m, "PXBNT_K_LENGTH", 88);
    PyModule_AddIntConstant(m, "PXBNT_S_PXBNT", 88);
    PyModule_AddIntConstant(m, "PXBNT_S_DOI", 8);
    PyModule_AddIntConstant(m, "PXBNT_S_NT_OWF_PASSWORD", 16);
    PyModule_AddIntConstant(m, "PXBNT_S_LM_OWF_PASSWORD", 16);
    PyModule_AddIntConstant(m, "PXB_M_FILL_1", 0x1L);
    PyModule_AddIntConstant(m, "PXB_M_FILL_2", 0x2L);
    PyModule_AddIntConstant(m, "PXB_M_FILL_3", 0x4L);
    PyModule_AddIntConstant(m, "PXB_M_FILL_4", 0x8L);
    PyModule_AddIntConstant(m, "PXB_M_FILL_5", 0x10L);
    PyModule_AddIntConstant(m, "PXB_M_FILL_6", 0x20L);
    PyModule_AddIntConstant(m, "PXB_M_FILL_7", 0x40L);
    PyModule_AddIntConstant(m, "PXB_M_DEBIT", 0x80L);
    PyModule_AddIntConstant(m, "PXB_S_PXB_FLAGS", 4);
    PyModule_AddIntConstant(m, "PXB_M_PRIMARY_EXTENSION", 0x1L);
    PyModule_AddIntConstant(m, "PXB_S_CREATE_FLAGS", 4);
    PyModule_AddIntConstant(m, "TOKEN_K_USERSESSIONKEY_OFFSET", 120);
    PyModule_AddIntConstant(m, "TOKEN_K_USERSESSIONKEY_SIZE", 16);
    PyModule_AddIntConstant(m, "TOKEN_K_LMSESSIONKEY_OFFSET", 136);
    PyModule_AddIntConstant(m, "TOKEN_K_LMSESSIONKEY_SIZE", 8);
    return m;
}