/*

REQUISITOS DE INFORMAÇÔES
   A partir deste sistema o usuário deseja extrair as seguintes informação
   1. Qual é a categoria que nunca foi emprestada por nenhum usuário?
   2. Qual é a categoria que nunca foi emprestada pelo cliente "'Joao das Coves'?
   3. Qual é o cliente campeao de emprestimos? Mais emprestimos realizou?
   4. Qual é o cliente que nunca atrasou a devolução de um emprestimo realizado?

(RA01) DESAFIO 1 - Complementar o modelo fisico, case sejá necessario para a respectiva extração das informações

(RA02) DESAFIO 2 - Revisar (corrigir) caso seja necessário conforme as boas práticas de modelagem trabalhadas na disciplina

(RA01) DESAFIO 3 - representar o DER obtido a partir da complementacao obtida do DESAFIO 1

(RA02) DESAFIO 4 - construir as 4 instruções SELECT que atendam aos REQUISITOS DE INFORMAÇÔES

(RA02) DESAFIO 5 - popular o modelo de tal forma que permita consruir a POC (instruções SELECT)

(RA02) DESAFIO 6 - Representar as expressoes em algebra relacional para as instruções SELECT


*/

create database biblioteca;
use biblioteca;

create table tb_classe(
	cod_classe int, 
	nome_classe varchar(20), 
	preco_classe double,
	primary key (cod_classe));

Insert into tb_classe values (1,'lazer', 70);
Insert into tb_classe values (2,'academico', 20);

create table tb_categoria(
	cod_categoria int, 
	nome_categoria varchar(20),
	primary key (cod_categoria));

Insert into tb_categoria values (1,'matematica');
Insert into tb_categoria values (2,'linguas');
Insert into tb_categoria values (3,'historia');
Insert into tb_categoria values (4,'fisica');
Insert into tb_categoria values (5,'biologia');

create table tb_cliente(
	cod_cliente int, 
	nome_cliente varchar(20), 
	cpf char(11), data_cadastro date, 
	cidade_cliente varchar(50), 
	UF_cliente char (2),
	primary key (cod_cliente));

Insert into tb_cliente values (1,'Joao das Coves', '11111111111','2009-05-04','Curitiba', null);
Insert into tb_cliente values (2,'Maria das Coves', '22222222222','2009-05-04','Curitiba', NULL);
Insert into tb_cliente values (3,'Maria Silveira', '33333333333','2010-05-04','Curitiba', 'PR');
Insert into tb_cliente values (4,'Joao Silveira', '44444444444','2010-05-04','Curitiba', 'PR');
Insert into tb_cliente values (5,'jack Estripador', '55555555555','2010-06-04','Londrina', 'PR');
Insert into tb_cliente values (6,'Joao Sabe Tudo', '66666666666','2009-05-04','Curitiba', NULL);

create table tb_titulo(
	cod_titulo int, 
	nome_titulo varchar(50), 
	ano_titulo int, 
	cod_categoria int, 
	cod_classe int,
	primary key (cod_titulo),
  foreign key (cod_categoria) references tb_categoria(cod_categoria),
  foreign key (cod_classe)    references tb_classe(cod_classe));


Insert into tb_titulo values (1,'titulo 1', 2005,1,1);
Insert into tb_titulo values (2,'titulo 2', 2000,1,2);
Insert into tb_titulo values (3,'titulo 3', 2010,1,1);
Insert into tb_titulo values (4,'titulo 4', 2009,2,1);
Insert into tb_titulo values (5,'titulo 5', 2005,1,1);











