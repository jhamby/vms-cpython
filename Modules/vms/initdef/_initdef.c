#include <Python.h>

PyDoc_STRVAR(doc__initdef,
"INIT definitions");

static struct PyModuleDef _initdef_module = {
    PyModuleDef_HEAD_INIT,
    "initdef",
    doc__initdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__initdef(void) {
    PyObject *m = PyModule_Create(&_initdef_module);
    PyModule_AddIntConstant(m, "INIT_K_DENSITY_800_BPI", 1);
    PyModule_AddIntConstant(m, "INIT_K_DENSITY_1600_BPI", 2);
    PyModule_AddIntConstant(m, "INIT_K_DENSITY_6250_BPI", 3);
    PyModule_AddIntConstant(m, "INIT_K_DENSITY_SINGLE_DISK", 4);
    PyModule_AddIntConstant(m, "INIT_K_DENSITY_DOUBLE_DISK", 5);
    PyModule_AddIntConstant(m, "INIT_K_DENSITY_DD_DISK", 6);
    PyModule_AddIntConstant(m, "INIT_K_DENSITY_HD_DISK", 7);
    PyModule_AddIntConstant(m, "INIT_K_DENSITY_COMPACT", 8);
    PyModule_AddIntConstant(m, "INIT_K_DENSITY_ED_DISK", 9);
    PyModule_AddIntConstant(m, "INIT_K_HOMEBLOCKS_GEOMETRY", 1);
    PyModule_AddIntConstant(m, "INIT_K_HOMEBLOCKS_FIXED", 2);
    PyModule_AddIntConstant(m, "INIT_K_HOMEBLOCKS_CONTIGUOUS", 3);
    PyModule_AddIntConstant(m, "INIT_S_BADBLOCKS_LBN_DEF", 8);
    PyModule_AddIntConstant(m, "INIT_S_BADBLOCKS_SEC_DEF", 16);
    PyModule_AddIntConstant(m, "INIT__ACCESSED", 1);
    PyModule_AddIntConstant(m, "INIT__BADBLOCKS_LBN", 2);
    PyModule_AddIntConstant(m, "INIT__BADBLOCKS_SEC", 3);
    PyModule_AddIntConstant(m, "INIT__CLUSTERSIZE", 4);
    PyModule_AddIntConstant(m, "INIT__COMPACTION", 5);
    PyModule_AddIntConstant(m, "INIT__NO_COMPACTION", 6);
    PyModule_AddIntConstant(m, "INIT__DENSITY", 7);
    PyModule_AddIntConstant(m, "INIT__DIRECTORIES", 8);
    PyModule_AddIntConstant(m, "INIT__ERASE", 9);
    PyModule_AddIntConstant(m, "INIT__NO_ERASE", 10);
    PyModule_AddIntConstant(m, "INIT__EXTENSION", 11);
    PyModule_AddIntConstant(m, "INIT__FPROT", 12);
    PyModule_AddIntConstant(m, "INIT__HEADERS", 13);
    PyModule_AddIntConstant(m, "INIT__HIGHWATER", 14);
    PyModule_AddIntConstant(m, "INIT__NO_HIGHWATER", 15);
    PyModule_AddIntConstant(m, "INIT__INDEX_BEGINNING", 16);
    PyModule_AddIntConstant(m, "INIT__INDEX_BLOCK", 17);
    PyModule_AddIntConstant(m, "INIT__INDEX_END", 18);
    PyModule_AddIntConstant(m, "INIT__INDEX_MIDDLE", 19);
    PyModule_AddIntConstant(m, "INIT__INTERCHANGE", 20);
    PyModule_AddIntConstant(m, "INIT__NO_INTERCHANGE", 21);
    PyModule_AddIntConstant(m, "INIT__LABEL_ACCESS", 22);
    PyModule_AddIntConstant(m, "INIT__LABEL_VOLO", 23);
    PyModule_AddIntConstant(m, "INIT__MAXFILES", 24);
    PyModule_AddIntConstant(m, "INIT__OVR_ACCESS", 25);
    PyModule_AddIntConstant(m, "INIT__NO_OVR_ACCESS", 26);
    PyModule_AddIntConstant(m, "INIT__OVR_EXP", 27);
    PyModule_AddIntConstant(m, "INIT__NO_OVR_EXP", 28);
    PyModule_AddIntConstant(m, "INIT__OVR_VOLO", 29);
    PyModule_AddIntConstant(m, "INIT__NO_OVR_VOLO", 30);
    PyModule_AddIntConstant(m, "INIT__OWNER", 31);
    PyModule_AddIntConstant(m, "INIT__READCHECK", 32);
    PyModule_AddIntConstant(m, "INIT__NO_READCHECK", 33);
    PyModule_AddIntConstant(m, "INIT__SIZE", 34);
    PyModule_AddIntConstant(m, "INIT__STRUCTURE_LEVEL_1", 35);
    PyModule_AddIntConstant(m, "INIT__STRUCTURE_LEVEL_2", 36);
    PyModule_AddIntConstant(m, "INIT__STRUCTURE_LEVEL_2_SUB_0", 37);
    PyModule_AddIntConstant(m, "INIT__USER_NAME", 38);
    PyModule_AddIntConstant(m, "INIT__VERIFIED", 39);
    PyModule_AddIntConstant(m, "INIT__NO_VERIFIED", 40);
    PyModule_AddIntConstant(m, "INIT__VPROT", 41);
    PyModule_AddIntConstant(m, "INIT__WINDOW", 42);
    PyModule_AddIntConstant(m, "INIT__WRITECHECK", 43);
    PyModule_AddIntConstant(m, "INIT__NO_WRITECHECK", 44);
    PyModule_AddIntConstant(m, "INIT__MIN_CLASS", 45);
    PyModule_AddIntConstant(m, "INIT__MAX_CLASS", 46);
    PyModule_AddIntConstant(m, "INIT__NO_PROTECTION", 47);
    PyModule_AddIntConstant(m, "INIT__HOMEBLOCKS", 48);
    PyModule_AddIntConstant(m, "INIT__STRUCTURE_LEVEL_5", 49);
    PyModule_AddIntConstant(m, "INIT__SHADOW", 50);
    PyModule_AddIntConstant(m, "INIT__HARDLINKS", 51);
    PyModule_AddIntConstant(m, "INIT__ACCESS_DATES", 52);
    PyModule_AddIntConstant(m, "INIT__SPARE", 53);
    PyModule_AddIntConstant(m, "INIT__VOLUME_LIMIT", 54);
    PyModule_AddIntConstant(m, "INIT__GPT", 55);
    PyModule_AddIntConstant(m, "INIT__NO_GPT", 56);
    PyModule_AddIntConstant(m, "INIT__ERASE_ON_DELETE", 57);
    PyModule_AddIntConstant(m, "INIT__ERASE_ON_INIT", 58);
    PyModule_AddIntConstant(m, "INIT__STRUCTURE_LEVEL_6", 59);
    PyModule_AddIntConstant(m, "INIT__LOGSIZE", 60);
    PyModule_AddIntConstant(m, "INIT__SPECIAL_FILES", 61);
    PyModule_AddIntConstant(m, "INIT__NO_SPECIAL_FILES", 62);
    PyModule_AddIntConstant(m, "INIT__LAST_INIT_ITEM", 63);
    PyModule_AddIntConstant(m, "INIT__MAX_ITEM_CODE", 62);
    PyModule_AddIntConstant(m, "INIT_S_USER_NAME", 12);
    PyModule_AddIntConstant(m, "INIT_S_DEVICE_NAME", 64);
    PyModule_AddIntConstant(m, "INIT_C_MIN_SECURITY_BLKCNT", 6);
    PyModule_AddIntConstant(m, "INIT_C_MIN_GPT_BLKCNT", 34);
    return m;
}