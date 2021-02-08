! MMS/EXT/DESCR=Python3.mms/MACRO=("OUTDIR=OUT","CONFIG=DEBUG")

! define output folder
.IF OUTDIR
! defined - ok
.ELSE
! not defined - define as OUT
OUTDIR = OUT
.ENDIF

! check DEBUG or RELEASE
.IF CONFIG
! defined - ok
.ELSE
! not defined - define as DEBUG
CONFIG = DEBUG
.ENDIF

.IF $(CONFIG) .EQ DEBUG
! debug
CC_QUALIFIERS = /DEBUG/NOOPTIMIZE/LIST=$(MMS$TARGET_NAME)
CC_DEFINES = _DEBUG
OUT_DIR = $(OUTDIR).$(CONFIG)
OBJ_DIR = $(OUT_DIR).OBJ
LINK_FLAGS = /DEBUG/MAP=[.$(OUT_DIR)]$(NOTDIR $(MMS$TARGET_NAME))
PYTHON$SHR_OPT = PYTHON$SHR_DBG
.ELSE
! release
CC_QUALIFIERS = /NODEBUG/OPTIMIZE/NOLIST
CC_DEFINES = _NDEBUG
OUT_DIR = $(OUTDIR).$(CONFIG)
OBJ_DIR = $(OUT_DIR).OBJ
LINK_FLAGS = /NODEBUG/NOMAP/NOTRACEBACK
PYTHON$SHR_OPT = PYTHON$SHR
.ENDIF

DYNLOAD_DIR = lib-dynload
PLATFORM = OpenVMS
SOABI = cpython-3a-ia64-openvms

CC_QUALIFIERS = -
$(CC_QUALIFIERS) -
/NAMES=(AS_IS,SHORTENED) -
/WARNINGS=(WARNINGS=ALL, DISABLE=(EXTRASEMI))
! /SHOW=(EXPANSION,INCLUDE)

CC_DEFINES = -
$(CC_DEFINES), -
_USE_STD_STAT, -
__STDC_FORMAT_MACROS, -
_POSIX_SEMAPHORES, -
_LARGEFILE, -
_SOCKADDR_LEN, -
USE_ZLIB_CRC32, -
_OSF_SOURCE, -                  ! OSF
HAVE_EXPAT_CONFIG_H, -          ! EXPAT
XML_POOR_ENTROPY, -
USE_PYEXPAT_CAPI, -
CONFIG_32, -                    ! DECIMAL
ANSI, -
PYTHONPATH="""""", -            ! GETPATH
PREFIX="""/usr/local""", -
EXEC_PREFIX="""/usr/local""", -
VERSION="""3.10""", -
VPATH="""""", -
SOABI="""$(SOABI)""", -         ! SOABI
SHLIB_EXT=""".EXE""", -
ABIFLAGS="""""", -
MULTIARCH="""$(SOABI)""", -
PLATFORM="""$(PLATFORM)""", -
__SIGNED_INT_TIME_T

CC_INCLUDES = -
[], -
[.Include], -
[.Include.internal], -
oss$root:[include], -
[.Modules.expat], -
[.Modules._decimal.libmpdec], -
[.Modules._multiprocessing], -
[.Modules._io], -
dtr$library

CC_FLAGS = $(CC_QUALIFIERS)/DEFINE=($(CC_DEFINES))/INCLUDE_DIRECTORY=($(CC_INCLUDES))

CC_CORE_CFLAGS = $(CC_QUALIFIERS)/DEFINE=("Py_BUILD_CORE",$(CC_DEFINES))/INCLUDE_DIRECTORY=($(CC_INCLUDES))

CC_CORE_MODULE_CFLAGS = $(CC_QUALIFIERS)/DEFINE=("Py_BUILD_CORE_MODULE",$(CC_DEFINES))/INCLUDE_DIRECTORY=($(CC_INCLUDES))

CC_CORE_BUILTIN_CFLAGS = $(CC_QUALIFIERS)/DEFINE=("Py_BUILD_CORE_BUILTIN",$(CC_DEFINES))/INCLUDE_DIRECTORY=($(CC_INCLUDES))

