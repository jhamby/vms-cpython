$ com_nam = f$environment("procedure")
$ com_dir = f$parse(com_nam,,,"directory")
$ com_dev = f$parse(com_nam,,,"device")
$ com_pat = com_dev + com_dir
$ INSTALL_DIR = com_pat - ".vms]" + ".out.python.]"
$ define /trans=concealed python3_10$root 'INSTALL_DIR'
$ define PYTHONHOME "/python3_10$root"
$ define python3_10$shr python3_10$root:[lib]python3_10$shr.exe
$ python3_10 :== $python3_10$root:[bin]python3^.10.exe
