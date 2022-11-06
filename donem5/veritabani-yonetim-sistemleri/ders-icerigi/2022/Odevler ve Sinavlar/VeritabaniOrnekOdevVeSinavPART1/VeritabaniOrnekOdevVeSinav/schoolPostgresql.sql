drop table Teach;
drop table Take;
drop table Teacher;
drop table Course;
drop table Student;
drop table Department;

create table Department
 (did number(5) not null,
 dname varchar(30) not null,
 comments varchar(50),
 email varchar(30),
 primary key(did));

create table Student
 (sid number(5) not null,
 fname varchar(30) not null,
 lname varchar(30),
 birthdate date,
 birthplace varchar(50),
 did number(5),
 foreign key (did) references Department(did),
 primary key(sid));

create table Course
 (cid number(5) not null,
 title varchar(30) not null,
 description varchar(50),
 credits number(2),
 did  number(5),
 foreign key (did) references Department(did),
 primary key(cid));

create table Teacher
 (tid number(5) not null,
 fname varchar(30) not null,
 lname varchar(30),
 birthdate date,
 birthplace varchar(50),
 did number(5),
 foreign key (did) references Department(did),
 primary key(tid));

create table Take
 (sid number(5) not null,
 cid number(5) not null,
 grade float,
 foreign key (sid) references Student(sid),
 foreign key (cid) references Course(cid),
 primary key (sid,cid));

create table Teach
 (tid number(5) not null,
 cid number(5) not null,
 foreign key (tid) references Teacher(tid),
 foreign key (cid) references Course(cid),
 primary key (tid,cid));

insert into Department values (1,	'Comp. Eng.',	'Computer Eng. Department', 'ceng@fatih.edu.tr');
insert into Department values (2,	'Elec. Eng.',	'Electronic Eng. Department', 'ee@fatih.edu.tr');
insert into Department values (3,	'Env. Eng.',	'Environmental Eng. Department', 'env@fatih.edu.tr');
insert into Department values (4,	'Ind. Eng.',	'Industrial Eng. Department', 'ie@fatih.edu.tr');

insert into Student values (1,	'Ali',	'Turan',	'23-Jan-1980',	'istanbul',	1);
insert into Student values (2,	'Ahmet',	'buyuk',	'2-Jul-1979',	'ankara',	1);
insert into Student values (3,	'Leyla',	'Sahin',	'18-May-1982',	'izmir',	1);
insert into Student values (4,	'Can',	'Turkoglu',	'6-Nov-1985',	'manisa',	2);
insert into Student values (5,	'Aziz',	'Keskin',	'11-Dec-1978',	'istanbul',	2);
insert into Student values (6,	'Talat',	'Sanli',	'12-Dec-1983',	'izmir',	3);
insert into Student values (7,	'Kamuran',	'Kece',	'26-Sep-1980',	'adana',	3);
insert into Student values (8,	'Turgut',	'Cemal',	'30-Oct-1977',	'bursa',	4);
insert into Student values (9,	'Oznur',	'Gunes',	'1-Aug-1979',	'bolu',	2);
insert into Student values (10,	'Pelin',	'Tugay',	'9-Mar-1980',	'izmir',	4);
insert into Student values (11,	'Savas',	'Tan',	'9-Mar-1980',	'izmir',	4);

insert into Course values (1,	'database',	'CENG 351',	3,	1);
insert into Course values (2, 	'operating system',	'CENG 341',	3,	1);
insert into Course values (3, 	'Introduction to Programming',	'CENG 101',	4,	1);
insert into Course values (4, 	'introduction to electronic',	'EE 101',	2,	2);
insert into Course values (5, 	'statistic',	'IE 301',	4,	4);
insert into Course values (6,	'circuit theory',	 'EE 202',	3,	2);
insert into Course values (7,	'introduction to environment',	'ENV 102',		3,	3);
insert into Course values (8, 	'operation research',	'IE 208',	3,	4);
insert into Course values (9, 	'summer practice',	'IE 299',	2,	4);
insert into Course values (10, 	'summer practice',	'ENV 299',	3,	3);
insert into Course values (11, 	'summer practice',	'CENG 299',	3,	1);
insert into Course values (12,	'summer practice',	 'EE 299',	3,	2);

insert into Teacher values (1,	'Selami',	'Durgun',	'10-Nov-1970',	'amasya',	1);
insert into Teacher values (2,	'Cengiz',	'Tahir',	'21-Jul-1960',	'istanbul',	1);
insert into Teacher values (3,	'Derya',	'Seckin',	'15-May-1962',	'mersin',	1);
insert into Teacher values (4,	'Dogan',	'Gedikli',	'16-Nov-1965',	'istanbul',	2);
insert into Teacher values (5,	'Ayten',	'Kahraman',	'11-Dec-1968',	'istanbul',	3);
insert into Teacher values (6,	'Tahsin',	'Ugur',	'12-Dec-1963',	'izmir',	4);
insert into Teacher values (7,	'Selcuk',	'Ozan',	'30-Oct-1960',	'amasya',	4);

insert into Teach values (1,	1);
insert into Teach values (3,	2);
insert into Teach values (2,	3);
insert into Teach values (4,	4);
insert into Teach values (7,	5);
insert into Teach values (4,	6);
insert into Teach values (5,	7);
insert into Teach values (6,	8);
insert into Teach values (7,	9);
insert into Teach values (5,	10);
insert into Teach values (1,	11);
insert into Teach values (4,	12);

insert into Take values (1,	1,	3);
insert into Take values (1,	3,	2.5);
insert into Take values (1,	4,	3.5);
insert into Take values (1,	6,	3);
insert into Take values (1,	9,	4);
insert into Take values (1,	10,	3);
insert into Take values (2,	1,	4);
insert into Take values (2,	2,	4);
insert into Take values (2,	3,	4);
insert into Take values (2,	4,	4);
insert into Take values (2,	5,	4);
insert into Take values (2,	6,	4);
insert into Take values (2,	7,	4);
insert into Take values (2,	8,	4);
insert into Take values (2,	9,	4);
insert into Take values (2,	10,	3);
insert into Take values (2,	11,	4);
insert into Take values (3,	1,	4);
insert into Take values (3,	2,	4);
insert into Take values (3,	3,	4);
insert into Take values (3,	4,	4);
insert into Take values (3,	5,	4);
insert into Take values (3,	6,	4);
insert into Take values (3,	7,	4);
insert into Take values (3,	8,	4);
insert into Take values (3,	9,	4);
insert into Take values (3,	10,	3);
insert into Take values (3,	11,	3.5);
insert into Take values (4,	1,	2.5);
insert into Take values (4,	5,	1.5);
insert into Take values (5,	11,	3.5);
insert into Take values (5,	1,	3);
insert into Take values (5,	5,	1.5);
insert into Take values (6,	2,	4);
insert into Take values (7,	5,	1.5);
insert into Take values (7,	1,	2.5);
insert into Take values (7,	8,	1.5);
insert into Take values (7,	2,	3);
insert into Take values (8,	2,	3.5);
insert into Take values (8,	7,	1.5);
insert into Take values (10,	2,	4);
insert into Take values (10,	8,	3);
insert into Take values (11,	8,	1);