.FIRST
    ! defines for nested includes, like:
    ! #include "clinic/transmogrify.h.h"
    define cpython [.Include.cpython]
    define stringlib [.Objects.stringlib]
    define clinic [.Objects.clinic],[.Python.clinic],[.Modules.clinic],[.Modules._io.clinic],[.Modules.cjkcodecs.clinic],[.Objects.stringlib.clinic],[.Modules._blake2.clinic],[.Modules._sha3.clinic],[.Modules._multiprocessing.clinic]
    ! define modules [.Modules]
    ! define readline oss$root:[include.readline]
    ! define lzma oss$root:[include.lzma]
    ! define internal [.Include.internal]
    ! define _ssl [.Modules._ssl]
    ! define impl [.Modules._blake2.impl]
    ! define kcp  [.Modules._sha3.kcp]
    ! define ctypes [.Modules._ctypes]
    ! SWIG
    ! swig :== $swig$root:[bin]swig.exe
    ! OPENSSL 111
    ! define openssl ssl111$include:
    ! names
    BUILD_OUT_DIR = F$ENVIRONMENT("DEFAULT")-"]"+".$(OUT_DIR).]"
    BUILD_OBJ_DIR = F$ENVIRONMENT("DEFAULT")-"]"+".$(OBJ_DIR).]"
    define /trans=concealed python$build_out 'BUILD_OUT_DIR'
    define /trans=concealed python$build_obj 'BUILD_OBJ_DIR'
    ! SQL
    ! sqlmod :==  mcr sql$mod

.SUFFIXES
.SUFFIXES .EXE .OLB .OBM .OBB .OBC .C

! CORE
.C.OBC
    @ pipe create/dir $(DIR $(MMS$TARGET)) | copy SYS$INPUT nl:
    $(CC) $(CC_CORE_CFLAGS) /OBJECT=$(MMS$TARGET) $(MMS$SOURCE)

.OBC.OLB
    @ IF F$SEARCH("$(MMS$TARGET)") .EQS. "" -
        THEN $(LIBR)/CREATE $(MMS$TARGET)
    $(LIBR) $(MMS$TARGET) $(MMS$SOURCE)

! BUILTIN MODULE
.C.OBB
    @ pipe create/dir $(DIR $(MMS$TARGET)) | copy SYS$INPUT nl:
    $(CC) $(CC_CORE_BUILTIN_CFLAGS) /OBJECT=$(MMS$TARGET) $(MMS$SOURCE)

.OBB.OLB
    @ IF F$SEARCH("$(MMS$TARGET)") .EQS. "" -
        THEN $(LIBR)/CREATE $(MMS$TARGET)
    $(LIBR) $(MMS$TARGET) $(MMS$SOURCE)

! SHARED MODULE
.C.OBM
    @ pipe create/dir $(DIR $(MMS$TARGET)) | copy SYS$INPUT nl:
    $(CC) $(CC_CORE_MODULE_CFLAGS) /OBJECT=$(MMS$TARGET) $(MMS$SOURCE)

.OBM.EXE
    @ pipe create/dir $(DIR $(MMS$TARGET)) | copy SYS$INPUT nl:
    $(LINK)$(LINK_FLAGS)/SHARE=python$build_out:[$(DYNLOAD_DIR)]$(NOTDIR $(MMS$TARGET_NAME)).EXE $(MMS$SOURCE_LIST),[.vms.opt]$(NOTDIR $(MMS$TARGET_NAME)).opt/OPT

##########################################################################
TARGET : [.$(OUT_DIR)]libpython3^.10.olb
    ! TARGET BUILT

CLEAN :
    del/tree [.$(OUT_DIR)...]*.*;*

pyconfig.h : [.vms]pyconfig.h
    copy [.vms]pyconfig.h []

[.Include]stdint.h : [.vms]stdint.h
    copy [.vms]stdint.h [.Include]stdint.h

[.Include]inttypes.h : [.vms]inttypes.h
    copy [.vms]inttypes.h [.Include]inttypes.h

[.Modules]config.c : [.vms]config.c
    copy [.vms]config.c [.Modules]config.c

##########################################################################
# Modules
MODULE_OBJS= -
[.$(OBJ_DIR).Modules]config.obc -
[.$(OBJ_DIR).Modules]getpath.obc -
[.$(OBJ_DIR).Modules]main.obc -
[.$(OBJ_DIR).Modules]gcmodule.obc

IO_H= -
[.Modules._io]_iomodule.h

##########################################################################
# Parser

PEGEN_OBJS= -
[.$(OBJ_DIR).Parser]pegen.obc -
[.$(OBJ_DIR).Parser]parser.obc -
[.$(OBJ_DIR).Parser]string_parser.obc -
[.$(OBJ_DIR).Parser]peg_api.obc

PEGEN_HEADERS= -
[.Include]parser_interface.h -
[.Parser]pegen.h -
[.Parser]string_parser.h

POBJS= -
[.$(OBJ_DIR).Parser]token.obc

