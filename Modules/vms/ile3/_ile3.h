#ifndef ILE3Object_defined
#define ILE3Object_defined

#include <iledef.h>

typedef struct {
    PyObject_HEAD
    unsigned int allocated;
    unsigned int size;
    int          pos;
    ILE3        *list;
    int         *types;
} ILE3Object;

#define ILE3_MODULE_NAME "_ile3"
#define ILE3_TYPE_NAME "ile3list"

#endif