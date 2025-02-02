#include <Python.h>

PyDoc_STRVAR(doc__dcdef,
"DC definitions");

static struct PyModuleDef _dcdef_module = {
    PyModuleDef_HEAD_INIT,
    "_dcdef",
    doc__dcdef,
    -1,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC
PyInit__dcdef(void) {
    PyObject *m = PyModule_Create(&_dcdef_module);
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddIntConstant(m, "AT__MBA", 0);
    PyModule_AddIntConstant(m, "AT__UBA", 1);
    PyModule_AddIntConstant(m, "AT__DR", 2);
    PyModule_AddIntConstant(m, "AT__MPM", 3);
    PyModule_AddIntConstant(m, "AT__CI", 4);
    PyModule_AddIntConstant(m, "AT__NULL", 5);
    PyModule_AddIntConstant(m, "AT__BDA", 6);
    PyModule_AddIntConstant(m, "AT__DMB32", 7);
    PyModule_AddIntConstant(m, "AT__DRB32", 8);
    PyModule_AddIntConstant(m, "AT__BVP", 9);
    PyModule_AddIntConstant(m, "AT__BVP_SSP", 10);
    PyModule_AddIntConstant(m, "AT__BVP_NIP", 11);
    PyModule_AddIntConstant(m, "AT__KA410", 12);
    PyModule_AddIntConstant(m, "AT__KA420", 12);
    PyModule_AddIntConstant(m, "AT__GENBI", 13);
    PyModule_AddIntConstant(m, "AT__NBI", 14);
    PyModule_AddIntConstant(m, "AT__DISK9", 15);
    PyModule_AddIntConstant(m, "AT__XBI", 16);
    PyModule_AddIntConstant(m, "AT__TERM9", 17);
    PyModule_AddIntConstant(m, "AT__TAPE9", 18);
    PyModule_AddIntConstant(m, "AT__PRTR9", 19);
    PyModule_AddIntConstant(m, "AT__SFUN9", 20);
    PyModule_AddIntConstant(m, "AT__USER9", 21);
    PyModule_AddIntConstant(m, "AT__MBUSIO", 22);
    PyModule_AddIntConstant(m, "AT__MBUSGFX", 23);
    PyModule_AddIntConstant(m, "AT__KA640", 24);
    PyModule_AddIntConstant(m, "AT__XWATCH", 25);
    PyModule_AddIntConstant(m, "AT__XBI_PLUS_XMI", 26);
    PyModule_AddIntConstant(m, "AT__XBI_PLUS_BI", 27);
    PyModule_AddIntConstant(m, "AT__XJA", 28);
    PyModule_AddIntConstant(m, "AT__HSX50", 29);
    PyModule_AddIntConstant(m, "AT__KDM70", 29);
    PyModule_AddIntConstant(m, "AT__NI", 30);
    PyModule_AddIntConstant(m, "AT__KA43", 31);
    PyModule_AddIntConstant(m, "AT__SJA", 32);
    PyModule_AddIntConstant(m, "AT__GENXMI", 33);
    PyModule_AddIntConstant(m, "AT__KA440", 34);
    PyModule_AddIntConstant(m, "AT__KA46", 34);
    PyModule_AddIntConstant(m, "AT__KA520", 35);
    PyModule_AddIntConstant(m, "AT__XSA", 36);
    PyModule_AddIntConstant(m, "AT__XZA", 37);
    PyModule_AddIntConstant(m, "AT__XZA_SCSI", 37);
    PyModule_AddIntConstant(m, "AT__VME", 38);
    PyModule_AddIntConstant(m, "AT__IOP", 39);
    PyModule_AddIntConstant(m, "AT__LAMB", 40);
    PyModule_AddIntConstant(m, "AT__KA49", 41);
    PyModule_AddIntConstant(m, "AT__TC", 42);
    PyModule_AddIntConstant(m, "AT__X1303", 43);
    PyModule_AddIntConstant(m, "AT__XMI", 44);
    PyModule_AddIntConstant(m, "AT__FBUS", 45);
    PyModule_AddIntConstant(m, "AT__COREIO", 46);
    PyModule_AddIntConstant(m, "AT__KA0202", 47);
    PyModule_AddIntConstant(m, "AT__KA0202_LBUS", 48);
    PyModule_AddIntConstant(m, "AT__KA0302", 49);
    PyModule_AddIntConstant(m, "AT__KA0402", 50);
    PyModule_AddIntConstant(m, "AT__TURBO_SCSI", 51);
    PyModule_AddIntConstant(m, "AT__CIMNA", 52);
    PyModule_AddIntConstant(m, "AT__XZA_DSSI", 53);
    PyModule_AddIntConstant(m, "AT__DEMNA", 54);
    PyModule_AddIntConstant(m, "AT__FFA", 55);
    PyModule_AddIntConstant(m, "AT__KA0602", 56);
    PyModule_AddIntConstant(m, "AT__EISA", 57);
    PyModule_AddIntConstant(m, "AT__VTI_COMBO", 58);
    PyModule_AddIntConstant(m, "AT__KA0702", 64);
    PyModule_AddIntConstant(m, "AT__TC_MULTI_NI", 65);
    PyModule_AddIntConstant(m, "AT__AHA_1742A", 66);
    PyModule_AddIntConstant(m, "AT__KA0902", 67);
    PyModule_AddIntConstant(m, "AT__PCI", 68);
    PyModule_AddIntConstant(m, "AT__KA0802", 69);
    PyModule_AddIntConstant(m, "AT__MULTIFUNCTION_PCI", 70);
    PyModule_AddIntConstant(m, "AT__ISA", 71);
    PyModule_AddIntConstant(m, "AT__XBUS", 72);
    PyModule_AddIntConstant(m, "AT__KA0C05", 73);
    PyModule_AddIntConstant(m, "AT__KA0E04", 74);
    PyModule_AddIntConstant(m, "AT__KA0D02", 75);
    PyModule_AddIntConstant(m, "AT__THIRDPARTY0", 76);
    PyModule_AddIntConstant(m, "AT__THIRDPARTY1", 77);
    PyModule_AddIntConstant(m, "AT__THIRDPARTY2", 78);
    PyModule_AddIntConstant(m, "AT__THIRDPARTY3", 79);
    PyModule_AddIntConstant(m, "AT__THIRDPARTY4", 80);
    PyModule_AddIntConstant(m, "AT__THIRDPARTY5", 81);
    PyModule_AddIntConstant(m, "AT__THIRDPARTY6", 82);
    PyModule_AddIntConstant(m, "AT__THIRDPARTY7", 83);
    PyModule_AddIntConstant(m, "AT__MULTIFUNCTION_ISA", 84);
    PyModule_AddIntConstant(m, "AT__KA0F05", 85);
    PyModule_AddIntConstant(m, "AT__LMCP", 86);
    PyModule_AddIntConstant(m, "AT__TIOP", 87);
    PyModule_AddIntConstant(m, "AT__ITIOP", 88);
    PyModule_AddIntConstant(m, "AT__KA1102", 89);
    PyModule_AddIntConstant(m, "AT__KA1504", 90);
    PyModule_AddIntConstant(m, "AT__HPC", 91);
    PyModule_AddIntConstant(m, "AT__PCMCIA", 92);
    PyModule_AddIntConstant(m, "AT__KA1402", 93);
    PyModule_AddIntConstant(m, "AT__KA0905", 94);
    PyModule_AddIntConstant(m, "AT__KA1802", 95);
    PyModule_AddIntConstant(m, "AT__KA1805", 96);
    PyModule_AddIntConstant(m, "AT__MEMCHAN", 97);
    PyModule_AddIntConstant(m, "AT__KA1B02", 98);
    PyModule_AddIntConstant(m, "AT__KA1B05", 99);
    PyModule_AddIntConstant(m, "AT__KA1A05", 100);
    PyModule_AddIntConstant(m, "AT__KA1605", 101);
    PyModule_AddIntConstant(m, "AT__MC_BUS", 102);
    PyModule_AddIntConstant(m, "AT__KA1105", 103);
    PyModule_AddIntConstant(m, "AT__KA1702", 104);
    PyModule_AddIntConstant(m, "AT__KA1E07", 105);
    PyModule_AddIntConstant(m, "AT__KA2005", 106);
    PyModule_AddIntConstant(m, "AT__KA2405", 107);
    PyModule_AddIntConstant(m, "AT__KA2208", 108);
    PyModule_AddIntConstant(m, "AT__KA2508", 109);
    PyModule_AddIntConstant(m, "AT__KA2308", 110);
    PyModule_AddIntConstant(m, "AT__WFQBB", 111);
    PyModule_AddIntConstant(m, "AT__WFIOP", 112);
    PyModule_AddIntConstant(m, "AT__WFPCA", 113);
    PyModule_AddIntConstant(m, "AT__KA2608", 114);
    PyModule_AddIntConstant(m, "AT__KA270F", 115);
    PyModule_AddIntConstant(m, "AT__IO7", 116);
    PyModule_AddIntConstant(m, "AT__I2000", 117);
    PyModule_AddIntConstant(m, "AT__ACPI_IA64_PLTFRM", 118);
    PyModule_AddIntConstant(m, "AT__ACPI_IA64_CONTAIN", 119);
    PyModule_AddIntConstant(m, "AT__ACPI_IA64_SYSBUS", 120);
    PyModule_AddIntConstant(m, "AT__ACPI_IA64_BUSLESS", 121);
    PyModule_AddIntConstant(m, "AT__ACPI_IA64_IOC", 122);
    PyModule_AddIntConstant(m, "AT__PCIE", 123);
    PyModule_AddIntConstant(m, "DC__ANY", 0);
    PyModule_AddIntConstant(m, "DC__DISK", 1);
    PyModule_AddIntConstant(m, "DC__TAPE", 2);
    PyModule_AddIntConstant(m, "DC__SCOM", 32);
    PyModule_AddIntConstant(m, "DC__CARD", 65);
    PyModule_AddIntConstant(m, "DC__TERM", 66);
    PyModule_AddIntConstant(m, "DC__LP", 67);
    PyModule_AddIntConstant(m, "DC__WORKSTATION", 70);
    PyModule_AddIntConstant(m, "DC__REALTIME", 96);
    PyModule_AddIntConstant(m, "DC__DECVOICE", 97);
    PyModule_AddIntConstant(m, "DC__AUDIO", 98);
    PyModule_AddIntConstant(m, "DC__VIDEO", 99);
    PyModule_AddIntConstant(m, "DC__BUS", 128);
    PyModule_AddIntConstant(m, "DC__MAILBOX", 160);
    PyModule_AddIntConstant(m, "DC__REMCSL_STORAGE", 170);
    PyModule_AddIntConstant(m, "DC__MISC", 200);
    PyModule_AddIntConstant(m, "DT__RK06", 1);
    PyModule_AddIntConstant(m, "DT__RK07", 2);
    PyModule_AddIntConstant(m, "DT__RP04", 3);
    PyModule_AddIntConstant(m, "DT__RP05", 4);
    PyModule_AddIntConstant(m, "DT__RP06", 5);
    PyModule_AddIntConstant(m, "DT__RM03", 6);
    PyModule_AddIntConstant(m, "DT__RP07", 7);
    PyModule_AddIntConstant(m, "DT__RP07HT", 8);
    PyModule_AddIntConstant(m, "DT__RL01", 9);
    PyModule_AddIntConstant(m, "DT__RL02", 10);
    PyModule_AddIntConstant(m, "DT__RX02", 11);
    PyModule_AddIntConstant(m, "DT__RX04", 12);
    PyModule_AddIntConstant(m, "DT__RM80", 13);
    PyModule_AddIntConstant(m, "DT__TU58", 14);
    PyModule_AddIntConstant(m, "DT__RM05", 15);
    PyModule_AddIntConstant(m, "DT__RX01", 16);
    PyModule_AddIntConstant(m, "DT__ML11", 17);
    PyModule_AddIntConstant(m, "DT__RB02", 18);
    PyModule_AddIntConstant(m, "DT__RB80", 19);
    PyModule_AddIntConstant(m, "DT__RA80", 20);
    PyModule_AddIntConstant(m, "DT__RA81", 21);
    PyModule_AddIntConstant(m, "DT__RA60", 22);
    PyModule_AddIntConstant(m, "DT__RZ01", 23);
    PyModule_AddIntConstant(m, "DT__RC25", 23);
    PyModule_AddIntConstant(m, "DT__RZF01", 24);
    PyModule_AddIntConstant(m, "DT__RCF25", 24);
    PyModule_AddIntConstant(m, "DT__RD51", 25);
    PyModule_AddIntConstant(m, "DT__RX50", 26);
    PyModule_AddIntConstant(m, "DT__RD52", 27);
    PyModule_AddIntConstant(m, "DT__RD53", 28);
    PyModule_AddIntConstant(m, "DT__RD26", 29);
    PyModule_AddIntConstant(m, "DT__RA82", 30);
    PyModule_AddIntConstant(m, "DT__RD31", 31);
    PyModule_AddIntConstant(m, "DT__RD54", 32);
    PyModule_AddIntConstant(m, "DT__CRX50", 33);
    PyModule_AddIntConstant(m, "DT__RRD50", 34);
    PyModule_AddIntConstant(m, "DT__GENERIC_DU", 35);
    PyModule_AddIntConstant(m, "DT__RX33", 36);
    PyModule_AddIntConstant(m, "DT__RX18", 37);
    PyModule_AddIntConstant(m, "DT__RA70", 38);
    PyModule_AddIntConstant(m, "DT__RA90", 39);
    PyModule_AddIntConstant(m, "DT__RD32", 40);
    PyModule_AddIntConstant(m, "DT__DISK9", 41);
    PyModule_AddIntConstant(m, "DT__RX35", 42);
    PyModule_AddIntConstant(m, "DT__RF30", 43);
    PyModule_AddIntConstant(m, "DT__RF70", 44);
    PyModule_AddIntConstant(m, "DT__RF71", 44);
    PyModule_AddIntConstant(m, "DT__RD33", 45);
    PyModule_AddIntConstant(m, "DT__ESE20", 46);
    PyModule_AddIntConstant(m, "DT__TU56", 47);
    PyModule_AddIntConstant(m, "DT__RZ22", 48);
    PyModule_AddIntConstant(m, "DT__RZ23", 49);
    PyModule_AddIntConstant(m, "DT__RZ24", 50);
    PyModule_AddIntConstant(m, "DT__RZ55", 51);
    PyModule_AddIntConstant(m, "DT__RRD40S", 52);
    PyModule_AddIntConstant(m, "DT__RRD40", 53);
    PyModule_AddIntConstant(m, "DT__GENERIC_DK", 54);
    PyModule_AddIntConstant(m, "DT__RX23", 55);
    PyModule_AddIntConstant(m, "DT__RF31", 56);
    PyModule_AddIntConstant(m, "DT__RF72", 57);
    PyModule_AddIntConstant(m, "DT__RAM_DISK", 58);
    PyModule_AddIntConstant(m, "DT__RZ25", 59);
    PyModule_AddIntConstant(m, "DT__RZ56", 60);
    PyModule_AddIntConstant(m, "DT__RZ57", 61);
    PyModule_AddIntConstant(m, "DT__RX23S", 62);
    PyModule_AddIntConstant(m, "DT__RX33S", 63);
    PyModule_AddIntConstant(m, "DT__RA92", 64);
    PyModule_AddIntConstant(m, "DT__SSTRIPE", 65);
    PyModule_AddIntConstant(m, "DT__RZ23L", 66);
    PyModule_AddIntConstant(m, "DT__RX26", 67);
    PyModule_AddIntConstant(m, "DT__RZ57I", 68);
    PyModule_AddIntConstant(m, "DT__RZ31", 69);
    PyModule_AddIntConstant(m, "DT__RZ58", 70);
    PyModule_AddIntConstant(m, "DT__SCSI_MO", 71);
    PyModule_AddIntConstant(m, "DT__RWZ01", 71);
    PyModule_AddIntConstant(m, "DT__RRD42", 72);
    PyModule_AddIntConstant(m, "DT__CD_LOADER_1", 73);
    PyModule_AddIntConstant(m, "DT__ESE25", 74);
    PyModule_AddIntConstant(m, "DT__RFH31", 75);
    PyModule_AddIntConstant(m, "DT__RFH72", 76);
    PyModule_AddIntConstant(m, "DT__RF73", 77);
    PyModule_AddIntConstant(m, "DT__RFH73", 78);
    PyModule_AddIntConstant(m, "DT__RA72", 79);
    PyModule_AddIntConstant(m, "DT__RA71", 80);
    PyModule_AddIntConstant(m, "DT__RAH72", 80);
    PyModule_AddIntConstant(m, "DT__RF32", 81);
    PyModule_AddIntConstant(m, "DT__RF35", 81);
    PyModule_AddIntConstant(m, "DT__RFH32", 82);
    PyModule_AddIntConstant(m, "DT__RFH35", 82);
    PyModule_AddIntConstant(m, "DT__RFF31", 83);
    PyModule_AddIntConstant(m, "DT__RF31F", 83);
    PyModule_AddIntConstant(m, "DT__RZ72", 84);
    PyModule_AddIntConstant(m, "DT__RZ73", 85);
    PyModule_AddIntConstant(m, "DT__RZ35", 86);
    PyModule_AddIntConstant(m, "DT__RZ24L", 87);
    PyModule_AddIntConstant(m, "DT__RZ25L", 88);
    PyModule_AddIntConstant(m, "DT__RZ55L", 89);
    PyModule_AddIntConstant(m, "DT__RZ56L", 90);
    PyModule_AddIntConstant(m, "DT__RZ57L", 91);
    PyModule_AddIntConstant(m, "DT__RA73", 92);
    PyModule_AddIntConstant(m, "DT__RZ26", 93);
    PyModule_AddIntConstant(m, "DT__RZ36", 94);
    PyModule_AddIntConstant(m, "DT__RZ74", 95);
    PyModule_AddIntConstant(m, "DT__ESE52", 96);
    PyModule_AddIntConstant(m, "DT__ESE56", 97);
    PyModule_AddIntConstant(m, "DT__ESE58", 98);
    PyModule_AddIntConstant(m, "DT__RZ27", 99);
    PyModule_AddIntConstant(m, "DT__RZ37", 100);
    PyModule_AddIntConstant(m, "DT__RZ34L", 101);
    PyModule_AddIntConstant(m, "DT__RZ35L", 102);
    PyModule_AddIntConstant(m, "DT__RZ36L", 103);
    PyModule_AddIntConstant(m, "DT__RZ38", 104);
    PyModule_AddIntConstant(m, "DT__RZ75", 105);
    PyModule_AddIntConstant(m, "DT__RZ59", 106);
    PyModule_AddIntConstant(m, "DT__RZ13", 107);
    PyModule_AddIntConstant(m, "DT__RZ14", 108);
    PyModule_AddIntConstant(m, "DT__RZ15", 109);
    PyModule_AddIntConstant(m, "DT__RZ16", 110);
    PyModule_AddIntConstant(m, "DT__RZ17", 111);
    PyModule_AddIntConstant(m, "DT__RZ18", 112);
    PyModule_AddIntConstant(m, "DT__EZ51", 113);
    PyModule_AddIntConstant(m, "DT__EZ52", 114);
    PyModule_AddIntConstant(m, "DT__EZ53", 115);
    PyModule_AddIntConstant(m, "DT__EZ54", 116);
    PyModule_AddIntConstant(m, "DT__EZ58", 117);
    PyModule_AddIntConstant(m, "DT__EF51", 118);
    PyModule_AddIntConstant(m, "DT__EF52", 119);
    PyModule_AddIntConstant(m, "DT__EF53", 120);
    PyModule_AddIntConstant(m, "DT__EF54", 121);
    PyModule_AddIntConstant(m, "DT__EF58", 122);
    PyModule_AddIntConstant(m, "DT__RF36", 123);
    PyModule_AddIntConstant(m, "DT__RF37", 124);
    PyModule_AddIntConstant(m, "DT__RF74", 125);
    PyModule_AddIntConstant(m, "DT__RF75", 126);
    PyModule_AddIntConstant(m, "DT__HSZ10", 127);
    PyModule_AddIntConstant(m, "DT__RZ28", 128);
    PyModule_AddIntConstant(m, "DT__GENERIC_RX", 180);
    PyModule_AddIntConstant(m, "DT__FD1", 129);
    PyModule_AddIntConstant(m, "DT__FD2", 130);
    PyModule_AddIntConstant(m, "DT__FD3", 131);
    PyModule_AddIntConstant(m, "DT__FD4", 132);
    PyModule_AddIntConstant(m, "DT__FD5", 133);
    PyModule_AddIntConstant(m, "DT__FD6", 134);
    PyModule_AddIntConstant(m, "DT__FD7", 135);
    PyModule_AddIntConstant(m, "DT__FD8", 136);
    PyModule_AddIntConstant(m, "DT__RZ29", 137);
    PyModule_AddIntConstant(m, "DT__RZ26L", 138);
    PyModule_AddIntConstant(m, "DT__RRD43", 139);
    PyModule_AddIntConstant(m, "DT__RRD44", 140);
    PyModule_AddIntConstant(m, "DT__HSX00", 141);
    PyModule_AddIntConstant(m, "DT__HSX01", 142);
    PyModule_AddIntConstant(m, "DT__RZ26B", 143);
    PyModule_AddIntConstant(m, "DT__RZ27B", 144);
    PyModule_AddIntConstant(m, "DT__RZ28B", 145);
    PyModule_AddIntConstant(m, "DT__RZ29B", 146);
    PyModule_AddIntConstant(m, "DT__RZ73B", 147);
    PyModule_AddIntConstant(m, "DT__RZ74B", 148);
    PyModule_AddIntConstant(m, "DT__RZ75B", 149);
    PyModule_AddIntConstant(m, "DT__RWZ21", 150);
    PyModule_AddIntConstant(m, "DT__RZ27L", 151);
    PyModule_AddIntConstant(m, "DT__HSZ20", 152);
    PyModule_AddIntConstant(m, "DT__HSZ40", 153);
    PyModule_AddIntConstant(m, "DT__HSZ15", 154);
    PyModule_AddIntConstant(m, "DT__RZ26M", 155);
    PyModule_AddIntConstant(m, "DT__RW504", 156);
    PyModule_AddIntConstant(m, "DT__RW510", 157);
    PyModule_AddIntConstant(m, "DT__RW514", 158);
    PyModule_AddIntConstant(m, "DT__RW516", 159);
    PyModule_AddIntConstant(m, "DT__RWZ52", 160);
    PyModule_AddIntConstant(m, "DT__RWZ53", 161);
    PyModule_AddIntConstant(m, "DT__RWZ54", 162);
    PyModule_AddIntConstant(m, "DT__RWZ31", 163);
    PyModule_AddIntConstant(m, "DT__EZ31", 164);
    PyModule_AddIntConstant(m, "DT__EZ32", 165);
    PyModule_AddIntConstant(m, "DT__EZ33", 166);
    PyModule_AddIntConstant(m, "DT__EZ34", 167);
    PyModule_AddIntConstant(m, "DT__EZ35", 168);
    PyModule_AddIntConstant(m, "DT__EZ31L", 169);
    PyModule_AddIntConstant(m, "DT__EZ32L", 170);
    PyModule_AddIntConstant(m, "DT__EZ33L", 171);
    PyModule_AddIntConstant(m, "DT__RZ28L", 172);
    PyModule_AddIntConstant(m, "DT__RWZ51", 173);
    PyModule_AddIntConstant(m, "DT__EZ56R", 174);
    PyModule_AddIntConstant(m, "DT__RAID0", 175);
    PyModule_AddIntConstant(m, "DT__RAID5", 176);
    PyModule_AddIntConstant(m, "DT__CONSOLE_CALLBACK", 177);
    PyModule_AddIntConstant(m, "DT__FILES_64", 178);
    PyModule_AddIntConstant(m, "DT__SWXCR", 179);
    PyModule_AddIntConstant(m, "DT__SNAPPY_DISK", 180);
    PyModule_AddIntConstant(m, "DT__SNAPPY_POOL", 181);
    PyModule_AddIntConstant(m, "DT__USB_CB_DISK", 182);
    PyModule_AddIntConstant(m, "DT__TE16", 1);
    PyModule_AddIntConstant(m, "DT__TU45", 2);
    PyModule_AddIntConstant(m, "DT__TU77", 3);
    PyModule_AddIntConstant(m, "DT__TS11", 4);
    PyModule_AddIntConstant(m, "DT__TU78", 5);
    PyModule_AddIntConstant(m, "DT__TA78", 6);
    PyModule_AddIntConstant(m, "DT__TU80", 7);
    PyModule_AddIntConstant(m, "DT__TU81", 8);
    PyModule_AddIntConstant(m, "DT__TA81", 9);
    PyModule_AddIntConstant(m, "DT__TK50", 10);
    PyModule_AddIntConstant(m, "DT__MR_TU70", 11);
    PyModule_AddIntConstant(m, "DT__MR_TU72", 12);
    PyModule_AddIntConstant(m, "DT__MW_TSU05", 13);
    PyModule_AddIntConstant(m, "DT__MW_TSV05", 14);
    PyModule_AddIntConstant(m, "DT__TK70", 15);
    PyModule_AddIntConstant(m, "DT__RV20", 16);
    PyModule_AddIntConstant(m, "DT__RV80", 16);
    PyModule_AddIntConstant(m, "DT__TK60", 17);
    PyModule_AddIntConstant(m, "DT__GENERIC_TU", 18);
    PyModule_AddIntConstant(m, "DT__TA79", 19);
    PyModule_AddIntConstant(m, "DT__TAPE9", 20);
    PyModule_AddIntConstant(m, "DT__TA90", 21);
    PyModule_AddIntConstant(m, "DT__TF30", 22);
    PyModule_AddIntConstant(m, "DT__TF85", 22);
    PyModule_AddIntConstant(m, "DT__TF70", 23);
    PyModule_AddIntConstant(m, "DT__RV60", 24);
    PyModule_AddIntConstant(m, "DT__TZ30", 25);
    PyModule_AddIntConstant(m, "DT__TM32", 26);
    PyModule_AddIntConstant(m, "DT__TZX0", 27);
    PyModule_AddIntConstant(m, "DT__TSZ05", 27);
    PyModule_AddIntConstant(m, "DT__GENERIC_MK", 28);
    PyModule_AddIntConstant(m, "DT__TK50S", 29);
    PyModule_AddIntConstant(m, "DT__TZ30S", 30);
    PyModule_AddIntConstant(m, "DT__TK70L", 31);
    PyModule_AddIntConstant(m, "DT__TLZ04", 32);
    PyModule_AddIntConstant(m, "DT__TZK10", 33);
    PyModule_AddIntConstant(m, "DT__TSZ07", 34);
    PyModule_AddIntConstant(m, "DT__TSZ08", 35);
    PyModule_AddIntConstant(m, "DT__TA90E", 36);
    PyModule_AddIntConstant(m, "DT__TZK11", 37);
    PyModule_AddIntConstant(m, "DT__TZ85", 38);
    PyModule_AddIntConstant(m, "DT__TZ86", 39);
    PyModule_AddIntConstant(m, "DT__TZ87", 40);
    PyModule_AddIntConstant(m, "DT__TZ857", 41);
    PyModule_AddIntConstant(m, "DT__EXABYTE", 42);
    PyModule_AddIntConstant(m, "DT__TAPE_LOADER_1", 43);
    PyModule_AddIntConstant(m, "DT__TA91", 44);
    PyModule_AddIntConstant(m, "DT__TLZ06", 45);
    PyModule_AddIntConstant(m, "DT__TA85", 46);
    PyModule_AddIntConstant(m, "DT__TKZ60", 47);
    PyModule_AddIntConstant(m, "DT__TLZ6", 48);
    PyModule_AddIntConstant(m, "DT__TZ867", 49);
    PyModule_AddIntConstant(m, "DT__TZ877", 50);
    PyModule_AddIntConstant(m, "DT__TAD85", 51);
    PyModule_AddIntConstant(m, "DT__TF86", 52);
    PyModule_AddIntConstant(m, "DT__TKZ09", 53);
    PyModule_AddIntConstant(m, "DT__TA86", 54);
    PyModule_AddIntConstant(m, "DT__TA87", 55);
    PyModule_AddIntConstant(m, "DT__TD34", 56);
    PyModule_AddIntConstant(m, "DT__TD44", 57);
    PyModule_AddIntConstant(m, "DT__HST00", 58);
    PyModule_AddIntConstant(m, "DT__HST01", 59);
    PyModule_AddIntConstant(m, "DT__TLZ07", 60);
    PyModule_AddIntConstant(m, "DT__TLZ7", 61);
    PyModule_AddIntConstant(m, "DT__TZ88", 62);
    PyModule_AddIntConstant(m, "DT__TZ885", 63);
    PyModule_AddIntConstant(m, "DT__TZ887", 64);
    PyModule_AddIntConstant(m, "DT__TZ89", 65);
    PyModule_AddIntConstant(m, "DT__TZ895", 66);
    PyModule_AddIntConstant(m, "DT__TZ897", 67);
    PyModule_AddIntConstant(m, "DT__TZ875", 68);
    PyModule_AddIntConstant(m, "DT__TL810", 69);
    PyModule_AddIntConstant(m, "DT__TL820", 70);
    PyModule_AddIntConstant(m, "DT__TZ865", 71);
    PyModule_AddIntConstant(m, "DT__TTYUNKN", 0);
    PyModule_AddIntConstant(m, "DT__VT05", 1);
    PyModule_AddIntConstant(m, "DT__FT1", 16);
    PyModule_AddIntConstant(m, "DT__FT2", 17);
    PyModule_AddIntConstant(m, "DT__FT3", 18);
    PyModule_AddIntConstant(m, "DT__FT4", 19);
    PyModule_AddIntConstant(m, "DT__FT5", 20);
    PyModule_AddIntConstant(m, "DT__FT6", 21);
    PyModule_AddIntConstant(m, "DT__FT7", 22);
    PyModule_AddIntConstant(m, "DT__FT8", 23);
    PyModule_AddIntConstant(m, "DT__LAX", 32);
    PyModule_AddIntConstant(m, "DT__LA36", 32);
    PyModule_AddIntConstant(m, "DT__LA120", 33);
    PyModule_AddIntConstant(m, "DT__VT5X", 64);
    PyModule_AddIntConstant(m, "DT__VT52", 64);
    PyModule_AddIntConstant(m, "DT__VT55", 65);
    PyModule_AddIntConstant(m, "DT__TQ_BTS", 4);
    PyModule_AddIntConstant(m, "DT__TEK401X", 10);
    PyModule_AddIntConstant(m, "DT__VT100", 96);
    PyModule_AddIntConstant(m, "DT__VK100", 2);
    PyModule_AddIntConstant(m, "DT__VT173", 3);
    PyModule_AddIntConstant(m, "DT__LA34", 34);
    PyModule_AddIntConstant(m, "DT__LA38", 35);
    PyModule_AddIntConstant(m, "DT__LA12", 36);
    PyModule_AddIntConstant(m, "DT__LA24", 37);
    PyModule_AddIntConstant(m, "DT__LA100", 37);
    PyModule_AddIntConstant(m, "DT__LQP02", 38);
    PyModule_AddIntConstant(m, "DT__VT101", 97);
    PyModule_AddIntConstant(m, "DT__VT102", 98);
    PyModule_AddIntConstant(m, "DT__VT105", 99);
    PyModule_AddIntConstant(m, "DT__VT125", 100);
    PyModule_AddIntConstant(m, "DT__VT131", 101);
    PyModule_AddIntConstant(m, "DT__VT132", 102);
    PyModule_AddIntConstant(m, "DT__DZ11", 66);
    PyModule_AddIntConstant(m, "DT__DZ32", 67);
    PyModule_AddIntConstant(m, "DT__DZ730", 68);
    PyModule_AddIntConstant(m, "DT__DMZ32", 69);
    PyModule_AddIntConstant(m, "DT__DHV", 70);
    PyModule_AddIntConstant(m, "DT__DHU", 71);
    PyModule_AddIntConstant(m, "DT__SLU", 72);
    PyModule_AddIntConstant(m, "DT__TERM9", 73);
    PyModule_AddIntConstant(m, "DT__LAT", 74);
    PyModule_AddIntConstant(m, "DT__VS100", 1);
    PyModule_AddIntConstant(m, "DT__VS125", 2);
    PyModule_AddIntConstant(m, "DT__VL_VS8200", 3);
    PyModule_AddIntConstant(m, "DT__VD", 4);
    PyModule_AddIntConstant(m, "DT__DECW_OUTPUT", 5);
    PyModule_AddIntConstant(m, "DT__DECW_INPUT", 6);
    PyModule_AddIntConstant(m, "DT__DECW_PSEUDO", 7);
    PyModule_AddIntConstant(m, "DT__DMC11", 1);
    PyModule_AddIntConstant(m, "DT__DMR11", 2);
    PyModule_AddIntConstant(m, "DT__XK_3271", 3);
    PyModule_AddIntConstant(m, "DT__XJ_2780", 4);
    PyModule_AddIntConstant(m, "DT__NW_X25", 5);
    PyModule_AddIntConstant(m, "DT__NV_X29", 6);
    PyModule_AddIntConstant(m, "DT__SB_ISB11", 7);
    PyModule_AddIntConstant(m, "DT__MX_MUX200", 8);
    PyModule_AddIntConstant(m, "DT__DMP11", 9);
    PyModule_AddIntConstant(m, "DT__DMF32", 10);
    PyModule_AddIntConstant(m, "DT__XV_3271", 11);
    PyModule_AddIntConstant(m, "DT__CI", 12);
    PyModule_AddIntConstant(m, "DT__NI", 13);
    PyModule_AddIntConstant(m, "DT__UNA11", 14);
    PyModule_AddIntConstant(m, "DT__DEUNA", 14);
    PyModule_AddIntConstant(m, "DT__YN_X25", 15);
    PyModule_AddIntConstant(m, "DT__YO_X25", 16);
    PyModule_AddIntConstant(m, "DT__YP_ADCCP", 17);
    PyModule_AddIntConstant(m, "DT__YQ_3271", 18);
    PyModule_AddIntConstant(m, "DT__YR_DDCMP", 19);
    PyModule_AddIntConstant(m, "DT__YS_SDLC", 20);
    PyModule_AddIntConstant(m, "DT__UK_KTC32", 21);
    PyModule_AddIntConstant(m, "DT__DEQNA", 22);
    PyModule_AddIntConstant(m, "DT__DMV11", 23);
    PyModule_AddIntConstant(m, "DT__ES_LANCE", 24);
    PyModule_AddIntConstant(m, "DT__DELUA", 25);
    PyModule_AddIntConstant(m, "DT__NQ_3271", 26);
    PyModule_AddIntConstant(m, "DT__DMB32", 27);
    PyModule_AddIntConstant(m, "DT__YI_KMS11K", 28);
    PyModule_AddIntConstant(m, "DT__ET_DEBNT", 29);
    PyModule_AddIntConstant(m, "DT__ET_DEBNA", 29);
    PyModule_AddIntConstant(m, "DT__SJ_DSV11", 30);
    PyModule_AddIntConstant(m, "DT__SL_DSB32", 31);
    PyModule_AddIntConstant(m, "DT__ZS_DST32", 32);
    PyModule_AddIntConstant(m, "DT__XQ_DELQA", 33);
    PyModule_AddIntConstant(m, "DT__ET_DEBNI", 34);
    PyModule_AddIntConstant(m, "DT__EZ_SGEC", 35);
    PyModule_AddIntConstant(m, "DT__EX_DEMNA", 36);
    PyModule_AddIntConstant(m, "DT__DIV32", 37);
    PyModule_AddIntConstant(m, "DT__XQ_DEQTA", 38);
    PyModule_AddIntConstant(m, "DT__FT_NI", 39);
    PyModule_AddIntConstant(m, "DT__EP_LANCE", 40);
    PyModule_AddIntConstant(m, "DT__KWV32", 41);
    PyModule_AddIntConstant(m, "DT__SM_DSF32", 42);
    PyModule_AddIntConstant(m, "DT__FX_DEMFA", 43);
    PyModule_AddIntConstant(m, "DT__SF_DSF32", 44);
    PyModule_AddIntConstant(m, "DT__SE_DUP11", 45);
    PyModule_AddIntConstant(m, "DT__SE_DPV11", 46);
    PyModule_AddIntConstant(m, "DT__ZT_DSW", 47);
    PyModule_AddIntConstant(m, "DT__FC_DEFZA", 48);
    PyModule_AddIntConstant(m, "DT__EC_PMAD", 49);
    PyModule_AddIntConstant(m, "DT__EZ_TGEC", 50);
    PyModule_AddIntConstant(m, "DT__EA_DEANA", 51);
    PyModule_AddIntConstant(m, "DT__EY_NITC2", 52);
    PyModule_AddIntConstant(m, "DT__ER_DE422", 53);
    PyModule_AddIntConstant(m, "DT__ER_DE200", 54);
    PyModule_AddIntConstant(m, "DT__EW_TULIP", 55);
    PyModule_AddIntConstant(m, "DT__FA_DEFAA", 56);
    PyModule_AddIntConstant(m, "DT__FC_DEFTA", 57);
    PyModule_AddIntConstant(m, "DT__FQ_DEFQA", 58);
    PyModule_AddIntConstant(m, "DT__FR_DEFEA", 59);
    PyModule_AddIntConstant(m, "DT__FW_DEFPA", 60);
    PyModule_AddIntConstant(m, "DT__IC_DETRA", 61);
    PyModule_AddIntConstant(m, "DT__IQ_DEQRA", 62);
    PyModule_AddIntConstant(m, "DT__IR_DW300", 63);
    PyModule_AddIntConstant(m, "DT__ZR_SCC", 64);
    PyModule_AddIntConstant(m, "DT__ZY_DSYT1", 65);
    PyModule_AddIntConstant(m, "DT__ZE_DNSES", 66);
    PyModule_AddIntConstant(m, "DT__ER_DE425", 67);
    PyModule_AddIntConstant(m, "DT__EW_DE435", 68);
    PyModule_AddIntConstant(m, "DT__ER_DE205", 69);
    PyModule_AddIntConstant(m, "DT__HC_OTTO", 70);
    PyModule_AddIntConstant(m, "DT__ZS_PBXDI", 71);
    PyModule_AddIntConstant(m, "DT__EL_ELAN", 72);
    PyModule_AddIntConstant(m, "DT__HW_OTTO", 73);
    PyModule_AddIntConstant(m, "DT__EO_3C598", 74);
    PyModule_AddIntConstant(m, "DT__IW_TC4048", 75);
    PyModule_AddIntConstant(m, "DT__EW_DE450", 76);
    PyModule_AddIntConstant(m, "DT__EW_DE500", 77);
    PyModule_AddIntConstant(m, "DT__CL_CLIP", 78);
    PyModule_AddIntConstant(m, "DT__ZW_PBXDP", 79);
    PyModule_AddIntConstant(m, "DT__HW_METEOR", 80);
    PyModule_AddIntConstant(m, "DT__ER_DE305", 81);
    PyModule_AddIntConstant(m, "DT__EW_DEGPA", 82);
    PyModule_AddIntConstant(m, "DT__IW_RACORE", 83);
    PyModule_AddIntConstant(m, "DT__EB_SMLAN", 84);
    PyModule_AddIntConstant(m, "DT__EI_82558", 85);
    PyModule_AddIntConstant(m, "DT__EI_82559", 86);
    PyModule_AddIntConstant(m, "DT__HW_HE622", 87);
    PyModule_AddIntConstant(m, "DT__HW_HE155", 88);
    PyModule_AddIntConstant(m, "DT__EW_BCM5703", 89);
    PyModule_AddIntConstant(m, "DT__EW_BCM5704", 90);
    PyModule_AddIntConstant(m, "DT__EW_XFRAME", 91);
    PyModule_AddIntConstant(m, "DT__EW_BCM5701", 92);
    PyModule_AddIntConstant(m, "DT__LL_LLAN", 93);
    PyModule_AddIntConstant(m, "DT__EG_ELP_FC", 94);
    PyModule_AddIntConstant(m, "DT__EG_Q_FC", 95);
    PyModule_AddIntConstant(m, "DT__EI_82540", 96);
    PyModule_AddIntConstant(m, "DT__VL_VLAN", 97);
    PyModule_AddIntConstant(m, "DT__EW_BCM5715", 98);
    PyModule_AddIntConstant(m, "DT__EI_AVIO", 99);
    PyModule_AddIntConstant(m, "DT__ER_BCM57711", 100);
    PyModule_AddIntConstant(m, "DT__EW_BCM57711", 101);
    PyModule_AddIntConstant(m, "DT__EB_BE", 102);
    PyModule_AddIntConstant(m, "DT__EW_BE", 103);
    PyModule_AddIntConstant(m, "DT__LP11", 1);
    PyModule_AddIntConstant(m, "DT__LA11", 2);
    PyModule_AddIntConstant(m, "DT__LA180", 3);
    PyModule_AddIntConstant(m, "DT__LC_DMF32", 4);
    PyModule_AddIntConstant(m, "DT__LI_DMB32", 5);
    PyModule_AddIntConstant(m, "DT__PRTR9", 6);
    PyModule_AddIntConstant(m, "DT__SCSI_SCANNER_1", 7);
    PyModule_AddIntConstant(m, "DT__PC_PRINTER", 8);
    PyModule_AddIntConstant(m, "DT__CR11", 1);
    PyModule_AddIntConstant(m, "DT__MBX", 1);
    PyModule_AddIntConstant(m, "DT__SHRMBX", 2);
    PyModule_AddIntConstant(m, "DT__NULL", 3);
    PyModule_AddIntConstant(m, "DT__PIPE", 4);
    PyModule_AddIntConstant(m, "DT__DAP_DEVICE", 1);
    PyModule_AddIntConstant(m, "DT__LPA11", 1);
    PyModule_AddIntConstant(m, "DT__DR780", 2);
    PyModule_AddIntConstant(m, "DT__DR750", 3);
    PyModule_AddIntConstant(m, "DT__DR11W", 4);
    PyModule_AddIntConstant(m, "DT__PCL11R", 5);
    PyModule_AddIntConstant(m, "DT__PCL11T", 6);
    PyModule_AddIntConstant(m, "DT__DR11C", 7);
    PyModule_AddIntConstant(m, "DT__BS_DT07", 8);
    PyModule_AddIntConstant(m, "DT__XP_PCL11B", 9);
    PyModule_AddIntConstant(m, "DT__IX_IEX11", 10);
    PyModule_AddIntConstant(m, "DT__FP_FEPCM", 11);
    PyModule_AddIntConstant(m, "DT__TK_FCM", 12);
    PyModule_AddIntConstant(m, "DT__XI_DR11C", 13);
    PyModule_AddIntConstant(m, "DT__XA_DRV11WA", 14);
    PyModule_AddIntConstant(m, "DT__DRB32", 15);
    PyModule_AddIntConstant(m, "DT__HX_DRQ3B", 16);
    PyModule_AddIntConstant(m, "DT__DECVOICE", 1);
    PyModule_AddIntConstant(m, "DT__DTC04", 2);
    PyModule_AddIntConstant(m, "DT__DTC05", 3);
    PyModule_AddIntConstant(m, "DT__DTCN5", 4);
    PyModule_AddIntConstant(m, "DT__AMD79C30A", 1);
    PyModule_AddIntConstant(m, "DT__CMI8738", 2);
    PyModule_AddIntConstant(m, "DT__CI780", 1);
    PyModule_AddIntConstant(m, "DT__CI750", 2);
    PyModule_AddIntConstant(m, "DT__UQPORT", 3);
    PyModule_AddIntConstant(m, "DT__UDA50", 3);
    PyModule_AddIntConstant(m, "DT__UDA50A", 4);
    PyModule_AddIntConstant(m, "DT__LESI", 5);
    PyModule_AddIntConstant(m, "DT__TU81P", 6);
    PyModule_AddIntConstant(m, "DT__RDRX", 7);
    PyModule_AddIntConstant(m, "DT__TK50P", 8);
    PyModule_AddIntConstant(m, "DT__RUX50P", 9);
    PyModule_AddIntConstant(m, "DT__RC26P", 10);
    PyModule_AddIntConstant(m, "DT__QDA50", 11);
    PyModule_AddIntConstant(m, "DT__KDA50", 11);
    PyModule_AddIntConstant(m, "DT__BDA50", 12);
    PyModule_AddIntConstant(m, "DT__KDB50", 12);
    PyModule_AddIntConstant(m, "DT__RRD50P", 13);
    PyModule_AddIntConstant(m, "DT__QDA25", 14);
    PyModule_AddIntConstant(m, "DT__KDA25", 14);
    PyModule_AddIntConstant(m, "DT__BCI750", 15);
    PyModule_AddIntConstant(m, "DT__BCA", 16);
    PyModule_AddIntConstant(m, "DT__RQDX3", 17);
    PyModule_AddIntConstant(m, "DT__NISCA", 18);
    PyModule_AddIntConstant(m, "DT__AIO", 19);
    PyModule_AddIntConstant(m, "DT__KFBTA", 19);
    PyModule_AddIntConstant(m, "DT__AIE", 20);
    PyModule_AddIntConstant(m, "DT__DEBNT", 20);
    PyModule_AddIntConstant(m, "DT__BSA", 21);
    PyModule_AddIntConstant(m, "DT__KSB50", 21);
    PyModule_AddIntConstant(m, "DT__TK70P", 22);
    PyModule_AddIntConstant(m, "DT__RV20P", 23);
    PyModule_AddIntConstant(m, "DT__RV80P", 23);
    PyModule_AddIntConstant(m, "DT__TK60P", 24);
    PyModule_AddIntConstant(m, "DT__SII", 25);
    PyModule_AddIntConstant(m, "DT__KFSQSA", 26);
    PyModule_AddIntConstant(m, "DT__KFQSA", 26);
    PyModule_AddIntConstant(m, "DT__SHAC", 27);
    PyModule_AddIntConstant(m, "DT__CIXCD", 28);
    PyModule_AddIntConstant(m, "DT__N5380", 29);
    PyModule_AddIntConstant(m, "DT__SCSII", 30);
    PyModule_AddIntConstant(m, "DT__HSX50", 31);
    PyModule_AddIntConstant(m, "DT__KDM70", 31);
    PyModule_AddIntConstant(m, "DT__TM32P", 32);
    PyModule_AddIntConstant(m, "DT__TK7LP", 33);
    PyModule_AddIntConstant(m, "DT__SWIFT", 34);
    PyModule_AddIntConstant(m, "DT__N53C94", 35);
    PyModule_AddIntConstant(m, "DT__KFMSA", 36);
    PyModule_AddIntConstant(m, "DT__SCSI_XTENDR", 37);
    PyModule_AddIntConstant(m, "DT__FT_TRACE_RAM", 38);
    PyModule_AddIntConstant(m, "DT__XVIB", 39);
    PyModule_AddIntConstant(m, "DT__XZA_SCSI", 40);
    PyModule_AddIntConstant(m, "DT__XZA_DSSI", 41);
    PyModule_AddIntConstant(m, "DT__N710_SCSI", 42);
    PyModule_AddIntConstant(m, "DT__N710_DSSI", 43);
    PyModule_AddIntConstant(m, "DT__AHA1742A", 44);
    PyModule_AddIntConstant(m, "DT__TZA_SCSI", 45);
    PyModule_AddIntConstant(m, "DT__N810_SCSI", 46);
    PyModule_AddIntConstant(m, "DT__CIPCA", 47);
    PyModule_AddIntConstant(m, "DT__ISP1020", 48);
    PyModule_AddIntConstant(m, "DT__MC_SPUR", 49);
    PyModule_AddIntConstant(m, "DT__PZA_SCSI", 50);
    PyModule_AddIntConstant(m, "DT__MCSCA", 51);
    PyModule_AddIntConstant(m, "DT__SMCI", 52);
    PyModule_AddIntConstant(m, "DT__KZPCM_SCSI", 53);
    PyModule_AddIntConstant(m, "DT__SYM896_SCSI", 54);
    PyModule_AddIntConstant(m, "DT__FCP_SCSI", 55);
    PyModule_AddIntConstant(m, "DT__LP7000_FC", 56);
    PyModule_AddIntConstant(m, "DT__SYM895_SCSI", 57);
    PyModule_AddIntConstant(m, "DT__KZPCA_SCSI", 58);
    PyModule_AddIntConstant(m, "DT__ADAPTEC7892_SCSI", 59);
    PyModule_AddIntConstant(m, "DT__ADAPTEC7895_SCSI", 60);
    PyModule_AddIntConstant(m, "DT__ADAPTEC7897_SCSI", 61);
    PyModule_AddIntConstant(m, "DT__ADAPTEC7899_SCSI", 62);
    PyModule_AddIntConstant(m, "DT__CISS", 63);
    PyModule_AddIntConstant(m, "DT__ISP23XX_FC", 64);
    PyModule_AddIntConstant(m, "DT__LSI1010_SCSI", 65);
    PyModule_AddIntConstant(m, "DT__LSI1030_SCSI", 66);
    PyModule_AddIntConstant(m, "DT__ISP24XX_FC", 67);
    PyModule_AddIntConstant(m, "DT__LSI106X_SAS", 68);
    PyModule_AddIntConstant(m, "DT__SW_ISCSI", 69);
    PyModule_AddIntConstant(m, "DT__LP8000_FC", 70);
    PyModule_AddIntConstant(m, "DT__LP9000_FC", 71);
    PyModule_AddIntConstant(m, "DT__LP9802_FC", 72);
    PyModule_AddIntConstant(m, "DT__LP10000_FC", 73);
    PyModule_AddIntConstant(m, "DT__LP11002_FC", 74);
    PyModule_AddIntConstant(m, "DT__ISP243X_FC", 75);
    PyModule_AddIntConstant(m, "DT__EP2422_FC", 76);
    PyModule_AddIntConstant(m, "DT__ISP253X_FC", 77);
    PyModule_AddIntConstant(m, "DT__GSP", 78);
    PyModule_AddIntConstant(m, "DT__ICH10_AHCI", 79);
    PyModule_AddIntConstant(m, "DT__DN11", 1);
    PyModule_AddIntConstant(m, "DT__PV", 2);
    PyModule_AddIntConstant(m, "DT__SFUN9", 3);
    PyModule_AddIntConstant(m, "DT__USER9", 4);
    PyModule_AddIntConstant(m, "DT__GENERIC_SCSI", 5);
    PyModule_AddIntConstant(m, "DT__DMA_520", 6);
    PyModule_AddIntConstant(m, "DT__T3270", 7);
    PyModule_AddIntConstant(m, "DT__IPMI", 9);
    PyModule_AddIntConstant(m, "DT__ACPI_SE", 10);
    return m;
}