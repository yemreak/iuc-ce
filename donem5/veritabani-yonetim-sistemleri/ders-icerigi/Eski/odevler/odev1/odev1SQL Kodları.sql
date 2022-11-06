/* Sql Kodları */

CREATE DATABASE restorant;

USE restorant;

CREATE TABLE Musteri (
    mno int Primary Key,
    madi nvarchar(17),
    msoyadi nvarchar(17),
    mtelefon varchar(10)
    );

CREATE TABLE Yemek(
    yno int Primary Key,
    yadi nvarchar(17),
    ykalori int,
    yfiyati int,
    yturu nvarchar(17)
    );

CREATE TABLE Siparis(
    mno int not null,
    yno int not null,
    tarihsaat datetime,
    foreign key (mno) references Musteri(mno),
    foreign key (yno) references Yemek(yno)
    );

CREATE TABLE Malzeme(
    zno int Primary Key,
    zadi nvarchar(17),
    ztipi nvarchar(17)
    );

CREATE TABLE Kullan(
    yno int not null,
    zno int not null,
    miktar int,
    foreign key (yno) references Yemek(yno),
    foreign key (zno) references Malzeme(zno)
    );

/* Veriler */

INSERT INTO Musteri (mno, madi, msoyadi, mtelefon) VALUES (1, 'Yunus Emre', 'Ak', '5308977689');
INSERT INTO Musteri (mno, madi, msoyadi, mtelefon) VALUES (2, 'Ali', 'Kurt', '1234567891');
INSERT INTO Musteri (mno, madi, msoyadi, mtelefon) VALUES (3, 'Ayse', 'Haydi', '1234567892');
INSERT INTO Musteri (mno, madi, msoyadi, mtelefon) VALUES (4, 'Fatma', 'Cifte', '1234567893');
INSERT INTO Musteri (mno, madi, msoyadi, mtelefon) VALUES (5, 'Hayriye', 'Telliye', '1234567894');
INSERT INTO Musteri (mno, madi, msoyadi, mtelefon) VALUES (6, 'Sarki', 'Sonu', '1234567895');
INSERT INTO Musteri (mno, madi, msoyadi, mtelefon) VALUES (7, 'Ac', 'Herif', '1234567895');

INSERT INTO Yemek (yno, yadi, ykalori, yfiyati, yturu) VALUES (1, 'Menemen', 1560, 7, 'Ana ogun');
INSERT INTO Yemek (yno, yadi, ykalori, yfiyati, yturu) VALUES (2, 'Kebap', 1430, 20, 'Ana Ogun');
INSERT INTO Yemek (yno, yadi, ykalori, yfiyati, yturu) VALUES (3, 'Doner', 1300, 15, 'Ana Ogun');
INSERT INTO Yemek (yno, yadi, ykalori, yfiyati, yturu) VALUES (4, 'Kuru Fasulye', 500, 13, 'Ana Ogun');
INSERT INTO Yemek (yno, yadi, ykalori, yfiyati, yturu) VALUES (5, 'Bulgur Pilavi', 200, 5, 'Ara Ogun');
INSERT INTO Yemek (yno, yadi, ykalori, yfiyati, yturu) VALUES (6, 'Kadinbudu Kofte', 1300, 18, 'Ana Ogun');
INSERT INTO Yemek (yno, yadi, ykalori, yfiyati, yturu) VALUES (7, 'Iskender', 1560, 19, 'Ana Ogun');
INSERT INTO Yemek (yno, yadi, ykalori, yfiyati, yturu) VALUES (8, 'Corba', 200, 5, 'Ara Ogun');
INSERT INTO Yemek (yno, yadi, ykalori, yfiyati, yturu) VALUES (9, 'Salata', 100, 7, 'Ara Ogun');

INSERT INTO Malzeme (zno, zadi, ztipi) VALUES (1, 'Su', 'sevilen');
INSERT INTO Malzeme (zno, zadi, ztipi) VALUES (2, 'Et', 'tip2');
INSERT INTO Malzeme (zno, zadi, ztipi) VALUES (3, 'Kereviz', 'tip3');
INSERT INTO Malzeme (zno, zadi, ztipi) VALUES (4, 'Sogan', 'tip4');
INSERT INTO Malzeme (zno, zadi, ztipi) VALUES (5, 'Biber', 'tip5');
INSERT INTO Malzeme (zno, zadi, ztipi) VALUES (6, 'Yogurt', 'tip2');
INSERT INTO Malzeme (zno, zadi, ztipi) VALUES (7, 'Tereyagi', 'tip2');
INSERT INTO Malzeme (zno, zadi, ztipi) VALUES (8, 'Patates', 'tip3');
INSERT INTO Malzeme (zno, zadi, ztipi) VALUES (9, 'Fasulye', 'tip2');
INSERT INTO Malzeme (zno, zadi, ztipi) VALUES (10, 'Bulgur', 'tip3');
INSERT INTO Malzeme (zno, zadi, ztipi) VALUES (11, 'Yumurta', 'tip4');
INSERT INTO Malzeme (zno, zadi, ztipi) VALUES (12, 'Kiyma', 'tip4');
INSERT INTO Malzeme (zno, zadi, ztipi) VALUES (13, 'Ekmek', 'tip4');
INSERT INTO Malzeme (zno, zadi, ztipi) VALUES (14, 'Maydanoz', 'tip4');
INSERT INTO Malzeme (zno, zadi, ztipi) VALUES (15, 'Domates', 'tip4');

