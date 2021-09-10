#ifndef VMS_SYS_PTR_DEFINED
#define VMS_SYS_PTR_DEFINED

#pragma __required_pointer_size __save
#pragma __required_pointer_size __short
    typedef void* vms_ptr32;
    typedef void** vms_ptr32_ptr32;
#pragma __required_pointer_size __restore

#endif
