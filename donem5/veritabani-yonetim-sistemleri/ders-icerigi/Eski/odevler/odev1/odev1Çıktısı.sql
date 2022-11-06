/* 1306150001 Yunus Emre Ak */
/* ÖDEV 1: Veritabanı-SQL, Teslim tarihi: 16 Ekim Salı */
/* Sade görünüm için hatalardan arındırılmıştır. */


/* Database oluşturma */

MariaDB [(none)]> CREATE DATABASE restorant;
Query OK, 1 row affected (0.00 sec)

MariaDB [(none)]> 
MariaDB [(none)]> USE restorant;
Database changed

MariaDB [restorant]> CREATE TABLE Musteri (
    ->     mno int Primary Key,
    ->     madi nvarchar(17),
    ->     msoyadi nvarchar(17),
    ->     mtelefon varchar(10)
    ->     );
Query OK, 0 rows affected (0.02 sec)

MariaDB [restorant]> 
MariaDB [restorant]> CREATE TABLE Yemek(
    ->     yno int Primary Key,
    ->     yadi nvarchar(17),
    ->     ykalori int,
    ->     yfiyati int,
    ->     yturu nvarchar(17)
    ->     );
Query OK, 0 rows affected (0.03 sec)

MariaDB [restorant]> 
MariaDB [restorant]> CREATE TABLE Siparis(
    ->     mno int not null,
    ->     yno int not null,
    ->     tarihsaat datetime,
    ->     foreign key (mno) references Musteri(mno),
    ->     foreign key (yno) references Yemek(yno)
    ->     );
Query OK, 0 rows affected (0.02 sec)

MariaDB [restorant]> 
MariaDB [restorant]> CREATE TABLE Malzeme(
    ->     zno int Primary Key,
    ->     zadi nvarchar(17),
    ->     ztipi nvarchar(17)
    ->     );
Query OK, 0 rows affected (0.02 sec)

MariaDB [restorant]> 
MariaDB [restorant]> CREATE TABLE Kullan(
    ->     yno int not null,
    ->     zno int not null,
    ->     miktar int,
    ->     foreign key (yno) references Yemek(yno),
    ->     foreign key (zno) references Malzeme(zno)
    ->     );
Query OK, 0 rows affected (0.12 sec)

/* Veriler Eklendi */

MariaDB [restorant]>     select * from Musteri;
+-----+------------+---------+------------+
| mno | madi       | msoyadi | mtelefon   |
+-----+------------+---------+------------+
|   1 | Yunus Emre | Ak      | 5308977689 |
|   2 | Ali        | Kurt    | 1234567891 |
|   3 | Ayse       | Haydi   | 1234567892 |
|   4 | Fatma      | Cifte   | 1234567893 |
|   5 | Hayriye    | Telliye | 1234567894 |
|   6 | Sarki      | Sonu    | 1234567895 |
|   7 | Ac         | Herif   | 1234567895 |
+-----+------------+---------+------------+
7 rows in set (0.00 sec)

MariaDB [restorant]> select * from Yemek;
+-----+-----------------+---------+---------+----------+
| yno | yadi            | ykalori | yfiyati | yturu    |
+-----+-----------------+---------+---------+----------+
|   1 | Menemen         |    1560 |       7 | Ana ogun |
|   2 | Kebap           |    1430 |      20 | Ana Ogun |
|   3 | Doner           |    1300 |      15 | Ana Ogun |
|   4 | Kuru Fasulye    |     500 |      13 | Ana Ogun |
|   5 | Bulgur Pilavi   |     200 |       5 | Ara Ogun |
|   6 | Kadinbudu Kofte |    1300 |      18 | Ana Ogun |
|   7 | Iskender        |    1560 |      19 | Ana Ogun |
|   8 | Corba           |     200 |       5 | Ara Ogun |
|   9 | Salata          |     100 |       7 | Ara Ogun |
+-----+-----------------+---------+---------+----------+
9 rows in set (0.01 sec)

