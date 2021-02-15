#include <Python.h>

PyDoc_STRVAR(doc__clidef,
"CLI definitions");

static struct PyModuleDef _clidef_module = {
    PyModuleDef_HEAD_INIT,
    "_clidef",
    doc__clidef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__clidef(void) {
    PyObject *m = PyModule_Create(&_clidef_module);
    PyModule_AddIntConstant(m, "CLI_M_DEBUG", 0x1L);
    PyModule_AddIntConstant(m, "CLI_M_DBGTRU", 0x2L);
    PyModule_AddIntConstant(m, "CLI_M_VERIFY", 0x4L);
    PyModule_AddIntConstant(m, "CLI_M_BATCH", 0x8L);
    PyModule_AddIntConstant(m, "CLI_M_INDIRECT", 0x10L);
    PyModule_AddIntConstant(m, "CLI_M_VFYINP", 0x20L);
    PyModule_AddIntConstant(m, "CLI_M_TRMVRBLV", 0x300L);
    PyModule_AddIntConstant(m, "CLI_M_DBGEXCP", 0x10000L);
    PyModule_AddIntConstant(m, "CLI_S_CLIDEF", 32);
    PyModule_AddIntConstant(m, "CLI_S_TRMVRBLV", 2);
    PyModule_AddIntConstant(m, "CLI_M_PARMREQ", 0x1L);
    PyModule_AddIntConstant(m, "CLI_M_ABSADR", 0x2L);
    PyModule_AddIntConstant(m, "CLI_M_EXPNAM", 0x4L);
    PyModule_AddIntConstant(m, "CLI_M_LASTVAL", 0x1L);
    PyModule_AddIntConstant(m, "CLI_M_DUMMY", 0x2L);
    PyModule_AddIntConstant(m, "CLI_M_PARMPRS", 0x1L);
    PyModule_AddIntConstant(m, "CLI_M_CONCATINP", 0x2L);
    PyModule_AddIntConstant(m, "CLI_M_MOREINP", 0x4L);
    PyModule_AddIntConstant(m, "CLI_M_PARMDEF", 0x8L);
    PyModule_AddIntConstant(m, "CLI_M_MOREVALS", 0x1L);
    PyModule_AddIntConstant(m, "CLI_M_KEYVALU", 0x2L);
    PyModule_AddIntConstant(m, "CLI_K_REQDESC", 28);
    PyModule_AddIntConstant(m, "CLI_C_REQDESC", 28);
    PyModule_AddIntConstant(m, "CLI_S_CLIDEF1", 28);
    PyModule_AddIntConstant(m, "CLI_S_SUBTYP", 4);
    PyModule_AddIntConstant(m, "CLI_S_PRITYP", 4);
    PyModule_AddIntConstant(m, "CLI_S_RQDESC", 8);
    PyModule_AddIntConstant(m, "CLI_S_CLIDEF2", 36);
    PyModule_AddIntConstant(m, "CLI_S_NAMDESC", 8);
    PyModule_AddIntConstant(m, "CLI_S_VALDESC", 8);
    PyModule_AddIntConstant(m, "CLI_S_TABDESC", 8);
    PyModule_AddIntConstant(m, "CLI_S_CLIDEF3", 12);
    PyModule_AddIntConstant(m, "CLI_S_CLIDEF4", 8);
    PyModule_AddIntConstant(m, "CLI_M_NOWAIT", 0x1L);
    PyModule_AddIntConstant(m, "CLI_M_NOCLISYM", 0x2L);
    PyModule_AddIntConstant(m, "CLI_M_NOLOGNAM", 0x4L);
    PyModule_AddIntConstant(m, "CLI_M_NOKEYPAD", 0x8L);
    PyModule_AddIntConstant(m, "CLI_M_NOTIFY", 0x10L);
    PyModule_AddIntConstant(m, "CLI_M_NOCONTROL", 0x20L);
    PyModule_AddIntConstant(m, "CLI_M_TRUSTED", 0x40L);
    PyModule_AddIntConstant(m, "CLI_M_AUTHPRIV", 0x80L);
    PyModule_AddIntConstant(m, "CLI_M_SUBSYSTEM", 0x100L);
    PyModule_AddIntConstant(m, "CLI_M_DETACHED", 0x200L);
    PyModule_AddIntConstant(m, "CLI_K_SPAWN_VERSION", 1);
    PyModule_AddIntConstant(m, "CLI_C_SPAWN_VERSION", 1);
    PyModule_AddIntConstant(m, "CLI_K_SRVDESC", 88);
    PyModule_AddIntConstant(m, "CLI_C_SRVDESC", 88);
    PyModule_AddIntConstant(m, "CLI_S_CLIDEF5", 88);
    PyModule_AddIntConstant(m, "CLI_S_CMDSTR", 8);
    PyModule_AddIntConstant(m, "CLI_S_INPUT", 8);
    PyModule_AddIntConstant(m, "CLI_S_OUTPUT", 8);
    PyModule_AddIntConstant(m, "CLI_S_PRCNAM", 8);
    PyModule_AddIntConstant(m, "CLI_S_PROMPT", 8);
    PyModule_AddIntConstant(m, "CLI_S_CLI", 8);
    PyModule_AddIntConstant(m, "CLI_S_TABLE", 8);
    PyModule_AddIntConstant(m, "CLI_M_ALLOCCUR", 0x1L);
    PyModule_AddIntConstant(m, "CLI_M_QDUSRV", 0x2L);
    PyModule_AddIntConstant(m, "CLI_M_QDEXPA", 0x4L);
    PyModule_AddIntConstant(m, "CLI_M_QUALTRU", 0x1L);
    PyModule_AddIntConstant(m, "CLI_M_QUALEXP", 0x2L);
    PyModule_AddIntConstant(m, "CLI_K_QUALDEF", 20);
    PyModule_AddIntConstant(m, "CLI_C_QUALDEF", 20);
    PyModule_AddIntConstant(m, "CLI_K_QDBITS", 20);
    PyModule_AddIntConstant(m, "CLI_C_QDBITS", 20);
    PyModule_AddIntConstant(m, "CLI_S_CLIDEF6", 24);
    PyModule_AddIntConstant(m, "CLI_S_QDVALDESC", 8);
    PyModule_AddIntConstant(m, "CLI_K_WORKAREA", 128);
    PyModule_AddIntConstant(m, "CLI_C_WORKAREA", 128);
    PyModule_AddIntConstant(m, "CLI_K_UTILOPR", 0);
    PyModule_AddIntConstant(m, "CLI_K_INPSPEC", 1);
    PyModule_AddIntConstant(m, "CLI_K_OUTSPEC", 2);
    PyModule_AddIntConstant(m, "CLI_K_PARDONE", 3);
    PyModule_AddIntConstant(m, "CLI_K_VALCONV", 4);
    PyModule_AddIntConstant(m, "CLI_K_CLINT", 5);
    PyModule_AddIntConstant(m, "CLI_K_INITPRS", 0);
    PyModule_AddIntConstant(m, "CLI_K_GETCMD", 1);
    PyModule_AddIntConstant(m, "CLI_K_GETQUAL", 2);
    PyModule_AddIntConstant(m, "CLI_K_GETOPT", 3);
    PyModule_AddIntConstant(m, "CLI_K_GETLINE", 4);
    PyModule_AddIntConstant(m, "CLI_K_CLISERV", 5);
    PyModule_AddIntConstant(m, "CLI_K_INPUT1", 16);
    PyModule_AddIntConstant(m, "CLI_K_INPUT2", 17);
    PyModule_AddIntConstant(m, "CLI_K_INPUT3", 18);
    PyModule_AddIntConstant(m, "CLI_K_INPUT4", 19);
    PyModule_AddIntConstant(m, "CLI_K_OUTPUT1", 32);
    PyModule_AddIntConstant(m, "CLI_K_OUTPUT2", 33);
    PyModule_AddIntConstant(m, "CLI_K_OUTPUT3", 34);
    PyModule_AddIntConstant(m, "CLI_K_OUTPUT4", 35);
    PyModule_AddIntConstant(m, "CLI_K_ENDPRM1", 48);
    PyModule_AddIntConstant(m, "CLI_K_ENDPRM2", 49);
    PyModule_AddIntConstant(m, "CLI_K_ENDPRM3", 50);
    PyModule_AddIntConstant(m, "CLI_K_ENDPRM4", 51);
    PyModule_AddIntConstant(m, "CLI_K_NUMERVAL", 64);
    PyModule_AddIntConstant(m, "CLI_K_ASCIIVAL", 65);
    PyModule_AddIntConstant(m, "CLI_K_KEYWORD", 66);
    PyModule_AddIntConstant(m, "CLI_K_KEYVAL", 67);
    PyModule_AddIntConstant(m, "CLI_K_FILSPEC", 68);
    PyModule_AddIntConstant(m, "CLI_K_PRESENT", 80);
    PyModule_AddIntConstant(m, "CLI_K_GETVALUE", 81);
    PyModule_AddIntConstant(m, "CLI_K_ENDPARSE", 82);
    PyModule_AddIntConstant(m, "CLI_K_DCLPARSE", 83);
    PyModule_AddIntConstant(m, "CLI_K_DISPATCH", 84);
    PyModule_AddIntConstant(m, "CLI_K_NEXTQUAL", 85);
    PyModule_AddIntConstant(m, "CLI_S_CLIDEF7", 128);
    PyModule_AddIntConstant(m, "CLI_S_WORKAREA", 128);
    PyModule_AddIntConstant(m, "CLI_S_CLIDEF8", 8);
    return m;
}