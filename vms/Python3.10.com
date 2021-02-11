$ if "''P1'" .eqs. ""
$ then
$   CONFIG := DEBUG
$ else
$   CONFIG := 'P1'
$ endif
$ write sys$output "Prepare for ''CONFIG'"
$
$ com_nam = f$environment("procedure")
$ com_dir = f$parse(com_nam,,,"directory")
$ com_dev = f$parse(com_nam,,,"device")
$ com_pat = com_dev + com_dir
$ prj_pat = com_pat - ".vms]"
$ bld_pat = prj_pat + ".out.''CONFIG']"
$ inc_pat = prj_pat + ".include]"
$ cpy_pat = prj_pat + ".include.cpython]"
$ lib_pat = prj_pat + ".lib...]"
$ vms_py_pat = prj_pat + ".modules.vms...]"
$ rdb_py_pat = prj_pat + ".modules.rdb...]"
$ vms_pat = prj_pat + ".vms]"
$ dyn_pat = prj_pat + ".out.'CONFIG'.lib-dynload...]"
$ @'com_pat'Python3^.10^.def.com
$
$ pipe delete/tree python3_10$root:[000000...]*.*;* | copy SYS$INPUT nl:
$
$ backup 'bld_pat'python3^.10.exe python3_10$root:[bin]
$
$ backup 'inc_pat'*.h python3_10$root:[include]
$ backup 'cpy_pat'*.h python3_10$root:[include.cpython]
$
$ backup 'lib_pat'*.* python3_10$root:[lib.python3^.10...]
$ backup 'vms_py_pat'*.py python3_10$root:[lib.python3^.10.vms]
$ backup 'rdb_py_pat'*.py python3_10$root:[lib.python3^.10]
$ backup 'bld_pat'python3_10$shr.exe python3_10$root:[lib]
$
$ backup 'vms_pat'python$define_root.com python3_10$root:[000000]
$ backup 'vms_pat'python$pcsi_preconfigure.com python3_10$root:[000000]
$ backup 'vms_pat'python$startup.com python3_10$root:[000000]
$ backup 'vms_pat'python$shutdown.com python3_10$root:[000000]
$
$ backup 'dyn_pat'*.* python3_10$root:[lib.python3^.10.lib-dynload...]*.*
$ backup 'vms_pat'_sysconfigdata__OpenVMS_cpython-3a-ia64-openvms.py python3_10$root:[lib.python3^.10]
