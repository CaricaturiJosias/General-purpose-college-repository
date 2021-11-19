create database curso;
use curso;

CREATE TABLE PROFESSORES (
	cod_prof int PRIMARY KEY,
	nome_prof varchar(30));

Insert into PROFESSORES values (100,'Deborah');
Insert into PROFESSORES values (200,'Mario');
Insert into PROFESSORES values (300,'Ricardo');
Insert into PROFESSORES values (400,'Justino');
Insert into PROFESSORES values (500,'Veronese');
Insert into PROFESSORES values (600,'Hamerski');
Insert into PROFESSORES values (700,'Gilson');
Insert into PROFESSORES values (800,'Thieme');
Insert into PROFESSORES values (900,'Camillo');
Insert into PROFESSORES values (1000,'Schmeil');


CREATE TABLE DISCIPLINAS (
	cod_disc int PRIMARY KEY,
	nome_disciplina varchar(30),
	total_horas decimal(5,2)
);


Insert into DISCIPLINAS values (1,'sbd', 10.3);
Insert into DISCIPLINAS values (2,'analise', 11.7);
Insert into DISCIPLINAS values (3,'redes e sistemas distribuidos', 22.1);
Insert into DISCIPLINAS values (4,'projeto final', 20.5);
Insert into DISCIPLINAS values (5,'engenharia de software',17.7);
Insert into DISCIPLINAS values (6,'filosofia', 15.2);
Insert into DISCIPLINAS values (7,'teologia', 30.5);
Insert into DISCIPLINAS values (8,'deontologia', 40.1);
Insert into DISCIPLINAS values (9,'sistemas operacionais', 12.4);
Insert into DISCIPLINAS values (10,'arquitetura de computadores', 60.0);


CREATE TABLE PROFESSORES_DISCIPLINAS (
	cod_prof integer,
	cod_disc integer,
	comecou_ministrar date,
	parou_ministrar date,
	/*total_horas decimal(5,2) null ,*/
	primary key (cod_prof,cod_disc),
  	foreign key (cod_prof) references PROFESSORES (cod_prof),
  	foreign key (cod_disc) references DISCIPLINAS (cod_disc)
);

Insert into PROFESSORES_DISCIPLINAS values (100,1,'2015-01-01',
'2018-01-01');
Insert into PROFESSORES_DISCIPLINAS values (200,2,'2017-01-01',
'2020-01-01');
Insert into PROFESSORES_DISCIPLINAS values (300,3,'2012-01-01',
'2021-01-01');
Insert into PROFESSORES_DISCIPLINAS values (400,4,'2011-01-01',
'2012-01-01');
Insert into PROFESSORES_DISCIPLINAS values (500,5,'2018-01-01',
'2019-01-01');
Insert into PROFESSORES_DISCIPLINAS values (600,6,'1999-01-01',
'2000-01-01');
Insert into PROFESSORES_DISCIPLINAS values (700,7,'2020-01-01',
'2030-01-01');
Insert into PROFESSORES_DISCIPLINAS values (800,8,'2022-01-01',
'2023-01-01');
Insert into PROFESSORES_DISCIPLINAS values (900,9,'2014-01-01',
'2026-01-01');
Insert into PROFESSORES_DISCIPLINAS values (1000,10,'2016-06-30',
'2017-01-01');
Insert into PROFESSORES_DISCIPLINAS values (900,2,'2025-01-01',
'2029-01-01');
Insert into PROFESSORES_DISCIPLINAS values (800,3,'2014-01-01',
'2015-01-01');
Insert into PROFESSORES_DISCIPLINAS values (700,4,'2014-01-01',
'2020-01-01');
Insert into PROFESSORES_DISCIPLINAS values (600,5,'2020-01-01',
'2021-01-01');
Insert into PROFESSORES_DISCIPLINAS values (500,6,'2002-01-01',
'2010-01-01');
Insert into PROFESSORES_DISCIPLINAS values (400,7,'2019-01-01',
'2030-01-01');
Insert into PROFESSORES_DISCIPLINAS values (300,8,'2035-01-01',
'2042-01-01');
Insert into PROFESSORES_DISCIPLINAS values (200,9,'2022-01-01',
'2025-01-01');
Insert into PROFESSORES_DISCIPLINAS values (200,1,'2013-01-01',
'2028-01-01');
Insert into PROFESSORES_DISCIPLINAS values (100,10,'2017-01-01',
'2020-01-01');

/*Informação 1*/
SELECT nome_prof
From professores
INNER JOIN PROFESSORES_DISCIPLINAS
	On professores.cod_prof = PROFESSORES_DISCIPLINAS.cod_prof
Where PROFESSORES_DISCIPLINAS.parou_ministrar < '2016-01-01';

/*Informação 2*/
Select nome_disciplina, count(*) 
from DISCIPLINAS
INNER JOIN PROFESSORES_DISCIPLINAS
	On DISCIPLINAS.cod_disc = PROFESSORES_DISCIPLINAS.cod_disc
group by nome_disciplina
HAVING count(*) < 3;

SELECT nome_prof
From professores
INNER JOIN PROFESSORES_DISCIPLINAS
	On professores.cod_prof = PROFESSORES_DISCIPLINAS.cod_prof
Where PROFESSORES_DISCIPLINAS.parou_ministrar = '2020-01-01';

/*Informação 2*/
Select nome_disciplina, count(*)
from DISCIPLINAS
INNER JOIN PROFESSORES_DISCIPLINAS
	On DISCIPLINAS.cod_disc = PROFESSORES_DISCIPLINAS.cod_disc
group by nome_disciplina
having  count(*) = 2;

/*Informação 3 - disciplinas ministradas por 2 ou + professores com a mesma data de início*/
select d.nome_disciplina, PD.comecou_ministrar, count(*)
from disciplinas as d
inner join PROFESSORES_DISCIPLINAS as PD
	On d.cod_disc = PD.cod_disc
group by d.cod_disc
having count(*) >= 2
order by pd.comecou_ministrar;

/*Informação 4 - quais são as disciplinas não ministradas em 2018*/

select d.nome_disciplina "Disciplina", pd.comecou_ministrar "Comeco", pd.parou_ministrar "Terminou"
from disciplinas as d
inner join PROFESSORES_DISCIPLINAS as PD
	On d.cod_disc = PD.cod_disc
where pd.comecou_ministrar > '2018-12-31'
or pd.parou_ministrar < '2017-12-31'
group by d.cod_disc
order by pd.comecou_ministrar;