PARSER_OBJS= -
$(POBJS) -
$(PEGEN_OBJS) -
[.$(OBJ_DIR).Parser]myreadline.obc -
[.$(OBJ_DIR).Parser]tokenizer.obc -
[.$(OBJ_DIR).vms]vms_smg_readline.obc

PARSER_HEADERS= -
$(PEGEN_HEADERS) -
[.Parser]tokenizer.h

##########################################################################
# Python

PYTHON_OBJS= -
[.$(OBJ_DIR).Python]_warnings.obc -
[.$(OBJ_DIR).Python]Python-ast.obc -
[.$(OBJ_DIR).Python]asdl.obc -
[.$(OBJ_DIR).Python]ast.obc -
[.$(OBJ_DIR).Python]ast_opt.obc -
[.$(OBJ_DIR).Python]ast_unparse.obc -
[.$(OBJ_DIR).Python]bltinmodule.obc -
[.$(OBJ_DIR).Python]ceval.obc -
[.$(OBJ_DIR).Python]codecs.obc -
[.$(OBJ_DIR).Python]compile.obc -
[.$(OBJ_DIR).Python]context.obc -
[.$(OBJ_DIR).Python]dynamic_annotations.obc -
[.$(OBJ_DIR).Python]errors.obc -
[.$(OBJ_DIR).Python]frozenmain.obc -
[.$(OBJ_DIR).Python]future.obc -
[.$(OBJ_DIR).Python]getargs.obc -
[.$(OBJ_DIR).Python]getcompiler.obc -
[.$(OBJ_DIR).Python]getcopyright.obc -
[.$(OBJ_DIR).Python]getplatform.obc -
[.$(OBJ_DIR).Python]getversion.obc -
[.$(OBJ_DIR).Python]hamt.obc -
[.$(OBJ_DIR).Python]hashtable.obc -
[.$(OBJ_DIR).Python]import.obc -
[.$(OBJ_DIR).Python]importdl.obc -
[.$(OBJ_DIR).Python]initconfig.obc -
[.$(OBJ_DIR).Python]marshal.obc -
[.$(OBJ_DIR).Python]modsupport.obc -
[.$(OBJ_DIR).Python]mysnprintf.obc -
[.$(OBJ_DIR).Python]mystrtoul.obc -
[.$(OBJ_DIR).Python]pathconfig.obc -
[.$(OBJ_DIR).Python]preconfig.obc -
[.$(OBJ_DIR).Python]pyarena.obc -
[.$(OBJ_DIR).Python]pyctype.obc -
[.$(OBJ_DIR).Python]pyfpe.obc -
[.$(OBJ_DIR).Python]pyhash.obc -
[.$(OBJ_DIR).Python]pylifecycle.obc -
[.$(OBJ_DIR).Python]pymath.obc -
[.$(OBJ_DIR).Python]pystate.obc -
[.$(OBJ_DIR).Python]pythonrun.obc -
[.$(OBJ_DIR).Python]pytime.obc -
[.$(OBJ_DIR).Python]bootstrap_hash.obc -
[.$(OBJ_DIR).Python]structmember.obc -
[.$(OBJ_DIR).Python]symtable.obc -
[.$(OBJ_DIR).Python]sysmodule.obc -
[.$(OBJ_DIR).Python]thread.obc -
[.$(OBJ_DIR).Python]traceback.obc -
[.$(OBJ_DIR).Python]getopt.obc -
[.$(OBJ_DIR).Python]pystrcmp.obc -
[.$(OBJ_DIR).Python]pystrtod.obc -
[.$(OBJ_DIR).Python]pystrhex.obc -
[.$(OBJ_DIR).Python]dtoa.obc -
[.$(OBJ_DIR).Python]formatter_unicode.obc -
[.$(OBJ_DIR).Python]fileutils.obc -
[.$(OBJ_DIR).Python]dynload_shlib.obc
! $(LIBOBJS) -
! $(MACHDEP_OBJS) -
! $(DTRACE_OBJS)

