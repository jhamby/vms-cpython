$ define /trans=concealed python$root $172$DKA300:[vorfolomeev.python.]
$ define PYTHONHOME "/python$root"
$ define python$shr python$root:[lib]python$shr.exe
$ python :== $python$root:[bin]python.exe
