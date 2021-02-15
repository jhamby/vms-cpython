#include <Python.h>

PyDoc_STRVAR(doc__lkidef,
"LKI definitions");

static struct PyModuleDef _lkidef_module = {
    PyModuleDef_HEAD_INIT,
    "_lkidef",
    doc__lkidef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__lkidef(void) {
    PyObject *m = PyModule_Create(&_lkidef_module);
    PyModule_AddIntConstant(m, "LKI_K_LENGTH", 24);
    PyModule_AddIntConstant(m, "LKI_C_LENGTH", 24);
    PyModule_AddIntConstant(m, "LKI_K_BR_LENGTH", 56);
    PyModule_AddIntConstant(m, "LKI_C_BR_LENGTH", 56);
    PyModule_AddIntConstant(m, "LKI_S_LKIDEF", 56);
    PyModule_AddIntConstant(m, "LKI_S_RQSTART", 8);
    PyModule_AddIntConstant(m, "LKI_S_RQLENGTH", 8);
    PyModule_AddIntConstant(m, "LKI_S_GRSTART", 8);
    PyModule_AddIntConstant(m, "LKI_S_GRLENGTH", 8);
    PyModule_AddIntConstant(m, "LKI_M_SYSNAM", 0x80000000L);
    PyModule_AddIntConstant(m, "LKI_S_NAMSPACE", 4);
    PyModule_AddIntConstant(m, "LKI_S_STATEF", 3);
    PyModule_AddIntConstant(m, "LKIUSR_K_LENGTH", 20);
    PyModule_AddIntConstant(m, "LKIUSR_C_LENGTH", 20);
    PyModule_AddIntConstant(m, "LKIUSR_K_BLOCKER_START", 20);
    PyModule_AddIntConstant(m, "LKIUSR_S_LKIUSRDEF", 20);
    PyModule_AddIntConstant(m, "LKIUSR_S_START", 8);
    PyModule_AddIntConstant(m, "LKIUSR_S_LENGTH", 8);
    PyModule_AddIntConstant(m, "LKI__RNG_S_RNGDEF", 32);
    PyModule_AddIntConstant(m, "LKI__RNG_S_RQSTART", 8);
    PyModule_AddIntConstant(m, "LKI__RNG_S_RQLENGTH", 8);
    PyModule_AddIntConstant(m, "LKI__RNG_S_GRSTART", 8);
    PyModule_AddIntConstant(m, "LKI__RNG_S_GRLENGTH", 8);
    PyModule_AddIntConstant(m, "LKI_C_GRANTED", 1);
    PyModule_AddIntConstant(m, "LKI_C_CONVERT", 0);
    PyModule_AddIntConstant(m, "LKI_C_WAITING", -1);
    PyModule_AddIntConstant(m, "LKI_C_RETRY", -2);
    PyModule_AddIntConstant(m, "LKI_C_SCSWAIT", -3);
    PyModule_AddIntConstant(m, "LKI_C_RSPNOTQED", -4);
    PyModule_AddIntConstant(m, "LKI_C_RSPQUEUED", -5);
    PyModule_AddIntConstant(m, "LKI_C_RSPGRANTD", -6);
    PyModule_AddIntConstant(m, "LKI_C_RSPDOLOCL", -7);
    PyModule_AddIntConstant(m, "LKI_C_RSPRESEND", -8);
    PyModule_AddIntConstant(m, "LKI_C_LKBTYPE", 1);
    PyModule_AddIntConstant(m, "LKI_C_RSBTYPE", 2);
    PyModule_AddIntConstant(m, "LKI_C_LISTEND", 0);
    PyModule_AddIntConstant(m, "LKI__PID", 256);
    PyModule_AddIntConstant(m, "LKI__STATE", 257);
    PyModule_AddIntConstant(m, "LKI__PARENT", 258);
    PyModule_AddIntConstant(m, "LKI__LCKREFCNT", 259);
    PyModule_AddIntConstant(m, "LKI__LOCKID", 260);
    PyModule_AddIntConstant(m, "LKI__REMLKID", 261);
    PyModule_AddIntConstant(m, "LKI__MSTLKID", 262);
    PyModule_AddIntConstant(m, "LKI__LKID", 263);
    PyModule_AddIntConstant(m, "LKI__CSID", 264);
    PyModule_AddIntConstant(m, "LKI__BRL", 265);
    PyModule_AddIntConstant(m, "LKI__RANGE", 266);
    PyModule_AddIntConstant(m, "LKI__LASTLKB", 267);
    PyModule_AddIntConstant(m, "LKI__NAMSPACE", 512);
    PyModule_AddIntConstant(m, "LKI__RESNAM", 513);
    PyModule_AddIntConstant(m, "LKI__RSBREFCNT", 514);
    PyModule_AddIntConstant(m, "LKI__VALBLK", 515);
    PyModule_AddIntConstant(m, "LKI__SYSTEM", 516);
    PyModule_AddIntConstant(m, "LKI__LCKCOUNT", 517);
    PyModule_AddIntConstant(m, "LKI__BLOCKEDBY", 518);
    PyModule_AddIntConstant(m, "LKI__BLOCKING", 519);
    PyModule_AddIntConstant(m, "LKI__LOCKS", 520);
    PyModule_AddIntConstant(m, "LKI__CVTCOUNT", 521);
    PyModule_AddIntConstant(m, "LKI__WAITCOUNT", 522);
    PyModule_AddIntConstant(m, "LKI__GRANTCOUNT", 523);
    PyModule_AddIntConstant(m, "LKI__MSTCSID", 524);
    PyModule_AddIntConstant(m, "LKI__VALBLKST", 525);
    PyModule_AddIntConstant(m, "LKI__BLOCKEDBY_BR", 526);
    PyModule_AddIntConstant(m, "LKI__BLOCKING_BR", 527);
    PyModule_AddIntConstant(m, "LKI__LOCKS_BR", 528);
    PyModule_AddIntConstant(m, "LKI__BLOCKER_BR", 529);
    PyModule_AddIntConstant(m, "LKI__XVALBLK", 530);
    PyModule_AddIntConstant(m, "LKI__XVALNOTVALID", 531);
    PyModule_AddIntConstant(m, "LKI__LASTRSB", 532);
    PyModule_AddIntConstant(m, "LKISND_K_HDRLEN", 16);
    PyModule_AddIntConstant(m, "LKISND_C_HDRLEN", 16);
    PyModule_AddIntConstant(m, "LKISND_S_LKISNDDEF", 16);
    return m;
}