create database Empresa_rastreamento;
use Empresa_rastreamento;

CREATE TABLE Cliente(
    Nome_cliente varchar(100),
	CPF char(11) unique,
    Telefone int,
    Login varchar(32) NOT NULL,
    Senha varchar(32) NOT NULL,
    primary key (CPF)
);

CREATE TABLE Funcionario(
    Data_contratacao date NOT NULL,
    Salario float NOT NULL,
    Nome_func varchar(100) NOT NULL,
    CPF_func char(11) unique NOT NULL,
    Telefone int,
    primary key (CPF_func)
);

CREATE TABLE Vendedor(
	ID_Vendedor int unique,
    CPF_func char(11),
    primary key (ID_Vendedor),
    foreign key (CPF_func) references Funcionario(CPF_func)
);

CREATE TABLE Pais(
	ID_Pais int unique,
    Nome_pais varchar(50),
    Sigla_pais char(3) unique,
    primary key(ID_Pais)
);

CREATE TABLE Estado(
	ID_Estado int unique,
    ID_Pais int,
    Nome_est varchar(50),
    Sigla_estado char(2) unique,
    primary key(ID_Estado, ID_Pais),
    foreign key (ID_Pais) references Pais(ID_Pais)
);

CREATE TABLE Cidade(
	ID_Cidade int unique,
    ID_Estado int,
    Nome_cidade varchar(50),
    Sigla_cidade char(3) unique,
    primary key(ID_Cidade, ID_Estado),
    foreign key (ID_Estado) references Estado(ID_Estado)
);

CREATE TABLE Instalador (
	ID_Instalador int unique,
    Nome_instalador varchar(100),
    ID_Cidade int,
    CPF_Func char(11),
    primary key (ID_Instalador),
    foreign key (ID_Cidade) references Cidade (ID_Cidade),
    foreign key (CPF_Func) references Funcionario (CPF_func)
);

CREATE TABLE Instalador_externo (
	ID_Instalador int unique,
    Nome_instalador varchar(100),
    ID_Cidade int,
    primary key (ID_Instalador),
    foreign key (ID_Cidade) references Cidade (ID_Cidade)
);

CREATE TABLE MARCA(
	ID_Marca int unique,
    Nome_marca varchar(50),
    primary key (ID_Marca)
);

CREATE TABLE MODELO(
	ID_Modelo int unique,
    ID_Marca int,
    Nome_Modelo varchar(50),
    primary key (ID_Modelo),
    foreign key (ID_Marca) references Marca(ID_Marca)
);

CREATE TABLE Cor(
	ID_Cor int unique,
    Nome_Cor varchar(50),
    primary key (ID_Cor)
);

CREATE TABLE Veiculo(
	PlacaV char(7) unique not null,
    ID_Modelo int,
    ID_Cor int,
    Ano int,
    primary key (PlacaV),
    foreign key (ID_Modelo) references Modelo(ID_Modelo),
    foreign key (ID_Cor) references Cor(ID_Cor)
);

CREATE TABLE ModeloRastreador(
	ID_ModeloRastreador int unique,
    Modelo varchar(20),
    primary key (ID_ModeloRastreador)
);

CREATE TABLE Rastreador(
	ID_Rastreador int unique,
    ID_ModeloRastreador int,
    primary key (ID_Rastreador),
    foreign key (ID_ModeloRastreador) references ModeloRastreador(ID_ModeloRastreador)
);

CREATE TABLE Negociado(
	Placa char(7) NOT NULL,
    ID_Rastreador int,
    ID_Vendedor int NOT NULL,
    CPF char(11) not null NOT NULL,
    negociado float NOT NULL,
	primary key (Placa, ID_Rastreador, ID_Vendedor, CPF),
    foreign key (ID_Rastreador) references Rastreador(ID_Rastreador),
    foreign key (Placa) references Veiculo(PlacaV),
    foreign key (ID_Vendedor) references Vendedor(ID_Vendedor),
    foreign key (CPF) references Cliente(CPF) 
);

CREATE TABLE Rastreado(
	Comodato bool default false,
    Placa char(7) NOT NULL,
    ID_Rastreador int NOT NULL,
    primary key(Placa, ID_Rastreador),
    foreign key (Placa) references Veiculo(PlacaV),
    foreign key (ID_Rastreador) references Rastreador(ID_Rastreador)
);

