-- Vize Soruları Çözümü

-- Student tablosuna “birthDate INTEGER” sütünunu ekleyiniz (ALTER kullan)
ALTER TABLE Student ADD birtDate INTEGER;

-- 5 numaralı (did) bölüme ‘Samsun’ doğumlu ‘Ali KURT’ adlı öğrenciyi ekleyiniz (INSERT kullan)
INSERT INTO Student (sid, name, birthPlace, did) VALUES (12, 'Ali KURT', 'Samsun', 5);

-- Öğrencisi olmayan bölümleri Department tablosundan siliniz. (DELETE kullan)
DELETE FROM Department d WHERE NOT EXISTS (
    SELECT * FROM Student s WHERE s.did = d.did
);

-- En az 10 adet öğrencinin aldığı derslerin kredisini 1 arttırınız. (UPDATE kullan)
UPDATE Course SET credits = credits + 1 WHERE credits IN (
    SELECT credits FROM Course c, Take t WHERE c.cid = t.cid 
    GROUP BY (c.cid) HAVING count(sid) >= 10
);

-- Dersten alınan notların ortalaması 50’den yüksek olan derslerin ders kodunu
-- öğrenci sayılarını SQL ve RA ile listeleyiniz.
SELECT c.cid, count(sid) FROM Take t, Course c 
WHERE t.cid=c.cid
GROUP BY c.cid HAVING AVG(grade) > 50;

 cid | count
-----+-------
  11 |     3
   4 |     4
   6 |     3
  10 |     3
   2 |     6
   1 |     6
   9 |     3
   8 |     5

-- ‘Ali KURT’ adlı öğrencinin notlarının hepsinden daha yüksek bir nota sahip olan öğrencilerin
-- kayıtlarını SQL ve RA ile listeleyiniz. (&gt;= ALL kullan)
SELECT DISTINCT s.* FROM Student s, Take t WHERE s.sid = t.sid AND
grade >= ALL(
    SELECT grade FROM Student s1, Take t1 WHERE 
    t1.sid = s1.sid AND s1.name = 'Ali KURT'
);

    sid |     name     | birthplace | did | birtdate
-----+--------------+------------+-----+----------
   1 | Ali Dogan    | istanbul   |   1 |
   2 | Ahmet buyuk  | ankara     |   1 |
   3 | Leyla Sahin  | izmir      |   1 |
   4 | Can Turkoglu | manisa     |   2 |
   5 | Aziz Keskin  | istanbul   |   2 |
   6 | Talat Sanli  | izmir      |   3 |
   7 | Kamuran Kece | adana      |   3 |
   8 | Turgut Cemal | bursa      |   4 |
   9 | Oznur Gunes  | bolu       |   2 |
  10 | Pelin Tugay  | izmir      |   4 |
  11 | Savas Tan    | izmir      |   4 |

-- ‘Database Systems’ dersini alan fakat ‘Operating Systems’ dersini almayan öğrencilerin kayıtlarını RA
-- ve SQL ile listeleyiniz.
SELECT DISTINCT s.sid FROM Course c, Student s, Take t WHERE s.sid = t.sid AND
t.cid = c.cid AND title='Database Systems' AND s.sid NOT IN (
    SELECT s1.sid FROM Student s1, Take t1, Course c1 WHERE 
    s1.sid = t1.sid AND t1.cid = c1.cid AND title='Operating Systems'
);

 sid
-----
   1
   4
   5

-- ‘Bilgisayar Mühendisliği’ bölümünde çalışan ve ders vermeyen (teach tablosundan bakılacak)
-- hocaların kayıtlarını
-- Exists
SELECT t.* FROM Teacher t, Department d WHERE t.did = d.did AND
d.name='Bilgisayar Muhendisligi' AND NOT EXISTS (
    SELECT * FROM Teach t1 WHERE t1.tid = t.tid
);

 tid |   name   | placeofbirth | did
-----+----------+--------------+-----
   8 | Bos Adam | Rome         |   1

-- In
SELECT t.* FROM Teacher t, Department d WHERE t.did = d.did AND
d.name='Bilgisayar Muhendisligi' AND t.tid IN (
    (SELECT tid FROM Teacher) EXCEPT (SELECT tid FROM Teach)
);

 tid |   name   | placeofbirth | did
-----+----------+--------------+-----
   8 | Bos Adam | Rome         |   1