create database crime;

drop table suspect;
drop table crime;
drop table witness;
drop table commits;
drop table witnessed;

create table suspect
   (suspectid 	int	not null,
    name 		varchar(30)	not null,
    address		varchar(50),
    city 		varchar(30),
    birthdate 	date,
    primary key(suspectid));

create table witness
   (witnessid 	int	not null,
    name 		varchar(30)	not null,
    address		varchar(50),
    city 		varchar(30),
    birthdate 	date,
    primary key(witnessid));

create table crime
   (crimeid 	int	not null,
    crimedate 	date,
    address		varchar(50),
    city 		varchar(30),
    description	varchar(30),
    primary key(crimeid));

create table commits
   (suspectid 	int	references suspect(suspectid) on delete cascade on update cascade,
    crimeid 	int	references crime(crimeid) on delete cascade on update cascade,
    punishment   varchar(15),
    commitdate 	date,
    primary key(suspectid, crimeid));

create table witnessed
   (witnessid 	int	references witness(witnessid) on delete cascade on update cascade,
    crimeid 	int	references crime(crimeid) on delete cascade on update cascade,
    comments 	varchar(15),
    primary key(witnessid, crimeid));

insert into suspect	values (1,	'ahmet cetin',	'11. cadde 25. sokak no:43',	'istanbul',	'23-SEP-1990');
insert into suspect	values (2,	'selim kahin',	'5. cadde 13.sokak no:54',	'ankara',	'22-JAN-1980');
insert into suspect	values (3,	'candan erkan',	'4. cadde 9.sokak no:11',	'New York',	'11-FEB-1970');
insert into suspect	values (4,	'betan saran',	'23. cadde 32.sokak no:12',	'istanbul',	'04-OCT-1992');
insert into suspect	values (5,	'guler kamil',	'4. cadde 21.sokak no:11',	'ankara',	'01-MAR-1994');

insert into crime	values (1,	'10-JAN-2003',	'2. cadde 4. sokak',		'istanbul',	'murder');
insert into crime	values (2,	'1-MAR-2004',	'1. cadde 2. sokak',		'istanbul',	'robbery');
insert into crime	values (3,	'3-FEB-2000',	'2. cadde 5. sokak',		'ankara',	'arson');
insert into crime	values (4,	'15-JUN-2001',	'9. cadde 9. sokak',		'ankara',	'murder');
insert into crime	values (5,	'3-NOV-2002',	'16. cadde 7. sokak',		'ankara',	'arson');
insert into crime	values (6,	'15-OCT-2003',	'3. cadde 8. sokak',		'istanbul',	'arson');
insert into crime	values (7,	'20-MAY-2004',	'7. cadde 1. sokak',		'bursa',	'robbery');
insert into crime	values (8,	'14-JAN-2000',	'21. cadde 5. sokak',		'izmir',	'arson');
insert into crime	values (9,	'23-JUL-2001',	'19. cadde 7. sokak',		'ankara',	'murder');
insert into crime	values (10,'8-OCT-1999',	'10. cadde 2. sokak',		'ankara',	'arson');

insert into commits	values(1, 1, 	'10 year',	'15-JUN-2003' );
insert into commits	values(1, 4, 	'15 year',	'15-JUN-2003' );
insert into commits	values(1, 9, 	'25 year',	'15-JUN-2003' );
insert into commits	values(2, 2, 	'2 year',	'5-MAY-2004' );
insert into commits	values(3, 1, 	'10 year',	'15-JUN-2003' );
insert into commits	values(3, 3, 	'5 year',	'15-JUN-2003' );
insert into commits	values(4, 5, 	'5 year',	'4-NOV-2002' );
insert into commits	values(5, 6, 	'1 year',	'7-DEC-2003' );
insert into commits	values(5, 1, 	'10 year',	'15-JUN-2003' );

insert into witness	values (1,	'ahmet cetin',	'10. cadde 5. sokak no:3',	'istanbul',	'23-SEP-1990');
insert into witness	values (2,	'selim kahin',	'50. cadde 3. sokak no:4',	'ankara',	'22-JAN-1980');
insert into witness	values (6,	'servet ceran',	'40. cadde 19.sokak no:1',	'ankara',	'11-FEB-1994');
insert into witness	values (7,	'mavera sundus',	'2. cadde 2. sokak no:2',	'istanbul',	'04-OCT-1991');
insert into witness	values (8,	'cem dursun',	'40. cadde 1. sokak no:1',	'ankara',	'01-MAR-1993');

insert into witnessed	values (1, 1,	'nothing');
insert into witnessed	values (2, 1,	'nothing');
insert into witnessed	values (6, 2,	'nothing');
insert into witnessed	values (7, 8,	'nothing');
insert into witnessed	values (8, 3,	'nothing');
insert into witnessed	values (8, 4,	'nothing');
insert into witnessed	values (2, 5,	'nothing');