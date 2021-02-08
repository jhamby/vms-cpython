/* -*- C -*- ***********************************************
Copyright (c) 2000, BeOpen.com.
Copyright (c) 1995-2000, Corporation for National Research Initiatives.
Copyright (c) 1990-1995, Stichting Mathematisch Centrum.
All rights reserved.

See the file "Misc/COPYRIGHT" for information on usage and
redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES.
******************************************************************/

/* Module configuration */

/* !!! !!! !!! This file is edited by the makesetup script !!! !!! !!! */

/* This file contains the table of built-in modules.
   See create_builtin() in import.c. */

#include "Python.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PY_INIT_NAME(name) PyInit_##name
#define EXT_PY_INIT(name) extern PyObject* PY_INIT_NAME(name)(void)
#define PY_INIT_REC(name) { #name, PY_INIT_NAME(name) }

#undef errno
#undef _stat

EXT_PY_INIT(posix);
EXT_PY_INIT(errno);
EXT_PY_INIT(pwd);
EXT_PY_INIT(_sre);
EXT_PY_INIT(_codecs);
EXT_PY_INIT(_weakref);
EXT_PY_INIT(_functools);
EXT_PY_INIT(_operator);
EXT_PY_INIT(_collections);
EXT_PY_INIT(_abc);
EXT_PY_INIT(itertools);
EXT_PY_INIT(atexit);
EXT_PY_INIT(_signal);
EXT_PY_INIT(_stat);
EXT_PY_INIT(time);
EXT_PY_INIT(_thread);
EXT_PY_INIT(_locale);
EXT_PY_INIT(_io);
EXT_PY_INIT(faulthandler);
EXT_PY_INIT(_tracemalloc);
EXT_PY_INIT(_symtable);

/* -- ADDMODULE MARKER 1 -- */

extern PyObject* PyMarshal_Init(void);
extern PyObject* PyInit__imp(void);
extern PyObject* PyInit_gc(void);
extern PyObject* PyInit__ast(void);
extern PyObject* _PyWarnings_Init(void);
extern PyObject* PyInit__string(void);

struct _inittab _PyImport_Inittab[] = {

    PY_INIT_REC(posix),
    PY_INIT_REC(errno),
    PY_INIT_REC(pwd),
    PY_INIT_REC(_sre),
    PY_INIT_REC(_codecs),
    PY_INIT_REC(_weakref),
    PY_INIT_REC(_functools),
    PY_INIT_REC(_operator),
    PY_INIT_REC(_collections),
    PY_INIT_REC(_abc),
    PY_INIT_REC(itertools),
    PY_INIT_REC(atexit),
    PY_INIT_REC(_signal),
    PY_INIT_REC(_stat),
    PY_INIT_REC(time),
    PY_INIT_REC(_thread),
    PY_INIT_REC(_locale),
    PY_INIT_REC(_io),
    PY_INIT_REC(faulthandler),
    PY_INIT_REC(_tracemalloc),
    PY_INIT_REC(_symtable),

/* -- ADDMODULE MARKER 2 -- */

    /* This module lives in marshal.c */
    {"marshal", PyMarshal_Init},

    /* This lives in import.c */
    {"_imp", PyInit__imp},

    /* This lives in Python/Python-ast.c */
    {"_ast", PyInit__ast},

    /* These entries are here for sys.builtin_module_names */
    {"builtins", NULL},
    {"sys", NULL},

    /* This lives in gcmodule.c */
    {"gc", PyInit_gc},

    /* This lives in _warnings.c */
    {"_warnings", _PyWarnings_Init},

    /* This lives in Objects/unicodeobject.c */
    {"_string", PyInit__string},

    /* Sentinel */
    {0, 0}
};


#ifdef __cplusplus
}
#endif
