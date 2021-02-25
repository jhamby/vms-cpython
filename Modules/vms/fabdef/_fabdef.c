#include <Python.h>

PyDoc_STRVAR(doc__fabdef,
"FAB definitions");

static struct PyModuleDef _fabdef_module = {
    PyModuleDef_HEAD_INIT,
    "_fabdef",
    doc__fabdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__fabdef(void) {
    PyObject *m = PyModule_Create(&_fabdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "FAB_C_BID", 3);
    PyModule_AddIntConstant(m, "FAB_M_PPF_RAT", 0x3FC0L);
    PyModule_AddIntConstant(m, "FAB_M_PPF_IND", 0x4000L);
    PyModule_AddIntConstant(m, "FAB_M_PPIFI", 0x8000L);
    PyModule_AddIntConstant(m, "FAB_M_ASY", 0x1L);
    PyModule_AddIntConstant(m, "FAB_M_MXV", 0x2L);
    PyModule_AddIntConstant(m, "FAB_M_SUP", 0x4L);
    PyModule_AddIntConstant(m, "FAB_M_TMP", 0x8L);
    PyModule_AddIntConstant(m, "FAB_M_TMD", 0x10L);
    PyModule_AddIntConstant(m, "FAB_M_DFW", 0x20L);
    PyModule_AddIntConstant(m, "FAB_M_SQO", 0x40L);
    PyModule_AddIntConstant(m, "FAB_M_RWO", 0x80L);
    PyModule_AddIntConstant(m, "FAB_M_POS", 0x100L);
    PyModule_AddIntConstant(m, "FAB_M_WCK", 0x200L);
    PyModule_AddIntConstant(m, "FAB_M_NEF", 0x400L);
    PyModule_AddIntConstant(m, "FAB_M_RWC", 0x800L);
    PyModule_AddIntConstant(m, "FAB_M_DMO", 0x1000L);
    PyModule_AddIntConstant(m, "FAB_M_SPL", 0x2000L);
    PyModule_AddIntConstant(m, "FAB_M_SCF", 0x4000L);
    PyModule_AddIntConstant(m, "FAB_M_DLT", 0x8000L);
    PyModule_AddIntConstant(m, "FAB_M_NFS", 0x10000L);
    PyModule_AddIntConstant(m, "FAB_M_UFO", 0x20000L);
    PyModule_AddIntConstant(m, "FAB_M_PPF", 0x40000L);
    PyModule_AddIntConstant(m, "FAB_M_INP", 0x80000L);
    PyModule_AddIntConstant(m, "FAB_M_CTG", 0x100000L);
    PyModule_AddIntConstant(m, "FAB_M_CBT", 0x200000L);
    PyModule_AddIntConstant(m, "FAB_M_SYNCSTS", 0x400000L);
    PyModule_AddIntConstant(m, "FAB_M_RCK", 0x800000L);
    PyModule_AddIntConstant(m, "FAB_M_NAM", 0x1000000L);
    PyModule_AddIntConstant(m, "FAB_M_CIF", 0x2000000L);
    PyModule_AddIntConstant(m, "FAB_M_ESC", 0x8000000L);
    PyModule_AddIntConstant(m, "FAB_M_TEF", 0x10000000L);
    PyModule_AddIntConstant(m, "FAB_M_OFP", 0x20000000L);
    PyModule_AddIntConstant(m, "FAB_M_KFO", 0x40000000L);
    PyModule_AddIntConstant(m, "FAB_M_EXTEND_FOP", 0x80000000L);
    PyModule_AddIntConstant(m, "FAB_M_ERL", 0x8000L);
    PyModule_AddIntConstant(m, "FAB_M_PUT", 0x1L);
    PyModule_AddIntConstant(m, "FAB_M_GET", 0x2L);
    PyModule_AddIntConstant(m, "FAB_M_DEL", 0x4L);
    PyModule_AddIntConstant(m, "FAB_M_UPD", 0x8L);
    PyModule_AddIntConstant(m, "FAB_M_TRN", 0x10L);
    PyModule_AddIntConstant(m, "FAB_M_BIO", 0x20L);
    PyModule_AddIntConstant(m, "FAB_M_BRO", 0x40L);
    PyModule_AddIntConstant(m, "FAB_M_EXE", 0x80L);
    PyModule_AddIntConstant(m, "FAB_M_SHRPUT", 0x1L);
    PyModule_AddIntConstant(m, "FAB_M_SHRGET", 0x2L);
    PyModule_AddIntConstant(m, "FAB_M_SHRDEL", 0x4L);
    PyModule_AddIntConstant(m, "FAB_M_SHRUPD", 0x8L);
    PyModule_AddIntConstant(m, "FAB_M_MSE", 0x10L);
    PyModule_AddIntConstant(m, "FAB_M_NIL", 0x20L);
    PyModule_AddIntConstant(m, "FAB_M_UPI", 0x40L);
    PyModule_AddIntConstant(m, "FAB_M_NQL", 0x80L);
    PyModule_AddIntConstant(m, "FAB_M_ORG", 0xF0L);
    PyModule_AddIntConstant(m, "FAB_C_SEQ", 0);
    PyModule_AddIntConstant(m, "FAB_C_REL", 16);
    PyModule_AddIntConstant(m, "FAB_C_IDX", 32);
    PyModule_AddIntConstant(m, "FAB_C_HSH", 48);
    PyModule_AddIntConstant(m, "FAB_C_SPECIAL", 64);
    PyModule_AddIntConstant(m, "FAB_M_FTN", 0x1L);
    PyModule_AddIntConstant(m, "FAB_M_CR", 0x2L);
    PyModule_AddIntConstant(m, "FAB_M_PRN", 0x4L);
    PyModule_AddIntConstant(m, "FAB_M_BLK", 0x8L);
    PyModule_AddIntConstant(m, "FAB_M_MSB", 0x10L);
    PyModule_AddIntConstant(m, "FAB_C_FIFO", 1);
    PyModule_AddIntConstant(m, "FAB_C_CHAR_SPECIAL", 2);
    PyModule_AddIntConstant(m, "FAB_C_BLOCK_SPECIAL", 3);
    PyModule_AddIntConstant(m, "FAB_C_SYMLINK", 4);
    PyModule_AddIntConstant(m, "FAB_C_SYMBOLIC_LINK", 5);
    PyModule_AddIntConstant(m, "FAB_C_RFM_DFLT", 2);
    PyModule_AddIntConstant(m, "FAB_C_UDF", 0);
    PyModule_AddIntConstant(m, "FAB_C_FIX", 1);
    PyModule_AddIntConstant(m, "FAB_C_VAR", 2);
    PyModule_AddIntConstant(m, "FAB_C_VFC", 3);
    PyModule_AddIntConstant(m, "FAB_C_STM", 4);
    PyModule_AddIntConstant(m, "FAB_C_STMLF", 5);
    PyModule_AddIntConstant(m, "FAB_C_STMCR", 6);
    PyModule_AddIntConstant(m, "FAB_C_MAXRFM", 6);
    PyModule_AddIntConstant(m, "FAB_M_ONLY_RU", 0x1L);
    PyModule_AddIntConstant(m, "FAB_M_RU", 0x2L);
    PyModule_AddIntConstant(m, "FAB_M_BI", 0x4L);
    PyModule_AddIntConstant(m, "FAB_M_AI", 0x8L);
    PyModule_AddIntConstant(m, "FAB_M_AT", 0x10L);
    PyModule_AddIntConstant(m, "FAB_M_NEVER_RU", 0x20L);
    PyModule_AddIntConstant(m, "FAB_M_JOURNAL_FILE", 0x40L);
    PyModule_AddIntConstant(m, "FAB_M_SSIO_RQST", 0x1L);
    PyModule_AddIntConstant(m, "FAB_M_SSIO_GRANTED", 0x2L);
    PyModule_AddIntConstant(m, "FAB_M_SSIO_FOC", 0x4L);
    PyModule_AddIntConstant(m, "FAB_M_RCF_RU", 0x1L);
    PyModule_AddIntConstant(m, "FAB_M_RCF_AI", 0x2L);
    PyModule_AddIntConstant(m, "FAB_M_RCF_BI", 0x4L);
    PyModule_AddIntConstant(m, "FAB_S_FABDEF", 80);
    PyModule_AddIntConstant(m, "FAB_S_PPF_RAT", 8);
    PyModule_AddIntConstant(m, "FAB_S_ORG", 4);
    PyModule_AddIntConstant(m, "FAB_S_LNM_MODE", 2);
    PyModule_AddIntConstant(m, "FAB_S_CHAN_MODE", 2);
    PyModule_AddIntConstant(m, "FAB_S_FILE_MODE", 2);
    PyModule_AddIntConstant(m, "FAB_S_CALLERS_MODE", 2);
    PyModule_AddIntConstant(m, "FAB_K_BLN", 80);
    PyModule_AddIntConstant(m, "FAB_C_BLN", 80);
    return m;
}