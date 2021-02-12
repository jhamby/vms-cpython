#include <Python.h>

PyDoc_STRVAR(doc__mntdef,
"MNT definitions");

static struct PyModuleDef _mntdef_module = {
    PyModuleDef_HEAD_INIT,
    "mntdef",
    doc__mntdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__mntdef(void) {
    PyObject *m = PyModule_Create(&_mntdef_module);
    PyModule_AddIntConstant(m, "MNT_M_FOREIGN", 0x1L);
    PyModule_AddIntConstant(m, "MNT_M_GROUP", 0x2L);
    PyModule_AddIntConstant(m, "MNT_M_NOASSIST", 0x4L);
    PyModule_AddIntConstant(m, "MNT_M_NODISKQ", 0x8L);
    PyModule_AddIntConstant(m, "MNT_M_NOHDR3", 0x10L);
    PyModule_AddIntConstant(m, "MNT_M_NOLABEL", 0x20L);
    PyModule_AddIntConstant(m, "MNT_M_NOWRITE", 0x40L);
    PyModule_AddIntConstant(m, "MNT_M_OVR_ACCESS", 0x80L);
    PyModule_AddIntConstant(m, "MNT_M_OVR_EXP", 0x100L);
    PyModule_AddIntConstant(m, "MNT_M_OVR_IDENT", 0x200L);
    PyModule_AddIntConstant(m, "MNT_M_OVR_SETID", 0x400L);
    PyModule_AddIntConstant(m, "MNT_M_READCHECK", 0x800L);
    PyModule_AddIntConstant(m, "MNT_M_SHARE", 0x1000L);
    PyModule_AddIntConstant(m, "MNT_M_MESSAGE", 0x2000L);
    PyModule_AddIntConstant(m, "MNT_M_SYSTEM", 0x4000L);
    PyModule_AddIntConstant(m, "MNT_M_WRITECHECK", 0x8000L);
    PyModule_AddIntConstant(m, "MNT_M_WRITETHRU", 0x10000L);
    PyModule_AddIntConstant(m, "MNT_M_NOCACHE", 0x20000L);
    PyModule_AddIntConstant(m, "MNT_M_OVR_LOCK", 0x40000L);
    PyModule_AddIntConstant(m, "MNT_M_NOMNTVER", 0x80000L);
    PyModule_AddIntConstant(m, "MNT_M_NOUNLOAD", 0x100000L);
    PyModule_AddIntConstant(m, "MNT_M_TAPE_DATA_WRITE", 0x200000L);
    PyModule_AddIntConstant(m, "MNT_M_NOCOPY", 0x400000L);
    PyModule_AddIntConstant(m, "MNT_M_NOAUTO", 0x800000L);
    PyModule_AddIntConstant(m, "MNT_M_INIT_ALL", 0x1000000L);
    PyModule_AddIntConstant(m, "MNT_M_INIT_CONT", 0x2000000L);
    PyModule_AddIntConstant(m, "MNT_M_OVR_VOLO", 0x4000000L);
    PyModule_AddIntConstant(m, "MNT_M_INTERCHG", 0x8000000L);
    PyModule_AddIntConstant(m, "MNT_M_CLUSTER", 0x10000000L);
    PyModule_AddIntConstant(m, "MNT_M_NOREBUILD", 0x20000000L);
    PyModule_AddIntConstant(m, "MNT_M_OVR_SHAMEM", 0x40000000L);
    PyModule_AddIntConstant(m, "MNT_M_MULTI_VOL", 0x80000000L);
    PyModule_AddIntConstant(m, "MNT2_M_DISKQ", 0x1L);
    PyModule_AddIntConstant(m, "MNT2_M_COMPACTION", 0x2L);
    PyModule_AddIntConstant(m, "MNT2_M_INCLUDE", 0x4L);
    PyModule_AddIntConstant(m, "MNT2_M_PASS2", 0x8L);
    PyModule_AddIntConstant(m, "MNT2_M_OVR_NOFE", 0x10L);
    PyModule_AddIntConstant(m, "MNT2_M_SCRATCH", 0x20L);
    PyModule_AddIntConstant(m, "MNT2_M_CDROM", 0x40L);
    PyModule_AddIntConstant(m, "MNT2_M_XAR", 0x80L);
    PyModule_AddIntConstant(m, "MNT2_M_DSI", 0x100L);
    PyModule_AddIntConstant(m, "MNT2_M_SUBSYSTEM", 0x200L);
    PyModule_AddIntConstant(m, "MNT2_M_NOCOMPACTION", 0x400L);
    PyModule_AddIntConstant(m, "MNT2_M_OVR_SECURITY", 0x800L);
    PyModule_AddIntConstant(m, "MNT2_M_OVR_LIMITED_SEARCH", 0x1000L);
    PyModule_AddIntConstant(m, "MNT2_M_POOL", 0x2000L);
    PyModule_AddIntConstant(m, "MNT2_M_WLG_ENABLE", 0x4000L);
    PyModule_AddIntConstant(m, "MNT2_M_WLG_DISABLE", 0x8000L);
    PyModule_AddIntConstant(m, "MNT2_M_REQUIRE_MEMBERS", 0x10000L);
    PyModule_AddIntConstant(m, "MNT2_M_VERIFY_LABEL", 0x20000L);
    PyModule_AddIntConstant(m, "MNT2_M_FULL_MERGE", 0x40000L);
    PyModule_AddIntConstant(m, "MNT2_M_WRITE_FIRST", 0x80000L);
    PyModule_AddIntConstant(m, "MNT2_M_DCD", 0x100000L);
    PyModule_AddIntConstant(m, "MNT2_M_NODCD", 0x200000L);
    PyModule_AddIntConstant(m, "MNT2_M_LOCAL_HOST", 0x400000L);
    PyModule_AddIntConstant(m, "MNT2_M_FACTOR", 0x800000L);
    PyModule_AddIntConstant(m, "MNT2_M_PRIORITY", 0x1000000L);
    PyModule_AddIntConstant(m, "MNT__DEVNAM", 1);
    PyModule_AddIntConstant(m, "MNT__VOLNAM", 2);
    PyModule_AddIntConstant(m, "MNT__LOGNAM", 3);
    PyModule_AddIntConstant(m, "MNT__FLAGS", 4);
    PyModule_AddIntConstant(m, "MNT__ACCESSED", 5);
    PyModule_AddIntConstant(m, "MNT__PROCESSOR", 6);
    PyModule_AddIntConstant(m, "MNT__VOLSET", 7);
    PyModule_AddIntConstant(m, "MNT__BLOCKSIZE", 8);
    PyModule_AddIntConstant(m, "MNT__DENSITY", 9);
    PyModule_AddIntConstant(m, "MNT__EXTENT", 10);
    PyModule_AddIntConstant(m, "MNT__FILEID", 11);
    PyModule_AddIntConstant(m, "MNT__LIMIT", 12);
    PyModule_AddIntConstant(m, "MNT__OWNER", 13);
    PyModule_AddIntConstant(m, "MNT__VPROT", 14);
    PyModule_AddIntConstant(m, "MNT__QUOTA", 15);
    PyModule_AddIntConstant(m, "MNT__RECORDSIZ", 16);
    PyModule_AddIntConstant(m, "MNT__WINDOW", 17);
    PyModule_AddIntConstant(m, "MNT__EXTENSION", 18);
    PyModule_AddIntConstant(m, "MNT__VISUAL_ID", 19);
    PyModule_AddIntConstant(m, "MNT__COMMENT", 20);
    PyModule_AddIntConstant(m, "MNT__CLASS", 21);
    PyModule_AddIntConstant(m, "MNT__UNUSED2", 22);
    PyModule_AddIntConstant(m, "MNT__ACCPTNAM", 23);
    PyModule_AddIntConstant(m, "MNT__SHACOPY_BUF", 24);
    PyModule_AddIntConstant(m, "MNT__SHANAM", 25);
    PyModule_AddIntConstant(m, "MNT__SHAMEM", 26);
    PyModule_AddIntConstant(m, "MNT__SHAMEM_MGCOPY", 27);
    PyModule_AddIntConstant(m, "MNT__SHAMEM_COPY", 28);
    PyModule_AddIntConstant(m, "MNT__PRFD_PATH", 29);
    PyModule_AddIntConstant(m, "MNT__ASSIGNMENT_UNIT", 30);
    PyModule_AddIntConstant(m, "MNT__CART_MEDIA_NAME", 31);
    PyModule_AddIntConstant(m, "MNT__CARTRIDGE_NAME", 32);
    PyModule_AddIntConstant(m, "MNT__CARTRIDGE_SIDE", 33);
    PyModule_AddIntConstant(m, "MNT__COLLECTION", 34);
    PyModule_AddIntConstant(m, "MNT__DEVICE_TYPE", 35);
    PyModule_AddIntConstant(m, "MNT__DISPOSITION", 36);
    PyModule_AddIntConstant(m, "MNT__LOCATION", 37);
    PyModule_AddIntConstant(m, "MNT__MEDIA_NAME", 38);
    PyModule_AddIntConstant(m, "MNT__UNUSED4", 39);
    PyModule_AddIntConstant(m, "MNT__UNDEFINED_FAT", 40);
    PyModule_AddIntConstant(m, "MNT__UCS", 41);
    PyModule_AddIntConstant(m, "MNT__TAPE_EXPIRATION", 42);
    PyModule_AddIntConstant(m, "MNT__PRIORITY", 43);
    PyModule_AddIntConstant(m, "MNT__FACTOR", 44);
    PyModule_AddIntConstant(m, "MNT__WBM_SIZE", 45);
    PyModule_AddIntConstant(m, "MNT__DATA", 46);
    PyModule_AddIntConstant(m, "MNT__NODATA", 47);
    PyModule_AddIntConstant(m, "MNT__LAST_ITEM_CODE", 48);
    PyModule_AddIntConstant(m, "MNT_C_BASE_CARTRIDGE", 1);
    PyModule_AddIntConstant(m, "MNT_C_COMPOUND_CARTRIDGE", 2);
    PyModule_AddIntConstant(m, "MNT_C_PREASSIGNED_SIDE", 3);
    PyModule_AddIntConstant(m, "MNT_C_SIDE", 4);
    PyModule_AddIntConstant(m, "MNT_C_KEEP", 1);
    PyModule_AddIntConstant(m, "MNT_C_RELEASE", 2);
    PyModule_AddIntConstant(m, "MNT_S_MNTDEF", 8);
    PyModule_AddIntConstant(m, "UNFAT_S_UNDEFINED_FAT", 4);
    return m;
}