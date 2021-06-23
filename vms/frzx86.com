$ if f$mode() .eqs. "NETWORK"
$ then define sys$output sys$net
$ endif
$ ! we have to copy image to the local disk before executing it
$ set default $172$DKA300:[vorfolomeev]
$ backup usr_disk:[.cpython...]_freeze_importlib.exe;* [.cpython...] /log/repl
$ mcr [.cpython.out.release.Programs]_freeze_importlib.exe importlib._bootstrap_external /usr_disk/vorfolomeev/cpython/Lib/importlib/_bootstrap_external.py /usr_disk/vorfolomeev/cpython/Python/importlib_external.h
$ mcr [.cpython.out.release.Programs]_freeze_importlib.exe importlib._bootstrap /usr_disk/vorfolomeev/cpython/Lib/importlib/_bootstrap.py /usr_disk/vorfolomeev/cpython/Python/importlib.h
$ mcr [.cpython.out.release.Programs]_freeze_importlib.exe zipimport /usr_disk/vorfolomeev/cpython/Lib/zipimport.py /usr_disk/vorfolomeev/cpython/Python/importlib_zipimport.h