INSERT INTO Siparis (mno, yno, tarihsaat) VALUES (1, 7, '2017-05-17 17:17:17');
INSERT INTO Siparis (mno, yno, tarihsaat) VALUES (1, 5, '2017-05-17 17:17:19');
INSERT INTO Siparis (mno, yno, tarihsaat) VALUES (1, 8, '2017-05-17 17:17:20');
INSERT INTO Siparis (mno, yno, tarihsaat) VALUES (2, 4, '2017-05-19 19:19:19');
INSERT INTO Siparis (mno, yno, tarihsaat) VALUES (3, 5, '2017-05-17 17:17:19');
INSERT INTO Siparis (mno, yno, tarihsaat) VALUES (3, 8, '2017-05-17 17:17:19');
INSERT INTO Siparis (mno, yno, tarihsaat) VALUES (4, 2, '2017-05-17 17:19:17');
INSERT INTO Siparis (mno, yno, tarihsaat) VALUES (4, 3, '2017-05-17 17:19:17');
INSERT INTO Siparis (mno, yno, tarihsaat) VALUES (5, 3, '2017-05-17 19:17:17');
INSERT INTO Siparis (mno, yno, tarihsaat) VALUES (5, 8, '2017-05-17 19:17:17');
INSERT INTO Siparis (mno, yno, tarihsaat) VALUES (6, 8, '2017-05-17 19:17:19');
INSERT INTO Siparis (mno, yno, tarihsaat) VALUES (7, 1, '2017-05-17 19:17:19');
INSERT INTO Siparis (mno, yno, tarihsaat) VALUES (7, 2, '2017-05-17 19:17:19');
INSERT INTO Siparis (mno, yno, tarihsaat) VALUES (7, 3, '2017-05-17 19:17:19');
INSERT INTO Siparis (mno, yno, tarihsaat) VALUES (7, 6, '2017-05-17 19:17:19');
INSERT INTO Siparis (mno, yno, tarihsaat) VALUES (7, 8, '2017-05-17 19:17:19');
INSERT INTO Siparis (mno, yno, tarihsaat) VALUES (7, 9, '2017-05-17 19:17:19');


