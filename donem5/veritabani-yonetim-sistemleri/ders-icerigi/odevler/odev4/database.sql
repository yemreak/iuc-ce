DROP TABLE Teach CASCADE;
DROP TABLE Take CASCADE;
DROP TABLE Teacher CASCADE;
DROP TABLE Course CASCADE;
DROP TABLE Student CASCADE;
DROP TABLE Department CASCADE;

create table Department(
    did int not null,
    name varchar(30) not null,
    noOfStudents int DEFAULT 0,
    primary key(did)
);

create table Student(
    sid int not null,
    name varchar(30) not null,
    did int,
    noOfCourses int DEFAULT 0,
    GPA int DEFAULT 0,
    foreign key (did) references Department(did),
    primary key(sid)
);

create table Course(
    cid int not null,
    title varchar(30) not null,
    credits numeric(2) DEFAULT 0,
    did int,
    noOfStudents int DEFAULT 0,
    foreign key (did) references Department(did),
    primary key(cid)
);

create table Teacher(
    tid int not null,
    name varchar(30) not null,
    placeOfBirth varchar(15),
    did int,
    foreign key (did) references Department(did),
    primary key(tid)
);

create table Take(
    sid int not null,
    cid int not null,
    grade float,
    foreign key (sid) references Student(sid),
    foreign key (cid) references Course(cid),
    primary key (sid,cid)
);

create table Teach(
    tid int not null,
    cid int not null,
    foreign key (tid) references Teacher(tid),
    foreign key (cid) references Course(cid),
    primary key (tid,cid)
);

# List of relations
\dt

insert into Department values (1,	'Bilgisayar Muhendisligi');
insert into Department values (2,	'Endustri Muhendisligi');
insert into Department values (3,	'Elektrik Muhendisligi');
insert into Department values (4,	'Kimya Muhendisligi');
insert into Department values (5,	'Piskoloji');

insert into Student values (1'Ali Dogan', 1);
insert into Student values (2,	'Ahmet buyuk', 1);
insert into Student values (3,	'Leyla Sahin', 1);
insert into Student values (4,	'Can Turkoglu', 2);
insert into Student values (5,	'Aziz Keskin', 2);
insert into Student values (6,	'Talat Sanli', 3);
insert into Student values (7,	'Kamuran Kece', 3);
insert into Student values (8,	'Turgut Cemal', 4);
insert into Student values (9,	'Oznur Gunes', 2);
insert into Student values (10,	'Pelin Tugay', 4);
insert into Student values (11,	'Savas Tan', 4);

insert into Course values (1,	'Database Systems',	3,	1);
insert into Course values (2, 	'Operating Systems',3,	1);
insert into Course values (3, 	'Introduction to Programming',	4,	1);
insert into Course values (4, 	'introduction to electronic',2,	2);
insert into Course values (5, 	'statistic',4,	4);
insert into Course values (6,	'circuit theory', 3,	2);
insert into Course values (7,	'introduction to environment',3,	3);
insert into Course values (8, 	'operation research',3,	4);
insert into Course values (9, 	'summer practice', 2,	4);
insert into Course values (10, 	'summer practice',	3,	3);
insert into Course values (11, 	'summer practice',	3,	1);
insert into Course values (12,	'summer practice',	3,	2);

insert into Teacher values (1,	'Selami Durgun', 'amasya',	1);
insert into Teacher values (2,	'Cengiz Tahir', 'istanbul',	1);
insert into Teacher values (3,	'Derya Seckin', 'mersin',	1);
insert into Teacher values (4,	'Dogan Gedikli', 'istanbul',	2);
insert into Teacher values (5,	'Ayten Kahraman', 'istanbul',	3);
insert into Teacher values (6,	'Tahsin Ugur', 'izmir',	4);
insert into Teacher values (7,	'Selcuk Ozan', 'amasya',	4);
insert into Teacher values (8,	'Bos Adam',	'Rome',	1);

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

insert into Take values (1,	1,	75);
insert into Take values (1,	3,	62.5);
insert into Take values (1,	4,	75.5);
insert into Take values (1,	6,	75);
insert into Take values (1,	9,	100);
insert into Take values (1,	10,	75);
insert into Take values (2,	1,	68);
insert into Take values (2,	2,	100);
insert into Take values (2,	3,	4);
insert into Take values (2,	4,	100);
insert into Take values (2,	5,	23);
insert into Take values (2,	6,	100);
insert into Take values (2,	7,	13);
insert into Take values (2,	8,	100);
insert into Take values (2,	9,	100);
insert into Take values (2,	10,	75);
insert into Take values (2,	11,	100);
insert into Take values (3,	1,	100);
insert into Take values (3,	2,	65);
insert into Take values (3,	3,	88);
insert into Take values (3,	4,	71);
insert into Take values (3,	5,	100);
insert into Take values (3,	6,	34);
insert into Take values (3,	7,	23);
insert into Take values (3,	8,	100);
insert into Take values (3,	9,	31);
insert into Take values (3,	10,	75);
insert into Take values (3,	11,	75.5);
insert into Take values (4,	1,	62.5);
insert into Take values (4,	5,	33);
insert into Take values (5,	11,	75.5);
insert into Take values (5,	1,	75);
insert into Take values (5,	5,	33);
insert into Take values (6,	2,	100);
insert into Take values (7,	5,	33);
insert into Take values (7,	1,	62.5);
insert into Take values (7,	8,	33);
insert into Take values (7,	2,	75);
insert into Take values (8,	2,	75.5);
insert into Take values (8,	7,	30);
insert into Take values (9,	3,	21);
insert into Take values (9,	4,	23);
insert into Take values (10,	2,100);
insert into Take values (10,	8,	75);
insert into Take values (11,	8,	25);

# Privilage
GRANT ALL PRIVILEGES ON ALL TABLES IN SCHEMA public TO yemreak;
