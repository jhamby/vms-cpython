/* Minimal main program -- everything is loaded from the library */

#include "Python.h"

#ifdef MS_WINDOWS
int
wmain(int argc, wchar_t **argv)
{
    return Py_Main(argc, argv);
}
#else
int
main(int argc, char **argv)
{
#if defined (__INITIAL_POINTER_SIZE) && __INITIAL_POINTER_SIZE == 64
    char **argv_pass = alloca(argc*sizeof(char*));
    for(int i = 0; i < argc; ++i) {
        argv_pass[i] = argv[i];
    }
#else
    char **argv_pass = argv;
#endif
#ifdef __VMS
    exit(Py_BytesMain(argc, argv_pass));
#else
    return Py_BytesMain(argc, argv_pass);
#endif
}
#endif
