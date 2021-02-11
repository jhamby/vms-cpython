%module quidef

%constant int QUI__CANCEL_OPERATION = 1;
%constant int QUI__DISPLAY_CHARACTERISTIC = 2;
%constant int QUI__DISPLAY_FILE = 3;
%constant int QUI__DISPLAY_FORM = 4;
%constant int QUI__DISPLAY_JOB = 5;
%constant int QUI__DISPLAY_QUEUE = 6;
%constant int QUI__TRANSLATE_QUEUE = 7;
%constant int QUI__DISPLAY_ENTRY = 8;
%constant int QUI__DISPLAY_QMAN = 9;
%constant int QUI__DISPLAY_MANAGER = 10;
%constant int QUI_K_MIN_FUNC = 1;
%constant int QUI_K_MAX_FUNC = 10;
%constant int QUI__ACCOUNT_NAME = 1;
%constant int QUI__AFTER_TIME = 2;
%constant int QUI__ASSIGNED_QUEUE_NAME = 3;
%constant int QUI__BASE_PRIORITY = 4;
%constant int QUI__CHARACTERISTIC_NAME = 5;
%constant int QUI__CHARACTERISTIC_NUMBER = 6;
%constant int QUI__CHARACTERISTICS = 7;
%constant int QUI__CHECKPOINT_DATA = 8;
%constant int QUI__CLI = 9;
%constant int QUI__COMPLETED_BLOCKS = 10;
%constant int QUI__CONDITION_VECTOR = 11;
%constant int QUI__CPU_DEFAULT = 12;
%constant int QUI__CPU_LIMIT = 13;
%constant int QUI__DEVICE_NAME = 14;
%constant int QUI__ENTRY_NUMBER = 15;
%constant int QUI__FILE_COPIES = 16;
%constant int QUI__FILE_COPIES_CHKPT = 17;
%constant int QUI__FILE_COPIES_DONE = 18;
%constant int QUI__FILE_FLAGS = 19;
%constant int QUI__FILE_SETUP_MODULES = 20;
%constant int QUI__FILE_SPECIFICATION = 21;
%constant int QUI__FILE_STATUS = 22;
%constant int QUI__FIRST_PAGE = 23;
%constant int QUI__FORM_DESCRIPTION = 24;
%constant int QUI__FORM_FLAGS = 25;
%constant int QUI__FORM_LENGTH = 26;
%constant int QUI__FORM_MARGIN_BOTTOM = 27;
%constant int QUI__FORM_MARGIN_LEFT = 28;
%constant int QUI__FORM_MARGIN_RIGHT = 29;
%constant int QUI__FORM_MARGIN_TOP = 30;
%constant int QUI__FORM_NAME = 31;
%constant int QUI__FORM_NUMBER = 32;
%constant int QUI__FORM_SETUP_MODULES = 33;
%constant int QUI__FORM_STOCK = 34;
%constant int QUI__FORM_WIDTH = 35;
%constant int QUI__GENERIC_TARGET = 36;
%constant int QUI__INTERVENING_BLOCKS = 37;
%constant int QUI__INTERVENING_JOBS = 38;
%constant int QUI__JOB_COPIES = 39;
%constant int QUI__JOB_COPIES_CHKPT = 40;
%constant int QUI__JOB_COPIES_DONE = 41;
%constant int QUI__JOB_FLAGS = 42;
%constant int QUI__JOB_LIMIT = 43;
%constant int QUI__JOB_NAME = 44;
%constant int QUI__JOB_RESET_MODULES = 45;
%constant int QUI__JOB_SIZE = 46;
%constant int QUI__JOB_SIZE_MAXIMUM = 47;
%constant int QUI__JOB_SIZE_MINIMUM = 48;
%constant int QUI__JOB_STATUS = 49;
%constant int QUI__LAST_PAGE = 50;
%constant int QUI__LIBRARY_SPECIFICATION = 51;
%constant int QUI__LOG_QUEUE = 52;
%constant int QUI__LOG_SPECIFICATION = 53;
%constant int QUI__NOTE = 54;
%constant int QUI__OPERATOR_REQUEST = 55;
%constant int QUI__OWNER_UIC = 56;
%constant int QUI__PAGE_SETUP_MODULES = 57;
%constant int QUI__PARAMETER_1 = 58;
%constant int QUI__PARAMETER_2 = 59;
%constant int QUI__PARAMETER_3 = 60;
%constant int QUI__PARAMETER_4 = 61;
%constant int QUI__PARAMETER_5 = 62;
%constant int QUI__PARAMETER_6 = 63;
%constant int QUI__PARAMETER_7 = 64;
%constant int QUI__PARAMETER_8 = 65;
%constant int QUI__PRIORITY = 66;
%constant int QUI__PROCESSOR = 67;
%constant int QUI__PROTECTION = 68;
%constant int QUI__QUEUE_FLAGS = 69;
%constant int QUI__QUEUE_NAME = 70;
%constant int QUI__QUEUE_STATUS = 71;
%constant int QUI__REFUSAL_REASON = 72;
%constant int QUI__REQUEUE_PRIORITY = 73;
%constant int QUI__REQUEUE_QUEUE_NAME = 74;
%constant int QUI__SCSNODE_NAME = 75;
%constant int QUI__SEARCH_FLAGS = 76;
%constant int QUI__SEARCH_NAME = 77;
%constant int QUI__SEARCH_NUMBER = 78;
%constant int QUI__SUBMISSION_TIME = 79;
%constant int QUI__UIC = 80;
%constant int QUI__USERNAME = 81;
%constant int QUI__WSDEFAULT = 82;
%constant int QUI__WSEXTENT = 83;
%constant int QUI__WSQUOTA = 84;
%constant int QUI__RAD = 85;
%constant int QUI__RESERVED_OUTPUT_86 = 86;
%constant int QUI__JOB_CONTROL_GQC = 87;
%constant int QUI__SEARCH_USERNAME = 88;
%constant int QUI__DEFAULT_FORM_NAME = 89;
%constant int QUI__DEFAULT_FORM_NUMBER = 90;
%constant int QUI__DEFAULT_FORM_STOCK = 91;
%constant int QUI__JOB_PID = 92;
%constant int QUI__FILE_IDENTIFICATION = 93;
%constant int QUI__PENDING_JOB_BLOCK_COUNT = 94;
%constant int QUI__JOB_RETENTION_TIME = 95;
%constant int QUI__JOB_COMPLETION_TIME = 96;
%constant int QUI__JOB_COMPLETION_QUEUE = 97;
%constant int QUI__RESERVED_OUTPUT_98 = 98;
%constant int QUI__RESERVED_OUTPUT_99 = 99;
%constant int QUI__RESERVED_OUTPUT_100 = 100;
%constant int QUI__RESERVED_OUTPUT_101 = 101;
%constant int QUI__RESERVED_OUTPUT_102 = 102;
%constant int QUI__SEARCH_BATCH_EPID = 103;
%constant int QUI__SEARCH_JOB_NAME = 104;
%constant int QUI__RESERVED_INPUT_105 = 105;
%constant int QUI__RESERVED_INPUT_106 = 106;
%constant int QUI__EXECUTING_JOB_COUNT = 107;
%constant int QUI__HOLDING_JOB_COUNT = 108;
%constant int QUI__TIMED_RELEASE_JOB_COUNT = 109;
%constant int QUI__PENDING_JOB_REASON = 110;
%constant int QUI__ORB = 111;
%constant int QUI__QUEUE_DESCRIPTION = 112;
%constant int QUI__SYMBIONT_FLAGS = 113;
%constant int QUI__JOB_ACCESS_CLASS = 114;
%constant int QUI__ORB_LOCK_KEY = 115;
%constant int QUI__CHECKPOINT_FREQUENCY = 116;
%constant int QUI__PENDING_JOB_COUNT = 117;
%constant int QUI__RETAINED_JOB_COUNT = 118;
%constant int QUI__RESTART_QUEUE_NAME = 119;
%constant int QUI__FILE_COUNT = 120;
%constant int QUI__ATTRIBUTES = 121;
%constant int QUI__ATTRIBUTES_SIZE = 122;
%constant int QUI__QUEUE_SUPPORT = 123;
%constant int QUI__QUEUE_ATTRIBUTES = 124;
%constant int QUI__QUEUE_ATTRIBUTES_SIZE = 125;
%constant int QUI__JOB_ATTRIBUTES = 126;
%constant int QUI__JOB_ATTRIBUTES_SIZE = 127;
%constant int QUI__FILE_ATTRIBUTES = 128;
%constant int QUI__FILE_ATTRIBUTES_SIZE = 129;
%constant int QUI__AUTOSTART_ON = 130;
%constant int QUI__AGENT_PROFILE = 131;
%constant int QUI__MANAGER_NAME = 132;
%constant int QUI__MANAGER_STATUS = 133;
%constant int QUI__RESERVED_OUTPUT_134 = 134;
%constant int QUI__MANAGER_NODES = 135;
%constant int QUI__MANAGER_AUTOSTART = 136;
%constant int QUI__QUEUE_DIRECTORY = 137;
%constant int QUI__RESERVED_OUTPUT_138 = 138;
%constant int QUI__RESERVED_OUTPUT_139 = 139;
%constant int QUI__RESERVED_OUTPUT_140 = 140;
%constant int QUI__RESERVED_OUTPUT_141 = 141;
%constant int QUI__RESERVED_OUTPUT_142 = 142;
%constant int QUI__RESERVED_OUTPUT_143 = 143;
%constant int QUI__RESERVED_OUTPUT_144 = 144;
%constant int QUI__RESERVED_OUTPUT_145 = 145;
%constant int QUI__RESERVED_OUTPUT_146 = 146;
%constant int QUI__RESERVED_OUTPUT_147 = 147;
%constant int QUI__RESERVED_OUTPUT_148 = 148;
%constant int QUI__RESERVED_OUTPUT_149 = 149;
%constant int QUI__RESERVED_OUTPUT_150 = 150;
%constant int QUI__RESERVED_OUTPUT_151 = 151;
%constant int QUI__RESERVED_OUTPUT_152 = 152;
%constant int QUI__RESERVED_OUTPUT_153 = 153;
%constant int QUI__RESERVED_OUTPUT_154 = 154;
%constant int QUI__RESERVED_OUTPUT_155 = 155;
%constant int QUI__RESERVED_OUTPUT_156 = 156;
%constant int QUI__RESERVED_OUTPUT_157 = 157;
%constant int QUI__RESERVED_OUTPUT_158 = 158;
%constant int QUI__RESERVED_OUTPUT_159 = 159;
%constant int QUI__RESERVED_INPUT_160 = 160;
%constant int QUI__RESERVED_INPUT_161 = 161;
%constant int QUI__RESERVED_INPUT_162 = 162;
%constant int QUI__RESERVED_INPUT_163 = 163;
%constant int QUI__RESERVED_INPUT_164 = 164;
%constant int QUI__RESERVED_INPUT_165 = 165;
%constant int QUI_K_MIN_ITEM = 1;
%constant int QUI_K_MAX_ITEM = 165;
%constant int QUI__CHARGE_CODE = 1;
%constant int QUI_M_FILE_BURST = 0x1L;
%constant int QUI_M_FILE_BURST_EXP = 0x2L;
%constant int QUI_M_FILE_DELETE = 0x4L;
%constant int QUI_M_FILE_DOUBLE_SPACE = 0x8L;
%constant int QUI_M_FILE_FLAG = 0x10L;
%constant int QUI_M_FILE_FLAG_EXP = 0x20L;
%constant int QUI_M_FILE_TRAILER = 0x40L;
%constant int QUI_M_FILE_TRAILER_EXP = 0x80L;
%constant int QUI_M_FILE_PAGE_HEADER = 0x100L;
%constant int QUI_M_FILE_PAGINATE = 0x200L;
%constant int QUI_M_FILE_PASSALL = 0x400L;
%constant int QUI_M_FILE_PAGINATE_EXP = 0x800L;
%constant int QUI_M_FILE_DELETE_ALWAYS = 0x1000L;
%constant int QUI_S_FILE_FLAGS = 4;
%constant int QUI_M_FILE_CHECKPOINTED = 0x1L;
%constant int QUI_M_FILE_EXECUTING = 0x2L;
%constant int QUI_S_FILE_STATUS = 4;
%constant int QUI_M_FORM_SHEET_FEED = 0x1L;
%constant int QUI_M_FORM_TRUNCATE = 0x2L;
%constant int QUI_M_FORM_WRAP = 0x4L;
%constant int QUI_S_FORM_FLAGS = 4;
%constant int QUI_M_JOB_CPU_LIMIT = 0x1L;
%constant int QUI_M_JOB_FILE_BURST = 0x2L;
%constant int QUI_M_JOB_FILE_BURST_ONE = 0x4L;
%constant int QUI_M_JOB_FILE_BURST_EXP = 0x8L;
%constant int QUI_M_JOB_FILE_FLAG = 0x10L;
%constant int QUI_M_JOB_FILE_FLAG_ONE = 0x20L;
%constant int QUI_M_JOB_FILE_FLAG_EXP = 0x40L;
%constant int QUI_M_JOB_FILE_TRAILER = 0x80L;
%constant int QUI_M_JOB_FILE_TRAILER_ONE = 0x100L;
%constant int QUI_M_JOB_FILE_TRAILER_EXP = 0x200L;
%constant int QUI_M_JOB_LOG_DELETE = 0x400L;
%constant int QUI_M_JOB_LOG_NULL = 0x800L;
%constant int QUI_M_JOB_LOG_SPOOL = 0x1000L;
%constant int QUI_M_JOB_LOWERCASE = 0x2000L;
%constant int QUI_M_JOB_NOTIFY = 0x4000L;
%constant int QUI_M_JOB_RESTART = 0x8000L;
%constant int QUI_M_JOB_WSDEFAULT = 0x10000L;
%constant int QUI_M_JOB_WSEXTENT = 0x20000L;
%constant int QUI_M_JOB_WSQUOTA = 0x40000L;
%constant int QUI_M_JOB_FILE_PAGINATE = 0x80000L;
%constant int QUI_M_JOB_FILE_PAGINATE_EXP = 0x100000L;
%constant int QUI_M_JOB_RETENTION = 0x200000L;
%constant int QUI_M_JOB_ERROR_RETENTION = 0x400000L;
%constant int QUI_M_JOB_RAD = 0x800000L;
%constant int QUI_S_JOB_FLAGS = 4;
%constant int QUI_M_JOB_ABORTING = 0x1L;
%constant int QUI_M_JOB_EXECUTING = 0x2L;
%constant int QUI_M_JOB_HOLDING = 0x4L;
%constant int QUI_M_JOB_INACCESSIBLE = 0x8L;
%constant int QUI_M_JOB_REFUSED = 0x10L;
%constant int QUI_M_JOB_REQUEUE = 0x20L;
%constant int QUI_M_JOB_RESTARTING = 0x40L;
%constant int QUI_M_JOB_RETAINED = 0x80L;
%constant int QUI_M_JOB_STARTING = 0x100L;
%constant int QUI_M_JOB_TIMED_RELEASE = 0x200L;
%constant int QUI_M_JOB_SUSPENDED = 0x400L;
%constant int QUI_M_JOB_PENDING = 0x800L;
%constant int QUI_M_JOB_UNDEFINED = 0x1000L;
%constant int QUI_M_JOB_STALLED = 0x2000L;
%constant int QUI_M_JOB_INCOMPLETE = 0x4000L;
%constant int QUI_M_JOB_COMPLETING = 0x8000L;
%constant int QUI_S_JOB_STATUS = 4;
%constant int QUI_V_JOB_TIMED = 9;
%constant int QUI_M_JOB_TIMED = 512;
%constant int QUI_M_PEND_CHAR_MISMATCH = 0x1L;
%constant int QUI_M_PEND_JOB_SIZE_MAX = 0x2L;
%constant int QUI_M_PEND_JOB_SIZE_MIN = 0x4L;
%constant int QUI_M_PEND_LOWERCASE_MISMATCH = 0x8L;
%constant int QUI_M_PEND_NO_ACCESS = 0x10L;
%constant int QUI_M_PEND_QUEUE_BUSY = 0x20L;
%constant int QUI_M_PEND_QUEUE_STATE = 0x40L;
%constant int QUI_M_PEND_STOCK_MISMATCH = 0x80L;
%constant int QUI_S_PENDING_JOB_REASON = 4;
%constant int QUI_M_QUEUE_BATCH = 0x1L;
%constant int QUI_M_QUEUE_CPU_DEFAULT = 0x2L;
%constant int QUI_M_QUEUE_CPU_LIMIT = 0x4L;
%constant int QUI_M_QUEUE_FILE_BURST = 0x8L;
%constant int QUI_M_QUEUE_FILE_BURST_ONE = 0x10L;
%constant int QUI_M_QUEUE_FILE_FLAG = 0x20L;
%constant int QUI_M_QUEUE_FILE_FLAG_ONE = 0x40L;
%constant int QUI_M_QUEUE_FILE_TRAILER = 0x80L;
%constant int QUI_M_QUEUE_FILE_TRAILER_ONE = 0x100L;
%constant int QUI_M_QUEUE_GENERIC = 0x200L;
%constant int QUI_M_QUEUE_GENERIC_SELECTION = 0x400L;
%constant int QUI_M_QUEUE_JOB_BURST = 0x800L;
%constant int QUI_M_QUEUE_JOB_FLAG = 0x1000L;
%constant int QUI_M_QUEUE_JOB_SIZE_SCHED = 0x2000L;
%constant int QUI_M_QUEUE_JOB_TRAILER = 0x4000L;
%constant int QUI_M_QUEUE_RETAIN_ALL = 0x8000L;
%constant int QUI_M_QUEUE_RETAIN_ERROR = 0x10000L;
%constant int QUI_M_QUEUE_SWAP = 0x20000L;
%constant int QUI_M_QUEUE_TERMINAL = 0x40000L;
%constant int QUI_M_QUEUE_WSDEFAULT = 0x80000L;
%constant int QUI_M_QUEUE_WSEXTENT = 0x100000L;
%constant int QUI_M_QUEUE_WSQUOTA = 0x200000L;
%constant int QUI_M_QUEUE_FILE_PAGINATE = 0x400000L;
%constant int QUI_M_QUEUE_RECORD_BLOCKING = 0x800000L;
%constant int QUI_M_QUEUE_PRINTER = 0x1000000L;
%constant int QUI_M_QUEUE_ACL_SPECIFIED = 0x2000000L;
%constant int QUI_M_QUEUE_NOTIFY_ON_INTERRUPT = 0x4000000L;
%constant int QUI_M_QUEUE_CHECKPOINT_FREQ = 0x8000000L;
%constant int QUI_M_QUEUE_AUTOSTART = 0x10000000L;
%constant int QUI_M_SECURITY_INACCESSIBLE = 0x20000000L;
%constant int QUI_M_QUEUE_NO_INITIAL_FF = 0x40000000L;
%constant int QUI_M_QUEUE_RAD = 0x80000000L;
%constant int QUI_S_QUEUE_FLAGS = 4;
%constant int QUI_M_QUEUE_ALIGNING = 0x1L;
%constant int QUI_M_QUEUE_IDLE = 0x2L;
%constant int QUI_M_QUEUE_LOWERCASE = 0x4L;
%constant int QUI_M_QUEUE_OPERATOR_REQUEST = 0x8L;
%constant int QUI_M_QUEUE_PAUSED = 0x10L;
%constant int QUI_M_QUEUE_PAUSING = 0x20L;
%constant int QUI_M_QUEUE_REMOTE = 0x40L;
%constant int QUI_M_QUEUE_RESETTING = 0x80L;
%constant int QUI_M_QUEUE_RESUMING = 0x100L;
%constant int QUI_M_QUEUE_SERVER = 0x200L;
%constant int QUI_M_QUEUE_STALLED = 0x400L;
%constant int QUI_M_QUEUE_STARTING = 0x800L;
%constant int QUI_M_QUEUE_STOPPED = 0x1000L;
%constant int QUI_M_QUEUE_STOPPING = 0x2000L;
%constant int QUI_M_QUEUE_UNAVAILABLE = 0x4000L;
%constant int QUI_M_QUEUE_CLOSED = 0x8000L;
%constant int QUI_M_QUEUE_BUSY = 0x10000L;
%constant int QUI_M_QUEUE_UNDEFINED = 0x20000L;
%constant int QUI_M_QUEUE_AVAILABLE = 0x40000L;
%constant int QUI_M_QUEUE_DISABLED = 0x80000L;
%constant int QUI_M_QUEUE_AUTOSTART_INACTIVE = 0x100000L;
%constant int QUI_M_QUEUE_STOP_PENDING = 0x200000L;
%constant int QUI_S_QUEUE_STATUS = 4;
%constant int QUI_M_SEARCH_ALL_JOBS = 0x1L;
%constant int QUI_M_SEARCH_WILDCARD = 0x2L;
%constant int QUI_M_SEARCH_BATCH = 0x4L;
%constant int QUI_M_SEARCH_SYMBIONT = 0x8L;
%constant int QUI_M_SEARCH_THIS_JOB = 0x10L;
%constant int QUI_M_SEARCH_PRINTER = 0x20L;
%constant int QUI_M_SEARCH_SERVER = 0x40L;
%constant int QUI_M_SEARCH_TERMINAL = 0x80L;
%constant int QUI_M_SEARCH_GENERIC = 0x100L;
%constant int QUI_M_SEARCH_GENERIC_TARGET = 0x200L;
%constant int QUI_M_SEARCH_PENDING_JOBS = 0x400L;
%constant int QUI_M_SEARCH_EXECUTING_JOBS = 0x800L;
%constant int QUI_M_SEARCH_TIMED_RELEASE_JOBS = 0x1000L;
%constant int QUI_M_SEARCH_HOLDING_JOBS = 0x2000L;
%constant int QUI_M_SEARCH_RETAINED_JOBS = 0x4000L;
%constant int QUI_M_SEARCH_FREEZE_CONTEXT = 0x8000L;
%constant int QUI_M_SEARCH_OPEN_JOBS = 0x10000L;
%constant int QUI_M_SEARCH_RESERVED_BIT1 = 0x20000L;
%constant int QUI_M_SEARCH_RESERVED_BIT2 = 0x40000L;
%constant int QUI_S_SEARCH_FLAGS = 4;
%constant int QUI_M_SYM_NOTIFIES = 0x1L;
%constant int QUI_M_SYM_REQUESTS_OPER = 0x2L;
%constant int QUI_M_SYM_COPIES_FILE = 0x4L;
%constant int QUI_M_SYM_COPIES_JOB = 0x8L;
%constant int QUI_M_SYM_ACCEPTS_ALL_FORMS = 0x10L;
%constant int QUI_M_SYM_NO_JOB_CHECKPOINT = 0x20L;
%constant int QUI_S_SYMBIONT_FLAGS = 4;
%constant int QUI_M_MANAGER_START_PENDING = 0x1L;
%constant int QUI_M_MANAGER_STARTING = 0x2L;
%constant int QUI_M_MANAGER_RUNNING = 0x4L;
%constant int QUI_M_MANAGER_FAILOVER = 0x8L;
%constant int QUI_M_MANAGER_STOPPING = 0x10L;
%constant int QUI_M_MANAGER_STOPPED = 0x20L;
%constant int QUI_S_MANAGER_STATUS = 4;
