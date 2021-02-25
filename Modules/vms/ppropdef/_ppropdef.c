#include <Python.h>

PyDoc_STRVAR(doc__ppropdef,
"PPROP definitions");

static struct PyModuleDef _ppropdef_module = {
    PyModuleDef_HEAD_INIT,
    "_ppropdef",
    doc__ppropdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__ppropdef(void) {
    PyObject *m = PyModule_Create(&_ppropdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "PPROP_C_PARSE_STYLE_TEMP", 0);
    PyModule_AddIntConstant(m, "PPROP_C_PARSE_STYLE_PERM", 1);
    PyModule_AddIntConstant(m, "PPROP_C_HOME_RAD", 2);
    PyModule_AddIntConstant(m, "PPROP_C_CASE_LOOKUP_TEMP", 3);
    PyModule_AddIntConstant(m, "PPROP_C_CASE_LOOKUP_PERM", 4);
    PyModule_AddIntConstant(m, "PPROP_C_MEDDLE_ENABLE", 5);
    PyModule_AddIntConstant(m, "PPROP_C_MEDDLE", 6);
    PyModule_AddIntConstant(m, "PPROP_C_UNITS", 7);
    PyModule_AddIntConstant(m, "PPROP_C_SS_LOG_ENABLE", 8);
    PyModule_AddIntConstant(m, "PPROP_C_SS_LOG_DISABLE", 9);
    PyModule_AddIntConstant(m, "PPROP_C_SS_LOG_UNLOAD", 10);
    PyModule_AddIntConstant(m, "PPROP_C_TOKEN", 11);
    PyModule_AddIntConstant(m, "PPROP_C_DEADLOCK_WAIT", 12);
    PyModule_AddIntConstant(m, "PPROP_C_SEARCH_SYMLINK_TEMP", 13);
    PyModule_AddIntConstant(m, "PPROP_C_SEARCH_SYMLINK_PERM", 14);
    PyModule_AddIntConstant(m, "PPROP_C_KERNEL_THREAD_LIMIT", 15);
    PyModule_AddIntConstant(m, "PARSE_STYLE_C_ODS2", 0);
    PyModule_AddIntConstant(m, "PARSE_STYLE_C_ODS5", 1);
    PyModule_AddIntConstant(m, "PARSE_STYLE_C_TRADITIONAL", 0);
    PyModule_AddIntConstant(m, "PARSE_STYLE_C_EXTENDED", 1);
    PyModule_AddIntConstant(m, "PPROP_K_CASE_BLIND", 0);
    PyModule_AddIntConstant(m, "PPROP_K_CASE_SENSITIVE", 1);
    PyModule_AddIntConstant(m, "PPROP_K_SEARCH_SYMLINK_NONE", 1);
    PyModule_AddIntConstant(m, "PPROP_K_SEARCH_SYMLINK_ALL", 2);
    PyModule_AddIntConstant(m, "PPROP_K_SEARCH_SYMLINK_NOELLIPS", 3);
    return m;
}