#ifndef ILE3Object_defined
#define ILE3Object_defined

typedef struct {
    PyObject_HEAD
    unsigned int allocated;
    unsigned int size;
    int          pos;
    void        *list;
    int         *types;
} ILE3Object;

#define ILE3_MODULE_NAME "_ile3"
#define ILE3_TYPE_NAME "ile3list"

#endif
