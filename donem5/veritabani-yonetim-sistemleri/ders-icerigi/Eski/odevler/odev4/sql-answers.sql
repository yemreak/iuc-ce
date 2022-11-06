-- 1. soru
-- Student tablosundaki GPA değerini gerektiğinde güncelleyen triggerları yazınız
-- (Take tablosundaki sid değiştiğinde ve take tablosuna kayıt eklenip silindiğinde çalışması
-- yeterli)

-- GPA Updater Function
CREATE FUNCTION update_gpa() RETURNS TRIGGER AS $$
    DECLARE
        id int; -- Id of student
    BEGIN
        -- If operation is DELETE
        IF (TG_OP = 'DELETE') THEN
            id = OLD.sid;
        -- Otherwise 
        ELSE
            id = NEW.sid;
        END IF;

        -- Calculate new GPAs what students have
        WITH newgpa as (
            SELECT SUM(credits * grade) / SUM(credits) FROM Take, Course
            WHERE id = Take.sid AND Take.cid = Course.cid 
            GROUP BY Take.sid
        )

        UPDATE Student SET Student.gpa = newgpa
        WHERE sid = id;
    END;
$$ LANGUAGE plpgsql;

-- Create trigger to update each student
CREATE TRIGGER gpa_update 
AFTER INSERT OR UPDATE OR DELETE ON Take
FOR EACH ROW
EXECUTE PROCEDURE update_gpa();


-- 2 Soru (?)
-- Course tablosundaki did için CREATE TABLE komutunda FOREIGN KEY yazılmadığını kabul edip, 
-- “did FOREIGN KEY references Department(did) ON DELETE CASCADE” yazılmış olsaydı, 
-- “(i) Department tablosundan kayıt silindiğinde o bölümün derslerini course tablosunda da 
-- silen ve (ii) Course tablosuna INSERT veya (did alanı) UPDATE yapıldığında” veritabanı 
-- sistemi tarafından otomatik yapılacak işlem ve kontrolleri yapacak TRIGGERları yazınız. 
-- (Eğer bir bolumun course tablosunda öğrencisi varsa ve o bölüm department tablosundan delete 
-- edilmeye çalışılıyorsa buna izin vermeyiniz, yani hata üretiniz. Hata üretmek için EXCEPTION
--  throw edebilirsiniz. PostgreSQL dokumantasyonuna bakınız)

CREATE FUNCTION delete_from_course() RETURNS TRIGGER AS $$
    BEGIN
	Delete From Course c 
	where c.did = OLD.did;
	RETURN OLD;
    END
$$ LANGUAGE plpgsql;

CREATE TRIGGER gpa_update 
BEFORE DELETE ON department
FOR EACH ROW
EXECUTE PROCEDURE delete_from_course();

-------------

CREATE OR REPLACE FUNCTION ogrenci_sayisi(
	id integer)
    RETURNS integer AS $$ 
declare toplam_sayi int;
BEGIN
   
   select count(s.sid)
   into toplam_sayi
    from student s
    where s.did in (
        select d.did
        from department d
        where d.did = id
        );
   return toplam_sayi;
END;
$$ LANGUAGE plpgsql;

-- 3 Soru
-- tid’si verilen bir hocanın verdiği dersi alan öğrencilerin kayıtlarını döndüren 
-- stored functıon’ı yazınız. Bu fonksiyonu herhangi bir sorguda kullanınız.

CREATE FUNCTION get_students(tid int) RETURNS SETOF Student AS $$
    BEGIN
        RETURN QUERY SELECT Student.* FROM Teach, Take, Student
        WHERE Teach.tid = tid AND Teach.cid = Take.cid AND Take.sid = Student.sid
        GROUP BY tid;
    END;
$$ LANGUAGE plpgsql;


-- 4. Soru (?)
-- Department tablosuna yapılan INSERT, UPDATE ve DELETE komutlarının hangi gün ve saatte 
-- apıldığını log(tarihSaat, komut) tablosunda yedekleyen (yani INSERT, UPDATE ve DELETE 
-- komutlarından biri çalıştırılınca log tablosuna INSERT yapan) statement level TRIGGERlari 
-- yazınız (derste çözmüştük)

CREATE TABLE log (tarihSaat TIMESTAMP, komut VARCHAR(77));

CREATE OR REPLACE FUNCTION add_log()
    RETURNS TRIGGER AS $$ 
Declare
id int;
BEGIN
		IF (TG_OP = 'DELETE') THEN
			Insert Into log values(OLD.did, current_timestamp ,TG_OP);
			RETURN OLD;
        ELSE  
		  Insert Into log values(NEW.did, current_timestamp ,TG_OP);
            RETURN NEW;
         End IF;
	RETURN NEW;
END;
$$ LANGUAGE plpgsql;


CREATE TRIGGER update_happens
  BEFORE UPDATE or DELETE or INSERT 
  ON department
  FOR EACH ROW
  EXECUTE PROCEDURE add_log();


-- 5. Soru (Odev4.java)
-- Teacher tablosundaki kayıtları listeleyen, tid’si verilen bir kaydı silen, yeni kayıt 
-- ekleyen, tid’si verilen bir kaydın bilgilerini güncelleyen Java konsol uygulamasını 
-- PostgrSQL JDBC kütüphanesini kullanarak yazınız.
