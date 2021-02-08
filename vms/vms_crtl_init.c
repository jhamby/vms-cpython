#include <stdio.h>
#include <errno.h>
#include <unixlib.h>


/*
** Sets current value for a feature
*/
static void set(char *name, int value) {
    errno = 0;
    int index = decc$feature_get_index(name);
    if (index > 0) {
        decc$feature_set_value(index, 1, value);
    }
}

/*
** Sets default value for a feature
*/
static void set_default(char *name, int value) {
    errno = 0;
    int index = decc$feature_get_index(name);
    if (index > 0) {
        decc$feature_set_value (index, 0, value);
    }
}

static void set_coe(void) {
    set ("DECC$UNIX_LEVEL", 100);

    const char *disable_feature[] = {
        "DECC$EFS_CASE_SPECIAL",
        "DECC$DETACHED_CHILD_PROCESS",
        "DECC$POSIX_STYLE_UID"          // else getpwuid() doesn't work
    };

    const char *enable_feature[] = {
        "DECC$ARGV_PARSE_STYLE",
        "DECC$EFS_CASE_PRESERVE",
        "DECC$ENABLE_GETENV_CACHE",
        "DECC$EXIT_AFTER_FAILED_EXEC",
        "DECC$FILE_SHARING",
        "DECC$MAILBOX_CTX_STM",
        "DECC$POPEN_NO_CRLF_REC_ATTR",
        "DECC$POSIX_SEEK_STREAM_FILE",
        "DECC$EFS_FILE_TIMESTAMPS",
        "DECC$EFS_CHARSET",
        "DECC$DISABLE_TO_VMS_LOGNAME_TRANSLATION",
        "DECC$FILENAME_UNIX_NO_VERSION",
        "DECC$FILENAME_UNIX_REPORT",
        "DECC$READDIR_DROPDOTNOTYPE",
        "DECC$RENAME_NO_INHERIT"
    };

    for(int i = 0; i < sizeof(disable_feature)/sizeof(disable_feature[0]); ++i) {
        set (disable_feature[i], 0);
    }

    for(int i = 0; i < sizeof(enable_feature)/sizeof(enable_feature[0]); ++i) {
        set (enable_feature[i], 1);
    }

}

#pragma extern_model save
#pragma extern_model strict_refdef "LIB$INITIALIZE" nowrt, long
#if __INITIAL_POINTER_SIZE
#    pragma __pointer_size __save
#    pragma __pointer_size 32
#else
#    pragma __required_pointer_size __save
#    pragma __required_pointer_size 32
#endif
void (* const iniarray[])() = {set_coe, } ;	/* Set our contribution to the LIB$INITIALIZE array */
#if __INITIAL_POINTER_SIZE
#    pragma __pointer_size __restore
#else
#    pragma __required_pointer_size __restore
#endif
#pragma extern_model restore

int LIB$INITIALIZE();
/* globaldef */ int (*lib_init_ref)() = LIB$INITIALIZE;