##########################################################################
# Objects
OBJECT_OBJS= -
[.$(OBJ_DIR).Objects]abstract.obc -
[.$(OBJ_DIR).Objects]accu.obc -
[.$(OBJ_DIR).Objects]boolobject.obc -
[.$(OBJ_DIR).Objects]bytes_methods.obc -
[.$(OBJ_DIR).Objects]bytearrayobject.obc -
[.$(OBJ_DIR).Objects]bytesobject.obc -
[.$(OBJ_DIR).Objects]call.obc -
[.$(OBJ_DIR).Objects]capsule.obc -
[.$(OBJ_DIR).Objects]cellobject.obc -
[.$(OBJ_DIR).Objects]classobject.obc -
[.$(OBJ_DIR).Objects]codeobject.obc -
[.$(OBJ_DIR).Objects]complexobject.obc -
[.$(OBJ_DIR).Objects]descrobject.obc -
[.$(OBJ_DIR).Objects]enumobject.obc -
[.$(OBJ_DIR).Objects]exceptions.obc -
[.$(OBJ_DIR).Objects]genericaliasobject.obc -
[.$(OBJ_DIR).Objects]genobject.obc -
[.$(OBJ_DIR).Objects]fileobject.obc -
[.$(OBJ_DIR).Objects]floatobject.obc -
[.$(OBJ_DIR).Objects]frameobject.obc -
[.$(OBJ_DIR).Objects]funcobject.obc -
[.$(OBJ_DIR).Objects]interpreteridobject.obc -
[.$(OBJ_DIR).Objects]iterobject.obc -
[.$(OBJ_DIR).Objects]listobject.obc -
[.$(OBJ_DIR).Objects]longobject.obc -
[.$(OBJ_DIR).Objects]dictobject.obc -
[.$(OBJ_DIR).Objects]odictobject.obc -
[.$(OBJ_DIR).Objects]memoryobject.obc -
[.$(OBJ_DIR).Objects]methodobject.obc -
[.$(OBJ_DIR).Objects]moduleobject.obc -
[.$(OBJ_DIR).Objects]namespaceobject.obc -
[.$(OBJ_DIR).Objects]object.obc -
[.$(OBJ_DIR).Objects]obmalloc.obc -
[.$(OBJ_DIR).Objects]picklebufobject.obc -
[.$(OBJ_DIR).Objects]rangeobject.obc -
[.$(OBJ_DIR).Objects]setobject.obc -
[.$(OBJ_DIR).Objects]sliceobject.obc -
[.$(OBJ_DIR).Objects]structseq.obc -
[.$(OBJ_DIR).Objects]tupleobject.obc -
[.$(OBJ_DIR).Objects]typeobject.obc -
[.$(OBJ_DIR).Objects]unicodeobject.obc -
[.$(OBJ_DIR).Objects]unicodectype.obc -
[.$(OBJ_DIR).Objects]unionobject.obc -
[.$(OBJ_DIR).Objects]weakrefobject.obc

##########################################################################
# Static modules
MODOBJS= -
[.$(OBJ_DIR).Modules]posixmodule.obb -
[.$(OBJ_DIR).Modules]_functoolsmodule.obb -
[.$(OBJ_DIR).Modules]signalmodule.obb -
[.$(OBJ_DIR).Modules]timemodule.obb -
[.$(OBJ_DIR).Modules]_threadmodule.obb -
[.$(OBJ_DIR).Modules]_localemodule.obb -
[.$(OBJ_DIR).Modules._io]_iomodule.obb -
[.$(OBJ_DIR).Modules._io]iobase.obb -
[.$(OBJ_DIR).Modules._io]fileio.obb -
[.$(OBJ_DIR).Modules._io]bufferedio.obb -
[.$(OBJ_DIR).Modules._io]textio.obb -
[.$(OBJ_DIR).Modules._io]bytesio.obb -
[.$(OBJ_DIR).Modules._io]stringio.obb -
[.$(OBJ_DIR).Modules]errnomodule.obc -
[.$(OBJ_DIR).Modules]pwdmodule.obc -
[.$(OBJ_DIR).Modules]_sre.obc -
[.$(OBJ_DIR).Modules]_codecsmodule.obc -
[.$(OBJ_DIR).Modules]_weakref.obc -
[.$(OBJ_DIR).Modules]_operator.obc -
[.$(OBJ_DIR).Modules]_collectionsmodule.obc -
[.$(OBJ_DIR).Modules]_abc.obc -
[.$(OBJ_DIR).Modules]itertoolsmodule.obc -
[.$(OBJ_DIR).Modules]atexitmodule.obc -
[.$(OBJ_DIR).Modules]_stat.obc -
[.$(OBJ_DIR).Modules]faulthandler.obc -
[.$(OBJ_DIR).Modules]_tracemalloc.obc -
[.$(OBJ_DIR).Modules]symtablemodule.obc

##########################################################################
# objects that get linked into the Python library
LIBRARY_OBJS_OMIT_FROZEN= -
[.$(OBJ_DIR).Modules]getbuildinfo.obc -
[.$(OBJ_DIR).vms]vms_poll_select_hack.obc -
$(PARSER_OBJS) -
$(OBJECT_OBJS) -
$(PYTHON_OBJS) -
$(MODULE_OBJS) -
$(MODOBJS)

