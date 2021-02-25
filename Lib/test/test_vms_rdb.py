import sys
import unittest
import os
import tempfile

if sys.platform != 'OpenVMS':
    raise unittest.SkipTest('OpenVMS required')

import _rdb
import _decc

class BaseTestCase(unittest.TestCase):


    def setUp(self):
        self.dbname = ''
        self.dbname_vms = ''
        self.create_sql_database()

    def tearDown(self):
        if self.dbname:
            os.chmod(self.dbname, 0o777)
            os.unlink(self.dbname)
            name, ext = os.path.splitext(self.dbname)
            name = name + '.snp'
            os.chmod(name, 0o777)
            os.unlink(name)
        self.dbname = ''

    def create_sql_database(self):
        """ tests creating SQL database """

        sql_content = \
'''$!============================================================
$temp = f$search("{dbname}")
$if temp .nes. ""
$then
$   goto go_out
$endif
$sql$
create database filename {dbname}
        number of users 500
        number of cluster nodes 1;
create domain   standard_address        char(25);
create domain   standard_city           char(20);
create domain   standard_name           char(30);
create domain   standard_tel            char(10);
commit;
create table customer(
        name    char(30),
        address char(25),
        city    char(20),
        tel1    char(10),
        tel2    char(10));
commit;
alter table customer add column postal char(6) after column city;
alter table customer add column province char(15) after column city;
commit;
insert into customer values(
        'Neil Rieck',
        '20 Water St N',
        'Kitchener',
        'Ontario',
        'N2H5A5',
        '5195551212',
        '');
insert into customer values(
        'Steve Kennel',
        '20 Water St N',
        'Kitchener',
        'Ontario',
        'N2H5A5',
        '5195551212',
        '');
insert into customer values(
        'Dave McNeil',
        '140 Bayfield St',
        'Barrie',
        'Ontario',
        'L4M3B1',
        '7055551212',
        '');
insert into customer(
        name,address,city,province,postal,tel1,tel2)
        values(
        'Karim Macklai',
        '220 Simcoe St',
        'Toronto',
        'Ontario',
        'M5T1T4',
        '4165551212',
        '');
commit;
exit
$go_out:
$exit
'''
        fd, self.dbname = tempfile.mkstemp(suffix='.RDB')
        os.close(fd)
        os.unlink(self.dbname)
        self.dbname_vms = _decc.to_vms(self.dbname)[0]
        sql_content = sql_content.format(dbname=self.dbname_vms)

        with tempfile.NamedTemporaryFile(suffix=".COM", delete=False) as tmpfile:
            tmpfile.write(sql_content.encode())
            tmpfile.close()
            tmpfile_vms_name = _decc.to_vms(tmpfile.name)[0]
            p = os.popen('@' + tmpfile_vms_name)
            data = p.read()
            p.close()
            os.unlink(tmpfile.name)

    def test_sql_database(self):
        """ tests SQL database """

        sqlca = _rdb.sqlca()
        sqlca.attach(self.dbname_vms)
        self.assertIsNot(sqlca.code, -1, sqlca.message)

        sqlca.set_readonly()
        self.assertIsNot(sqlca.code, -1, sqlca.message)

        ch = sqlca.declare_cursor("C001", "select name, address, city from customer")
        self.assertIsNot(ch, None, sqlca.message)

        fields = ch.fields()
        self.assertIsNot(fields, None, sqlca.message)
        self.assertIsNot(len(fields), 3, "must be 3 columns")

        ch.open_cursor()
        self.assertIsNot(sqlca.code, -1, sqlca.message)

        while ch.fetch() == 0:
            data = ch.data()
            self.assertIsNot(data, None, sqlca.message)
            self.assertIsNot(len(data), 3, "must be 3 columns")

        self.assertIs(sqlca.code, _rdb.SQLCODE_EOS, sqlca.message)

        ch.close_cursor()
        self.assertIsNot(sqlca.code, -1, sqlca.message)

        ch.release()
        sqlca.detach()


if __name__ == "__main__":
    unittest.main(verbosity=2)