CREATE TABLE Instalacoes(
	ID_Rastreador int NOT NULL,
    ID_Instalador int NOT NULL,
    Placa char(7) NOT NULL,
    Data_instalacao date NOT NULL,
    primary key(ID_Rastreador, ID_Instalador,Placa, Data_Instalacao),
    foreign key (ID_Rastreador) references Rastreador(ID_Rastreador),
    foreign key (Placa) references Veiculo(PlacaV),
    foreign key (ID_Instalador) references Instalador(ID_Instalador)
);

CREATE TABLE Instalacoes_externas(
	ID_Rastreador int NOT NULL,
    ID_Instalador int NOT NULL,
    Placa char(7) NOT NULL,
    Data_instalacao date NOT NULL,
    primary key(ID_Rastreador, ID_Instalador,Placa, Data_Instalacao),
    foreign key (ID_Rastreador) references Rastreador(ID_Rastreador),
    foreign key (Placa) references Veiculo(PlacaV),
    foreign key (ID_Instalador) references Instalador_externo(ID_Instalador)
);

CREATE TABLE Permissao_Acesso(
	Placa char(7) NOT NULL,
    CPF char(11) NOT NULL,
    primary key(Placa, CPF),
    foreign key (Placa) references Veiculo(PlacaV),
    foreign key (CPF) references Cliente(CPF) 
);

INSERT INTO PAIS VALUES (1, "Brasil", "BRA");

INSERT INTO ESTADO VALUES(1, 1, "Parana", "PR"),
					     (2, 1, "Sao Paulo", "SP");

INSERT INTO CIDADE VALUES(1,1,"Curitiba", "CWB"),
						 (2,1,"Londrina", "LBD"),
						 (3,2,"São Paulo", "CGH"),
						 (4,2,"Campinas", "VCP");

INSERT INTO COR VALUES(1, "Azul"),
					  (2, "Vermelho"),
					  (3, "Verde"),
					  (4, "Amarelo");

INSERT INTO MARCA VALUES(1, "Ford"),
						(2, "Renault");

INSERT INTO MODELO VALUES(1,1,"Pinto"),
					     (2,2,"Twingo");

INSERT INTO MODELORASTREADOR VALUES(1, "st310"),
								   (2, "st310u");

INSERT INTO RASTREADOR VALUES(1, 1),
							 (2, 1),
							 (3, 2),
							 (4, 2);

INSERT INTO CLIENTE VALUES("Nome A", "12312312312", 111111111, "Login A", "Senha A"),
						  ("Nome B", "45645645645", 222222222, "Login B", "Senha B"),
						  ("Nome C", "78978978978", 333333333, "Login C", "Senha C"),
						  ("Nome D", "99999999999", 333333333, "Login D", "Senha D");

INSERT INTO VEICULO VALUES("BRA1A11", 2, 1, 2000),
						  ("BRA2A22", 2, 2, 1995),
						  ("BRA3A33", 1, 4, 1975);

INSERT INTO FUNCIONARIO VALUES ("2020-08-30", 2001.50, "Funcionario 1", "11122233344", 444444444),
							   ("2015-10-25", 4500, "Funcionario 2", "22233344455", 555555555),
							   ("1998-02-16", 10000, "Funcionario 3", "33344455566", 666666666),
							   ("2018-03-01", 6200, "Funcionario 4", "44455566677", 777777777),
							   ("2007-07-26", 4300, "Funcionario 5", "55566677788", 888888888);

INSERT INTO INSTALADOR VALUES(1,"Instalador A", 1, "33344455566"),
							 (2,"Instalador B", 2, "44455566677"),
							 (3,"Instalador C", 2, "55566677788"),
							 (4,"Instalador D", 3, "22233344455");

INSERT INTO INSTALADOR_EXTERNO VALUES(1,"Instalador EA", 1),
									 (2,"Instalador EB", 2),
									 (3,"Instalador EC", 4),
									 (4,"Instalador ED", 4);

INSERT INTO VENDEDOR VALUES (1,"11122233344"),
							(2,"22233344455");

INSERT INTO NEGOCIADO(ID_Rastreador, negociado, ID_Vendedor, Placa, CPF) VALUES 
															(1, 95, 1, "BRA1A11", "12312312312"),
															(2, 155, 2, "BRA2A22", "45645645645"),
															(3, 155, 2, "BRA3A33", "45645645645");
                                                            
