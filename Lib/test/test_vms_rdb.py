import sys
import unittest
import os
import tempfile

if sys.platform != 'OpenVMS':
    raise unittest.SkipTest('OpenVMS required')

import _rdb
import _decc

class BaseTestCase(unittest.TestCase):

    db_data = [
        [   'Neil Rieck',
            '20 Water St N',
            'Kitchener',
            'Ontario',
            'N2H5A5',
            '5195551212',
            '',
        ],
        [   'Steve Kennel',
            '20 Water St N',
            'Kitchener',
            'Ontario',
            'N2H5A5',
            '5195551212',
            '',
        ],
        [   'Dave McNeil',
            '140 Bayfield St',
            'Barrie',
            'Ontario',
            'L4M3B1',
            '7055551212',
            '',
        ],
        [   'Karim Macklai',
            '220 Simcoe St',
            'Toronto',
            'Ontario',
            'M5T1T4',
            '4165551212',
            '',
        ],
    ]

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

        sql_content_header = \
'''$!============================================================
$temp = f$search("{dbname}")
$if temp .nes. ""
$then
$   goto go_out
$endif
$mcr sql$
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
'''
        sql_content_record = \
'''
insert into customer values(
        '{name}',
        '{addr}',
        '{city}',
        '{province}',
        '{postal}',
        '{tel1}',
        '{tel2}');
'''
        sql_content_record_with_names = \
'''
insert into customer(
        name,address,city,province,postal,tel1,tel2)
        values(
        '{name}',
        '{addr}',
        '{city}',
        '{province}',
        '{postal}',
        '{tel1}',
        '{tel2}');
'''
        sql_content_footer = \
'''
commit;
exit
$go_out:
$exit
'''
        fd, self.dbname = tempfile.mkstemp(suffix='.RDB')
        os.close(fd)
        os.unlink(self.dbname)
        self.dbname_vms = _decc.to_vms(self.dbname)[0]
        sql_content = sql_content_header.format(dbname=self.dbname_vms)
        for data in BaseTestCase.db_data[:-2]:
            sql_content += sql_content_record.format(
                name=data[0],
                addr=data[1],
                city=data[2],
                province=data[3],
                postal=data[4],
                tel1=data[5],
                tel2=data[6],
            )
        for data in BaseTestCase.db_data[-2:]:
            sql_content += sql_content_record.format(
                name=data[0],
                addr=data[1],
                city=data[2],
                province=data[3],
                postal=data[4],
                tel1=data[5],
                tel2=data[6],
            )
        sql_content += sql_content_footer

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
        self.assertNotEqual(sqlca.code, -1, sqlca.message)

        sqlca.set_readonly()
        self.assertNotEqual(sqlca.code, -1, sqlca.message)

        ch = sqlca.declare_cursor("C001", "select name, address, city from customer")
        self.assertNotEqual(ch, None, sqlca.message)

        fields = ch.fields()
        self.assertNotEqual(fields, None, sqlca.message)
        self.assertEqual(len(fields), 3, "must be 3 columns")

        ch.open_cursor()
        self.assertNotEqual(sqlca.code, -1, sqlca.message)

        pos = 0
        while ch.fetch() == 0:
            data = ch.data()
            self.assertNotEqual(data, None, sqlca.message)
            self.assertEqual(len(data), 3, "must be 3 columns")
            name, addr, city = data
            self.assertEqual(name.strip(), BaseTestCase.db_data[pos][0])
            self.assertEqual(addr.strip(), BaseTestCase.db_data[pos][1])
            self.assertEqual(city.strip(), BaseTestCase.db_data[pos][2])
            pos += 1

        self.assertEqual(sqlca.code, _rdb.SQLCODE_EOS, sqlca.message)

        ch.close_cursor()
        self.assertNotEqual(sqlca.code, -1, sqlca.message)

        ch.release()
        sqlca.detach()

    def test_sql_exec(self):
        sqlca = _rdb.sqlca()

        sqlca.attach(self.dbname_vms)
        self.assertNotEqual(sqlca.code, -1, sqlca.message)

        stmt = sqlca.prepare("insert into customer (name, address, city) values (?,?,?)")
        self.assertIsNot(stmt, None, sqlca.message)

        rv = stmt.exec('Bill Smith', '20 Seagul St', 'Berlin')
        rv = stmt.exec('Joe Smith', '26 Free St', 'Toronto')
        rv = stmt.exec('Bill Murrey', '13 Elm St', 'Washingtown')
        
        sqlca.commit()
        sqlca.rollback()
        sqlca.detach()

    def test_sql_select(self):
        sqlca = _rdb.sqlca()

        sqlca.attach(self.dbname_vms)
        self.assertNotEqual(sqlca.code, -1, sqlca.message)

        stmt = sqlca.prepare("select name, address from customer where city = ?")
        self.assertIsNot(stmt, None, sqlca.message)

        row = stmt.select('Toronto')
        self.assertIsNot(row, None, sqlca.message)
        
        sqlca.commit()
        sqlca.rollback()
        sqlca.detach()

if __name__ == "__main__":
    unittest.main(verbosity=2)
