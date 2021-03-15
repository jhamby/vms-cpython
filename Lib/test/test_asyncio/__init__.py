import os
from test.support import load_package_tests
from test.support import import_helper

if os.sys.platform == 'OpenVMS':
    import unittest
    raise unittest.SkipTest('Asyncio does not fully supported by OpenVMS')

# Skip tests if we don't have concurrent.futures.
import_helper.import_module('concurrent.futures')

def load_tests(*args):
    return load_package_tests(os.path.dirname(__file__), *args)
