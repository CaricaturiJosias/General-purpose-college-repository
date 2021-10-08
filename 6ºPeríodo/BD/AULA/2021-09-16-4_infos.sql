/*
INFORMACAO 1 - Quais sao os titulos mais emprestados?

INFORMACAO 2 - Quais sao os clientes que emprestaram mais de uma vez o titulo "titulo 3"?

INFORMACAO 3 - Quais sao os clientes que ja atrasaram alguma vez a devolucao de um titulo?

INFORMACAO 4 - Quais sao os clientes que nunca atrasaram a devolucao de um titulo?
       OPERADOR DA ALGEBRA RELACIONAL (DIFERENCA EM TER CONJUNTOS)

EXERCICIO 16/9/2021

INFORMACAO NOVA 1 - Quais sao o titulo menos emprestado?

INFORMACAO NOVA 2 - Qual é a cidade de origem mais frequente dos clientes?

INFORMACAO NOVA 3 - Quais são as cidades de origem que tem mais de 2 dos clientes?

INFORMACAO NOVE 4 - Qual é a categoria mais emprestada?
*/
create database biblioteca;
use biblioteca;

create table tb_cidade(
	 cod_cidade int,
     nome_cidade varchar (50),
     UF char(2),
     primary key (cod_cidade));

insert into tb_cidade values(1,"Curtiiba","PR");
insert into tb_cidade values(2,"Londrina","PR");

create table tb_cliente(cod_cliente int, 
	nome_cliente varchar(20), 
	cpf char(11), 
	data_cadastro date,
	cidade_cliente int,
	primary key (cod_cliente),
	foreign key (cidade_cliente) references tb_cidade(cod_cidade));

/* Qual é o CPF do 'Joao das Coves'?   EXEMPLO DE EXTRACAO DE DADO*/
SELECT CPF
FROM tb_cliente
WHERE nome_cliente = 'Joao das Coves';

Insert into tb_cliente values (1,'Joao das Coves', '11111111111','2009-05-04',1);
Insert into tb_cliente values (2,'Maria das Coves', '22222222222','2009-05-04',1);
Insert into tb_cliente values (3,'Maria Silveira', '33333333333','2010-05-04',1);
Insert into tb_cliente values (4,'Joao Silveira', '44444444444','2010-05-04',1);
Insert into tb_cliente values (5,'jack Estripador', '55555555555','2010-04-08',2);
Insert into tb_cliente values (6,'Joao Sabe Tudo', '66666666666','2009-05-04',1);
Insert into tb_cliente values (7,'Joao Sabe Nada', '77777777777','2009-04-08',1);

create table tb_classe(cod_classe int, 
	nome_classe varchar(20), 
	preco_classe double,
	primary key (cod_classe));

Insert into tb_classe values (1,'esporte', 70);
Insert into tb_classe values (2,'academico', 20);

create table tb_categoria(cod_categoria int, 
	nome_categoria varchar(20),
	cod_classe int,
	primary key (cod_categoria),
    foreign key (cod_classe) references tb_classe(cod_classe));

Insert into tb_categoria values (7,'sistemas integraveis',2);
Insert into tb_categoria values (2,'linguas',2);
Insert into tb_categoria values (3,'historia',2);
Insert into tb_categoria values (4,'fisica',2);
Insert into tb_categoria values (5,'biologia',2);


create table tb_titulo(cod_titulo int, 
	nome_titulo varchar(50),
	no_titulo int, 
	cod_categoria int, 
	primary key (cod_titulo),
  foreign key (cod_categoria) references tb_categoria(cod_categoria));

Insert into tb_titulo values (8,'titulo 6', 2005,6);
Insert into tb_titulo values (9,'titulo 7', 2000,7);
Insert into tb_titulo values (3,'titulo 3', 2010,3);
Insert into tb_titulo values (4,'titulo 4', 2009,4);
Insert into tb_titulo values (5,'titulo 5', 2005,5);

create table tb_emprestimo (
       cod_titulo int,
       cod_cliente int,
       data_emprestimo date,
       data_prevista_devolucao date,
       data_efetiva_devolução date,
       primary key(cod_titulo,cod_cliente,data_emprestimo),
       foreign key (cod_titulo) references tb_titulo(cod_titulo),
       foreign key (cod_cliente) references tb_cliente(cod_cliente));

Insert into tb_emprestimo values(8,5,'2021-03-23','2021-04-10', '2021-04-10');
Insert into tb_emprestimo values(9,5,'2021-03-23','2021-04-10', '2021-04-10');
Insert into tb_emprestimo values(1,4,'2021-03-23','2021-04-10', '2021-04-10');
Insert into tb_emprestimo values(1,5,'2021-03-23','2021-04-10', '2021-04-10');
Insert into tb_emprestimo values(2,2,'2021-03-23','2021-04-10', '2021-04-10');
Insert into tb_emprestimo values(2,2,'2021-04-23','2021-05-10', '2021-05-08');

/*INFORMAÇÃO 1*/
SELECT nome_titulo, COUNT(*)
FROM tb_titulo
INNER JOIN tb_emprestimo on tb_titulo.cod_titulo = tb_emprestimo.cod_titulo
INNER JOIN tb_cliente on tb_cliente.cod_cliente = tb_emprestimo.cod_cliente
GROUP BY tb_titulo.nome_titulo
ORDER BY COUNT(*);

/*INFORMAÇÃO 2*/
SELECT nome_cidade, COUNT(*)
FROM tb_cidade
INNER JOIN tb_cliente on tb_cliente.cidade_cliente = tb_cidade.cod_cidade
INNER JOIN tb_emprestimo on tb_emprestimo.cod_cliente = tb_cliente.cod_cliente
GROUP BY tb_cidade.nome_cidade
ORDER BY COUNT(*) desc;

/*INFORMAÇÃO 3*/
SELECT nome_cidade, COUNT(*)
FROM tb_cidade
INNER JOIN tb_cliente on tb_cliente.cidade_cliente = tb_cidade.cod_cidade
INNER JOIN tb_emprestimo on tb_emprestimo.cod_cliente = tb_cliente.cod_cliente
GROUP BY tb_cidade.nome_cidade
HAVING COUNT(*) > 2
ORDER BY COUNT(*) desc;

/*INFORMAÇÃO 4*/
SELECT nome_categoria, COUNT(*)
from tb_categoria
INNER JOIN tb_titulo on tb_titulo.cod_categoria = tb_categoria.cod_categoria
INNER JOIN tb_emprestimo on tb_emprestimo.cod_titulo = tb_titulo.cod_titulo
GROUP BY tb_categoria.nome_categoria
ORDER BY COUNT(*) desc;