$ com_nam = f$environment("procedure")
$ com_dir = f$parse(com_nam,,,"directory")
$ com_dev = f$parse(com_nam,,,"device")
$ com_pat = com_dev + com_dir
$ INSTALL_DIR = com_pat - ".vms]" + ".out.python.]"
$ define /trans=concealed python$root 'INSTALL_DIR'
$ define PYTHONHOME "/python$root"
$ define python$shr python$root:[lib]python$shr.exe
$ python :== $python$root:[bin]python3^.10.exe
