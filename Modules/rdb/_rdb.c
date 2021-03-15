#define PY_SSIZE_T_CLEAN
#include "Python.h"
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

#include <descrip.h>
#include <starlet.h>
#include <str$routines.h>
#include <lib$routines.h>

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
    SQLCA_Object   *pSQLCA;
} STMT_Object;

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
    PyObject *args
) {
    PyCLEAR(self->pErr);

    char *cmd = NULL;
    Py_ssize_t cmd_size = 0;
    ConvertArgToStr(args, cmd, cmd_size, "exec");

    Py_BEGIN_ALLOW_THREADS
    eib$$db_exec_immediate(&self->sqlca, cmd);
    Py_END_ALLOW_THREADS

    if (self->sqlca.SQLCODE != SQLCODE_SUCCESS) {
       self->pErr = RDB_error_message(NULL, NULL);
    }

    return PyLong_FromLong(self->sqlca.SQLCODE);
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
static PyObject* STMT_new(PyTypeObject *type, PyObject *args, PyObject *kwds);
static PyObject* STMT_release(STMT_Object *self, PyObject *args);

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
        pSTMT->sqlda_i->SQLVAR[i].SQLDATA = (char*) PyMem_Calloc(1, pSTMT->sqlda_i->SQLVAR[i].SQLLEN);
        if (pSTMT->sqlda_i->SQLVAR[i].SQLDATA == NULL) {
            Py_DECREF(pSTMT);
            return PyErr_NoMemory();
        }
    }

    for (int i = 0; i < pSTMT->sqlda_o->SQLD; i++) {
        if (pSTMT->sqlda_o->SQLVAR[i].SQLTYPE == SQLDA2_INTERVAL) {
            pSTMT->sqlda_o->SQLVAR[i].SQLTYPE = SQLDA_VARCHAR;
            pSTMT->sqlda_o->SQLVAR[i].SQLLEN = 100;
        }
        pSTMT->sqlda_o->SQLVAR[i].SQLIND = PyMem_Calloc(1, sizeof(int));
        if (pSTMT->sqlda_o->SQLVAR[i].SQLIND == NULL) {
            Py_DECREF(pSTMT);
            return PyErr_NoMemory();
        }
        switch (pSTMT->sqlda_o->SQLVAR[i].SQLTYPE) {
            case SQLDA_VARCHAR:
                pSTMT->sqlda_o->SQLVAR[i].SQLDATA = PyMem_Calloc(1, sizeof(vc_t));
                break;
            case SQLDA_CHAR:
            case SQLDA_INTEGER:
            case SQLDA_SMALLINT:
            case SQLDA_TINYINT:
            case SQLDA_FLOAT:
            case SQLDA_SEGSTRING:
            case SQLDA_QUADWORD:
            case SQLDA_DATE:
            case SQLDA2_DATETIME:
                pSTMT->sqlda_o->SQLVAR[i].SQLDATA = PyMem_Calloc(1, pSTMT->sqlda_o->SQLVAR[i].SQLLEN);
                break;
            default:
                // PyErr_Format(PyExc_RuntimeError, "Unknown type %i", pSTMT->sqlda_o->SQLVAR[i].SQLTYPE);
                pSTMT->sqlda_o->SQLVAR[i].SQLDATA = PyMem_Calloc(1, pSTMT->sqlda_o->SQLVAR[i].SQLLEN);
        }
        if (pSTMT->sqlda_o->SQLVAR[i].SQLDATA == NULL) {
            Py_DECREF(pSTMT);
            return PyErr_NoMemory();
        }
    }
    return (PyObject*)pSTMT;

