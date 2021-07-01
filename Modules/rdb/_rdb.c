#define PY_SSIZE_T_CLEAN
#include "Python.h"
#include "datetime.h"
#include "structmember.h"

#define ConvertArgToStr(arg, value, size, func_name)            \
    if (PyUnicode_CheckExact(arg)) {                            \
        (value) = (char*)PyUnicode_AsUTF8AndSize(arg, &(size)); \
    } else if (PyBytes_CheckExact(arg)) {                       \
        PyBytes_AsStringAndSize(arg, &(value), &(size));        \
    }                                                           \
    if (!(value) || !(size)) {                                  \
        _PyArg_BadArgument(func_name, #arg, "str", arg);        \
        return NULL;                                            \
    }

#define PyCLEAR(obj)    \
    if (obj) {          \
        Py_DECREF(obj); \
        obj = NULL;     \
    }

#define PyFREE(mem)     \
    if (mem) {          \
        PyMem_Free(mem);\
        mem = NULL;     \
    }

#define __NEW_STARLET 1

#include <builtins.h>
#include <descrip.h>
#include <lib$routines.h>
#include <starlet.h>
#include <str$routines.h>

#pragma names save
#pragma names uppercase
#include <sql_rdb_headers.h>
#pragma message save
#pragma message disable(CLOSECOMMENT)
#include <sql_literals.h>
#pragma message restore
#include <sql_sqlca.h>
#include <sql_sqlda.h>
extern void eib$$db_attach(void *, char *);
extern void eib$$db_detach(void *);
extern void eib$$db_commit(void *);
extern void eib$$db_rollback(void *);
extern void eib$$db_exec_immediate(void *, char *);
extern void eib$$db_exec(void *, long *, void *, void *);
extern void eib$$db_set_readonly(void *);
extern void eib$$db_set_readwrite(void *);
extern void eib$$db_release(void *, long *);
extern void eib$$db_prepare(void *, long *, char *);
extern void eib$$db_open_cursor(void *, char *, void *);
extern void eib$$db_close_cursor(void *, char *);
extern void eib$$db_declare(void *, char *, long *);
extern void eib$$db_describe_select(void *, long *, void *);
extern void eib$$db_describe_markers(void *, long *, void *);
extern void eib$$db_fetch(void *, char *, void *);
#pragma names restore

#define RDB_MODULE_NAME "_rdb"
#define STMT_TYPE_NAME  "stmt"
#define SQLCA_TYPE_NAME "sqlca"

extern int decc$feature_set(const char* __name, int __mode, int __value);
extern void vms_set_crtl_values(void);

#ifndef min
#define min(a, b)   ((a) < (b) ? (a) : (b))
#endif

#ifndef max
#define max(a, b)   ((a) > (b) ? (a) : (b))
#endif

// #pragma nomember_alignment

// #define MAXARGS        100

// typedef struct
// {
//     char    sqldaid[8];
//     int     i0;
//     short   sqln;
//     short   sqld;
//     struct  sqlvar {
//         short   sqltype;
//         long    sqldlen;
//         int     i0;
//         char    *sqldata;
//         int     *sqlnind;
//         int     i1;
//         int     i2;
//         short   l0;
//         char    d0[128];
//         char    d1[128];
//         char    d2[128];
//         char    d3[128];
//     }
//     sqlvar[MAXARGS];
// } sqlda_t;

static struct SQLCA SQLCA_initial_value = {
 "SQLCA  ", 128, 0, {0, ""}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, ""
 };

typedef struct {
    PyObject_HEAD
    struct SQLCA sqlca;
    PyObject    *pErr;
} SQLCA_Object;

typedef struct {
    PyObject_HEAD
    SQL_T_SQLDA2   *sqlda_o;
    SQL_T_SQLDA2   *sqlda_i;
    int             ncols;
    long            id;
    char            cursor[32];
    int             declared;
    SQLCA_Object   *pSQLCA;
} STMT_Object;

static volatile unsigned int global_cursor_id = 1;

extern PyTypeObject STMT_Type;

typedef long   vc_len_t;
typedef short  sc_len_t;

# define MAXVLEN 8192

typedef struct {
    unsigned long  dlen;
    char   data[MAXVLEN];
} vc_t;

/* ------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------ */

static PyObject*
RDB_error_message(
    PyObject * self,
    PyObject * args
) {
    char                    str[256];
    unsigned short          pos;
    unsigned short          len;
    struct dsc$descriptor_s dsc;

    dsc.dsc$w_length  = sizeof(str) - 1;
    dsc.dsc$b_class   = DSC$K_CLASS_S;
    dsc.dsc$b_dtype   = DSC$K_DTYPE_T;
    dsc.dsc$a_pointer = str;

    sql$get_error_text(&dsc);
    str$trim(&dsc, &dsc, &len);
    str[len] = '\0';
    return PyUnicode_FromString(str);
}

/* ------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------ */

static PyObject* SQLCA_prepare(SQLCA_Object *self, PyObject *args);
static PyObject* STMT_exec(STMT_Object *self, PyObject *const *args, Py_ssize_t nargs);
static PyObject* STMT_new(PyTypeObject *type, PyObject *args, PyObject *kwds);
static PyObject* STMT_release(STMT_Object *self, PyObject *args);
static PyObject* STMT_data(STMT_Object *self, PyObject *args);
/* ------------------------------------------------------------------------------------------------------------------------------ */
static PyObject*
SQLCA_new(
    PyTypeObject *type,
    PyObject *args,
    PyObject *kwds)
{
    SQLCA_Object *self;
    self = (SQLCA_Object *) type->tp_alloc(type, 0);
    if (self != NULL) {
        memcpy(&self->sqlca, &SQLCA_initial_value, sizeof(struct SQLCA));
        self->pErr = NULL;
    }
    return (PyObject *) self;
}

/* ------------------------------------------------------------------------------------------------------------------------------ */

static void
SQLCA_dealloc(SQLCA_Object *self)
{
    // TODO: detach?
    PyCLEAR(self->pErr);
    PyObject_Del(self);
}

/* ------------------------------------------------------------------------------------------------------------------------------ */

static int
SQLCA_init(
    SQLCA_Object *self,
    PyObject *args,
    PyObject *kwds)
{
    return 0;
}

/* ------------------------------------------------------------------------------------------------------------------------------ */

static PyObject*
SQLCA_attach(
    SQLCA_Object *self,
    PyObject *args
) {
    PyCLEAR(self->pErr);

    char *dbname = NULL;
    Py_ssize_t dbname_size = 0;
    ConvertArgToStr(args, dbname, dbname_size, "attach");

    char *tmp = alloca(dbname_size + 16);
    sprintf(tmp, "filename %s", dbname);

    decc$feature_set("DECC$UNIX_LEVEL", 1, 0);

    Py_BEGIN_ALLOW_THREADS
    eib$$db_attach(&self->sqlca, tmp);
    Py_END_ALLOW_THREADS

    vms_set_crtl_values();

    if (self->sqlca.SQLCODE != SQLCODE_SUCCESS) {
        self->pErr = RDB_error_message(NULL, NULL);
    }

    return PyLong_FromLong(self->sqlca.SQLCODE);
}

/* ------------------------------------------------------------------------------------------------------------------------------ */

static PyObject*
SQLCA_detach(
    SQLCA_Object *self,
    PyObject *args
) {
    PyCLEAR(self->pErr);

    Py_BEGIN_ALLOW_THREADS
    eib$$db_detach(&self->sqlca);
    Py_END_ALLOW_THREADS

    if (self->sqlca.SQLCODE != SQLCODE_SUCCESS) {
        self->pErr = RDB_error_message(NULL, NULL);
    }

    return PyLong_FromLong(self->sqlca.SQLCODE);
}

/* ------------------------------------------------------------------------------------------------------------------------------ */

static PyObject*
SQLCA_rollback(
    SQLCA_Object *self,
    PyObject *args
) {
    PyCLEAR(self->pErr);

    Py_BEGIN_ALLOW_THREADS
    eib$$db_rollback(&self->sqlca);
    Py_END_ALLOW_THREADS

    if (self->sqlca.SQLCODE != SQLCODE_SUCCESS) {
        self->pErr = RDB_error_message(NULL, NULL);
    }

    return PyLong_FromLong(self->sqlca.SQLCODE);
}

/* ------------------------------------------------------------------------------------------------------------------------------ */

static PyObject*
SQLCA_commit(
    SQLCA_Object *self,
    PyObject *args
) {
    PyCLEAR(self->pErr);

    Py_BEGIN_ALLOW_THREADS
    eib$$db_commit(&self->sqlca);
    Py_END_ALLOW_THREADS

    if (self->sqlca.SQLCODE != SQLCODE_SUCCESS) {
        self->pErr = RDB_error_message(NULL, NULL);
    }

    return PyLong_FromLong(self->sqlca.SQLCODE);
}

/* ------------------------------------------------------------------------------------------------------------------------------ */

static PyObject*
SQLCA_exec(
    SQLCA_Object *self,
    PyObject *const *args,
    Py_ssize_t nargs
) {
    PyCLEAR(self->pErr);

    if (nargs == 0) {
        // hmm...
        PyErr_SetString(PyExc_TypeError, "must be at least one argument");
        return NULL;
    }
    if (nargs == 1) {
        // just a command
        char *cmd = NULL;
        Py_ssize_t cmd_size = 0;
        ConvertArgToStr(args[0], cmd, cmd_size, "exec");
        Py_BEGIN_ALLOW_THREADS
        eib$$db_exec_immediate(&self->sqlca, cmd);
        Py_END_ALLOW_THREADS
        if (self->sqlca.SQLCODE != SQLCODE_SUCCESS) {
            self->pErr = RDB_error_message(NULL, NULL);
        }
        return PyLong_FromLong(self->sqlca.SQLCODE);
    } else {
        // command with parameters
        STMT_Object *pStmt = (STMT_Object *)SQLCA_prepare(self, args[0]);
        if (pStmt == NULL || ((PyObject*)pStmt) == Py_None) {
            return (PyObject*)pStmt;
        }
        PyObject *ret_code = STMT_exec(pStmt, args + 1, nargs - 1);
        // delete statement
        Py_XDECREF(STMT_release(pStmt, NULL));
        Py_DECREF(pStmt);
        return ret_code;
    }
    return NULL;
}

/* ------------------------------------------------------------------------------------------------------------------------------ */

static PyObject*
SQLCA_set_readonly(
    SQLCA_Object *self,
    PyObject *args
) {
    PyCLEAR(self->pErr);

    Py_BEGIN_ALLOW_THREADS
    eib$$db_set_readonly(&self->sqlca);
    Py_END_ALLOW_THREADS

    if (self->sqlca.SQLCODE != SQLCODE_SUCCESS) {
        self->pErr = RDB_error_message(NULL, NULL);
    }

    return PyLong_FromLong(self->sqlca.SQLCODE);
}

/* ------------------------------------------------------------------------------------------------------------------------------ */

static PyObject*
SQLCA_set_readwrite(
    SQLCA_Object *self,
    PyObject *args
) {
    PyCLEAR(self->pErr);

    Py_BEGIN_ALLOW_THREADS
    eib$$db_set_readwrite(&self->sqlca);
    Py_END_ALLOW_THREADS

    if (self->sqlca.SQLCODE != SQLCODE_SUCCESS) {
        self->pErr = RDB_error_message(NULL, NULL);
    }

    return PyLong_FromLong(self->sqlca.SQLCODE);
}

/* ------------------------------------------------------------------------------------------------------------------------------ */

static SQL_T_SQLDA2 * SQLDA_alloc(short int len) {
    len = max(1, len);
    int size = sizeof(SQL_T_SQLDA2) + sizeof(SQL_T_SQLVAR2) * (len -1);
    SQL_T_SQLDA2 *sqlda = (SQL_T_SQLDA2 *)PyMem_Calloc(1, size);
    if (sqlda != NULL) {
        strncpy(sqlda->SQLDAID, "SQLDA2  ", sizeof(sqlda->SQLDAID));
        sqlda->SQLN = len;
    }
    return sqlda;
}

static PyObject*
SQLCA_prepare(
    SQLCA_Object *self,
    PyObject *args
) {
    PyCLEAR(self->pErr);

    char *cmd = NULL;
    Py_ssize_t cmd_size = 0;
    ConvertArgToStr(args, cmd, cmd_size, "prepare");

    STMT_Object *pSTMT = (STMT_Object *)STMT_new(&STMT_Type, NULL, NULL);
    if (pSTMT == NULL) {
        return PyErr_NoMemory();
    }
    Py_INCREF(self);
    pSTMT->pSQLCA = self;

    Py_BEGIN_ALLOW_THREADS
    eib$$db_prepare(&self->sqlca, &pSTMT->id, cmd);
    Py_END_ALLOW_THREADS

    if (self->sqlca.SQLCODE != SQLCODE_SUCCESS) {
        goto error_exit;
    }

    SQL_T_SQLDA2    sqlda;
    memset(&sqlda, 0, sizeof(sqlda));
    strncpy(sqlda.SQLDAID, "SQLDA2  ", 8);

    Py_BEGIN_ALLOW_THREADS
    eib$$db_describe_select(&self->sqlca, &pSTMT->id, &sqlda);
    Py_END_ALLOW_THREADS

    pSTMT->ncols = sqlda.SQLD;
    pSTMT->sqlda_o = SQLDA_alloc(sqlda.SQLD);

    Py_BEGIN_ALLOW_THREADS
    eib$$db_describe_select(&self->sqlca, &pSTMT->id, pSTMT->sqlda_o);
    Py_END_ALLOW_THREADS

    if (self->sqlca.SQLCODE != SQLCODE_SUCCESS) {
        goto error_exit;
    }

    memset(&sqlda, 0, sizeof(sqlda));
    strncpy(sqlda.SQLDAID, "SQLDA2  ", 8);
    Py_BEGIN_ALLOW_THREADS
    eib$$db_describe_markers(&self->sqlca, &pSTMT->id, &sqlda);
    Py_END_ALLOW_THREADS

    pSTMT->sqlda_i = SQLDA_alloc(sqlda.SQLD);

    Py_BEGIN_ALLOW_THREADS
    eib$$db_describe_markers(&self->sqlca, &pSTMT->id, pSTMT->sqlda_i);
    Py_END_ALLOW_THREADS

    if (self->sqlca.SQLCODE != SQLCODE_SUCCESS) {
        goto error_exit;
    }

    for (int i = 0; i < pSTMT->sqlda_i->SQLD; i++) {
        pSTMT->sqlda_i->SQLVAR[i].SQLDATA = (char*) PyMem_Calloc(1, pSTMT->sqlda_i->SQLVAR[i].SQLOCTET_LEN);
        if (pSTMT->sqlda_i->SQLVAR[i].SQLDATA == NULL) {
            Py_DECREF(pSTMT);
            return PyErr_NoMemory();
        }
    }

    for (int i = 0; i < pSTMT->sqlda_o->SQLD; i++) {
        pSTMT->sqlda_o->SQLVAR[i].SQLIND = PyMem_Calloc(1, sizeof(int));
        if (pSTMT->sqlda_o->SQLVAR[i].SQLIND == NULL) {
            Py_DECREF(pSTMT);
            return PyErr_NoMemory();
        }
        pSTMT->sqlda_o->SQLVAR[i].SQLDATA = PyMem_Calloc(1, pSTMT->sqlda_o->SQLVAR[i].SQLOCTET_LEN);
        if (pSTMT->sqlda_o->SQLVAR[i].SQLDATA == NULL) {
            Py_DECREF(pSTMT);
            return PyErr_NoMemory();
        }
    }
    __ATOMIC_INCREMENT_LONG(&global_cursor_id);
    sprintf(pSTMT->cursor, "$DC_%08d", global_cursor_id);
    pSTMT->declared = 0;

    return (PyObject*)pSTMT;

error_exit:
    {
        PyObject *pErr = RDB_error_message(NULL, NULL);
        Py_XDECREF(STMT_release(pSTMT, NULL));
        PyCLEAR(self->pErr);
        self->pErr = pErr;
    }
    Py_DECREF(pSTMT);
    Py_RETURN_NONE;
}

/* ------------------------------------------------------------------------------------------------------------------------------ */

static PyObject*
SQLCA_declare_cursor(
    SQLCA_Object *self,
    PyObject *const *args,
    Py_ssize_t nargs
) {
    PyCLEAR(self->pErr);

    if (!_PyArg_CheckPositional("declare_cursor", nargs, 2, 2)) {
        return NULL;
    }

    char *cursor = NULL;
    Py_ssize_t cursor_size = 0;
    ConvertArgToStr(args[0], cursor, cursor_size, "declare_cursor");

    STMT_Object *pSTMT = NULL;
    if (strcmp(Py_TYPE(args[1])->tp_name, RDB_MODULE_NAME "." STMT_TYPE_NAME) == 0) {
        pSTMT = (STMT_Object *)args[1];
        if (pSTMT->pSQLCA != self) {
            PyErr_SetString(PyExc_RuntimeError, "SQLCA are not identical");
            return NULL;
        }
        Py_INCREF(pSTMT);
    } else if (PyUnicode_CheckExact(args[1]) || PyBytes_CheckExact(args[1])) {
        pSTMT = (STMT_Object *)SQLCA_prepare(self, args[1]);
        if (pSTMT == NULL || (PyObject*)pSTMT == Py_None) {
            return (PyObject*)pSTMT;
        }
    } else {
        _PyArg_BadArgument("declare_cursor", "args[1]", "str | bytes", args[1]);
    }

    cursor_size = min(cursor_size, sizeof(pSTMT->cursor) - 1);
    strncpy(pSTMT->cursor, cursor, cursor_size);

    Py_BEGIN_ALLOW_THREADS
    eib$$db_declare(&self->sqlca, pSTMT->cursor, &pSTMT->id);
    Py_END_ALLOW_THREADS

    if (self->sqlca.SQLCODE != SQLCODE_SUCCESS) {
        self->pErr = RDB_error_message(NULL, NULL);
        Py_DECREF(pSTMT);
        Py_RETURN_NONE;
    }

    return (PyObject*)pSTMT;
}

/* ------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------------------------------------------------ */

static PyObject*
STMT_new(
    PyTypeObject *type,
    PyObject *args,
    PyObject *kwds)
{
    STMT_Object *self;
    self = (STMT_Object *) type->tp_alloc(type, 0);
    if (self != NULL) {
        self->id = 0;
        self->ncols = 0;
        self->cursor[0] = 0;
        self->sqlda_i = NULL;
        self->sqlda_o = NULL;
        self->pSQLCA = NULL;
    }
    return (PyObject *) self;
}

/* ------------------------------------------------------------------------------------------------------------------------------ */

static void
STMT_dealloc(STMT_Object *self)
{
    PyObject *pTmp = STMT_release(self, NULL);
    Py_XDECREF(pTmp);
    PyCLEAR(self->pSQLCA);
    if (self->sqlda_i) {
        for(int i = 0; i < self->sqlda_i->SQLD; ++i) {
            PyFREE(self->sqlda_i->SQLVAR[i].SQLDATA);
            PyFREE(self->sqlda_i->SQLVAR[i].SQLIND);
        }
        PyFREE(self->sqlda_i);
    }
    if (self->sqlda_o) {
        for(int i = 0; i < self->sqlda_o->SQLD; ++i) {
            PyFREE(self->sqlda_o->SQLVAR[i].SQLDATA);
            PyFREE(self->sqlda_o->SQLVAR[i].SQLIND);
        }
        PyFREE(self->sqlda_o);
    }
    PyObject_Del(self);
}

/* ------------------------------------------------------------------------------------------------------------------------------ */
static STMT_Object *fill_statement(
    STMT_Object *pStmt,
    PyObject *const *args,
    Py_ssize_t nargs
) {
    vc_t *vcp;
    char *str;
    Py_ssize_t str_size;
    PyObject* objectsRepresentation;
    long long long_value;
    double double_value;
    char tmp[32], *t;

    if (pStmt->sqlda_i->SQLD != nargs) {
        PyErr_Format(PyExc_TypeError, "Must be %i args, given %i", pStmt->sqlda_i->SQLD, nargs);
        return NULL;
    }
    for (int i = 0; i < nargs; i++) {
        switch (pStmt->sqlda_i->SQLVAR[i].SQLTYPE) {
            case SQLDA_VARCHAR:
                // 1. clean 
                vcp = (vc_t *) pStmt->sqlda_i->SQLVAR[i].SQLDATA;
                memset(vcp->data, 0, pStmt->sqlda_i->SQLVAR[i].SQLLEN);
                vcp->dlen = strlen(vcp->data);
                // 2. create ASCII from PyObject
                if (PyUnicode_CheckExact(args[i])) {
                    objectsRepresentation = NULL;
                    str = (char*)PyUnicode_AsUTF8AndSize(args[i], &str_size);
                } else if (PyBytes_CheckExact(args[i])) {
                    objectsRepresentation = NULL;
                    PyBytes_AsStringAndSize(args[i], &str, &str_size);
                } else {
                    objectsRepresentation = PyObject_Repr(args[i]);
                    str = (char*)PyUnicode_AsUTF8AndSize(objectsRepresentation, &str_size);
                }
                // 3. copy string
                if (str && str_size) {
                    if (str_size > pStmt->sqlda_i->SQLVAR[i].SQLLEN) {
                        str_size = pStmt->sqlda_i->SQLVAR[i].SQLLEN;
                    }
                    strncpy(vcp->data, str, str_size);
                    vcp->dlen = strlen(vcp->data);
                }
                Py_XDECREF(objectsRepresentation);
                objectsRepresentation = NULL;
                PyErr_Clear();
                break;

            case SQLDA_CHAR:
                // 1. clean
                memset(pStmt->sqlda_i->SQLVAR[i].SQLDATA, ' ', pStmt->sqlda_i->SQLVAR[i].SQLLEN);
                // 2. create ASCII from PyObject
                if (PyUnicode_CheckExact(args[i])) {
                    objectsRepresentation = NULL;
                    str = (char*)PyUnicode_AsUTF8AndSize(args[i], &str_size);
                } else if (PyBytes_CheckExact(args[i])) {
                    objectsRepresentation = NULL;
                    PyBytes_AsStringAndSize(args[i], &str, &str_size);
                } else {
                    objectsRepresentation = PyObject_Repr(args[i]);
                    str = (char*)PyUnicode_AsUTF8AndSize(objectsRepresentation, &str_size);
                }
                // 3. copy string
                if (str && str_size) {
                    if (str_size > pStmt->sqlda_i->SQLVAR[i].SQLLEN) {
                        str_size = pStmt->sqlda_i->SQLVAR[i].SQLLEN;
                    }
                    memcpy(pStmt->sqlda_i->SQLVAR[i].SQLDATA, str, str_size);
                }
                Py_XDECREF(objectsRepresentation);
                objectsRepresentation = NULL;
                PyErr_Clear();
                break;

            case SQLDA_ROWID:
            case SQLDA_DECIMAL:
            case SQLDA_TINYINT:
            case SQLDA_SMALLINT:
            case SQLDA_INTEGER:
            case SQLDA_SEGSTRING:
            case SQLDA_QUADWORD:
                str = NULL;
                long_value = 0;
                if (PyUnicode_CheckExact(args[i])) {
                    str = (char*)PyUnicode_AsUTF8AndSize(args[i], &str_size);
                } else if (PyBytes_CheckExact(args[i])) {
                    PyBytes_AsStringAndSize(args[i], &str, &str_size);
                } else if (PyLong_Check(args[i])) {
                    long_value = PyLong_AsLongLong(args[i]);
                } else {
                    PyErr_Format(PyExc_TypeError, "Incompatible type at pos %i", i + 1);
                    return NULL;
                    // long_value = 0;
                }
                if (str && str_size) {
                    objectsRepresentation = PyLong_FromString(str, NULL, 10);
                    long_value = PyLong_AsLongLong(objectsRepresentation);
                    Py_DECREF(objectsRepresentation);
                    objectsRepresentation = NULL;
                }
                if (pStmt->sqlda_i->SQLVAR[i].SQLOCTET_LEN <= sizeof(long_value)) {
                    memcpy(pStmt->sqlda_i->SQLVAR[i].SQLDATA, &long_value, pStmt->sqlda_i->SQLVAR[i].SQLOCTET_LEN);
                } else {
                    PyErr_Format(PyExc_TypeError, "Incompatible type at pos %i", i + 1);
                    return NULL;
                    // memcpy(pStmt->sqlda_i->SQLVAR[i].SQLDATA, &long_value, sizeof(long_value));
                    // memset(pStmt->sqlda_i->SQLVAR[i].SQLDATA + sizeof(long_value), 0, pStmt->sqlda_i->SQLVAR[i].SQLOCTET_LEN - sizeof(long_value));
                }
                PyErr_Clear();
                break;

            case SQLDA_FLOAT:
                if (PyFloat_Check (args[i])) {
                    double_value = PyFloat_AsDouble(args[i]);
                } else {
                    objectsRepresentation = PyFloat_FromString(args[i]);
                    if (!objectsRepresentation) {
                        PyErr_Format(PyExc_TypeError, "Incompatible type at pos %i", i + 1);
                        return NULL;
                        // double_value = 0;
                    } else {
                        double_value = PyFloat_AsDouble(objectsRepresentation);
                        Py_DECREF(objectsRepresentation);
                        objectsRepresentation = NULL;
                    }
                }
                if (pStmt->sqlda_i->SQLVAR[i].SQLLEN == sizeof(float)) {
                    *(float*)pStmt->sqlda_i->SQLVAR[i].SQLDATA = (float)double_value;
                } else if (pStmt->sqlda_i->SQLVAR[i].SQLLEN == sizeof(double)) {
                    *(double*)pStmt->sqlda_i->SQLVAR[i].SQLDATA = double_value;
                } else {
                    PyErr_Format(PyExc_TypeError, "Incompatible type at pos %i", i + 1);
                    return NULL;
                    // memset(pStmt->sqlda_i->SQLVAR[i].SQLDATA, 0, pStmt->sqlda_i->SQLVAR[i].SQLLEN);
                }
                PyErr_Clear();
                break;

            case SQLDA2_DATETIME:
            case SQLDA2_INTERVAL:
            case SQLDA_DATE:
                if (pStmt->sqlda_i->SQLVAR[i].SQLOCTET_LEN != 8) {
                    PyErr_Format(PyExc_TypeError, "Invalid SQLOCTET_LEN at pos %i", i + 1);
                    return NULL;
                    // memset(pStmt->sqlda_i->SQLVAR[i].SQLDATA, 0, pStmt->sqlda_i->SQLVAR[i].SQLOCTET_LEN);
                    // break;
                }
                if (PyUnicode_CheckExact(args[i])) {
                    objectsRepresentation = NULL;
                    str = (char*)PyUnicode_AsUTF8AndSize(args[i], &str_size);
                } else if (PyBytes_CheckExact(args[i])) {
                    objectsRepresentation = NULL;
                    PyBytes_AsStringAndSize(args[i], &str, &str_size);
                } else {
                    objectsRepresentation = PyObject_Repr(args[i]);
                    str = (char*)PyUnicode_AsUTF8AndSize(objectsRepresentation, &str_size);
                }
                if (!str || !str_size) {
                    PyErr_Format(PyExc_TypeError, "Incompatible type at pos %i", i + 1);
                    return NULL;
                    // memset(pStmt->sqlda_i->SQLVAR[i].SQLDATA, 0, pStmt->sqlda_i->SQLVAR[i].SQLOCTET_LEN);
                } else {
                    struct dsc$descriptor_s tmp_dsc;
                    tmp_dsc.dsc$w_length = str_size;
                    tmp_dsc.dsc$b_class = DSC$K_CLASS_S;
                    tmp_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
                    tmp_dsc.dsc$a_pointer = str;
                    memset(pStmt->sqlda_i->SQLVAR[i].SQLDATA, 0, pStmt->sqlda_i->SQLVAR[i].SQLOCTET_LEN);
                    if (1 != sys$bintim(&tmp_dsc, (struct _generic_64 *)pStmt->sqlda_i->SQLVAR[i].SQLDATA)) {
                        PyErr_Format(PyExc_TypeError, "Invalid time string (%s)", str);
                        return NULL;
                    }
                }
                PyErr_Clear();
                break;

            case SQLDA_ASCIZ:
            case SQLDA_VARBYTE:
            case SQLDA_SURROGATE:
            case SQLDA_VARBINARY:
            case SQLDA_BINARY:
                PyErr_Format(PyExc_TypeError, "Unsupported data type %i at pos %i", pStmt->sqlda_i->SQLVAR[i].SQLTYPE, i + 1);
                return NULL;

            default:
                PyErr_Format(PyExc_TypeError, "Unknown data type %i at pos %i", pStmt->sqlda_i->SQLVAR[i].SQLTYPE, i + 1);
                return NULL;
        }
    }
    return pStmt;
}
/* ------------------------------------------------------------------------------------------------------------------------------ */

static PyObject*
STMT_exec(
    STMT_Object *self,
    PyObject *const *args,
    Py_ssize_t nargs
) {
    if (self->pSQLCA == NULL) {
        return NULL;
    }
    PyCLEAR(self->pSQLCA->pErr);

    if (nargs > 0 && !fill_statement(self, args, nargs)) {
        return NULL;
    }

    Py_BEGIN_ALLOW_THREADS
    eib$$db_exec(&self->pSQLCA->sqlca, &self->id, self->sqlda_i, self->sqlda_o);
    Py_END_ALLOW_THREADS

    if (self->pSQLCA->sqlca.SQLCODE != SQLCODE_SUCCESS) {
        self->pSQLCA->pErr = RDB_error_message(NULL, NULL);
    }

    return PyLong_FromLong(self->pSQLCA->sqlca.SQLCODE);
}

/* ------------------------------------------------------------------------------------------------------------------------------ */
static PyObject*
STMT_select(
    STMT_Object *self,
    PyObject *const *args,
    Py_ssize_t nargs
) {
    if (self->pSQLCA == NULL) {
        return NULL;
    }
    PyCLEAR(self->pSQLCA->pErr);

    if (nargs > 0 && !fill_statement(self, args, nargs)) {
        return NULL;
    }

    if (!self->declared) {
        Py_BEGIN_ALLOW_THREADS
        eib$$db_declare(&self->pSQLCA->sqlca, self->cursor, &self->id);
        Py_END_ALLOW_THREADS
        if (self->pSQLCA->sqlca.SQLCODE != SQLCODE_SUCCESS) {
            self->pSQLCA->pErr = RDB_error_message(NULL, NULL);
            return PyLong_FromLong(self->pSQLCA->sqlca.SQLCODE);
        }
    }

    self->declared = 1;

    Py_BEGIN_ALLOW_THREADS
    eib$$db_open_cursor(&self->pSQLCA->sqlca, self->cursor, self->sqlda_i);
    Py_END_ALLOW_THREADS

    if (self->pSQLCA->sqlca.SQLCODE != SQLCODE_SUCCESS) {
        self->pSQLCA->pErr = RDB_error_message(NULL, NULL);
        return PyLong_FromLong(self->pSQLCA->sqlca.SQLCODE);
    }

    Py_BEGIN_ALLOW_THREADS
    eib$$db_fetch(&self->pSQLCA->sqlca, self->cursor, self->sqlda_o);
    Py_END_ALLOW_THREADS

    // list to return 
    PyObject *pList = NULL;

    // save fetch status
    int fetch_code = self->pSQLCA->sqlca.SQLCODE;
    PyObject *pErr = NULL;
    if (fetch_code != SQLCODE_SUCCESS) {
        // save error
        pErr = RDB_error_message(NULL, NULL);
    } else {
        // get data
        pList = STMT_data(self, NULL);
    }

    // close cursor in any case without checking an error
    Py_BEGIN_ALLOW_THREADS
    eib$$db_close_cursor(&self->pSQLCA->sqlca, self->cursor);
    Py_END_ALLOW_THREADS

    // restore fetch status
    self->pSQLCA->pErr = pErr;
    self->pSQLCA->sqlca.SQLCODE = fetch_code;

    // check errors from STMT_data
    if (!pList) {
        Py_RETURN_NONE;
    }

    return pList;
}

/* ------------------------------------------------------------------------------------------------------------------------------ */

static PyObject*
STMT_release(
    STMT_Object *self,
    PyObject *args
) {
    if (self->pSQLCA == NULL) {
        return NULL;
    }
    PyCLEAR(self->pSQLCA->pErr);

    if (self->id) {
        Py_BEGIN_ALLOW_THREADS
        eib$$db_release(&self->pSQLCA->sqlca, &self->id);
        Py_END_ALLOW_THREADS
        self->id = 0;
    }

    if (self->pSQLCA->sqlca.SQLCODE != SQLCODE_SUCCESS) {
        self->pSQLCA->pErr = RDB_error_message(NULL, NULL);
    }

    return PyLong_FromLong(self->pSQLCA->sqlca.SQLCODE);
}

/* ------------------------------------------------------------------------------------------------------------------------------ */

static PyObject*
STMT_open_cursor(
    STMT_Object *self,
    PyObject *const *args,
    Py_ssize_t nargs
) {
    if (self->pSQLCA == NULL) {
        return NULL;
    }
    PyCLEAR(self->pSQLCA->pErr);

    if (nargs > 0 && !fill_statement(self, args, nargs)) {
        return NULL;
    }

    Py_BEGIN_ALLOW_THREADS
    eib$$db_open_cursor(&self->pSQLCA->sqlca, self->cursor, self->sqlda_i);
    Py_END_ALLOW_THREADS

    if (self->pSQLCA->sqlca.SQLCODE != SQLCODE_SUCCESS) {
        self->pSQLCA->pErr = RDB_error_message(NULL, NULL);
    }

    return PyLong_FromLong(self->pSQLCA->sqlca.SQLCODE);
}

/* ------------------------------------------------------------------------------------------------------------------------------ */

static PyObject*
STMT_close_cursor(
    STMT_Object *self,
    PyObject *args
) {
    if (self->pSQLCA == NULL) {
        return NULL;
    }
    PyCLEAR(self->pSQLCA->pErr);

    Py_BEGIN_ALLOW_THREADS
    eib$$db_close_cursor(&self->pSQLCA->sqlca, self->cursor);
    Py_END_ALLOW_THREADS

    if (self->pSQLCA->sqlca.SQLCODE != SQLCODE_SUCCESS) {
        self->pSQLCA->pErr = RDB_error_message(NULL, NULL);
    }

    return PyLong_FromLong(self->pSQLCA->sqlca.SQLCODE);
}

/* ------------------------------------------------------------------------------------------------------------------------------ */

static PyObject*
STMT_fetch(
    STMT_Object *self,
    PyObject *args
) {
    if (self->pSQLCA == NULL) {
        return NULL;
    }
    PyCLEAR(self->pSQLCA->pErr);

    Py_BEGIN_ALLOW_THREADS
    eib$$db_fetch(&self->pSQLCA->sqlca, self->cursor, self->sqlda_o);
    Py_END_ALLOW_THREADS

    if (self->pSQLCA->sqlca.SQLCODE != SQLCODE_SUCCESS) {
        self->pSQLCA->pErr = RDB_error_message(NULL, NULL);
    }

    return PyLong_FromLong(self->pSQLCA->sqlca.SQLCODE);
}

/* ------------------------------------------------------------------------------------------------------------------------------ */

enum TIMBUF_POS {
    YEAR = 0,
    MONTH,
    DAY,
    HOUR,
    MINUTE,
    SECOND,
    SUBSEC,
};

enum TIMBUF_MUL {
    DAYHOUR = 24,
    DAYMIN  = 24*60,
    DAYSEC  = 24*60*60,
    HOURMIN = 60,
    HOURSEC = 60*60,
    MINSEC  = 60,
};

static PyObject*
STMT_data(
    STMT_Object *self,
    PyObject *args
) {
    if (self->pSQLCA == NULL) {
        return NULL;
    }
    PyCLEAR(self->pSQLCA->pErr);

    PyObject *pList = PyList_New(self->sqlda_o->SQLD);
    if (pList == NULL) {
        return PyErr_NoMemory();
    }

    vc_len_t len;
    PyObject *pValue;
    SQL_T_SQLVAR2 *pVar;
    long long long_long_value;
    double double_value;
    unsigned short int timbuf[7];
    int sign;

    static PyObject *pNullStr = NULL;
    if (pNullStr == NULL) {
        pNullStr = PyUnicode_FromString("<null>");
    }

    static PyObject *pInvalidStr = NULL;
    if (pInvalidStr == NULL) {
        pInvalidStr = PyUnicode_FromString("<inv>");
    }

    for(int i = 0; i < self->sqlda_o->SQLD; ++i) {
        pVar = &self->sqlda_o->SQLVAR[i];
        pValue = NULL;
        if (*pVar->SQLIND < 0) {
            pValue = pNullStr;
            Py_INCREF(pValue);
        } else {
            switch (pVar->SQLTYPE) {
                case SQLDA_VARCHAR:
                    len = (vc_len_t) *pVar->SQLDATA;
                    if (len < 0) {              /* Hack */
                        len += 256;
                    }
                    pValue = PyUnicode_FromStringAndSize(pVar->SQLDATA + sizeof(vc_len_t), len);
                    break;
                case SQLDA_CHAR:
                    len = pVar->SQLLEN;
                    pValue = PyUnicode_FromStringAndSize(pVar->SQLDATA, len);
                    break;
                case SQLDA_FLOAT:
                    if (pVar->SQLLEN == 8) {
                        pValue = PyFloat_FromDouble(*(double *)pVar->SQLDATA);
                    } else if (pVar->SQLLEN == 4) {
                        pValue = PyFloat_FromDouble(*(float *)pVar->SQLDATA);
                    } else {
                        pValue = pInvalidStr;
                        Py_INCREF(pValue);
                    }
                    break;
                case SQLDA_SEGSTRING:
                case SQLDA_TINYINT:
                case SQLDA_QUADWORD:
                case SQLDA_DECIMAL:
                case SQLDA_SMALLINT:
                case SQLDA_INTEGER:
                    if (pVar->SQLOCTET_LEN <= sizeof(long_long_value)) {
                        long_long_value = 0;
                        memcpy(&long_long_value, pVar->SQLDATA, pVar->SQLOCTET_LEN);
                        pValue = PyLong_FromLongLong(long_long_value);
                    } else {
                        // PyErr_Format(PyExc_TypeError, "Incompatible type at pos %i", i + 1);
                        // return NULL;
                        pValue = pInvalidStr;
                        Py_INCREF(pValue);
                    }
                    break;
                case SQLDA2_INTERVAL:
                    long_long_value = *(long long*)pVar->SQLDATA;
                    switch(pVar->SQLLEN) {
                        case SQLDA2_DT_YEAR:
                            pValue = PyLong_FromLong(long_long_value / 12);
                            break;
                        case SQLDA2_DT_MONTH:
                            pValue = PyLong_FromLong(long_long_value);
                            break;
                        case SQLDA2_DT_YEAR_MONTH:
                            sign = 1;
                            if (long_long_value < 0) {
                                sign = -1;
                                long_long_value = -long_long_value;
                            }
                            pValue = Py_BuildValue("(i,i)", sign*(long_long_value/12), sign*(long_long_value%12));
                            break;
                        case SQLDA2_DT_SECOND:
                        case SQLDA2_DT_MINUTE:
                        case SQLDA2_DT_HOUR:
                        case SQLDA2_DT_DAY:
                        case SQLDA2_DT_DAY_HOUR:
                        case SQLDA2_DT_DAY_MINUTE:
                        case SQLDA2_DT_DAY_SECOND:
                        case SQLDA2_DT_HOUR_MINUTE:
                        case SQLDA2_DT_HOUR_SECOND:
                        case SQLDA2_DT_MINUTE_SECOND:
                            sign = -1;
                            if (long_long_value > 0) {
                                sign = 1;
                                long_long_value = -long_long_value;
                            }
                            if (1 != sys$numtim(timbuf, (struct _generic_64*)&long_long_value)) {
                                pValue = pInvalidStr;
                                Py_INCREF(pValue);
                            } else {
                                if (!PyDateTimeAPI) {
                                    PyDateTime_IMPORT;
                                }
                                if (!PyDateTimeAPI) {
                                    pValue = pInvalidStr;
                                    Py_INCREF(pValue);
                                } else {
                                    switch(pVar->SQLLEN) {
                                        case SQLDA2_DT_SECOND:
                                            long_long_value = timbuf[DAY] * DAYSEC + timbuf[HOUR] * HOURSEC + timbuf[MINUTE] * MINSEC + timbuf[SECOND];
                                            double_value = 0.01 * timbuf[SUBSEC] + long_long_value;
                                            pValue = PyFloat_FromDouble(sign*double_value);
                                            break;
                                        case SQLDA2_DT_MINUTE:
                                            long_long_value = timbuf[DAY] * DAYMIN + timbuf[HOUR] * HOURMIN + timbuf[MINUTE];
                                            pValue = PyLong_FromLongLong(sign*long_long_value);
                                            break;
                                        case SQLDA2_DT_HOUR:
                                            long_long_value = timbuf[DAY] * DAYHOUR + timbuf[HOUR];
                                            pValue = PyLong_FromLongLong(sign*long_long_value);
                                            break;
                                        case SQLDA2_DT_DAY:
                                            long_long_value = timbuf[DAY];
                                            pValue = PyLong_FromLongLong(sign*long_long_value);
                                            break;
                                        case SQLDA2_DT_DAY_HOUR:
                                            pValue = Py_BuildValue("(i,i)", sign*timbuf[DAY], sign*timbuf[HOUR]);
                                            break;
                                        case SQLDA2_DT_DAY_MINUTE:
                                            pValue = Py_BuildValue("(i,i,i)", sign*timbuf[DAY], sign*timbuf[HOUR], sign*timbuf[MINUTE]);
                                            break;
                                        case SQLDA2_DT_DAY_SECOND:
                                            pValue = Py_BuildValue("(i,i,i,d)", sign*timbuf[DAY], sign*timbuf[HOUR], sign*timbuf[MINUTE], sign*(timbuf[SECOND] + 0.01 * timbuf[SUBSEC]));
                                            break;
                                        case SQLDA2_DT_HOUR_MINUTE:
                                            pValue = Py_BuildValue("(i,i)", sign*(timbuf[DAY] * DAYHOUR + timbuf[HOUR]), sign*timbuf[MINUTE]);
                                            break;
                                        case SQLDA2_DT_HOUR_SECOND:
                                            pValue = Py_BuildValue("(i,i,d)", sign*(timbuf[DAY] * DAYHOUR + timbuf[HOUR]), sign*timbuf[MINUTE], sign*(timbuf[SECOND] + 0.01 * timbuf[SUBSEC]));
                                            break;
                                        case SQLDA2_DT_MINUTE_SECOND:
                                            pValue = Py_BuildValue("(i,d)", sign*(timbuf[DAY] * DAYMIN + timbuf[HOUR] * HOURMIN + timbuf[MINUTE]), sign*(timbuf[SECOND] + 0.01 * timbuf[SUBSEC]));
                                            break;
                                        default:
                                            pValue = pInvalidStr;
                                            Py_INCREF(pValue);
                                    }
                                }
                            }
                            break;
                        default:
                            pValue = pInvalidStr;
                            Py_INCREF(pValue);
                    }
                    break;
                case SQLDA2_DATETIME:
                case SQLDA_DATE:
                    if (1 != sys$numtim(timbuf, (struct _generic_64*)pVar->SQLDATA)) {
                        pValue = pInvalidStr;
                        Py_INCREF(pValue);
                    } else {
                        if (!PyDateTimeAPI) {
                            PyDateTime_IMPORT;
                        }
                        if (!PyDateTimeAPI) {
                            pValue = pInvalidStr;
                            Py_INCREF(pValue);
                        } else {
                            switch (pVar->SQLCHRONO_SCALE) {
                                case 0:
                                case 3:
                                    pValue = PyDateTime_FromDateAndTime(timbuf[0], timbuf[1], timbuf[2],
                                        timbuf[3], timbuf[4], timbuf[5], timbuf[6]);
                                    break;
                                case 1:
                                    pValue = PyDate_FromDate(timbuf[0], timbuf[1], timbuf[2]);
                                    break;
                                case 2:
                                    pValue = PyTime_FromTime(timbuf[3], timbuf[4], timbuf[5], timbuf[6]);
                                    break;
                                default:
                                    pValue = pInvalidStr;
                                    Py_INCREF(pValue);
                                    break;
                            }
                        }
                    }
                    break;
                case SQLDA_ASCIZ:
                case SQLDA_VARBYTE:
                case SQLDA_SURROGATE:
                case SQLDA_VARBINARY:
                case SQLDA_BINARY:
                case SQLDA_ROWID:
                    pValue = pInvalidStr;
                    Py_INCREF(pValue);
                    break;
                default:
                    pValue = pInvalidStr;
                    Py_INCREF(pValue);
                    break;
            }
        }
        if (pValue) {
            if (-1 == PyList_SetItem(pList, i, pValue)) {
                PyErr_SetString(PyExc_RuntimeError, "PyList_SetItem failed");
                Py_DECREF(pList);
                return NULL;
            }
        } else {
            PyErr_Format(PyExc_RuntimeError, "Cannot create value from column %i", i + 1);
            Py_DECREF(pList);
            return NULL;
        }
    }
    return pList;
}

/* ------------------------------------------------------------------------------------------------------------------------------ */

static PyObject*
STMT_fields(
    STMT_Object *self,
    PyObject *args
) {
    if (self->pSQLCA == NULL) {
        return NULL;
    }
    PyCLEAR(self->pSQLCA->pErr);

    PyObject *pList = PyList_New(self->sqlda_o->SQLD);
    if (pList == NULL) {
        return PyErr_NoMemory();
    }

    vc_len_t len;
    PyObject *pValue;
    SQL_T_SQLVAR2 *pVar;

    for(int i = 0; i < self->sqlda_o->SQLD; ++i) {
        pVar = &self->sqlda_o->SQLVAR[i];
        pValue = NULL;
        len = 0;
        switch (pVar->SQLTYPE) {
            case SQLDA_VARCHAR:
                len = pVar->SQLLEN;
                break;
            case SQLDA_CHAR:
            case SQLDA_FLOAT:
            case SQLDA_SEGSTRING:
            case SQLDA_TINYINT:
            case SQLDA_QUADWORD:
            case SQLDA_DECIMAL:
            case SQLDA_SMALLINT:
            case SQLDA_INTEGER:
            case SQLDA2_DATETIME:
            case SQLDA2_INTERVAL:
            case SQLDA_DATE:
                // supported
                len = pVar->SQLOCTET_LEN;
                break;
            case SQLDA_ASCIZ:
            case SQLDA_VARBYTE:
            case SQLDA_SURROGATE:
            case SQLDA_VARBINARY:
            case SQLDA_BINARY:
            case SQLDA_ROWID:
                // unsupported
                len = pVar->SQLOCTET_LEN;
                break;
            default:
                // unknown
                len = 0;
                break;
        }
        pValue = Py_BuildValue("(s#,i,i)", pVar->SQLNAME, pVar->SQLNAME_LEN, pVar->SQLTYPE, len);
        if (-1 == PyList_SetItem(pList, i, pValue)) {
            PyErr_SetString(PyExc_RuntimeError, "PyList_SetItem failed");
            Py_DECREF(pList);
            return NULL;
        }
    }
    return pList;
}

/* ------------------------------------------------------------------------------------------------------------------------------ */


/********************************************************************
  SQLCA Type
*/

static PyMethodDef SQLCA_methods[] = {
    {"attach", (PyCFunction) SQLCA_attach, METH_O,
        PyDoc_STR("attach(dbname: str)->status: int   Attach")},
    {"detach", (PyCFunction) SQLCA_detach, METH_NOARGS,
        PyDoc_STR("detach()->status: int   Detach")},
    {"rollback", (PyCFunction) SQLCA_rollback, METH_NOARGS,
        PyDoc_STR("rollback()->status: int   Rollback")},
    {"commit", (PyCFunction) SQLCA_commit, METH_NOARGS,
        PyDoc_STR("commit()->status: int   Commit")},
    {"exec", (PyCFunction) SQLCA_exec, METH_FASTCALL,
        PyDoc_STR("exec(cmd: str, *args)->status: int   Exec")},
    {"set_readonly", (PyCFunction) SQLCA_set_readonly, METH_NOARGS,
        PyDoc_STR("set_readonly()->status: int   Set readonly")},
    {"set_readwrite", (PyCFunction) SQLCA_set_readwrite, METH_NOARGS,
        PyDoc_STR("set_readwrite()->status: int   Set readwrite")},
    {"prepare", (PyCFunction) SQLCA_prepare, METH_O,
        PyDoc_STR("prepare(cmd: str)->stmt: stmt   Prepare")},
    {"declare_cursor", (PyCFunction) SQLCA_declare_cursor, METH_FASTCALL,
        PyDoc_STR("declare_cursor(name: str, cmd: str)->stmt: stmt   Declare cursor")},

    {NULL, NULL}
};

static PyMemberDef SQLCA_members[] = {
    {"code", T_INT, offsetof(SQLCA_Object, sqlca.SQLCODE), READONLY,
     "SQLCODE"},
    {"message", T_OBJECT, offsetof(SQLCA_Object, pErr), READONLY,
     "Error message"},
    {NULL}
};

PyTypeObject SQLCA_Type = {
    PyObject_HEAD_INIT(NULL)
    RDB_MODULE_NAME "." SQLCA_TYPE_NAME,
    .tp_basicsize = sizeof(SQLCA_Object),
    .tp_dealloc = (destructor) SQLCA_dealloc,
    .tp_getattro = PyObject_GenericGetAttr,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = SQLCA_new,
    .tp_methods = SQLCA_methods,
    .tp_members = SQLCA_members,
};

/********************************************************************
   STMT Type
*/

static PyMethodDef  STMT_methods[] = {
    {"exec", (PyCFunction) STMT_exec, METH_FASTCALL,
        PyDoc_STR("exec(*args)->status: int   Execute statement")},
    {"release", (PyCFunction) STMT_release, METH_NOARGS,
        PyDoc_STR("release()->status: int   Release statement")},
    {"open_cursor", (PyCFunction) STMT_open_cursor, METH_FASTCALL,
        PyDoc_STR("open_cursor(*args)->status: int   Open cursor")},
    {"close_cursor", (PyCFunction) STMT_close_cursor, METH_NOARGS,
        PyDoc_STR("close_cursor()->status: int   Close cursor")},
    {"fetch", (PyCFunction) STMT_fetch, METH_NOARGS,
        PyDoc_STR("fetch()->status: int   Fetch data after open_cursor()")},
    {"fields", (PyCFunction) STMT_fields, METH_NOARGS,
        PyDoc_STR("fields()->[(name: str, type: int, len: int),...]   Fields info")},
    {"data", (PyCFunction) STMT_data, METH_NOARGS,
        PyDoc_STR("data()->[value,...]   Get row data after fetch()")},
    {"select", (PyCFunction) STMT_select, METH_FASTCALL,
        PyDoc_STR("select(*args)->[value,...]   Select first row")},
    {NULL, NULL}
};

static PyMemberDef  STMT_members[] = {
    {"ncols", T_SHORT, offsetof(STMT_Object, ncols), READONLY,
     "Number of columns"},
    {NULL}
};

PyTypeObject STMT_Type = {
    PyObject_HEAD_INIT(NULL)
    RDB_MODULE_NAME "." STMT_TYPE_NAME,
    .tp_basicsize = sizeof( STMT_Object),
    .tp_dealloc = (destructor) STMT_dealloc,
    .tp_getattro = PyObject_GenericGetAttr,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = STMT_new,
    .tp_methods = STMT_methods,
    .tp_members = STMT_members,
};

/********************************************************************
  Module
*/
static PyMethodDef _module_methods[] = {
    {"error_message", (PyCFunction) RDB_error_message, METH_NOARGS,
        PyDoc_STR("error_message()->err: str   SQL error message")},
    {NULL, NULL}
};

static struct PyModuleDef _module_definition = {
    PyModuleDef_HEAD_INIT,
    .m_name = RDB_MODULE_NAME,
    .m_doc = "OpenVMS RDB implementation",
    .m_size = -1,
    .m_methods = _module_methods,
};

PyMODINIT_FUNC PyInit__rdb(void)
{
    if (PyType_Ready(&SQLCA_Type) < 0) {
        return NULL;
    }
    if (PyType_Ready(&STMT_Type) < 0) {
        return NULL;
    }
    PyObject *m = PyModule_Create(&_module_definition);
    if (m == NULL) {
        return NULL;
    }
    Py_INCREF(&SQLCA_Type);
    if (PyModule_AddObject(m, SQLCA_TYPE_NAME, (PyObject *) &SQLCA_Type) < 0) {
        Py_DECREF(&SQLCA_Type);
        Py_DECREF(m);
        return NULL;
    }
    Py_INCREF(&STMT_Type);
    if (PyModule_AddObject(m, STMT_TYPE_NAME, (PyObject *) &STMT_Type) < 0) {
        Py_DECREF(&SQLCA_Type);
        Py_DECREF(&STMT_Type);
        Py_DECREF(m);
        return NULL;
    }
    PyModule_AddIntConstant(m, "SQLDA_VARCHAR", SQLDA_VARCHAR);
    PyModule_AddIntConstant(m, "SQLDA_CHAR", SQLDA_CHAR);
    PyModule_AddIntConstant(m, "SQLDA_ROWID", SQLDA_ROWID);
    PyModule_AddIntConstant(m, "SQLDA_FLOAT", SQLDA_FLOAT);
    PyModule_AddIntConstant(m, "SQLDA_DECIMAL", SQLDA_DECIMAL);
    PyModule_AddIntConstant(m, "SQLDA_INTEGER", SQLDA_INTEGER);
    PyModule_AddIntConstant(m, "SQLDA_SMALLINT", SQLDA_SMALLINT);
    PyModule_AddIntConstant(m, "SQLDA_DATE", SQLDA_DATE);
    PyModule_AddIntConstant(m, "SQLDA_QUADWORD", SQLDA_QUADWORD);
    PyModule_AddIntConstant(m, "SQLDA_ASCIZ", SQLDA_ASCIZ);
    PyModule_AddIntConstant(m, "SQLDA_SEGSTRING", SQLDA_SEGSTRING);
    PyModule_AddIntConstant(m, "SQLDA_TINYINT", SQLDA_TINYINT);
    PyModule_AddIntConstant(m, "SQLDA_VARBYTE", SQLDA_VARBYTE);
    PyModule_AddIntConstant(m, "SQLDA2_DATETIME", SQLDA2_DATETIME);
    PyModule_AddIntConstant(m, "SQLDA2_INTERVAL", SQLDA2_INTERVAL);
    PyModule_AddIntConstant(m, "SQLDA_SURROGATE", SQLDA_SURROGATE);
    PyModule_AddIntConstant(m, "SQLDA_VARBINARY", SQLDA_VARBINARY);
    PyModule_AddIntConstant(m, "SQLDA_BINARY", SQLDA_BINARY);
    PyModule_AddIntConstant(m, "SQLDA2_DT_DATE", SQLDA2_DT_DATE);
    PyModule_AddIntConstant(m, "SQLDA2_DT_TIME", SQLDA2_DT_TIME);
    PyModule_AddIntConstant(m, "SQLDA2_DT_TIMESTAMP", SQLDA2_DT_TIMESTAMP);
    PyModule_AddIntConstant(m, "SQLDA2_DT_TIME_TZ", SQLDA2_DT_TIME_TZ);
    PyModule_AddIntConstant(m, "SQLDA2_DT_TIMESTAMP_TZ", SQLDA2_DT_TIMESTAMP_TZ);
    PyModule_AddIntConstant(m, "SQLDA2_DT_YEAR", SQLDA2_DT_YEAR);
    PyModule_AddIntConstant(m, "SQLDA2_DT_MONTH", SQLDA2_DT_MONTH);
    PyModule_AddIntConstant(m, "SQLDA2_DT_DAY", SQLDA2_DT_DAY);
    PyModule_AddIntConstant(m, "SQLDA2_DT_HOUR", SQLDA2_DT_HOUR);
    PyModule_AddIntConstant(m, "SQLDA2_DT_MINUTE", SQLDA2_DT_MINUTE);
    PyModule_AddIntConstant(m, "SQLDA2_DT_SECOND", SQLDA2_DT_SECOND);
    PyModule_AddIntConstant(m, "SQLDA2_DT_YEAR_MONTH", SQLDA2_DT_YEAR_MONTH);
    PyModule_AddIntConstant(m, "SQLDA2_DT_DAY_HOUR", SQLDA2_DT_DAY_HOUR);
    PyModule_AddIntConstant(m, "SQLDA2_DT_DAY_MINUTE", SQLDA2_DT_DAY_MINUTE);
    PyModule_AddIntConstant(m, "SQLDA2_DT_DAY_SECOND", SQLDA2_DT_DAY_SECOND);
    PyModule_AddIntConstant(m, "SQLDA2_DT_HOUR_MINUTE", SQLDA2_DT_HOUR_MINUTE);
    PyModule_AddIntConstant(m, "SQLDA2_DT_HOUR_SECOND", SQLDA2_DT_HOUR_SECOND);
    PyModule_AddIntConstant(m, "SQLDA2_DT_MINUTE_SECOND", SQLDA2_DT_MINUTE_SECOND);
    PyModule_AddIntConstant(m, "SQL_K_SQLCODE_OFFSET", SQL$K_SQLCODE_OFFSET);
    PyModule_AddIntConstant(m, "SQLCODE_SUCCESS", SQLCODE_SUCCESS);
    PyModule_AddIntConstant(m, "SQLCODE_EOS", SQLCODE_EOS);
    PyModule_AddIntConstant(m, "SQLCODE_ELIM_NULL", SQLCODE_ELIM_NULL);
    PyModule_AddIntConstant(m, "SQLCODE_TRUN_RTRV", SQLCODE_TRUN_RTRV);
    PyModule_AddIntConstant(m, "SQLCODE_RDBERR", SQLCODE_RDBERR);
    PyModule_AddIntConstant(m, "SQLCODE_OUTOFRAN", SQLCODE_OUTOFRAN);
    PyModule_AddIntConstant(m, "SQLCODE_NULLNOIND", SQLCODE_NULLNOIND);
    PyModule_AddIntConstant(m, "SQLCODE_STR_DAT_TRUNC", SQLCODE_STR_DAT_TRUNC);
    PyModule_AddIntConstant(m, "SQLCODE_INV_DATETIME", SQLCODE_INV_DATETIME);
    PyModule_AddIntConstant(m, "SQLCODE_CURNOTOPE", SQLCODE_CURNOTOPE);
    PyModule_AddIntConstant(m, "SQLCODE_CURALROPE", SQLCODE_CURALROPE);
    PyModule_AddIntConstant(m, "SQLCODE_UDCURNOPE", SQLCODE_UDCURNOPE);
    PyModule_AddIntConstant(m, "SQLCODE_UDCURNPOS", SQLCODE_UDCURNPOS);
    PyModule_AddIntConstant(m, "SQLCODE_UDCURDEL", SQLCODE_UDCURDEL);
    PyModule_AddIntConstant(m, "SQLCODE_NO_DUP", SQLCODE_NO_DUP);
    PyModule_AddIntConstant(m, "SQLCODE_SELMORVAL", SQLCODE_SELMORVAL);
    PyModule_AddIntConstant(m, "SQLCODE_ROTXN", SQLCODE_ROTXN);
    PyModule_AddIntConstant(m, "SQLCODE_SVPTINVSPEC", SQLCODE_SVPTINVSPEC);
    PyModule_AddIntConstant(m, "SQLCODE_SVPTEXIST", SQLCODE_SVPTEXIST);
    PyModule_AddIntConstant(m, "SQLCODE_SVPTNOEXIST", SQLCODE_SVPTNOEXIST);
    PyModule_AddIntConstant(m, "SQLCODE_DEADLOCK", SQLCODE_DEADLOCK);
    PyModule_AddIntConstant(m, "SQLCODE_INTEG_FAIL", SQLCODE_INTEG_FAIL);
    PyModule_AddIntConstant(m, "SQLCODE_NOT_VALID", SQLCODE_NOT_VALID);
    PyModule_AddIntConstant(m, "SQLCODE_LOCK_CONFLICT", SQLCODE_LOCK_CONFLICT);
    PyModule_AddIntConstant(m, "SQLCODE_BAD_TXN_STATE", SQLCODE_BAD_TXN_STATE);
    PyModule_AddIntConstant(m, "SQLCODE_NO_TXN", SQLCODE_NO_TXN);
    PyModule_AddIntConstant(m, "SQLCODE_BAD_VERSION", SQLCODE_BAD_VERSION);
    PyModule_AddIntConstant(m, "SQLCODE_TRIG_ERROR", SQLCODE_TRIG_ERROR);
    PyModule_AddIntConstant(m, "SQLCODE_NOIMPTXN", SQLCODE_NOIMPTXN);
    PyModule_AddIntConstant(m, "SQLCODE_DISTIDERR", SQLCODE_DISTIDERR);
    PyModule_AddIntConstant(m, "SQLCODE_BAD_CTX_VER", SQLCODE_BAD_CTX_VER);
    PyModule_AddIntConstant(m, "SQLCODE_BAD_CTX_TYPE", SQLCODE_BAD_CTX_TYPE);
    PyModule_AddIntConstant(m, "SQLCODE_BAD_CTX_LEN", SQLCODE_BAD_CTX_LEN);
    PyModule_AddIntConstant(m, "SQLCODE_BASROWDEL", SQLCODE_BASROWDEL);
    PyModule_AddIntConstant(m, "SQLCODE_DIFFDEFINV", SQLCODE_DIFFDEFINV);
    PyModule_AddIntConstant(m, "SQLCODE_STMTNOTPRE", SQLCODE_STMTNOTPRE);
    PyModule_AddIntConstant(m, "SQLCODE_NOSUCHCONN", SQLCODE_NOSUCHCONN);
    PyModule_AddIntConstant(m, "SQLCODE_CONNAMEXI", SQLCODE_CONNAMEXI);
    PyModule_AddIntConstant(m, "SQLCODE_DBENVSYNERR", SQLCODE_DBENVSYNERR);
    PyModule_AddIntConstant(m, "SQLCODE_DBSPECSYNERR", SQLCODE_DBSPECSYNERR);
    PyModule_AddIntConstant(m, "SQLCODE_ATTACHERR", SQLCODE_ATTACHERR);
    PyModule_AddIntConstant(m, "SQLCODE_NOSUCHALIAS", SQLCODE_NOSUCHALIAS);
    PyModule_AddIntConstant(m, "SQLCODE_ALIASINUSE", SQLCODE_ALIASINUSE);
    PyModule_AddIntConstant(m, "SQLCODE_COLEXISTS", SQLCODE_COLEXISTS);
    PyModule_AddIntConstant(m, "SQLCODE_COLNOTDEF", SQLCODE_COLNOTDEF);
    PyModule_AddIntConstant(m, "SQLCODE_TBLEXISTS", SQLCODE_TBLEXISTS);
    PyModule_AddIntConstant(m, "SQLCODE_DOMEXISTS", SQLCODE_DOMEXISTS);
    PyModule_AddIntConstant(m, "SQLCODE_DOMNOTDEF", SQLCODE_DOMNOTDEF);
    PyModule_AddIntConstant(m, "SQLCODE_NO_PRIV", SQLCODE_NO_PRIV);
    PyModule_AddIntConstant(m, "SQLCODE_BAD_LENGTH", SQLCODE_BAD_LENGTH);
    PyModule_AddIntConstant(m, "SQLCODE_BAD_SCALE", SQLCODE_BAD_SCALE);
    PyModule_AddIntConstant(m, "SQLCODE_RO_TABLE", SQLCODE_RO_TABLE);
    PyModule_AddIntConstant(m, "SQLCODE_OBSMETADATA", SQLCODE_OBSMETADATA);
    PyModule_AddIntConstant(m, "SQLCODE_UNRES_REL", SQLCODE_UNRES_REL);
    PyModule_AddIntConstant(m, "SQLCODE_CASENOTFND", SQLCODE_CASENOTFND);
    PyModule_AddIntConstant(m, "SQLCODE_CHKOPT_VIOL", SQLCODE_CHKOPT_VIOL);
    PyModule_AddIntConstant(m, "SQLCODE_UNTERM_C_STR", SQLCODE_UNTERM_C_STR);
    PyModule_AddIntConstant(m, "SQLCODE_INDIC_OVFLOW", SQLCODE_INDIC_OVFLOW);
    PyModule_AddIntConstant(m, "SQLCODE_INV_PARAM_VAL", SQLCODE_INV_PARAM_VAL);
    PyModule_AddIntConstant(m, "SQLCODE_NULL_ELIMIN", SQLCODE_NULL_ELIMIN);
    PyModule_AddIntConstant(m, "SQLCODE_INV_ESC_SEQ", SQLCODE_INV_ESC_SEQ);
    PyModule_AddIntConstant(m, "SQLCODE_RELNOTDEF", SQLCODE_RELNOTDEF);
    PyModule_AddIntConstant(m, "SQLCODE_RELNOTDCL", SQLCODE_RELNOTDCL);
    PyModule_AddIntConstant(m, "SQLCODE_SIGNAL_SQLSTATE", SQLCODE_SIGNAL_SQLSTATE);
    PyModule_AddIntConstant(m, "SQLCODE_NORETSTMT", SQLCODE_NORETSTMT);
    PyModule_AddIntConstant(m, "SQLCODE_INVSUBSTRLEN", SQLCODE_INVSUBSTRLEN);
    #ifdef SQLCODE_INV_INTERVAL
    PyModule_AddIntConstant(m, "SQLCODE_INV_INTERVAL", SQLCODE_INV_INTERVAL);
    #endif
    #ifdef SQLCODE_INV_FRACSEC
    PyModule_AddIntConstant(m, "SQLCODE_INV_FRACSEC", SQLCODE_INV_FRACSEC);
    #endif
    #ifdef SQLCODE_INV_INTLEAD
    PyModule_AddIntConstant(m, "SQLCODE_INV_INTLEAD", SQLCODE_INV_INTLEAD);
    #endif
    #ifdef SQLCODE_INC_CSET
    PyModule_AddIntConstant(m, "SQLCODE_INC_CSET", SQLCODE_INC_CSET);
    #endif
    #ifdef SQLCODE_DATA_CVT_ERROR
    PyModule_AddIntConstant(m, "SQLCODE_DATA_CVT_ERROR", SQLCODE_DATA_CVT_ERROR);
    #endif
    PyModule_AddIntConstant(m, "SQLCODE_SVPTBADLOC", SQLCODE_SVPTBADLOC);
    PyModule_AddIntConstant(m, "ACC_K_TERMLEN", 84);
    return m;
}
