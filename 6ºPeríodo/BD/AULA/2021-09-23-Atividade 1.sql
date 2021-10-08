create database teste;
use teste;

Create table cidade(
	id_cidade int not null unique,
    nome varchar(50),
    primary key (id_cidade)
);

Create table TABprof (
	cod int not null unique,
    nome varchar(50),
    data_nasc date,
    municipio_residencia int,
    primary key (cod),
    foreign key (municipio_residencia) references cidade (id_cidade)
);

Create table TABdisciplina(
	cod int unique not null,
    nome varchar(50),
    primary key (cod)
);

Create table TABprof_disciplina(
	cod_prof int,
    cod_disciplina int,
    ano int,
    foreign key (cod_prof) references tabprof (cod),
    foreign key (cod_disciplina) references tabdisciplina (cod)
);

INSERT INTO cidade values (1, "Curitib");
INSERT INTO tabprof values (1, "Souza", "2001-03-20", 1);
INSERT INTO tabprof values (2, "Josefa", "2003-10-13", 1);
INSERT INTO tabprof values (3, "Roberto", "1998-09-13", 1);
INSERT INTO tabdisciplina values (1, "Experiencia criativa 1");
INSERT INTO tabdisciplina values (2, "Materia 2");
INSERT INTO TABprof_disciplina values (1,1, 2019);
INSERT INTO TABprof_disciplina values (2,1, 2018);
INSERT INTO TABprof_disciplina values (1,2, 2000);
INSERT INTO TABprof_disciplina values (3,2, 1915);

Select nome
From TABprof 
Where cod not in (
	Select cod_prof
	From tabprof_disciplina
	INNER JOIN TABDisciplina on TABprof_disciplina.cod_disciplina = TABDisciplina.cod
	Where TABDisciplina.nome = 'Experiencia Criativa 1')
Order by cod;

/*--------------------------------------*/

Select tabprof.nome
from TABprof_disciplina
INNER JOIN TABprof on TABprof_disciplina.cod_prof = TABprof.cod
INNER JOIN TABdisciplina on TABprof_disciplina.cod_disciplina = TABdisciplina.cod
Where TABDisciplina.nome = 'Experiencia Criativa 1' and tabprof.cod
not in (
	Select cod_prof
	From TABprof_disciplina
	INNER JOIN TABdisciplina on TABprof_disciplina.cod_disciplina = TABdisciplina.cod
	Where TABprof_disciplina.ano = 2019)
order by nome;