LIBRARY_OBJS= -
$(LIBRARY_OBJS_OMIT_FROZEN) -
[.$(OBJ_DIR).Python]frozen.obc

##########################################################################

BYTESTR_DEPS = -
[.Objects.stringlib]count.h -
[.Objects.stringlib]ctype.h -
[.Objects.stringlib]fastsearch.h -
[.Objects.stringlib]find.h -
[.Objects.stringlib]join.h -
[.Objects.stringlib]partition.h -
[.Objects.stringlib]split.h -
[.Objects.stringlib]stringdefs.h -
[.Objects.stringlib]transmogrify.h

UNICODE_DEPS = -
[.Objects.stringlib]asciilib.h -
[.Objects.stringlib]codecs.h -
[.Objects.stringlib]count.h -
[.Objects.stringlib]fastsearch.h -
[.Objects.stringlib]find.h -
[.Objects.stringlib]find_max_char.h -
[.Objects.stringlib]localeutil.h -
[.Objects.stringlib]partition.h -
[.Objects.stringlib]replace.h -
[.Objects.stringlib]split.h -
[.Objects.stringlib]ucs1lib.h -
[.Objects.stringlib]ucs2lib.h -
[.Objects.stringlib]ucs4lib.h -
[.Objects.stringlib]undef.h -
[.Objects.stringlib]unicode_format.h -
[.Objects.stringlib]unicodedefs.h

############################################################################
# Header files