error_exit:
    {
        PyObject *pErr = RDB_error_message(NULL, NULL);
        STMT_release(pSTMT, NULL);
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

static PyObject*
STMT_exec(
    STMT_Object *self,
    PyObject *args
) {
    if (self->pSQLCA == NULL) {
        return NULL;
    }
    PyCLEAR(self->pSQLCA->pErr);

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
    PyObject *args
) {
    if (self->pSQLCA == NULL) {
        return NULL;
    }
    PyCLEAR(self->pSQLCA->pErr);

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
    struct dsc$descriptor_s     dd;
    struct dsc$descriptor_sd    qd;
    char str[64];
    sc_len_t *p;
    PyObject *pValue;
    SQL_T_SQLVAR2 *pVar;
    unsigned long ret_len;

    static PyObject *pNullStr = NULL;
    if (pNullStr == NULL) {
        pNullStr = PyUnicode_FromString("<null>");
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
                case SQLDA_TINYINT:
                    pValue = PyLong_FromLong(*(char *) pVar->SQLDATA);
                    break;
                case SQLDA_FLOAT:
                    if (pVar->SQLLEN == 8) {
                        pValue = PyFloat_FromDouble(*(double *)pVar->SQLDATA);
                    } else if (pVar->SQLLEN == 4) {
                        pValue = PyFloat_FromDouble(*(float *)pVar->SQLDATA);
                    }
                    break;
                case SQLDA_DATE:
                    dd.dsc$w_length  = 32;
                    dd.dsc$b_dtype   = DSC$K_DTYPE_T;
                    dd.dsc$b_class   = DSC$K_CLASS_S;
                    dd.dsc$a_pointer = str;
                    sys$asctim(0, &dd, (struct _generic_64 *)pVar->SQLDATA, 0);
                    str[20] = '\0';
                    if (str[0] == ' ') {
                        str[0] = '0';
                    }
                    pValue = PyUnicode_FromString(str);
                    break;
                case SQLDA_SMALLINT:
                case SQLDA_QUADWORD:
                case SQLDA_INTEGER:
                    p = (sc_len_t *) &pVar->SQLLEN;

                    dd.dsc$w_length  = 64;
                    dd.dsc$b_dtype   = DSC$K_DTYPE_T;
                    dd.dsc$b_class   = DSC$K_CLASS_S;
                    dd.dsc$a_pointer = str;

                    qd.dsc$b_class   = DSC$K_CLASS_SD;
                    qd.dsc$w_length  = p[0];
                    qd.dsc$a_pointer = pVar->SQLDATA;
                    qd.dsc$b_scale   = -1 * p[1];
                    qd.dsc$b_digits  = 0;

                    switch (pVar->SQLTYPE) {
                        case SQLDA_SMALLINT:
                            qd.dsc$b_dtype = DSC$K_DTYPE_W;
                            break;
                        case SQLDA_QUADWORD:
                            qd.dsc$b_dtype = DSC$K_DTYPE_Q;
                            break;
                        case SQLDA_INTEGER:
                            qd.dsc$b_dtype = DSC$K_DTYPE_L;
                            break;
                    }
                    ret_len = 0;
                    lib$cvt_dx_dx((unsigned int *)&qd, (unsigned int *)&dd, &ret_len);
                    str[ret_len] = '\0';
                    pValue = PyUnicode_FromString(str);
                    break;
                default:
                    pValue = pNullStr;
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
            PyErr_Format(PyExc_RuntimeError, "Cannot create value from column %i", i);
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
                len = (vc_len_t) *pVar->SQLDATA;
                if (len < 0) {              /* Hack */
                    len += 256;
                }
                break;
            case SQLDA_CHAR:
                len = pVar->SQLLEN;
                break;
            case SQLDA_TINYINT:
                len = 1;
                break;
            case SQLDA_FLOAT:
                len = pVar->SQLLEN;
                break;
            case SQLDA_DATE:
                len = 20;
                break;
            case SQLDA_SMALLINT:
            case SQLDA_QUADWORD:
            case SQLDA_INTEGER:
                len = *(sc_len_t *) &pVar->SQLLEN;
                break;
            default:
                len = pVar->SQLLEN;
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

// char **FetchRow(void *addr)
// {
//     stmt_t *   sp = (stmt_t *) addr;
//     char **   arr = NULL;
//     int    i;
//     int    nc;

//     if (Fetch(addr) != 1)
//     {
//        return (NULL);
//     }

//     nc = sp->sqlda_o.sqld;
//     arr = calloc((nc + 1), sizeof(char *));
//     assert(arr);

//     for (i = 0; i < nc; i++)
//     {
//         arr[i] = strdup(Data(addr, i));
//        assert(arr[i]);
//     }

//     arr[i] = NULL;
//     return (arr);
// }

// /* ------------------------------------------------------------------------------------------------------------------------------ */

// int Fetch(void *addr)
// {
//     stmt_t *   sp = (stmt_t *) addr;

//     eib$$db_fetch(&SQLCA, sp->cursor, &sp->sqlda_o);

//     switch (SQLCA.SQLCODE)
//     {
//        case SQLCODE_SUCCESS:
//           return (1);
//           break;

//        case SQLCODE_EOS:
//           return (0);
//           break;

//        default:
//           return (-1);
//           break;
//     }
// }

/* ------------------------------------------------------------------------------------------------------------------------------ */

// static unsigned long
// dbl_to_str(
//     double val,
//     char *str,
//     int len
// ) {
//     struct dsc$descriptor_sd  data_desc;
//     struct dsc$descriptor_s  strn_desc;
//     unsigned long    status;

//     data_desc.dsc$b_class   = DSC$K_CLASS_SD;
//     data_desc.dsc$w_length  = sizeof(double);
//     data_desc.dsc$a_pointer = (char *) &val;
//     data_desc.dsc$b_scale   = 0;
//     data_desc.dsc$b_digits  = 0;
//     data_desc.dsc$b_dtype   = DSC$K_DTYPE_G;  /* G-Floating 64-bit */

//     strn_desc.dsc$w_length  = len;
//     strn_desc.dsc$b_dtype   = DSC$K_DTYPE_T;
//     strn_desc.dsc$b_class   = DSC$K_CLASS_S;
//     strn_desc.dsc$a_pointer = str;

//     status = lib$cvt_dx_dx(&data_desc, &strn_desc);

//     if (!$VMS_STATUS_SUCCESS(status)) {
//         strn_desc.dsc$w_length = 0;
//     }
//     str[strn_desc.dsc$w_length] = '\0';

//     return status;
// }

// /* ------------------------------------------------------------------------------------------------------------------------------ */

// static unsigned long
// flt_to_str(
//     float val,
//     char *str,
//     int len
// ) {
//     struct dsc$descriptor_sd  data_desc;
//     struct dsc$descriptor_s  strn_desc;
//     unsigned long    status;

//     data_desc.dsc$b_class   = DSC$K_CLASS_SD;
//     data_desc.dsc$w_length  = sizeof(double);
//     data_desc.dsc$a_pointer = (char *) &val;
//     data_desc.dsc$b_scale   = 0;
//     data_desc.dsc$b_digits  = 0;
//     data_desc.dsc$b_dtype   = DSC$K_DTYPE_F;  /* F-Floating 32-bit */

//     strn_desc.dsc$w_length  = len;
//     strn_desc.dsc$b_dtype   = DSC$K_DTYPE_T;
//     strn_desc.dsc$b_class   = DSC$K_CLASS_S;
//     strn_desc.dsc$a_pointer = str;

//     status = lib$cvt_dx_dx(&data_desc, &strn_desc);

//     if (OKAY(status))
//     {
//        str[strn_desc.dsc$w_length] = '\0';
//     }

//     return (status);
// }

// /* ------------------------------------------------------------------------------------------------------------------------------ */

// char *Data(void *addr, int n)
// {
//     stmt_t *    sp = (stmt_t *) addr;
//         struct dsc$descriptor_s         dd;
//         vc_len_t                 len;
//         sc_len_t *                      p;
//         char *                   q;
//     struct dsc$descriptor_sd        qd;
//     static char    str[MAXVLEN];
//     struct sqlvar *   var;

//     var = &sp->sqlda_o->SQLVAR[n];

//     if (*var->sqlnind < 0)
//         {
//        strcpy(str, "<null>");
//         }
//         else
//         {
//            switch (var->sqltype)
//            {
//               case SQLDA_VARCHAR:
//                  len = (vc_len_t) *var->sqldata;

//                  if (len < 0)               /* Hack */
//                  {
//                     len = 256 + len;
//                  }

//                  str[len] = '\0';
//                  strncpy(str, (char *)(var->sqldata + sizeof(vc_len_t)), len);

//                  for (q = str + len - 1; q >= str && *q == ' ' ; q--)
//                  {
//                     *q = '\0';
//                  }

//              break;

//           case SQLDA_CHAR:
//                  len = var->sqldlen;
//                  str[len] = '\0';
//                  strncpy(str, var->sqldata, len);

//                  for (q = str + len - 1 ; q >= str && *q == ' ' ; q--)
//                  {
//                     *q = '\0';
//                  }

//              break;

//           case SQLDA_TINYINT:
//                  sprintf(str, "%d", *(char *) var->sqldata);
//              break;

//           case SQLDA_FLOAT:
//                  if (var->sqldlen == 8)
//                  {
//                     dbl_to_str(*(double *) var->sqldata, str, sizeof(str) - 1);
//                  }
//                  else
//                  {
//                     flt_to_str(*(float  *) var->sqldata, str, sizeof(str) - 1);
//                  }

//              break;

//           case SQLDA_DATE:
//                  dd.dsc$w_length  = 32;
//                  dd.dsc$b_dtype   = DSC$K_DTYPE_T;
//                  dd.dsc$b_class   = DSC$K_CLASS_S;
//                  dd.dsc$a_pointer = str;

//                  sys$asctim(0, &dd, var->sqldata, 0);
//              str[20] = '\0';
//                  if (str[0] == ' ') str[0] = '0';

//              break;

//               case SQLDA_SMALLINT:
//               case SQLDA_QUADWORD:
//               case SQLDA_INTEGER:
//                  p = (sc_len_t *) &var->sqldlen;

//                  dd.dsc$w_length  = 64;
//                  dd.dsc$b_dtype   = DSC$K_DTYPE_T;
//                  dd.dsc$b_class   = DSC$K_CLASS_S;
//                  dd.dsc$a_pointer = str;

//                  qd.dsc$b_class   = DSC$K_CLASS_SD;
//                  qd.dsc$w_length  = p[0];
//                  qd.dsc$a_pointer = var->sqldata;
//                  qd.dsc$b_scale   = -1 * p[1];
//                  qd.dsc$b_digits  = 0;

//                  switch (var->sqltype)
//                  {
//                     case SQLDA_SMALLINT:
//                        qd.dsc$b_dtype = DSC$K_DTYPE_W;
//                        break;

//                     case SQLDA_QUADWORD:
//                        qd.dsc$b_dtype = DSC$K_DTYPE_Q;
//                        break;

//                     case SQLDA_INTEGER:
//                        qd.dsc$b_dtype = DSC$K_DTYPE_L;
//                        break;
//                  }

//                  lib$cvt_dx_dx(&qd, &dd, &dd.dsc$w_length);
//                  str[dd.dsc$w_length] = '\0';
//              break;

//           default:
//              strcpy(str, "<null>");
//              break;
//        }
//     }

//     return (str);
// }

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
    {"exec", (PyCFunction) SQLCA_exec, METH_O,
        PyDoc_STR("exec(cmd: str)->status: int   Exec")},
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
    {"exec", (PyCFunction) STMT_exec, METH_NOARGS,
        PyDoc_STR("exec()->status: int   Execute statement")},
    {"release", (PyCFunction) STMT_release, METH_NOARGS,
        PyDoc_STR("release()->status: int   Release statement")},
    {"open_cursor", (PyCFunction) STMT_open_cursor, METH_NOARGS,
        PyDoc_STR("open_cursor()->status: int   Open cursor")},
    {"close_cursor", (PyCFunction) STMT_close_cursor, METH_NOARGS,
        PyDoc_STR("close_cursor()->status: int   Close cursor")},
    {"fetch", (PyCFunction) STMT_fetch, METH_NOARGS,
        PyDoc_STR("fetch()->status: int   Fetch")},
    {"fields", (PyCFunction) STMT_fields, METH_NOARGS,
        PyDoc_STR("fields()->[(name: str, type: int, len: int),...]   Fields info")},
    {"data", (PyCFunction) STMT_data, METH_NOARGS,
        PyDoc_STR("data()->[value,...]   Row data")},
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
