/*
quantos estudante estao matriculados?

quantos estudantes estao matriculados no curso "Curso 4"?

quais os nomes dos estudantes aniversariantes de hoje?
*/

create database teste;

use teste;

create table TBEscola(cod int,
	nome varchar (100),
	primary key (cod));
    
insert into TBEscola values (1, "Escola 1");
insert into TBEscola values (2, "Escola 2");
insert into TBEscola values (3, "Escola 3");
insert into TBEscola values (4, "Escola 4");
insert into TBEscola values (5, "Escola 5");
insert into TBEscola values (6, "Escola 6");
    

create table TBCurso(cod int,
		nome varchar(100),
        cod_escola int,
        foreign key(cod_escola) references TBEscola(cod),
        primary key (cod));
  
insert into TBCurso values (1, "Curso 1", 1);
insert into TBCurso values (2, "Curso 2", 1);
insert into TBCurso values (3, "Curso 3", 2);
insert into TBCurso values (4, "Curso 4", 3);

create table TBEstudante(mat int,
		nome varchar(100),
        data_nasc date,
        cod_curso int,
        foreign key (cod_curso) references TBCurso(cod));

insert into TBEstudante values (1, "Estudante 1", '2000/08/10',4);      
insert into TBEstudante values (2, "Estudante 2", '2000/04/06',4);      
insert into TBEstudante values (4, "Estudante 4", '2000/04/03',4);      
insert into TBEstudante values (5, "Estudante 5", '2000/08/10',1);      
insert into TBEstudante values (6, "Estudante 6", '2000/12/03',4);      
insert into TBEstudante values (7, "Estudante 7", '2000/04/03',4);      
  
    
    
    