$ ! PYTHON$SHUTDOWN.COM
$ !+
$ ! June-2021
$ ! Shutdown file for Python on OpenVMS
$ !
$ !-
$
$ verify = f$verify(0)
$ set noon
$
$! Cleanup logical names...
$!
$!! if f$file_attributes("PYTHON$SHR","KNOWN")
$!! then
$!!    install remove python$shr
$!! endif
$
$ if f$trnlnm("PYTHON$SHR", "LNM$SYSTEM_TABLE") .nes. ""
$ then
$    deassign/sys PYTHON$SHR
$ endif
$
$ if f$trnlnm("PYTHON$ROOT", "LNM$SYSTEM_TABLE") .nes. ""
$ then
$    deassign/sys PYTHON$ROOT
$ endif
$
$ exit