MariaDB [restorant]> select * from siparis;
+-----+-----+---------------------+
| mno | yno | tarihsaat           |
+-----+-----+---------------------+
|   1 |   7 | 2017-05-17 17:17:17 |
|   1 |   5 | 2017-05-17 17:17:19 |
|   1 |   8 | 2017-05-17 17:17:20 |
|   2 |   4 | 2017-05-19 19:19:19 |
|   3 |   5 | 2017-05-17 17:17:19 |
|   3 |   8 | 2017-05-17 17:17:19 |
|   4 |   2 | 2017-05-17 17:19:17 |
|   4 |   3 | 2017-05-17 17:19:17 |
|   5 |   3 | 2017-05-17 19:17:17 |
|   5 |   8 | 2017-05-17 19:17:17 |
|   6 |   8 | 2017-05-17 19:17:19 |
|   7 |   1 | 2017-05-17 19:17:19 |
|   7 |   2 | 2017-05-17 19:17:19 |
|   7 |   3 | 2017-05-17 19:17:19 |
|   7 |   6 | 2017-05-17 19:17:19 |
|   7 |   8 | 2017-05-17 19:17:19 |
|   7 |   9 | 2017-05-17 19:17:19 |
+-----+-----+---------------------+
17 rows in set (0.00 sec)

MariaDB [restorant]> select * from malzeme;
+-----+----------+---------+
| zno | zadi     | ztipi   |
+-----+----------+---------+
|   1 | Su       | sevilen |
|   2 | Et       | tip2    |
|   3 | Kereviz  | tip3    |
|   4 | Sogan    | tip4    |
|   5 | Biber    | tip5    |
|   6 | Yogurt   | tip2    |
|   7 | Tereyagi | tip2    |
|   8 | Patates  | tip3    |
|   9 | Fasulye  | tip2    |
|  10 | Bulgur   | tip3    |
|  11 | Yumurta  | tip4    |
|  12 | Kiyma    | tip4    |
|  13 | Ekmek    | tip4    |
|  14 | Maydanoz | tip4    |
|  15 | Domates  | tip4    |
+-----+----------+---------+
15 rows in set (0.00 sec)

MariaDB [restorant]> select * from kullan;
+-----+-----+--------+
| yno | zno | miktar |
+-----+-----+--------+
|   1 |  15 |    100 |
|   1 |   1 |    100 |
|   1 |   4 |    100 |
|   1 |   5 |    100 |
|   1 |  14 |    100 |
|   1 |   7 |    100 |
|   1 |  11 |    100 |
|   2 |  15 |    150 |
|   2 |  13 |    150 |
|   2 |   9 |    150 |
|   2 |   3 |    150 |
|   2 |   8 |    150 |
|   2 |   7 |    150 |
|   3 |   2 |     69 |
|   3 |   5 |     69 |
|   3 |  15 |     69 |
|   3 |   9 |     69 |
|   3 |   4 |     69 |
|   3 |  12 |     69 |
|   4 |   1 |     30 |
|   4 |   9 |     30 |
|   5 |  12 |    460 |
|   5 |  10 |    460 |
|   5 |   3 |    460 |
|   5 |   6 |    460 |
|   6 |  10 |    360 |
|   6 |  11 |    360 |
|   6 |  15 |    360 |
|   6 |  12 |    360 |
|   7 |   1 |    260 |
|   7 |   9 |    260 |
|   7 |   4 |    260 |
|   7 |   7 |    260 |
|   8 |   1 |    160 |
|   8 |   4 |    160 |
|   8 |   2 |    160 |
|   8 |   3 |    160 |
|   8 |  15 |    160 |
|   9 |   3 |    160 |
|   9 |   1 |    160 |
|   9 |  15 |    160 |
+-----+-----+--------+
41 rows in set (0.00 sec)


MariaDB [restorant]> /* Soru 1 */
MariaDB [restorant]> 
MariaDB [restorant]> SELECT zadi as Malzeme FROM 
    ->     malzeme, musteri, siparis, yemek, kullan WHERE 
    ->     musteri.madi = 'Ali' AND 
    ->     musteri.msoyadi='Kurt' AND 
    ->     musteri.mno=siparis.mno AND 
    ->     siparis.yno=yemek.yno AND 
    ->     yemek.yno=kullan.yno AND 
    ->     kullan.zno=malzeme.zno;
+---------+
| Malzeme |
+---------+
| Su      |
| Fasulye |
+---------+
2 rows in set (0.00 sec)

MariaDB [restorant]> 
MariaDB [restorant]> /* Soru 2 */
MariaDB [restorant]> 
MariaDB [restorant]> SELECT DISTINCT yemek.yno as Yemek_No, yadi as Adi, ykalori as Kalori, yfiyati as Fiyat, yturu as Tur FROM 
    ->     malzeme, kullan, yemek WHERE 
    ->     malzeme.zno = kullan.zno AND 
    ->     yemek.yno = kullan.yno AND
    ->     zadi NOT IN (
    ->         SELECT zadi FROM 
    ->         yemek, malzeme, kullan WHERE 
    ->         yadi='Kuru fasulye' AND 
    ->         yemek.yno = kullan.yno AND 
    ->         kullan.zno = malzeme.zno
    ->         );
