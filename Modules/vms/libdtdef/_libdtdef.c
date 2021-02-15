#include <Python.h>

PyDoc_STRVAR(doc__libdtdef,
"LIBDT definitions");

static struct PyModuleDef _libdtdef_module = {
    PyModuleDef_HEAD_INIT,
    "_libdtdef",
    doc__libdtdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__libdtdef(void) {
    PyObject *m = PyModule_Create(&_libdtdef_module);
    PyModule_AddIntConstant(m, "LIB_K_MONTH_NAME", 0);
    PyModule_AddIntConstant(m, "LIB_K_MONTH_NAME_ABB", 3);
    PyModule_AddIntConstant(m, "LIB_K_WEEKDAY_NAME", 6);
    PyModule_AddIntConstant(m, "LIB_K_WEEKDAY_NAME_ABB", 9);
    PyModule_AddIntConstant(m, "LIB_K_MERIDIEM_INDICATOR", 12);
    PyModule_AddIntConstant(m, "LIB_K_OUTPUT_FORMAT", 1);
    PyModule_AddIntConstant(m, "LIB_K_INPUT_FORMAT", 2);
    PyModule_AddIntConstant(m, "LIB_K_RELATIVE_DAY_NAME", 15);
    PyModule_AddIntConstant(m, "LIB_K_FORMAT_MNEMONICS", 18);
    PyModule_AddIntConstant(m, "LIB_K_LANGUAGE", 4);
    PyModule_AddIntConstant(m, "LIB_K_MONTH_OF_YEAR", 1);
    PyModule_AddIntConstant(m, "LIB_K_DAY_OF_YEAR", 2);
    PyModule_AddIntConstant(m, "LIB_K_HOUR_OF_YEAR", 3);
    PyModule_AddIntConstant(m, "LIB_K_MINUTE_OF_YEAR", 4);
    PyModule_AddIntConstant(m, "LIB_K_SECOND_OF_YEAR", 5);
    PyModule_AddIntConstant(m, "LIB_K_DAY_OF_MONTH", 6);
    PyModule_AddIntConstant(m, "LIB_K_HOUR_OF_MONTH", 7);
    PyModule_AddIntConstant(m, "LIB_K_MINUTE_OF_MONTH", 8);
    PyModule_AddIntConstant(m, "LIB_K_SECOND_OF_MONTH", 9);
    PyModule_AddIntConstant(m, "LIB_K_DAY_OF_WEEK", 10);
    PyModule_AddIntConstant(m, "LIB_K_HOUR_OF_WEEK", 11);
    PyModule_AddIntConstant(m, "LIB_K_MINUTE_OF_WEEK", 12);
    PyModule_AddIntConstant(m, "LIB_K_SECOND_OF_WEEK", 13);
    PyModule_AddIntConstant(m, "LIB_K_HOUR_OF_DAY", 14);
    PyModule_AddIntConstant(m, "LIB_K_MINUTE_OF_DAY", 15);
    PyModule_AddIntConstant(m, "LIB_K_SECOND_OF_DAY", 16);
    PyModule_AddIntConstant(m, "LIB_K_MINUTE_OF_HOUR", 17);
    PyModule_AddIntConstant(m, "LIB_K_SECOND_OF_HOUR", 18);
    PyModule_AddIntConstant(m, "LIB_K_SECOND_OF_MINUTE", 19);
    PyModule_AddIntConstant(m, "LIB_K_JULIAN_DATE", 20);
    PyModule_AddIntConstant(m, "LIB_K_DELTA_WEEKS", 21);
    PyModule_AddIntConstant(m, "LIB_K_DELTA_DAYS", 22);
    PyModule_AddIntConstant(m, "LIB_K_DELTA_HOURS", 23);
    PyModule_AddIntConstant(m, "LIB_K_DELTA_MINUTES", 24);
    PyModule_AddIntConstant(m, "LIB_K_DELTA_SECONDS", 25);
    PyModule_AddIntConstant(m, "LIB_K_DELTA_WEEKS_F", 26);
    PyModule_AddIntConstant(m, "LIB_K_DELTA_DAYS_F", 27);
    PyModule_AddIntConstant(m, "LIB_K_DELTA_HOURS_F", 28);
    PyModule_AddIntConstant(m, "LIB_K_DELTA_MINUTES_F", 29);
    PyModule_AddIntConstant(m, "LIB_K_DELTA_SECONDS_F", 30);
    PyModule_AddIntConstant(m, "LIB_K_MAX_OPERATION", 31);
    PyModule_AddIntConstant(m, "LIB_M_TIME_FIELDS", 0x1L);
    PyModule_AddIntConstant(m, "LIB_M_DATE_FIELDS", 0x2L);
    PyModule_AddIntConstant(m, "LIB_S_DT_PRINT_FIELDS", 1);
    PyModule_AddIntConstant(m, "LIB_M_YEAR", 0x1L);
    PyModule_AddIntConstant(m, "LIB_M_MONTH", 0x2L);
    PyModule_AddIntConstant(m, "LIB_M_DAY", 0x4L);
    PyModule_AddIntConstant(m, "LIB_M_HOUR", 0x8L);
    PyModule_AddIntConstant(m, "LIB_M_MINUTE", 0x10L);
    PyModule_AddIntConstant(m, "LIB_M_SECOND", 0x20L);
    PyModule_AddIntConstant(m, "LIB_M_HUNDREDTHS", 0x40L);
    PyModule_AddIntConstant(m, "LIB_S_DT_DEFAULT_FIELDS", 1);
    return m;
}