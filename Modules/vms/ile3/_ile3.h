#ifndef ILE3Object_defined
#define ILE3Object_defined

typedef struct {
    PyObject_HEAD
    unsigned int    allocated;
    unsigned int    size;
    int             pos;
    __void_ptr32    plist;
    __void_ptr32    ptypes;
} ILE3Object;

#define ILE3_MODULE_NAME "_ile3"
#define ILE3_TYPE_NAME "ile3list"

#endif