INSERT INTO PERMISSAO_ACESSO VALUES("BRA1A11", "12312312312"),
									("BRA1A11", "45645645645"),
									("BRA1A11", "99999999999"),
									("BRA2A22", "78978978978"),
									("BRA2A22", "45645645645"),
									("BRA3A33", "99999999999");
                                    
INSERT INTO RASTREADO VALUES (1, "BRA1A11", 1),
							 (1, "BRA2A22", 2),
							 (1, "BRA3A33", 3);
                             
INSERT INTO INSTALACOES VALUES(1, 1, "BRA1A11", "2020-10-24"),
							  (2, 1, "BRA3A33", "2002-04-04"),
							  (3, 1, "BRA2A22", "2020-10-24"),
							  (4, 2, "BRA3A33", "2018-04-04");
                              
INSERT INTO INSTALACOES_EXTERNAS VALUES(3, 1, "BRA1A11", "2020-10-24"),
									   (4, 1, "BRA3A33", "2000-02-04"),
									   (4, 4, "BRA3A33", "1990-05-15");

/*INFORMAÇÃO 1 - Rastreadores por cidade*/

SELECT Nome_cidade "Cidade", count(*)
FROM Cidade
INNER JOIN INSTALADOR on INSTALADOR.ID_Cidade = cidade.ID_Cidade
INNER JOIN Instalacoes on INSTALADOR.ID_Instalador = instalacoes.ID_Instalador
Group by nome_cidade;

/*Prova de conceito

SELECT Nome_cidade "Cidade", count(*)
FROM Cidade
INNER JOIN INSTALADOR on INSTALADOR.ID_Cidade = cidade.ID_Cidade
INNER JOIN Instalacoes on INSTALADOR.ID_Instalador = instalacoes.ID_Instalador
INNER JOIN Rastreador on INSTALACOES.ID_Rastreador = Rastreador.ID_Rastreador
INNER JOIN ModeloRastreador on Rastreador.id_ModeloRastreador = ModeloRastreador.ID_ModeloRastreador
WHERE nome_cidade = "Londrina"
Group by nome_cidade;

Resultado esperado
+---------------------------------+
|Cidade   | Count(*)              | 
|---------------------------------|
|Londrina | 1                     |
+---------------------------------+

*/
/*INFORMAÇÃO 2 - Motoristas permitidos a dirigir um carro*/

SELECT PlacaV "Placa", nome_cliente "Nome do cliente"
From veiculo
INNER JOIN permissao_acesso on veiculo.placaV = permissao_acesso.placa
INNER JOIN cliente on cliente.cpf = permissao_acesso.cpf
Group by veiculo.placaV, cliente.nome_cliente;
/*	
WHERE veiculo.placaV = "placa"
*/
/*POC - Prova de conceito
SELECT PlacaV "Placa", nome_cliente "Nome do cliente"
From veiculo
INNER JOIN permissao_acesso on veiculo.placaV = permissao_acesso.placa
INNER JOIN cliente on cliente.cpf = permissao_acesso.cpf
WHERE veiculo.placaV = "BRA2A22"
Group by veiculo.placaV, cliente.nome_cliente;

Resultado esperado
+---------------------------------+
|Placa   | Nome do cliente        |
|---------------------------------|
|BRA2A22 | Nome B                 |
|---------------------------------|
|BRA2A22 | Nome C
+---------------------------------+
*/

/*INFORMAÇÃO 3 - Vendas por vendedor*/

SELECT nome_func "Nome do vendedor", COUNT(*)
FROM funcionario
INNER JOIN vendedor on funcionario.cpf_func = vendedor.cpf_func
INNER JOIN Negociado on vendedor.id_vendedor = Negociado.id_vendedor
GROUP BY nome_func
order by count(*) desc;
/*
SELECT nome_func "Nome do vendedor", COUNT(*)
FROM funcionario
INNER JOIN vendedor on funcionario.cpf_func = vendedor.cpf_func
INNER JOIN Negociado on vendedor.id_vendedor = Negociado.id_vendedor
WHERE funcionario.nome_func = "Funcionario 2"

Resultado esperado
+---------------------------------+
|Nome do vendedor  | Count(*)     | 
|---------------------------------|
|Funcionario 2     | 2            |
+---------------------------------+

*/

/*INFORMAÇÃO 4 - Instalações por cidade*/

SELECT nome_cidade "Cidade", COUNT(*) "Quantidade"
FROM cidade
INNER JOIN instalador on instalador.id_cidade = cidade.id_cidade
INNER JOIN instalacoes on instalacoes.id_instalador = instalador.id_instalador
group by nome_cidade
order by "Quantidade" desc;

