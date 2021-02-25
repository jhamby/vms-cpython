$!============================================================
$temp = f$search("rdb_db.rdb")
$if temp .nes. ""
$then
$   goto go_out
$endif
$sql$
create database filename rdb_db.rdb
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