PYTHON_HEADERS= -
[.Include]stdint.h -
[.Include]inttypes.h -
[.Include]Python.h -
[.Include]abstract.h -
[.Include]asdl.h -
[.Include]ast.h -
[.Include]bltinmodule.h -
[.Include]boolobject.h -
[.Include]bytearrayobject.h -
[.Include]bytesobject.h -
[.Include]cellobject.h -
[.Include]ceval.h -
[.Include]classobject.h -
[.Include]code.h -
[.Include]codecs.h -
[.Include]compile.h -
[.Include]complexobject.h -
[.Include]context.h -
[.Include]descrobject.h -
[.Include]dictobject.h -
[.Include]dynamic_annotations.h -
[.Include]enumobject.h -
[.Include]errcode.h -
[.Include]eval.h -
[.Include]fileobject.h -
[.Include]fileutils.h -
[.Include]floatobject.h -
[.Include]frameobject.h -
[.Include]funcobject.h -
[.Include]genobject.h -
[.Include]import.h -
[.Include]interpreteridobject.h -
[.Include]intrcheck.h -
[.Include]iterobject.h -
[.Include]listobject.h -
[.Include]longintrepr.h -
[.Include]longobject.h -
[.Include]marshal.h -
[.Include]memoryobject.h -
[.Include]methodobject.h -
[.Include]modsupport.h -
[.Include]moduleobject.h -
[.Include]namespaceobject.h -
[.Include]object.h -
[.Include]objimpl.h -
[.Include]odictobject.h -
[.Include]opcode.h -
[.Include]osdefs.h -
[.Include]osmodule.h -
[.Include]patchlevel.h -
[.Include]picklebufobject.h -
[.Include]pyarena.h -
[.Include]pycapsule.h -
[.Include]pyctype.h -
[.Include]pydebug.h -
[.Include]pydtrace.h -
[.Include]pyerrors.h -
[.Include]pyfpe.h -
[.Include]pyframe.h -
[.Include]pyhash.h -
[.Include]pylifecycle.h -
[.Include]pymacconfig.h -
[.Include]pymacro.h -
[.Include]pymath.h -
[.Include]pymem.h -
[.Include]pyport.h -
[.Include]pystate.h -
[.Include]pystrcmp.h -
[.Include]pystrhex.h -
[.Include]pystrtod.h -
[.Include]pythonrun.h -
[.Include]pythread.h -
[.Include]pytime.h -
[.Include]rangeobject.h -
[.Include]setobject.h -
[.Include]sliceobject.h -
[.Include]structmember.h -
[.Include]structseq.h -
[.Include]symtable.h -
[.Include]sysmodule.h -
[.Include]token.h -
[.Include]traceback.h -
[.Include]tracemalloc.h -
[.Include]tupleobject.h -
[.Include]unicodeobject.h -
[.Include]warnings.h -
[.Include]weakrefobject.h -
pyconfig.h -
$(PARSER_HEADERS) -
[.Include]Python-ast.h -
[.Include.cpython]abstract.h -
[.Include.cpython]bytearrayobject.h -
[.Include.cpython]bytesobject.h -
[.Include.cpython]ceval.h -
[.Include.cpython]code.h -
[.Include.cpython]dictobject.h -
[.Include.cpython]fileobject.h -
[.Include.cpython]fileutils.h -
[.Include.cpython]frameobject.h -
[.Include.cpython]import.h -
[.Include.cpython]initconfig.h -
[.Include.cpython]interpreteridobject.h -
[.Include.cpython]listobject.h -
[.Include.cpython]methodobject.h -
[.Include.cpython]object.h -
[.Include.cpython]objimpl.h -
[.Include.cpython]pyerrors.h -
[.Include.cpython]pylifecycle.h -
[.Include.cpython]pymem.h -
[.Include.cpython]pystate.h -
[.Include.cpython]pythonrun.h -
[.Include.cpython]sysmodule.h -
[.Include.cpython]traceback.h -
[.Include.cpython]tupleobject.h -
[.Include.cpython]unicodeobject.h -
[.Include.internal]pycore_abstract.h -
[.Include.internal]pycore_accu.h -
[.Include.internal]pycore_atomic.h -
[.Include.internal]pycore_atomic_funcs.h -
[.Include.internal]pycore_bitutils.h -
[.Include.internal]pycore_bytes_methods.h -
[.Include.internal]pycore_call.h -
[.Include.internal]pycore_ceval.h -
[.Include.internal]pycore_code.h -
[.Include.internal]pycore_condvar.h -
[.Include.internal]pycore_context.h -
[.Include.internal]pycore_dtoa.h -
[.Include.internal]pycore_fileutils.h -
[.Include.internal]pycore_format.h -
[.Include.internal]pycore_getopt.h -
[.Include.internal]pycore_gil.h -
[.Include.internal]pycore_hamt.h -
[.Include.internal]pycore_hashtable.h -
[.Include.internal]pycore_import.h -
[.Include.internal]pycore_initconfig.h -
[.Include.internal]pycore_interp.h -
[.Include.internal]pycore_list.h -
[.Include.internal]pycore_long.h -
[.Include.internal]pycore_object.h -
[.Include.internal]pycore_pathconfig.h -
[.Include.internal]pycore_pyerrors.h -
[.Include.internal]pycore_pyhash.h -
[.Include.internal]pycore_pylifecycle.h -
[.Include.internal]pycore_pymem.h -
[.Include.internal]pycore_pystate.h -
[.Include.internal]pycore_runtime.h -
[.Include.internal]pycore_sysmodule.h -
[.Include.internal]pycore_traceback.h -
[.Include.internal]pycore_tuple.h -
[.Include.internal]pycore_ucnhash.h -
[.Include.internal]pycore_unionobject.h -
[.Include.internal]pycore_warnings.h -
[.Python]stdlib_module_names.h
! $(DTRACE_HEADERS)

############################################################################
# Importlib

[.$(OUT_DIR).Programs]_freeze_importlib.exe : [.$(OBJ_DIR).Programs]_freeze_importlib.obc $(LIBRARY_OBJS_OMIT_FROZEN)
  @ pipe create/dir $(DIR $(MMS$TARGET)) | copy SYS$INPUT nl:
    $(LINK)/NODEBUG/NOMAP/EXECUTABLE=python$build_out:[Programs]$(NOTDIR $(MMS$TARGET_NAME)).exe [.vms.opt]$(NOTDIR $(MMS$TARGET_NAME)).opt/OPT

[.$(OBJ_DIR).Programs]_freeze_importlib.obc : [.Programs]_freeze_importlib.c $(PYTHON_HEADERS)

[.Python]importlib_external.h : [.Lib.importlib]_bootstrap_external.py [.$(OUT_DIR).Programs]_freeze_importlib.exe
    mcr [.$(OUT_DIR).Programs]_freeze_importlib.exe importlib._bootstrap_external Lib/importlib/_bootstrap_external.py Python/importlib_external.h

[.Python]importlib.h : [.Lib.importlib]_bootstrap.py [.$(OUT_DIR).Programs]_freeze_importlib.exe
    mcr [.$(OUT_DIR).Programs]_freeze_importlib.exe importlib._bootstrap Lib/importlib/_bootstrap.py Python/importlib.h

[.Python]importlib_zipimport.h : [.Lib]zipimport.py [.$(OUT_DIR).Programs]_freeze_importlib.exe
    mcr [.$(OUT_DIR).Programs]_freeze_importlib.exe zipimport Lib/zipimport.py Python/importlib_zipimport.h