/*POC
SELECT nome_cidade "Cidade", COUNT(*) "Quantidade"
FROM cidade
INNER JOIN instalador on instalador.id_cidade = cidade.id_cidade
INNER JOIN instalacoes on instalacoes.id_instalador = instalador.id_instalador
where cidade.nome_cidade = "Curitiba" or "São Paulo"
group by nome_cidade
order by "Quantidade" desc;

Resultado esperado
+---------------------------------+
|Cidade   | Quantidade            | 
|---------------------------------|
|Curitiba | 3                     |
+---------------------------------+
*/

SELECT nome_cidade "Cidade", COUNT(*) "Quantidade"
FROM cidade
INNER JOIN instalador_externo on instalador_externo.id_cidade = cidade.id_cidade
INNER JOIN instalacoes_externas on instalacoes_externas.id_instalador = instalador_externo.id_instalador
group by nome_cidade
order by "Quantidade" desc;

/*INFORMAÇÃO 5 - Clientes com mais veículos rastreados em seu nome*/

SELECT nome_cliente "Cliente", COUNT(*) "Carros que tem em seu nome"
from cliente
INNER JOIN negociado on negociado.CPF = cliente.CPF
INNER JOIN veiculo on veiculo.placav = negociado.placa
INNER JOIN Rastreado on veiculo.placav = rastreado.placa
group by nome_cliente, veiculo.placav
order by "Quantidade" desc;
/*POC
SELECT nome_cliente "Cliente", COUNT(*) "Carros que tem em seu nome"
from cliente
INNER JOIN negociado on negociado.CPF = cliente.CPF
INNER JOIN veiculo on veiculo.placav = negociado.placa
INNER JOIN Rastreado on veiculo.placav = rastreado.placa
where cliente.nome_cliente = "Nome A"
group by nome_cliente, veiculo.placav
order by "Quantidade" desc;

Resultado esperado
+--------------------------------------+
|Cliente| Carros que tem em seu nome   |
|--------------------------------------|
|Nome A | 1                            |
+--------------------------------------+
*/

/*INFORMAÇÃO 6 - Veiculos com maior número de pessoas com acesso a ele*/

SELECT placav "Placa do carro", COUNT(*) "Clientes com acesso"
from veiculo
INNER JOIN permissao_acesso on veiculo.Placav = permissao_acesso.Placa
group by placav, "Quantidade"
order by "Quantidade" desc;
/* POC
SELECT placav "Placa do carro", COUNT(*) "Clientes com acesso"
from veiculo
INNER JOIN permissao_acesso on veiculo.Placav = permissao_acesso.Placa
WHERE veiculo.placav = "BRA2A22"
group by placav, "Quantidade"
order by "Quantidade" desc;

Resultado esperado
+--------------------------------------+
|Placa do carro| Clientes com acesso   |
|--------------------------------------|
|BRA2A22       |2                      |
+--------------------------------------+
*/
/*INFORMAÇÃO 7 - Instalações externas a empresa por estado*/

SELECT Nome_est "Estado", count(*) "Quantidade de instalações"
FROM Estado
INNER JOIN Cidade on cidade.id_estado = estado.id_estado
INNER JOIN INSTALADOR_externo on INSTALADOR_externo.ID_Cidade = cidade.ID_Cidade
INNER JOIN Instalacoes_externas on INSTALADOR_externo.ID_Instalador = instalacoes_externas.ID_Instalador
Group by nome_est
ORDER BY "Quantidade" desc;

/* POC
SELECT Nome_est "Estado", count(*) "Quantidade de instalações"
FROM Estado
INNER JOIN Cidade on cidade.id_estado = estado.id_estado
INNER JOIN INSTALADOR_externo on INSTALADOR_externo.ID_Cidade = cidade.ID_Cidade
INNER JOIN Instalacoes_externas on INSTALADOR_externo.ID_Instalador = instalacoes_externas.ID_Instalador
WHERE Estado.Nome_est = "Parana"
Group by nome_est
ORDER BY "Quantidade" desc;

Resultado esperado
+-----------------------------------+
|Estado  | Quantidade de instalações|
|-----------------------------------|
|Paraná  | 2                        |
+-----------------------------------+
*/

/*INFORMACAO 8 - Instalacoes externas por cidade (semelhante a informação 1)*/

