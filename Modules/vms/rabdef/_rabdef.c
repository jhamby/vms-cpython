#include <Python.h>

PyDoc_STRVAR(doc__rabdef,
"RAB definitions");

static struct PyModuleDef _rabdef_module = {
    PyModuleDef_HEAD_INIT,
    "_rabdef",
    doc__rabdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__rabdef(void) {
    PyObject *m = PyModule_Create(&_rabdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "RAB_C_BID", 1);
    PyModule_AddIntConstant(m, "RAB_M_PPF_RAT", 0x3FC0L);
    PyModule_AddIntConstant(m, "RAB_M_PPF_IND", 0x4000L);
    PyModule_AddIntConstant(m, "RAB_M_PPISI", 0x8000L);
    PyModule_AddIntConstant(m, "RAB_M_ASY", 0x1L);
    PyModule_AddIntConstant(m, "RAB_M_TPT", 0x2L);
    PyModule_AddIntConstant(m, "RAB_M_REA", 0x4L);
    PyModule_AddIntConstant(m, "RAB_M_RRL", 0x8L);
    PyModule_AddIntConstant(m, "RAB_M_UIF", 0x10L);
    PyModule_AddIntConstant(m, "RAB_M_MAS", 0x20L);
    PyModule_AddIntConstant(m, "RAB_M_FDL", 0x40L);
    PyModule_AddIntConstant(m, "RAB_M_REV", 0x80L);
    PyModule_AddIntConstant(m, "RAB_M_EOF", 0x100L);
    PyModule_AddIntConstant(m, "RAB_M_RAH", 0x200L);
    PyModule_AddIntConstant(m, "RAB_M_WBH", 0x400L);
    PyModule_AddIntConstant(m, "RAB_M_BIO", 0x800L);
    PyModule_AddIntConstant(m, "RAB_M_CDK", 0x1000L);
    PyModule_AddIntConstant(m, "RAB_M_LOA", 0x2000L);
    PyModule_AddIntConstant(m, "RAB_M_LIM", 0x4000L);
    PyModule_AddIntConstant(m, "RAB_M_SYNCSTS", 0x8000L);
    PyModule_AddIntConstant(m, "RAB_M_LOC", 0x10000L);
    PyModule_AddIntConstant(m, "RAB_M_WAT", 0x20000L);
    PyModule_AddIntConstant(m, "RAB_M_ULK", 0x40000L);
    PyModule_AddIntConstant(m, "RAB_M_RLK", 0x80000L);
    PyModule_AddIntConstant(m, "RAB_M_NLK", 0x100000L);
    PyModule_AddIntConstant(m, "RAB_M_KGE", 0x200000L);
    PyModule_AddIntConstant(m, "RAB_M_KGT", 0x400000L);
    PyModule_AddIntConstant(m, "RAB_M_NXR", 0x800000L);
    PyModule_AddIntConstant(m, "RAB_M_RNE", 0x1000000L);
    PyModule_AddIntConstant(m, "RAB_M_TMO", 0x2000000L);
    PyModule_AddIntConstant(m, "RAB_M_CVT", 0x4000000L);
    PyModule_AddIntConstant(m, "RAB_M_RNF", 0x8000000L);
    PyModule_AddIntConstant(m, "RAB_M_ETO", 0x10000000L);
    PyModule_AddIntConstant(m, "RAB_M_PTA", 0x20000000L);
    PyModule_AddIntConstant(m, "RAB_M_PMT", 0x40000000L);
    PyModule_AddIntConstant(m, "RAB_M_CCO", 0x80000000L);
    PyModule_AddIntConstant(m, "RAB_M_EQNXT", 0x200000L);
    PyModule_AddIntConstant(m, "RAB_M_NXT", 0x400000L);
    PyModule_AddIntConstant(m, "RAB_M_NQL", 0x1L);
    PyModule_AddIntConstant(m, "RAB_M_NODLCKWT", 0x2L);
    PyModule_AddIntConstant(m, "RAB_M_NODLCKBLK", 0x4L);
    PyModule_AddIntConstant(m, "RAB_C_SEQ", 0);
    PyModule_AddIntConstant(m, "RAB_C_KEY", 1);
    PyModule_AddIntConstant(m, "RAB_C_RFA", 2);
    PyModule_AddIntConstant(m, "RAB_C_STM", 3);
    PyModule_AddIntConstant(m, "RAB_C_MAXRAC", 2);
    PyModule_AddIntConstant(m, "RAB_S_RABDEF", 68);
    PyModule_AddIntConstant(m, "RAB_S_PPF_RAT", 8);
    PyModule_AddIntConstant(m, "RAB_S_RFA", 6);
    PyModule_AddIntConstant(m, "RAB_K_BLN", 68);
    PyModule_AddIntConstant(m, "RAB_C_BLN", 68);
    PyModule_AddIntConstant(m, "RAB64_C_BID", 1);
    PyModule_AddIntConstant(m, "RAB64_M_PPF_RAT", 0x3FC0L);
    PyModule_AddIntConstant(m, "RAB64_M_PPF_IND", 0x4000L);
    PyModule_AddIntConstant(m, "RAB64_M_PPISI", 0x8000L);
    PyModule_AddIntConstant(m, "RAB64_M_ASY", 0x1L);
    PyModule_AddIntConstant(m, "RAB64_M_TPT", 0x2L);
    PyModule_AddIntConstant(m, "RAB64_M_REA", 0x4L);
    PyModule_AddIntConstant(m, "RAB64_M_RRL", 0x8L);
    PyModule_AddIntConstant(m, "RAB64_M_UIF", 0x10L);
    PyModule_AddIntConstant(m, "RAB64_M_MAS", 0x20L);
    PyModule_AddIntConstant(m, "RAB64_M_FDL", 0x40L);
    PyModule_AddIntConstant(m, "RAB64_M_REV", 0x80L);
    PyModule_AddIntConstant(m, "RAB64_M_EOF", 0x100L);
    PyModule_AddIntConstant(m, "RAB64_M_RAH", 0x200L);
    PyModule_AddIntConstant(m, "RAB64_M_WBH", 0x400L);
    PyModule_AddIntConstant(m, "RAB64_M_BIO", 0x800L);
    PyModule_AddIntConstant(m, "RAB64_M_CDK", 0x1000L);
    PyModule_AddIntConstant(m, "RAB64_M_LOA", 0x2000L);
    PyModule_AddIntConstant(m, "RAB64_M_LIM", 0x4000L);
    PyModule_AddIntConstant(m, "RAB64_M_SYNCSTS", 0x8000L);
    PyModule_AddIntConstant(m, "RAB64_M_LOC", 0x10000L);
    PyModule_AddIntConstant(m, "RAB64_M_WAT", 0x20000L);
    PyModule_AddIntConstant(m, "RAB64_M_ULK", 0x40000L);
    PyModule_AddIntConstant(m, "RAB64_M_RLK", 0x80000L);
    PyModule_AddIntConstant(m, "RAB64_M_NLK", 0x100000L);
    PyModule_AddIntConstant(m, "RAB64_M_KGE", 0x200000L);
    PyModule_AddIntConstant(m, "RAB64_M_KGT", 0x400000L);
    PyModule_AddIntConstant(m, "RAB64_M_NXR", 0x800000L);
    PyModule_AddIntConstant(m, "RAB64_M_RNE", 0x1000000L);
    PyModule_AddIntConstant(m, "RAB64_M_TMO", 0x2000000L);
    PyModule_AddIntConstant(m, "RAB64_M_CVT", 0x4000000L);
    PyModule_AddIntConstant(m, "RAB64_M_RNF", 0x8000000L);
    PyModule_AddIntConstant(m, "RAB64_M_ETO", 0x10000000L);
    PyModule_AddIntConstant(m, "RAB64_M_PTA", 0x20000000L);
    PyModule_AddIntConstant(m, "RAB64_M_PMT", 0x40000000L);
    PyModule_AddIntConstant(m, "RAB64_M_CCO", 0x80000000L);
    PyModule_AddIntConstant(m, "RAB64_M_EQNXT", 0x200000L);
    PyModule_AddIntConstant(m, "RAB64_M_NXT", 0x400000L);
    PyModule_AddIntConstant(m, "RAB64_M_NQL", 0x1L);
    PyModule_AddIntConstant(m, "RAB64_M_NODLCKWT", 0x2L);
    PyModule_AddIntConstant(m, "RAB64_M_NODLCKBLK", 0x4L);
    PyModule_AddIntConstant(m, "RAB64_C_SEQ", 0);
    PyModule_AddIntConstant(m, "RAB64_C_KEY", 1);
    PyModule_AddIntConstant(m, "RAB64_C_RFA", 2);
    PyModule_AddIntConstant(m, "RAB64_C_STM", 3);
    PyModule_AddIntConstant(m, "RAB64_C_MAXRAC", 2);
    PyModule_AddIntConstant(m, "RAB64_M_RESERVED29", 0x20000000L);
    PyModule_AddIntConstant(m, "RAB64_M_RESERVED30", 0x40000000L);
    PyModule_AddIntConstant(m, "RAB64_M_RESERVED31", 0x80000000L);
    PyModule_AddIntConstant(m, "RAB_M_RESERVED29", 536870912);
    PyModule_AddIntConstant(m, "RAB_M_RESERVED30", 1073741824);
    PyModule_AddIntConstant(m, "RAB_M_RESERVED31", -2147483648);
    PyModule_AddIntConstant(m, "RAB64_S_RAB64DEF", 144);
    PyModule_AddIntConstant(m, "RAB64_S_PPF_RAT", 8);
    PyModule_AddIntConstant(m, "RAB64_S_RFA", 6);
    PyModule_AddIntConstant(m, "RAB64_S_UBF", 8);
    PyModule_AddIntConstant(m, "RAB_S_UBF", 8);
    PyModule_AddIntConstant(m, "RAB64_S_USZ", 8);
    PyModule_AddIntConstant(m, "RAB_S_USZ", 8);
    PyModule_AddIntConstant(m, "RAB64_S_RBF", 8);
    PyModule_AddIntConstant(m, "RAB_S_RBF", 8);
    PyModule_AddIntConstant(m, "RAB64_S_RSZ", 8);
    PyModule_AddIntConstant(m, "RAB_S_RSZ", 8);
    PyModule_AddIntConstant(m, "RAB64_S_KBF", 8);
    PyModule_AddIntConstant(m, "RAB_S_KBF", 8);
    PyModule_AddIntConstant(m, "RAB64_S_RHB", 8);
    PyModule_AddIntConstant(m, "RAB_S_RHB", 8);
    PyModule_AddIntConstant(m, "RAB64_S_CTX", 8);
    PyModule_AddIntConstant(m, "RAB_S_CTX", 8);
    PyModule_AddIntConstant(m, "RAB64_K_BLN64", 144);
    PyModule_AddIntConstant(m, "RAB64_C_BLN64", 144);
    PyModule_AddIntConstant(m, "RAB_K_BLN64", 144);
    PyModule_AddIntConstant(m, "RAB_C_BLN64", 144);
    PyModule_AddIntConstant(m, "RAB_K_MAXBLN", 144);
    PyModule_AddIntConstant(m, "RAB_C_MAXBLN", 144);
    return m;
}