############################################################################
# Static modules
[.$(OBJ_DIR).Modules]posixmodule.obb : [.Modules]posixmodule.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]_functoolsmodule.obb : [.Modules]_functoolsmodule.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]signalmodule.obb : [.Modules]signalmodule.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]timemodule.obb : [.Modules]timemodule.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]_threadmodule.obb : [.Modules]_threadmodule.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]_localemodule.obb : [.Modules]_localemodule.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules._io]_iomodule.obb : [.Modules._io]_iomodule.c $(IO_HEADERS) $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules._io]iobase.obb : [.Modules._io]iobase.c $(IO_HEADERS) $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules._io]fileio.obb : [.Modules._io]fileio.c $(IO_HEADERS) $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules._io]bufferedio.obb : [.Modules._io]bufferedio.c $(IO_HEADERS) $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules._io]textio.obb : [.Modules._io]textio.c $(IO_HEADERS) $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules._io]bytesio.obb : [.Modules._io]bytesio.c $(IO_HEADERS) $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules._io]stringio.obb : [.Modules._io]stringio.c $(IO_HEADERS) $(PYTHON_HEADERS)

[.$(OBJ_DIR).Modules]errnomodule.obc : [.Modules]errnomodule.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]pwdmodule.obc : [.Modules]pwdmodule.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]_sre.obc : [.Modules]_sre.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]_codecsmodule.obc : [.Modules]_codecsmodule.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]_weakref.obc : [.Modules]_weakref.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]_operator.obc : [.Modules]_operator.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]_collectionsmodule.obc : [.Modules]_collectionsmodule.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]_abc.obc : [.Modules]_abc.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]itertoolsmodule.obc : [.Modules]itertoolsmodule.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]atexitmodule.obc : [.Modules]atexitmodule.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]_stat.obc : [.Modules]_stat.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]faulthandler.obc : [.Modules]faulthandler.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]_tracemalloc.obc : [.Modules]_tracemalloc.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]symtablemodule.obc : [.Modules]symtablemodule.c $(PYTHON_HEADERS)

############################################################################
# Static code

[.$(OBJ_DIR).Parser]myreadline.obc : [.Parser]myreadline.c $(PYTHON_HEADERS)

[.$(OBJ_DIR).Modules]config.obc : [.Modules]config.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]getpath.obc : [.Modules]getpath.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]main.obc : [.Modules]main.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Modules]gcmodule.obc : [.Modules]gcmodule.c $(PYTHON_HEADERS)

[.$(OBJ_DIR).Parser]pegen.obc : [.Parser]pegen.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Parser]parser.obc : [.Parser]parser.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Parser]string_parser.obc : [.Parser]string_parser.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Parser]peg_api.obc : [.Parser]peg_api.c $(PYTHON_HEADERS)

[.$(OBJ_DIR).Parser]token.obc : [.Parser]token.c $(PYTHON_HEADERS)

[.$(OBJ_DIR).Parser]tokenizer.obc : [.Parser]tokenizer.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).vms]vms_smg_readline.obc : [.vms]vms_smg_readline.c $(PYTHON_HEADERS)

