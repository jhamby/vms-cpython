$ on error then $ gosub on_error
$ pipe python -m test --list-tests > TEST_NAMES.TXT
$ OPEN TEST_NAMES TEST_NAMES.TXT
$ LOOP:
$ READ/END_OF_FILE=FILE_END TEST_NAMES NAME
$ python -m test 'NAME'
$ GOTO LOOP
$ FILE_END:
$ CLOSE TEST_NAMES
$ DEL TEST_NAMES.TXT;*
$ on_error:
$ on error then $ gosub on_error
$ return
