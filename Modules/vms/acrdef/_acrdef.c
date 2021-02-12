#include <Python.h>

PyDoc_STRVAR(doc__acrdef,
"ACR definitions");

static struct PyModuleDef _acrdef_module = {
    PyModuleDef_HEAD_INIT,
    "acrdef",
    doc__acrdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__acrdef(void) {
    PyObject *m = PyModule_Create(&_acrdef_module);
    PyModule_AddIntConstant(m, "ACR_K_VERSION2", 0);
    PyModule_AddIntConstant(m, "ACR_K_VERSION3T", 1);
    PyModule_AddIntConstant(m, "ACR_K_VERSION3", 2);
    PyModule_AddIntConstant(m, "ACR_K_VERSION4", 3);
    PyModule_AddIntConstant(m, "ACR_K_CURVER", 3);
    PyModule_AddIntConstant(m, "ACR_M_PACKET", 0x1L);
    PyModule_AddIntConstant(m, "ACR_M_TYPE", 0xFEL);
    PyModule_AddIntConstant(m, "ACR_M_SUBTYPE", 0xF00L);
    PyModule_AddIntConstant(m, "ACR_M_VERSION", 0x7000L);
    PyModule_AddIntConstant(m, "ACR_M_CUSTOMER", 0x8000L);
    PyModule_AddIntConstant(m, "ACR_K_PRCDEL", 1);
    PyModule_AddIntConstant(m, "ACR_K_PRCPUR", 2);
    PyModule_AddIntConstant(m, "ACR_K_IMGDEL", 3);
    PyModule_AddIntConstant(m, "ACR_K_IMGPUR", 4);
    PyModule_AddIntConstant(m, "ACR_K_SYSINIT", 5);
    PyModule_AddIntConstant(m, "ACR_K_SETTIME", 6);
    PyModule_AddIntConstant(m, "ACR_K_LOGFAIL", 7);
    PyModule_AddIntConstant(m, "ACR_K_PRINT", 8);
    PyModule_AddIntConstant(m, "ACR_K_USER", 9);
    PyModule_AddIntConstant(m, "ACR_K_ENABLE", 10);
    PyModule_AddIntConstant(m, "ACR_K_DISABLE", 11);
    PyModule_AddIntConstant(m, "ACR_K_ALTACM", 12);
    PyModule_AddIntConstant(m, "ACR_K_FILE_FL", 13);
    PyModule_AddIntConstant(m, "ACR_K_FILE_BL", 14);
    PyModule_AddIntConstant(m, "ACR_K_INTERACTIVE", 1);
    PyModule_AddIntConstant(m, "ACR_K_SUBPROCESS", 2);
    PyModule_AddIntConstant(m, "ACR_K_DETACHED", 3);
    PyModule_AddIntConstant(m, "ACR_K_BATCH", 4);
    PyModule_AddIntConstant(m, "ACR_K_NETWORK", 5);
    PyModule_AddIntConstant(m, "ACR_K_ID", 1);
    PyModule_AddIntConstant(m, "ACR_K_RESOURCE", 2);
    PyModule_AddIntConstant(m, "ACR_K_IMAGENAME", 3);
    PyModule_AddIntConstant(m, "ACR_K_FILENAME", 4);
    PyModule_AddIntConstant(m, "ACR_K_USER_DATA", 5);
    PyModule_AddIntConstant(m, "ACR_S_ACRDEF", 4);
    PyModule_AddIntConstant(m, "ACR_S_TYPE", 7);
    PyModule_AddIntConstant(m, "ACR_S_SUBTYPE", 4);
    PyModule_AddIntConstant(m, "ACR_S_VERSION", 3);
    PyModule_AddIntConstant(m, "ACR_K_HDRLEN", 12);
    PyModule_AddIntConstant(m, "ACR_C_HDRLEN", 12);
    PyModule_AddIntConstant(m, "ACR_S_ACRDEF1", 12);
    PyModule_AddIntConstant(m, "ACR_S_SYSTIME", 8);
    PyModule_AddIntConstant(m, "ACR_M_FULLNAME", 0x1L);
    PyModule_AddIntConstant(m, "ACR_M_UIDGID", 0x2L);
    PyModule_AddIntConstant(m, "ACR_M_FILL_1", 0xFCL);
    PyModule_AddIntConstant(m, "ACR_K_IDVAR", 58);
    PyModule_AddIntConstant(m, "ACR_C_IDVAR", 58);
    PyModule_AddIntConstant(m, "ACR_S_ACRDEF2", 58);
    PyModule_AddIntConstant(m, "ACR_S_PRIV", 8);
    PyModule_AddIntConstant(m, "ACR_S_FILL_1", 6);
    PyModule_AddIntConstant(m, "ACR_S_ACRDEF3", 56);
    PyModule_AddIntConstant(m, "ACR_S_LOGIN", 8);
    PyModule_AddIntConstant(m, "ACR_S_ACRDEF4", 260);
    PyModule_AddIntConstant(m, "ACR_S_IMAGENAME", 256);
    PyModule_AddIntConstant(m, "ACR_S_ACRDEF5", 40);
    PyModule_AddIntConstant(m, "ACR_S_QUETIME", 8);
    PyModule_AddIntConstant(m, "ACR_S_BEGTIME", 8);
    PyModule_AddIntConstant(m, "ACR_S_ACRDEF6", 260);
    PyModule_AddIntConstant(m, "ACR_S_FILENAME", 256);
    PyModule_AddIntConstant(m, "ACR_S_ACRDEF7", 260);
    PyModule_AddIntConstant(m, "ACR_S_USER_DATA", 256);
    return m;
}