+----------+-----------------+--------+-------+----------+
| Yemek_No | Adi             | Kalori | Fiyat | Tur      |
+----------+-----------------+--------+-------+----------+
|        1 | Menemen         |   1560 |     7 | Ana ogun |
|        2 | Kebap           |   1430 |    20 | Ana Ogun |
|        3 | Doner           |   1300 |    15 | Ana Ogun |
|        5 | Bulgur Pilavi   |    200 |     5 | Ara Ogun |
|        6 | Kadinbudu Kofte |   1300 |    18 | Ana Ogun |
|        7 | Iskender        |   1560 |    19 | Ana Ogun |
|        8 | Corba           |    200 |     5 | Ara Ogun |
|        9 | Salata          |    100 |     7 | Ara Ogun |
+----------+-----------------+--------+-------+----------+
8 rows in set (0.00 sec)

MariaDB [restorant]> 
MariaDB [restorant]> /* Soru 3 */
MariaDB [restorant]> 
MariaDB [restorant]> SELECT DISTINCT musteri.mno as Musteri_No, madi as Adi, msoyadi as Soyadi, mtelefon as Telefon FROM
    ->     kullan, malzeme, yemek, musteri, siparis WHERE
    ->     musteri.mno = siparis.mno AND
    ->     siparis.yno = yemek.yno AND
    ->     yemek.yno = kullan.yno AND
    ->     kullan.zno = malzeme.zno AND
    ->     zadi='Domates' AND
    ->     yemek.yadi IN (
    ->         SELECT yemek.yadi FROM
    ->             kullan, malzeme, yemek WHERE
    ->             yemek.yno = kullan.yno AND
    ->             kullan.zno = malzeme.zno AND
    ->             zadi='Kereviz'
    ->     );
+------------+------------+---------+------------+
| Musteri_No | Adi        | Soyadi  | Telefon    |
+------------+------------+---------+------------+
|          4 | Fatma      | Cifte   | 1234567893 |
|          7 | Ac         | Herif   | 1234567895 |
|          1 | Yunus Emre | Ak      | 5308977689 |
|          3 | Ayse       | Haydi   | 1234567892 |
|          5 | Hayriye    | Telliye | 1234567894 |
|          6 | Sarki      | Sonu    | 1234567895 |
+------------+------------+---------+------------+
6 rows in set (0.00 sec)

MariaDB [restorant]> 
MariaDB [restorant]> /* Soru 4 */
MariaDB [restorant]> 
MariaDB [restorant]> SELECT DISTINCT musteri.madi as Adi, musteri.msoyadi as Soyadi FROM
    ->     yemek, siparis, musteri WHERE
    ->     musteri.mno = siparis.mno AND
    ->     siparis.yno = yemek.yno AND
    ->     yemek.yno IN (
    ->         SELECT yemek.yno FROM
    ->             yemek, malzeme, kullan WHERE
    ->             yemek.yno = kullan.yno AND
    ->             kullan.zno = malzeme.zno AND
    ->             zadi = 'Domates'
    ->     ) group by musteri.madi HAVING
    ->     count(*) = (
    ->         SELECT count(*) FROM
    ->             yemek, malzeme, kullan WHERE
    ->             yemek.yno = kullan.yno AND
    ->             kullan.zno = malzeme.zno AND
    ->             zadi = 'Domates'
    ->     );
+------+--------+
| Adi  | Soyadi |
+------+--------+
| Ac   | Herif  |
+------+--------+
1 row in set (0.00 sec)

MariaDB [restorant]> 
MariaDB [restorant]> /* Soru 5 */
MariaDB [restorant]> 
MariaDB [restorant]> SELECT DISTINCT zadi as Malzeme, count(*) as Sayisi , AVG(miktar) as Ortalama FROM
    ->     malzeme, kullan, yemek WHERE
    ->     yemek.yno = kullan.yno AND
    ->     kullan.zno = malzeme.zno 
    ->     group by zadi HAVING
    ->     count(*) >= 3; 
+----------+--------+----------+
| Malzeme  | Sayisi | Ortalama |
+----------+--------+----------+
| Domates  |      6 | 166.5000 |
| Fasulye  |      4 | 127.2500 |
| Kereviz  |      4 | 232.5000 |
| Kiyma    |      3 | 296.3333 |
| Sogan    |      4 | 147.2500 |
| Su       |      5 | 142.0000 |
| Tereyagi |      3 | 170.0000 |
+----------+--------+----------+
7 rows in set (0.00 sec)
