#include <Python.h>

PyDoc_STRVAR(doc__jbcmsgdef,
"JBCMSG definitions");

static struct PyModuleDef _jbcmsgdef_module = {
    PyModuleDef_HEAD_INIT,
    "_jbcmsgdef",
    doc__jbcmsgdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__jbcmsgdef(void) {
    PyObject *m = PyModule_Create(&_jbcmsgdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "JBC__FACILITY", 4);
    PyModule_AddIntConstant(m, "JBC__NORMAL", 262145);
    PyModule_AddIntConstant(m, "JBC__NOCMKRNL", 272386);
    PyModule_AddIntConstant(m, "JBC__NOOPER", 272530);
    PyModule_AddIntConstant(m, "JBC__NOSYSNAM", 272402);
    PyModule_AddIntConstant(m, "JBC__ILLDEVNAM", 294916);
    PyModule_AddIntConstant(m, "JBC__UNSDEVTYP", 294924);
    PyModule_AddIntConstant(m, "JBC__ILLFILNAM", 294932);
    PyModule_AddIntConstant(m, "JBC__INVQUENAM", 294940);
    PyModule_AddIntConstant(m, "JBC__NOPRIV", 294946);
    PyModule_AddIntConstant(m, "JBC__NOQUEHDR", 294956);
    PyModule_AddIntConstant(m, "JBC__NOQUESPACE", 294962);
    PyModule_AddIntConstant(m, "JBC__NOSUCHQUE", 294970);
    PyModule_AddIntConstant(m, "JBC__NOSUCHJOB", 294978);
    PyModule_AddIntConstant(m, "JBC__NOOPENJOB", 294986);
    PyModule_AddIntConstant(m, "JBC__REFERENCED", 294994);
    PyModule_AddIntConstant(m, "JBC__STARTED", 295002);
    PyModule_AddIntConstant(m, "JBC__INVITMCOD", 295012);
    PyModule_AddIntConstant(m, "JBC__INVFUNCOD", 295020);
    PyModule_AddIntConstant(m, "JBC__EMPTYJOB", 295026);
    PyModule_AddIntConstant(m, "JBC__JOBQUEDIS", 295034);
    PyModule_AddIntConstant(m, "JBC__JOBABORT", 295044);
    PyModule_AddIntConstant(m, "JBC__ACMINVOP", 295052);
    PyModule_AddIntConstant(m, "JBC__INVPARLEN", 295060);
    PyModule_AddIntConstant(m, "JBC__TRMMBXUSE", 295068);
    PyModule_AddIntConstant(m, "JBC__MAXSYMEXD", 295076);
    PyModule_AddIntConstant(m, "JBC__SCTTABFUL", 295084);
    PyModule_AddIntConstant(m, "JBC__CREPRCFAL", 295092);
    PyModule_AddIntConstant(m, "JBC__SYMNTBFUL", 295100);
    PyModule_AddIntConstant(m, "JBC__NODSTQUE", 295106);
    PyModule_AddIntConstant(m, "JBC__INVDSTQUE", 295116);
    PyModule_AddIntConstant(m, "JBC__JOBDELETE", 295124);
    PyModule_AddIntConstant(m, "JBC__NORESTART", 295130);
    PyModule_AddIntConstant(m, "JBC__JOBREQUEUE", 295140);
    PyModule_AddIntConstant(m, "JBC__QUERESET", 295148);
    PyModule_AddIntConstant(m, "JBC__SYSFAIL", 295156);
    PyModule_AddIntConstant(m, "JBC__EXECUTING", 295162);
    PyModule_AddIntConstant(m, "JBC__INVMSGBUF", 295172);
    PyModule_AddIntConstant(m, "JBC__MISREQPAR", 295180);
    PyModule_AddIntConstant(m, "JBC__INVPARVAL", 295188);
    PyModule_AddIntConstant(m, "JBC__INCQUETYP", 295196);
    PyModule_AddIntConstant(m, "JBC__INCDSTQUE", 295204);
    PyModule_AddIntConstant(m, "JBC__JOBQUEENA", 295210);
    PyModule_AddIntConstant(m, "JBC__NOTASSIGN", 295218);
    PyModule_AddIntConstant(m, "JBC__INCOMPLETE", 295226);
    PyModule_AddIntConstant(m, "JBC__INVCHANAM", 295236);
    PyModule_AddIntConstant(m, "JBC__INVFORNAM", 295244);
    PyModule_AddIntConstant(m, "JBC__NOSUCHCHAR", 295250);
    PyModule_AddIntConstant(m, "JBC__NOSUCHFORM", 295258);
    PyModule_AddIntConstant(m, "JBC__DUPFORM", 295266);
    PyModule_AddIntConstant(m, "JBC__INCFORMPAR", 295276);
    PyModule_AddIntConstant(m, "JBC__NOSUCHFILE", 295282);
    PyModule_AddIntConstant(m, "JBC__DELACCESS", 295290);
    PyModule_AddIntConstant(m, "JBC__QUENOTSTOP", 295298);
    PyModule_AddIntConstant(m, "JBC__NOMORECHAR", 295306);
    PyModule_AddIntConstant(m, "JBC__NOMOREFILE", 295314);
    PyModule_AddIntConstant(m, "JBC__NOMOREFORM", 295322);
    PyModule_AddIntConstant(m, "JBC__NOMOREJOB", 295330);
    PyModule_AddIntConstant(m, "JBC__NOMOREQUE", 295338);
    PyModule_AddIntConstant(m, "JBC__NOJOBCTX", 295346);
    PyModule_AddIntConstant(m, "JBC__NOQUECTX", 295354);
    PyModule_AddIntConstant(m, "JBC__NOSUCHNODE", 295362);
    PyModule_AddIntConstant(m, "JBC__GEN_MAX", 295370);
    PyModule_AddIntConstant(m, "JBC__QUE_CLOSED", 295378);
    PyModule_AddIntConstant(m, "JBC__NOSUCHENT", 295386);
    PyModule_AddIntConstant(m, "JBC__NOMOREENT", 295394);
    PyModule_AddIntConstant(m, "JBC__JOBCTLABORT", 295404);
    PyModule_AddIntConstant(m, "JBC__NOTSUPPORTED", 295412);
    PyModule_AddIntConstant(m, "JBC__NOTMEANINGFUL", 295419);
    PyModule_AddIntConstant(m, "JBC__QUEDISABLED", 295426);
    PyModule_AddIntConstant(m, "JBC__NOTDISABLED", 295434);
    PyModule_AddIntConstant(m, "JBC__NOTENAGEN", 295442);
    PyModule_AddIntConstant(m, "JBC__ENABLEQUE", 295448);
    PyModule_AddIntConstant(m, "JBC__QUENOTMOD", 295459);
    PyModule_AddIntConstant(m, "JBC__ATT_MAX", 295466);
    PyModule_AddIntConstant(m, "JBC__ATTNOTAVAIL", 295474);
    PyModule_AddIntConstant(m, "JBC__QEXISTS", 295482);
    PyModule_AddIntConstant(m, "JBC__NOSUCHQMGR", 295490);
    PyModule_AddIntConstant(m, "JBC__JOBNOTEXEC", 295498);
    PyModule_AddIntConstant(m, "JBC__DUPCHARNAME", 295506);
    PyModule_AddIntConstant(m, "JBC__DUPCHARNUM", 295514);
    PyModule_AddIntConstant(m, "JBC__DUPFORMNAME", 295522);
    PyModule_AddIntConstant(m, "JBC__STKNOTCHANGE", 295530);
    PyModule_AddIntConstant(m, "JBC__ITMREMOVED", 295539);
    PyModule_AddIntConstant(m, "JBC__PRIOSMALL", 295547);
    PyModule_AddIntConstant(m, "JBC__QMANMAX", 295552);
    PyModule_AddIntConstant(m, "JBC__NOAUTOSTART", 295560);
    PyModule_AddIntConstant(m, "JBC__NOTALLREQUE", 295568);
    PyModule_AddIntConstant(m, "JBC__NULL1", 295580);
    PyModule_AddIntConstant(m, "JBC__TOOMUCHINFO", 295586);
    PyModule_AddIntConstant(m, "JBC__AUTONOTSTART", 295595);
    PyModule_AddIntConstant(m, "JBC__NULL2", 295602);
    PyModule_AddIntConstant(m, "JBC__QMANNOTSTARTED", 295610);
    PyModule_AddIntConstant(m, "JBC__BUFTOOSMALL", 295616);
    PyModule_AddIntConstant(m, "JBC__INTERNALERROR", 295624);
    PyModule_AddIntConstant(m, "JBC__QMGREXISTS", 295634);
    PyModule_AddIntConstant(m, "JBC__TWOQMGRS", 295642);
    PyModule_AddIntConstant(m, "JBC__INVQMANNAM", 295650);
    PyModule_AddIntConstant(m, "JBC__NOMOREQMGR", 295658);
    PyModule_AddIntConstant(m, "JBC__QMANABORT", 295668);
    PyModule_AddIntConstant(m, "JBC__ACCDISERR", 295939);
    PyModule_AddIntConstant(m, "JBC__ALLOCMEM", 295948);
    PyModule_AddIntConstant(m, "JBC__COMREMJBC", 295956);
    PyModule_AddIntConstant(m, "JBC__INVBLOCK", 295964);
    PyModule_AddIntConstant(m, "JBC__INVMSG", 295970);
    PyModule_AddIntConstant(m, "JBC__NEWQUEUE", 295979);
    PyModule_AddIntConstant(m, "JBC__OPEJBCMBX", 295988);
    PyModule_AddIntConstant(m, "JBC__PRCREAT", 295996);
    PyModule_AddIntConstant(m, "JBC__QUEFORMAT", 296000);
    PyModule_AddIntConstant(m, "JBC__REAJBCMBX", 296012);
    PyModule_AddIntConstant(m, "JBC__REQUEST", 296019);
    PyModule_AddIntConstant(m, "JBC__SETIMR", 296026);
    PyModule_AddIntConstant(m, "JBC__SYMCREPRC", 296034);
    PyModule_AddIntConstant(m, "JBC__SYMDEL", 296042);
    PyModule_AddIntConstant(m, "JBC__WRIRSPMSG", 296050);
    PyModule_AddIntConstant(m, "JBC__WRISMBMBX", 296058);
    PyModule_AddIntConstant(m, "JBC__NFY_COMPLETE", 296067);
    PyModule_AddIntConstant(m, "JBC__NFY_CURRENT", 296075);
    PyModule_AddIntConstant(m, "JBC__NFY_HOLD", 296083);
    PyModule_AddIntConstant(m, "JBC__NFY_PENDING", 296091);
    PyModule_AddIntConstant(m, "JBC__NFY_TIMER", 296099);
    PyModule_AddIntConstant(m, "JBC__STRUCT_LEVEL", 296107);
    PyModule_AddIntConstant(m, "JBC__DIAGNOSTIC", 296112);
    PyModule_AddIntConstant(m, "JBC__DIAG_TEXT", 296120);
    PyModule_AddIntConstant(m, "JBC__DIAG_DATA", 296128);
    PyModule_AddIntConstant(m, "JBC__RESTRICT", 296136);
    PyModule_AddIntConstant(m, "JBC__NFY_FAILURE", 296147);
    PyModule_AddIntConstant(m, "JBC__NFY_CPULIM", 296155);
    PyModule_AddIntConstant(m, "JBC__NFY_WSVAL", 296163);
    PyModule_AddIntConstant(m, "JBC__RESTARTCOM", 296171);
    PyModule_AddIntConstant(m, "JBC__NFY_NOACCESS", 296179);
    PyModule_AddIntConstant(m, "JBC__NFY_CHARAC", 296187);
    PyModule_AddIntConstant(m, "JBC__NFY_NOLOWER", 296195);
    PyModule_AddIntConstant(m, "JBC__NFY_SIZE_MIN", 296203);
    PyModule_AddIntConstant(m, "JBC__NFY_SIZE_MAX", 296211);
    PyModule_AddIntConstant(m, "JBC__NFY_FORM", 296219);
    PyModule_AddIntConstant(m, "JBC__NFY_QUESTATE", 296227);
    PyModule_AddIntConstant(m, "JBC__FAILCREPRC", 296234);
    PyModule_AddIntConstant(m, "JBC__QMANCREPRC", 296242);
    PyModule_AddIntConstant(m, "JBC__INITFAIL", 296252);
    PyModule_AddIntConstant(m, "JBC__QMANDEL", 296258);
    PyModule_AddIntConstant(m, "JBC__NOTIMZONRUL", 296264);
    PyModule_AddIntConstant(m, "JBC__LMFPRCFAIL", 296272);
    PyModule_AddIntConstant(m, "JBC__LMFLICERR", 296280);
    PyModule_AddIntConstant(m, "JBC__LMFERROR", 296288);
    PyModule_AddIntConstant(m, "JBC__ACCNOTENB", 298914);
    return m;
}