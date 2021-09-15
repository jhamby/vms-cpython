#ifndef VMS_SYS_PTR_DEFINED
#define VMS_SYS_PTR_DEFINED

#ifdef __INITIAL_POINTER_SIZE
#pragma __required_pointer_size __save
#pragma __required_pointer_size __short
extern void * _malloc32  (__size_t);
extern void * _realloc32 (void *, __size_t);
#define malloc32  _malloc32
#define realloc32 _realloc32
#else
void * malloc  (__size_t __size);
void * realloc (void* __ptr, __size_t __size);
#define malloc32  malloc
#define realloc32 realloc
#endif

typedef struct _generic_64   **p32p32int64_t;
typedef unsigned int          *p32uint_t;
typedef unsigned int         **p32p32uint_t;
typedef void                  *p32void_t;
typedef void                 **p32p32void_t;

#ifdef __INITIAL_POINTER_SIZE
#pragma __required_pointer_size __restore
#endif

extern __size_t strlen(const char *);
extern void * memcpy(void *, __const_void_ptr64 , __size_t );
extern void   free(void *__ptr);

inline p32void_t dup32(void *mem, int size) { 
    if (size == -1) {
        size = strlen((char*)mem) + 1;
    }
    p32void_t tmp = malloc32(size);
    memcpy(tmp, mem, size);
    return tmp;
}

#endif
