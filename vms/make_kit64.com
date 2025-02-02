$ set verify
$
$ delete/log/noconf vsi-axpvms-python*.pcsi;*
$ delete/log/noconf vsi-axpvms-python*.pcsi$compressed;*
$
$ com_nam = f$environment("procedure")
$ com_dir = f$parse(com_nam,,,"directory")
$ com_dev = f$parse(com_nam,,,"device")
$ out_pat = com_dev + com_dir - "vms]" + "out.]"
$
$ product package python64 -
        /source=python64.pcsi$desc -
        /destination=[] -
        /material=('out_pat') -
        /format=sequential -
        /opt=noconf -
        /log -
        /producer=VSI
$
$ product copy python64 /source=[] /dest=[] /format=compressed /opt=noconf
$ purge/log
$
$ purge/log [...]
$
$ set noverify
$
$ exit

