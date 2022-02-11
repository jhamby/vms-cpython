$ if f$mode() .eqs. "NETWORK"
$ then define sys$output sys$net
$ endif
$ ! we have to copy image to the local disk before executing it
$ ! CHANGE PATHS!!!
$ set default $172$DKA300:[vorfolomeev]
$ backup wrk_disk:[.cpython.out.RELEASEx86.Programs]_freeze_importlib.exe;* [] /log/repl
$ mcr []_freeze_importlib.exe importlib._bootstrap_external /wrk_disk/vorfolomeev/cpython/Lib/importlib/_bootstrap_external.py /wrk_disk/vorfolomeev/cpython/Python/importlib_external.h
$ mcr []_freeze_importlib.exe importlib._bootstrap /wrk_disk/vorfolomeev/cpython/Lib/importlib/_bootstrap.py /wrk_disk/vorfolomeev/cpython/Python/importlib.h
$ mcr []_freeze_importlib.exe zipimport /wrk_disk/vorfolomeev/cpython/Lib/zipimport.py /wrk_disk/vorfolomeev/cpython/Python/importlib_zipimport.h
$ delete _freeze_importlib.exe;*