INSERT INTO Kullan (yno, zno, miktar) VALUES (1, 15, 100);
INSERT INTO Kullan (yno, zno, miktar) VALUES (1, 1, 100);
INSERT INTO Kullan (yno, zno, miktar) VALUES (1, 4, 100);
INSERT INTO Kullan (yno, zno, miktar) VALUES (1, 5, 100);
INSERT INTO Kullan (yno, zno, miktar) VALUES (1, 14, 100);
INSERT INTO Kullan (yno, zno, miktar) VALUES (1, 7, 100);
INSERT INTO Kullan (yno, zno, miktar) VALUES (1, 11, 100);
INSERT INTO Kullan (yno, zno, miktar) VALUES (2, 15, 150);
INSERT INTO Kullan (yno, zno, miktar) VALUES (2, 13, 150);
INSERT INTO Kullan (yno, zno, miktar) VALUES (2, 9, 150);
INSERT INTO Kullan (yno, zno, miktar) VALUES (2, 3, 150);
INSERT INTO Kullan (yno, zno, miktar) VALUES (2, 8, 150);
INSERT INTO Kullan (yno, zno, miktar) VALUES (2, 7, 150);
INSERT INTO Kullan (yno, zno, miktar) VALUES (3, 2, 69);
INSERT INTO Kullan (yno, zno, miktar) VALUES (3, 5, 69);
INSERT INTO Kullan (yno, zno, miktar) VALUES (3, 15, 69);
INSERT INTO Kullan (yno, zno, miktar) VALUES (3, 9, 69);
INSERT INTO Kullan (yno, zno, miktar) VALUES (3, 4, 69);
INSERT INTO Kullan (yno, zno, miktar) VALUES (3, 12, 69);
INSERT INTO Kullan (yno, zno, miktar) VALUES (4, 1, 30);
INSERT INTO Kullan (yno, zno, miktar) VALUES (4, 9, 30);
INSERT INTO Kullan (yno, zno, miktar) VALUES (5, 12, 460);
INSERT INTO Kullan (yno, zno, miktar) VALUES (5, 10, 460);
INSERT INTO Kullan (yno, zno, miktar) VALUES (5, 3, 460);
INSERT INTO Kullan (yno, zno, miktar) VALUES (5, 6, 460);
INSERT INTO Kullan (yno, zno, miktar) VALUES (6, 10, 360);
INSERT INTO Kullan (yno, zno, miktar) VALUES (6, 11, 360);
INSERT INTO Kullan (yno, zno, miktar) VALUES (6, 15, 360);
INSERT INTO Kullan (yno, zno, miktar) VALUES (6, 12, 360);
INSERT INTO Kullan (yno, zno, miktar) VALUES (7, 1, 260);
INSERT INTO Kullan (yno, zno, miktar) VALUES (7, 9, 260);
INSERT INTO Kullan (yno, zno, miktar) VALUES (7, 4, 260);
INSERT INTO Kullan (yno, zno, miktar) VALUES (7, 7, 260);
INSERT INTO Kullan (yno, zno, miktar) VALUES (8, 1, 160);
INSERT INTO Kullan (yno, zno, miktar) VALUES (8, 4, 160);
INSERT INTO Kullan (yno, zno, miktar) VALUES (8, 2, 160);
INSERT INTO Kullan (yno, zno, miktar) VALUES (8, 3, 160);
INSERT INTO Kullan (yno, zno, miktar) VALUES (8, 15, 160);
INSERT INTO Kullan (yno, zno, miktar) VALUES (9, 3, 160);
INSERT INTO Kullan (yno, zno, miktar) VALUES (9, 1, 160);
INSERT INTO Kullan (yno, zno, miktar) VALUES (9, 15, 160);

/* Çözümler */

/* Soru 1 */
SELECT zadi as Malzeme FROM 
    malzeme, musteri, siparis, yemek, kullan WHERE 
    musteri.madi = 'Ali' AND 
    musteri.msoyadi='Kurt' AND 
    musteri.mno=siparis.mno AND 
    siparis.yno=yemek.yno AND 
    yemek.yno=kullan.yno AND 
    kullan.zno=malzeme.zno;

/* Soru 2 */
SELECT DISTINCT yemek.yno as Yemek_No, yadi as Adi, ykalori as Kalori, yfiyati as Fiyat, yturu as Tur FROM 
    malzeme, kullan, yemek WHERE 
    malzeme.zno = kullan.zno AND 
    yemek.yno = kullan.yno AND
    zadi NOT IN (
        SELECT zadi FROM 
        yemek, malzeme, kullan WHERE 
        yadi='Kuru fasulye' AND 
        yemek.yno = kullan.yno AND 
        kullan.zno = malzeme.zno
        );

/* Soru 3 */
SELECT DISTINCT musteri.mno as Musteri_No, madi as Adi, msoyadi as Soyadi, mtelefon as Telefon FROM
    kullan, malzeme, yemek, musteri, siparis WHERE
    musteri.mno = siparis.mno AND
    siparis.yno = yemek.yno AND
    yemek.yno = kullan.yno AND
    kullan.zno = malzeme.zno AND
    zadi='Domates' AND
    yemek.yadi IN (
        SELECT yemek.yadi FROM
            kullan, malzeme, yemek WHERE
            yemek.yno = kullan.yno AND
            kullan.zno = malzeme.zno AND
            zadi='Kereviz'
    );

/* Soru 4 */
SELECT DISTINCT musteri.madi as Adi, musteri.msoyadi as Soyadi FROM
    yemek, siparis, musteri WHERE
    musteri.mno = siparis.mno AND
    siparis.yno = yemek.yno AND
    yemek.yno IN (
        SELECT yemek.yno FROM
            yemek, malzeme, kullan WHERE
            yemek.yno = kullan.yno AND
            kullan.zno = malzeme.zno AND
            zadi = 'Domates'
    ) group by musteri.madi HAVING
    count(*) = (
        SELECT count(*) FROM
            yemek, malzeme, kullan WHERE
            yemek.yno = kullan.yno AND
            kullan.zno = malzeme.zno AND
            zadi = 'Domates'
    );

/* Soru 5 */

SELECT DISTINCT zadi as Malzeme, count(*) as Sayisi , AVG(miktar) as Ortalama FROM
    malzeme, kullan, yemek WHERE
    yemek.yno = kullan.yno AND
    kullan.zno = malzeme.zno 
    group by zadi HAVING
    count(*) >= 3; 
    