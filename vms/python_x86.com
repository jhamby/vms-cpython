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
$ prj_ptt = com_pat - ".vms]"
$ bld_pat = prj_ptt + ".out.''CONFIG']"
$ inc_pat = prj_ptt + ".include]"
$ cpy_pat = prj_ptt + ".include.cpython]"
$ lib_pat = prj_ptt + ".lib...]"
$ vms_py_pat = prj_ptt + ".modules.vms...]"
$ rdb_py_pat = prj_ptt + ".modules.rdb...]"
$ vms_pat = prj_ptt + ".vms]"
$ dyn_pat = prj_ptt + ".out.'CONFIG'.lib-dynload...]"
$ @'com_pat'Python^.def_x86.com
$
$ pipe delete/tree python$root:[000000...]*.*;* | copy SYS$INPUT nl:
$
$ backup 'bld_pat'python.exe python$root:[bin] /log
$
$ backup 'inc_pat'*.h python$root:[include] /log
$ backup 'cpy_pat'*.h python$root:[include.cpython] /log
$ backup 'vms_pat'pyconfig.h python$root:[include] /log
$
$ backup 'lib_pat'*.* python$root:[lib.python3^.10...] /log
$ backup 'vms_py_pat'*.py python$root:[lib.python3^.10.vms] /log
$ backup 'rdb_py_pat'*.py python$root:[lib.python3^.10] /log
$ backup 'bld_pat'python$shr.exe python$root:[lib] /log
$
$ backup 'vms_pat'python$define_root.com python$root:[000000] /log
$ backup 'vms_pat'python$pcsi_preconfigure.com python$root:[000000] /log
$ backup 'vms_pat'python$startup.com python$root:[000000] /log
$ backup 'vms_pat'python$shutdown.com python$root:[000000] /log
$
$ backup 'dyn_pat'*.* python$root:[lib.python3^.10.lib-dynload...]*.* /log
$ backup 'vms_pat'_sysconfigdata__OpenVMS_cpython-310-x86_64-openvms.py python$root:[lib.python3^.10] /log
