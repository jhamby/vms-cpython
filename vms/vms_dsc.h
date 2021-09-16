#ifndef VMS_DSC_H
#define VMS_DSC_H

#if defined(__VMS) && __INITIAL_POINTER_SIZE == 64
#   define  set_dsc_string(dsc, val)    (dsc).dsc$a_pointer = _strdup32(val)
#   define  free_dsc_string(dsc)        free((dsc).dsc$a_pointer)
#else
#   define  set_dsc_string(dsc, val)    (dsc).dsc$a_pointer = (val)
#   define  free_dsc_string
#endif

#endif