[.$(OBJ_DIR).Python]_warnings.obc : [.Python]_warnings.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]Python-ast.obc : [.Python]Python-ast.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]asdl.obc : [.Python]asdl.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]ast.obc : [.Python]ast.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]ast_opt.obc : [.Python]ast_opt.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]ast_unparse.obc : [.Python]ast_unparse.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]bltinmodule.obc : [.Python]bltinmodule.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]ceval.obc : [.Python]ceval.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]codecs.obc : [.Python]codecs.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]compile.obc : [.Python]compile.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]context.obc : [.Python]context.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]dynamic_annotations.obc : [.Python]dynamic_annotations.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]errors.obc : [.Python]errors.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]frozenmain.obc : [.Python]frozenmain.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]future.obc : [.Python]future.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]getargs.obc : [.Python]getargs.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]getcompiler.obc : [.Python]getcompiler.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]getcopyright.obc : [.Python]getcopyright.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]getplatform.obc : [.Python]getplatform.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]getversion.obc : [.Python]getversion.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]hamt.obc : [.Python]hamt.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]hashtable.obc : [.Python]hashtable.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]import.obc : [.Python]import.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]importdl.obc : [.Python]importdl.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]initconfig.obc : [.Python]initconfig.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]marshal.obc : [.Python]marshal.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]modsupport.obc : [.Python]modsupport.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]mysnprintf.obc : [.Python]mysnprintf.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]mystrtoul.obc : [.Python]mystrtoul.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]pathconfig.obc : [.Python]pathconfig.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]preconfig.obc : [.Python]preconfig.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]pyarena.obc : [.Python]pyarena.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]pyctype.obc : [.Python]pyctype.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]pyfpe.obc : [.Python]pyfpe.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]pyhash.obc : [.Python]pyhash.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]pylifecycle.obc : [.Python]pylifecycle.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]pymath.obc : [.Python]pymath.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]pystate.obc : [.Python]pystate.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]pythonrun.obc : [.Python]pythonrun.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]pytime.obc : [.Python]pytime.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]bootstrap_hash.obc : [.Python]bootstrap_hash.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]structmember.obc : [.Python]structmember.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]symtable.obc : [.Python]symtable.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]sysmodule.obc : [.Python]sysmodule.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]thread.obc : [.Python]thread.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]traceback.obc : [.Python]traceback.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]getopt.obc : [.Python]getopt.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]pystrcmp.obc : [.Python]pystrcmp.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]pystrtod.obc : [.Python]pystrtod.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]pystrhex.obc : [.Python]pystrhex.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]dtoa.obc : [.Python]dtoa.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]formatter_unicode.obc : [.Python]formatter_unicode.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]fileutils.obc : [.Python]fileutils.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Python]dynload_shlib.obc : [.Python]dynload_shlib.c $(PYTHON_HEADERS)

[.$(OBJ_DIR).Objects]abstract.obc : [.Objects]abstract.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]accu.obc : [.Objects]accu.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]boolobject.obc : [.Objects]boolobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]bytes_methods.obc : [.Objects]bytes_methods.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]bytearrayobject.obc : [.Objects]bytearrayobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]bytesobject.obc : [.Objects]bytesobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]call.obc : [.Objects]call.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]capsule.obc : [.Objects]capsule.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]cellobject.obc : [.Objects]cellobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]classobject.obc : [.Objects]classobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]codeobject.obc : [.Objects]codeobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]complexobject.obc : [.Objects]complexobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]descrobject.obc : [.Objects]descrobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]enumobject.obc : [.Objects]enumobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]exceptions.obc : [.Objects]exceptions.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]genericaliasobject.obc : [.Objects]genericaliasobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]genobject.obc : [.Objects]genobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]fileobject.obc : [.Objects]fileobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]floatobject.obc : [.Objects]floatobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]frameobject.obc : [.Objects]frameobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]funcobject.obc : [.Objects]funcobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]interpreteridobject.obc : [.Objects]interpreteridobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]iterobject.obc : [.Objects]iterobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]listobject.obc : [.Objects]listobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]longobject.obc : [.Objects]longobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]dictobject.obc : [.Objects]dictobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]odictobject.obc : [.Objects]odictobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]memoryobject.obc : [.Objects]memoryobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]methodobject.obc : [.Objects]methodobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]moduleobject.obc : [.Objects]moduleobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]namespaceobject.obc : [.Objects]namespaceobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]object.obc : [.Objects]object.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]obmalloc.obc : [.Objects]obmalloc.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]picklebufobject.obc : [.Objects]picklebufobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]rangeobject.obc : [.Objects]rangeobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]setobject.obc : [.Objects]setobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]sliceobject.obc : [.Objects]sliceobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]structseq.obc : [.Objects]structseq.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]tupleobject.obc : [.Objects]tupleobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]typeobject.obc : [.Objects]typeobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]unicodeobject.obc : [.Objects]unicodeobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]unicodectype.obc : [.Objects]unicodectype.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]unionobject.obc : [.Objects]unionobject.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).Objects]weakrefobject.obc : [.Objects]weakrefobject.c $(PYTHON_HEADERS)

[.$(OBJ_DIR).Modules]getbuildinfo.obc : [.Modules]getbuildinfo.c $(PYTHON_HEADERS)
[.$(OBJ_DIR).vms]vms_poll_select_hack.obc : [.vms]vms_poll_select_hack.c $(PYTHON_HEADERS)

[.$(OBJ_DIR).Python]frozen.obc : [.Python]frozen.c -
[.Python]importlib.h -
[.Python]importlib_external.h -
[.Python]importlib_zipimport.h -
$(PYTHON_HEADERS)

############################################################################
# Library
[.$(OUT_DIR)]libpython3^.10.olb : [.$(OUT_DIR)]libpython3^.10.olb($(LIBRARY_OBJS))
    continue