SELECT Nome_cidade "Cidade", count(*) "Quantidade de instalações"
FROM Cidade
INNER JOIN INSTALADOR_externo on INSTALADOR_externo.ID_Cidade = cidade.ID_Cidade
INNER JOIN Instalacoes_externas on INSTALADOR_externo.ID_Instalador = instalacoes_externas.ID_Instalador
Group by nome_cidade;

/* POC
SELECT Nome_cidade "Cidade", count(*) "Quantidade de instalações"
FROM Cidade
INNER JOIN INSTALADOR_externo on INSTALADOR_externo.ID_Cidade = cidade.ID_Cidade
INNER JOIN Instalacoes_externas on INSTALADOR_externo.ID_Instalador = instalacoes_externas.ID_Instalador
WHERE Cidade.Nome_cidade = "Campinas"
Group by nome_cidade;

Resultado esperado
+------------------------------------+
|Cidade   | Quantidade de instalações|
|------------------------------------|
|Campinas | 1                        |
+------------------------------------+
*/

/*INFORMAÇÃO 9 - Carros rastreados por modelo de rastreador por cidade*/
SELECT Modelo"Modelo do rastreador", nome_cidade"Cidade", count(*) "Quantidade de rastreados"
from ModeloRastreador
INNER JOIN Rastreador on Rastreador.id_ModeloRastreador = ModeloRastreador.id_ModeloRastreador
INNER JOIN instalacoes on rastreador.id_rastreador = instalacoes.id_rastreador
INNER JOIN veiculo on instalacoes.Placa = veiculo.Placav
INNER JOIN instalador on instalador.id_instalador = instalacoes.id_instalador
INNER JOIN cidade on instalador.id_cidade = cidade.id_cidade
Group by ModeloRastreador.Modelo, cidade.nome_cidade
Order by "Quantidade" desc;

/*POC
SELECT nome_cidade"Cidade", count(*) "Quantidade de rastreados"
from ModeloRastreador
INNER JOIN Rastreador on Rastreador.id_ModeloRastreador = ModeloRastreador.id_ModeloRastreador
INNER JOIN instalacoes on rastreador.id_rastreador = instalacoes.id_rastreador
INNER JOIN veiculo on instalacoes.Placa = veiculo.Placav
INNER JOIN instalador on instalador.id_instalador = instalacoes.id_instalador
INNER JOIN cidade on instalador.id_cidade = cidade.id_cidade
WHERE ModeloRastreador.Modelo = "st310u"
Group by cidade.nome_cidade
Order by "Quantidade" desc;

Resultado esperado
+-------------------------------------+
| Cidade   | Quantidade de rastreados |
|-------------------------------------|
| Curitiba | 1                        |
|-------------------------------------|
| Londrina | 1                        |
+-------------------------------------+
*/

/*INFORMAÇÃO 10 - Modelo de rastreadores instalador por marca de veiculo*/
SELECT nome_marca "Marca do veículo", count(*) "Quantidade de rastreados"
FROM ModeloRastreador
INNER JOIN Rastreador on rastreador.id_ModeloRastreador = ModeloRastreador.id_ModeloRastreador
INNER JOIN instalacoes on rastreador.id_rastreador = instalacoes.id_rastreador
INNER JOIN veiculo on veiculo.Placav = instalacoes.Placa
INNER JOIN Modelo on modelo.id_modelo = veiculo.id_modelo
INNER JOIN Marca  on Modelo.ID_Marca = Marca.ID_Marca 
Group by Marca.nome_marca
Order by "Quantidade de rastreados" desc;

/*POC
SELECT nome_marca"Marca do veículo", count(*) "Quantidade de rastreados"
FROM ModeloRastreador
INNER JOIN Rastreador on rastreador.id_ModeloRastreador = ModeloRastreador.id_ModeloRastreador
INNER JOIN instalacoes on rastreador.id_rastreador = instalacoes.id_rastreador
INNER JOIN veiculo on veiculo.Placav = instalacoes.Placa
INNER JOIN Modelo on modelo.id_modelo = veiculo.id_modelo
INNER JOIN Marca  on Modelo.ID_Marca = Marca.ID_Marca 
Where ModeloRastreador.Modelo = "st310"
Group by Marca.nome_marca
Order by "Quantidade de rastreados" desc;

+---------------------------------------------+
| Marca do veículo | Quantidade de rastreados |
|---------------------------------------------|
| Renault          | 2                        |
|---------------------------------------------|
| Ford             | 2                        |
+---------------------------------------------+
*/
