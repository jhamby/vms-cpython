$ ! PYTHON$STARTUP.COM
$ !+
$ ! June-2021
$ ! Startup file for Python on OpenVMS
$ !
$ !-
$
$ set noon
$
$ file = f$search("sys$startup:python$define_logicals.com")
$
$ if file .eqs. ""
$ then
$    root = f$trnlmn("pcsi$destination")
$    if "''root'" .eqs. ""
$    then
$       write sys$output "The logical name python$root is not defined; check installation."
$       exit
$    endif
$
$    root = "''root" - "]" + "python.]"
$    define/system/trans=concealed python$root 'root
$    define/system python$shr python$root:[lib]python$shr.exe
$    python :== $python$root:[bin]python.exe
$ else
$    @sys$startup:python$define_logicals.com
$ endif
$
$!! if f$file_attributes("PYTHON$SHR","KNOWN")
$!! then
$!!    install replace python$shr
$!! else
$!!    install add python$shr /open /header_res /share
$!! endif
$
$ exit
