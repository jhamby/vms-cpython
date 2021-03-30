"""Basic tests for os.popen()

  Particularly useful for platforms that fake popen.
"""

import unittest
from test import support
import os, sys

if not hasattr(os, 'popen'):
    raise unittest.SkipTest("need os.popen()")

# Test that command-lines get down as we expect.
# To do this we execute:
#    python -c "import sys;print(sys.argv)" {rest_of_commandline}
# This results in Python being spawned and printing the sys.argv list.
# We can then eval() the result of this, and see what each argv was.
python = sys.executable
if ' ' in python:
    python = '"' + python + '"'     # quote embedded space for cmdline

if (sys.platform == 'OpenVMS'):
    python = 'python'

class PopenTest(unittest.TestCase):

    def _do_test_commandline(self, cmdline, expected):
        cmd = '%s -c "import sys; print(sys.argv)" %s'
        cmd = cmd % (python, cmdline)
        with os.popen(cmd) as p:
            if (sys.platform == 'OpenVMS'):
                # skip the first lines if they are empty
                data = p.read()
                while data == '':
                    data = p.read()
            else:
                data = p.read()
        got = eval(data)[1:] # strip off argv[0]
        self.assertEqual(got, expected)

    def test_popen(self):
        self.assertRaises(TypeError, os.popen)
        self._do_test_commandline(
            "foo bar",
            ["foo", "bar"]
        )
        self._do_test_commandline(
            'foo "spam and eggs" "silly walk"',
            ["foo", "spam and eggs", "silly walk"]
        )
        if sys.platform == 'OpenVMS':
            # in DCL quote is passed as double quote
            self._do_test_commandline(
                'foo "a \"\"quoted\"\" arg" bar',
                ["foo", 'a "quoted" arg', "bar"]
            )
        else:
            self._do_test_commandline(
                'foo "a \\"quoted\\" arg" bar',
                ["foo", 'a "quoted" arg', "bar"]
            )
        support.reap_children()

    @unittest.skipIf(sys.platform == 'OpenVMS', 'OpenVMS command EXIT has another meaning')
    def test_return_code(self):
        self.assertEqual(os.popen("exit 0").close(), None)
        status = os.popen("exit 42").close()
        if os.name == 'nt':
            self.assertEqual(status, 42)
        else:
            self.assertEqual(os.waitstatus_to_exitcode(status), 42)

    def test_contextmanager(self):
        cmd = "echo hello"
        if sys.platform == 'OpenVMS':
            cmd = 'write sys$output F$FAO("hello")'
        with os.popen(cmd) as f:
            self.assertEqual(f.read(), "hello\n")

    def test_iterating(self):
        cmd = "echo hello"
        if sys.platform == 'OpenVMS':
            cmd = 'write sys$output F$FAO("hello")'
        with os.popen(cmd) as f:
            self.assertEqual(list(f), ["hello\n"])

    def test_keywords(self):
        with os.popen(cmd="exit 0", mode="w", buffering=-1):
            pass

if __name__ == "__main__":
    unittest.main()
