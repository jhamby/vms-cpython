#include <Python.h>

PyDoc_STRVAR(doc__iccdef,
"ICC definitions");

static struct PyModuleDef _iccdef_module = {
    PyModuleDef_HEAD_INIT,
    "_iccdef",
    doc__iccdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__iccdef(void) {
    PyObject *m = PyModule_Create(&_iccdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "IOS_ICC_S_IOS_ICC", 20);
    PyModule_AddIntConstant(m, "IOS_ICC_s_parameters", 16);
    PyModule_AddIntConstant(m, "IOS_ICC_s_connect", 16);
    PyModule_AddIntConstant(m, "IOS_ICC_s_receive", 16);
    PyModule_AddIntConstant(m, "IOS_ICC_s_reply", 16);
    PyModule_AddIntConstant(m, "IOS_ICC_s_transceive", 16);
    PyModule_AddIntConstant(m, "IOS_ICC_s_reply_buffer", 8);
    PyModule_AddIntConstant(m, "ICC_C_receive_len", 16);
    PyModule_AddIntConstant(m, "ICC_C_reply_len", 8);
    PyModule_AddIntConstant(m, "ICC_C_transceive_len", 20);
    PyModule_AddIntConstant(m, "ICC_C_MAX_ASSOC_LEN", 31);
    PyModule_AddIntConstant(m, "ICC_C_MAX_CONN_DATA_LEN", 1000);
    PyModule_AddUnsignedLongConstant(m, "ICC_M_Synch_Mode", 0x1UL);
    PyModule_AddIntConstant(m, "ICC_S_ICC_CONNECTION_FLAGS", 1);
    PyModule_AddIntConstant(m, "ICC_C_EV_CONNECT", 0);
    PyModule_AddIntConstant(m, "ICC_C_EV_DISCONNECT", 1);
    PyModule_AddIntConstant(m, "ICC_C_min_event", 0);
    PyModule_AddIntConstant(m, "ICC_C_max_event", 1);
    PyModule_AddIntConstant(m, "ICC_C_DFLT_ASSOC_HANDLE", 1);
    PyModule_AddIntConstant(m, "ICC_C_DEFAULT_MAXFLOWBUFCNT", 5);
    return m;
}