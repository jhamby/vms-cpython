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
#ifdef __VMS
    exit(Py_BytesMain(argc, argv));
#else
    return Py_BytesMain(argc, argv);
#endif
}
#endif
