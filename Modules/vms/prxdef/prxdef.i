%module prxdef

%constant int PRX_K_ADD = 1;
%constant int PRX_K_DELETE = 2;
%constant int PRX_K_SHOW = 3;
%constant int PRX_K_VERIFY = 4;
%constant int PRX_K_PERFORMANCE = 5;
%constant int PRX_K_ZERO_PERFORMANCE = 6;
%constant int PRX_K_CREATE = 7;
%constant int PRX_K_STOP = 8;
%constant int PRX_K_START = 9;
%constant int PRX_K_MAX_PROXY_CODE = 10;
%constant int PRX_K_PERFORMANCE_LENGTH = 48;
%constant int PRX_S_PERFORMANCE = 48;
%constant int PRX_M_IGNORE_RETURN = 0x1L;
%constant int PRX_M_BYPASS_EXPAND = 0x2L;
%constant int PRX_M_RESERVE_1 = 0xFCL;
%constant int PRX_M_DEFAULT = 0x100L;
%constant int PRX_M_EXACT = 0x200L;
%constant int PRX_M_DELETE_ALLOWED = 0x400L;
%constant int PRX_M_FILL_1 = 0xFFFFF800L;
%constant int PRX_K_HEADER_LENGTH = 8;
%constant int PRX_S_HEADER = 8;
%constant int PRX_S_FILL_1 = 21;
%constant int PRX_S_PRX_GENERIC_DESC1 = 5;
%constant int PRX_K_USER_NAME_LENGTH = 32;
%constant int PRX_K_REMOTE_NODE_NAME_LENGTH = 1024;
%constant int PRX_K_MAX_LOCAL_USERS = 16;
%constant int PRX_K_LOCAL_USER_ENTRY = 36;
%constant int PRX_S_DATA = 1100;
%constant int PRX_S_LOCAL_USER_NAME = 32;
%constant int PRX_S_REMOTE_USER_NAME = 32;
%constant int PRX_S_REMOTE_NODE_NAME = 1024;
%constant int PRX_K_DATA_LENGTH = 1100;
%constant int PRX_S_BUFSIZ_SUMMARY = 8;
%constant int PRX_K_MAX_REPLY = 1692;
%constant int PRX_S_REPLY_UNION = 88;
%constant int PRX_S_VALID_USER = 32;
%constant int PRX_S_SHOW_DEF_USER = 32;
%constant int PRX_S_SHOW_REM_USER = 32;
%constant int PRX_S_SHOW_LOCAL_DATA = 4;
%constant int PRX_K_MAX_LENGTH = 1108;
