create database Empresa_rastreamento;
use Empresa_rastreamento;

CREATE TABLE Cliente(
    Nome_cliente varchar(50),
	CPF char(11),
    Telefone int,
    Login varchar(32),
    Senha varchar(32),
    primary key (CPF)
);

CREATE TABLE Funcionario(
    Data_contratacao date,
    Salario float,
    Nome_func varchar(50),
    CPF_func char(11),
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
    Sigla_pais char(3),
    primary key(ID_Pais)
);

CREATE TABLE Estado(
	ID_Estado int unique,
    ID_Pais int,
    Nome_est varchar(50),
    Sigla_est char(2),
    primary key(ID_Estado),
    foreign key (ID_Pais) references Pais(ID_Pais)
);

CREATE TABLE Cidade(
	ID_Cidade int unique,
    ID_Estado int,
    Nome_cidade varchar(50),
    Sigla_cid char(3),
    primary key(ID_Cidade),
    foreign key (ID_Estado) references Estado(ID_Estado)
);

CREATE TABLE Instalador (
	ID_Instalador int unique,
    Nome_instalador varchar(50),
    ID_Cidade int,
    CPF_Func char(11),
    primary key (ID_Instalador),
    foreign key (ID_Cidade) references Cidade (ID_Cidade),
    foreign key (CPF_Func) references Funcionario (CPF_func)
);

CREATE TABLE Instalador_externo (
	ID_Instalador int unique,
    Nome_instalador_ex varchar(50),
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
	ID_Negocio int unique,
    Valor float,
    ID_Rastreador int,
    Placa char(7),
    ID_Vendedor int,
    CPF char(11) not null,
	primary key (ID_Negocio),
    foreign key (ID_Rastreador) references Rastreador(ID_Rastreador),
    foreign key (Placa) references Veiculo(PlacaV),
    foreign key (ID_Vendedor) references Vendedor(ID_Vendedor),
    foreign key (CPF) references Cliente(CPF) 
);

CREATE TABLE Rastreado(
	Comodato bool default false,
    Placa char(7),
    ID_Rastreador int,
    foreign key (Placa) references Veiculo(PlacaV),
    foreign key (ID_Rastreador) references Rastreador(ID_Rastreador)
);

CREATE TABLE Instalacoes(
	ID_Rastreador int,
    ID_Instalador int,
    Placa char(7),
    Data_instalacao date,
    foreign key (ID_Rastreador) references Rastreador(ID_Rastreador),
    foreign key (Placa) references Veiculo(PlacaV),
    foreign key (ID_Instalador) references Instalador(ID_Instalador)
);

CREATE TABLE Instalacoes_externas(
	ID_Rastreador int,
    ID_Instalador int,
    Placa char(7),
    Data_instalacao date,
    foreign key (ID_Rastreador) references Rastreador(ID_Rastreador),
    foreign key (Placa) references Veiculo(PlacaV),
    foreign key (ID_Instalador) references Instalador_externo(ID_Instalador)
);

CREATE TABLE Permissao_Acesso(
	Placa char(7),
    CPF char(11),
    foreign key (Placa) references Veiculo(PlacaV),
    foreign key (CPF) references Cliente(CPF) 
);

INSERT INTO PAIS VALUES (1, "Brasil", "BRA");
INSERT INTO ESTADO VALUES(1, 1, "Parana", "PR");
INSERT INTO ESTADO VALUES(2, 1, "Sao Paulo", "SP");
INSERT INTO CIDADE VALUES(1,1,"Curitiba", "CWB");
INSERT INTO CIDADE VALUES(2,1,"Londrina", "LBD");
INSERT INTO CIDADE VALUES(3,2,"São Paulo", "CGH");
INSERT INTO CIDADE VALUES(4,2,"Campinas", "VCP");

INSERT INTO COR VALUES(1, "Azul");
INSERT INTO COR VALUES(2, "Vermelho");
INSERT INTO COR VALUES(3, "Verde");
INSERT INTO COR VALUES(4, "Amarelo");
INSERT INTO MARCA VALUES(1, "Ford");
INSERT INTO MARCA VALUES(2, "Renault");
INSERT INTO MODELO VALUES(1,1,"Pinto");
INSERT INTO MODELO VALUES(2,2,"Twingo");
INSERT INTO MODELORASTREADOR VALUES(1, "st310");
INSERT INTO MODELORASTREADOR VALUES(2, "st310u");
INSERT INTO RASTREADOR VALUES(1, 1);
INSERT INTO RASTREADOR VALUES(2, 1);
INSERT INTO RASTREADOR VALUES(3, 2);
INSERT INTO RASTREADOR VALUES(4, 2);
INSERT INTO CLIENTE VALUES("Nome A", "12312312312", 111111111, "Login A", "Senha A");
INSERT INTO CLIENTE VALUES("Nome B", "45645645645", 222222222, "Login B", "Senha B");
INSERT INTO CLIENTE VALUES("Nome C", "78978978978", 333333333, "Login C", "Senha C");
INSERT INTO CLIENTE VALUES("Nome D", "99999999999", 333333333, "Login D", "Senha D");
INSERT INTO VEICULO VALUES("BRA1A11", 2, 1, 2000);
INSERT INTO VEICULO VALUES("BRA2A22", 2, 2, 1995);
INSERT INTO VEICULO VALUES("BRA3A33", 1, 4, 1975);
INSERT INTO FUNCIONARIO VALUES ("2020-08-30", 2001.50, "Funcionario 1", "11122233344", 444444444);
INSERT INTO FUNCIONARIO VALUES ("2015-10-25", 4500, "Funcionario 2", "22233344455", 555555555);
INSERT INTO FUNCIONARIO VALUES ("1998-02-16", 10000, "Funcionario 3", "33344455566", 666666666);
INSERT INTO FUNCIONARIO VALUES ("2018-03-01", 6200, "Funcionario 4", "44455566677", 777777777);
INSERT INTO FUNCIONARIO VALUES ("2007-07-26", 4300, "Funcionario 5", "55566677788", 888888888);
INSERT INTO INSTALADOR VALUES(1,"Instalador A", 1, "33344455566");
INSERT INTO INSTALADOR VALUES(2,"Instalador B", 2, "44455566677");
INSERT INTO INSTALADOR VALUES(3,"Instalador C", 2, "55566677788");
INSERT INTO INSTALADOR VALUES(4,"Instalador D", 3, "22233344455");
INSERT INTO INSTALADOR_EXTERNO VALUES(1,"Instalador EA", 1);
INSERT INTO INSTALADOR_EXTERNO VALUES(2,"Instalador EB", 2);
INSERT INTO INSTALADOR_EXTERNO VALUES(3,"Instalador EC", 4);
INSERT INTO INSTALADOR_EXTERNO VALUES(4,"Instalador ED", 4);
INSERT INTO VENDEDOR VALUES (1,"11122233344");
INSERT INTO VENDEDOR VALUES (2,"22233344455");
INSERT INTO NEGOCIADO VALUES (1, 95, 1, "BRA1A11", 1, "12312312312");
INSERT INTO NEGOCIADO VALUES (2, 155, 2, "BRA2A22", 1, "45645645645");
INSERT INTO NEGOCIADO VALUES (3, 155, 2, "BRA3A33", 1, "45645645645");
INSERT INTO PERMISSAO_ACESSO VALUES("BRA1A11", "12312312312");
INSERT INTO PERMISSAO_ACESSO VALUES("BRA1A11", "45645645645");
INSERT INTO PERMISSAO_ACESSO VALUES("BRA1A11", "99999999999");
INSERT INTO PERMISSAO_ACESSO VALUES("BRA2A22", "78978978978");
INSERT INTO PERMISSAO_ACESSO VALUES("BRA2A22", "45645645645");
INSERT INTO PERMISSAO_ACESSO VALUES("BRA3A33", "99999999999");
INSERT INTO RASTREADO VALUES (1, "BRA1A11", 1);
INSERT INTO RASTREADO VALUES (1, "BRA2A22", 2);
INSERT INTO RASTREADO VALUES (1, "BRA3A33", 3);
INSERT INTO INSTALACOES VALUES(1, 1, "BRA1A11", "2020-10-24");
INSERT INTO INSTALACOES VALUES(2, 1, "BRA3A33", "2002-04-04");
INSERT INTO INSTALACOES VALUES(3, 1, "BRA2A22", "2020-10-24");
INSERT INTO INSTALACOES VALUES(4, 2, "BRA3A33", "2018-04-04");
INSERT INTO INSTALACOES_EXTERNAS VALUES(3, 1, "BRA1A11", "2020-10-24");
INSERT INTO INSTALACOES_EXTERNAS VALUES(4, 1, "BRA3A33", "2000-02-04");
INSERT INTO INSTALACOES_EXTERNAS VALUES(4, 4, "BRA3A33", "1990-05-15");

/*INFORMAÇÃO 1 - Rastreadores por cidade*/

SELECT Nome_cidade "Cidade", count(*)
FROM Cidade
INNER JOIN INSTALADOR on INSTALADOR.ID_Cidade = cidade.ID_Cidade
INNER JOIN Instalacoes on INSTALADOR.ID_Instalador = instalacoes.ID_Instalador
INNER JOIN Rastreador on INSTALACOES.ID_Rastreador = Rastreador.ID_Rastreador
INNER JOIN ModeloRastreador on Rastreador.id_ModeloRastreador = ModeloRastreador.ID_ModeloRastreador
Group by nome_cidade;

/*INFORMAÇÃO 2 - Motoristas permitidos a dirigir um carro*/

SELECT PlacaV "Placa", nome_cliente "Nome do cliente"
From veiculo
INNER JOIN permissao_acesso on veiculo.placaV = permissao_acesso.placa
INNER JOIN cliente on cliente.cpf = permissao_acesso.cpf
Group by veiculo.placaV, cliente.nome_cliente;

/*INFORMAÇÃO 3 - Vendas por vendedor*/

SELECT nome_func "Nome do vendedor", valor,  nome_cliente "Nome do cliente"
FROM funcionario
INNER JOIN vendedor on funcionario.cpf_func = vendedor.cpf_func
INNER JOIN Negociado on vendedor.id_vendedor = Negociado.id_vendedor
INNER JOIN Cliente on Negociado.CPF = Cliente.CPF
Group by valor, funcionario.nome_func, cliente.nome_cliente;

/*INFORMAÇÃO 4 - Instalações por cidade*/

SELECT nome_cidade "Cidade", COUNT(*)
FROM cidade
INNER JOIN instalador on instalador.id_cidade = cidade.id_cidade
INNER JOIN instalacoes on instalacoes.id_instalador = instalador.id_instalador
group by nome_cidade
order by COUNT(*) desc;

SELECT nome_cidade "Cidade", COUNT(*)
FROM cidade
INNER JOIN instalador_externo on instalador_externo.id_cidade = cidade.id_cidade
INNER JOIN instalacoes_externas on instalacoes_externas.id_instalador = instalador_externo.id_instalador
group by nome_cidade
order by COUNT(*) desc;

/*INFORMAÇÃO 5 - Veículos que um cliente tem rastreado em seu nome*/

SELECT nome_cliente "Cliente", placaV "Placa registrada"
from cliente
INNER JOIN negociado on negociado.CPF = cliente.CPF
INNER JOIN veiculo on veiculo.placav = negociado.placav
group by nome_cliente, veiculo.placa;

/*INFORMAÇÃO 6 - Veiculos que um cliente tem acesso para dirigir*/

SELECT placav "Placa do carro", nome_cliente "Cliente com acesso"
from veiculo
INNER JOIN permissao_acesso on veiculo.Placav = permissao_acesso.Placav
INNER JOIN cliente on permissao_acesso.CPF = cliente.CPF
group by placav, cliente.nome_cliente;

/*INFORMAÇÃO 7 - Instalações externas a empresa por estado*/

SELECT Nome_est "Estado", count(*)
FROM Estado
INNER JOIN Cidade on cidade.id_estado = estado.id_estado
INNER JOIN INSTALADOR_externo on INSTALADOR_externo.ID_Cidade = cidade.ID_Cidade
INNER JOIN Instalacoes_externas on INSTALADOR_externo.ID_Instalador = instalacoes_externas.ID_Instalador
INNER JOIN Rastreador on INSTALACOES_externas.ID_Rastreador = Rastreador.ID_Rastreador
INNER JOIN ModeloRastreador on Rastreador.id_ModeloRastreador = ModeloRastreador.ID_ModeloRastreador
Group by nome_est
ORDER BY COUNT(*) desc;

/*INFORMACAO 8 - Instalacoes externas por cidade (semelhante a informação 1)*/

SELECT Nome_cidade "Cidade", count(*)
FROM Cidade
INNER JOIN INSTALADOR_externo on INSTALADOR_externo.ID_Cidade = cidade.ID_Cidade
INNER JOIN Instalacoes_externas on INSTALADOR_externo.ID_Instalador = instalacoes_externas.ID_Instalador
INNER JOIN Rastreador on INSTALACOES_externas.ID_Rastreador = Rastreador.ID_Rastreador
INNER JOIN ModeloRastreador on Rastreador.id_ModeloRastreador = ModeloRastreador.ID_ModeloRastreador
Group by nome_cidade;

/*INFORMAÇÃO 9 - Carros rastreados por modelo de rastreador por cidade*/
SELECT Modelo, nome_cidade, count(*)
from ModeloRastreador
INNER JOIN Rastreador on Rastreador.id_ModeloRastreador = ModeloRastreador.id_ModeloRastreador
INNER JOIN instalacoes on rastreador.id_rastreador = instalacoes.id_rastreador
INNER JOIN veiculo on instalacoes.Placav = veiculo.Placav
INNER JOIN instalador on instalador.id_instalador = instalacoes.id_instalador
INNER JOIN cidade on instalador.id_cidade = cidade.id_cidade
Group by ModeloRastreador.Modelo, cidade.nome_cidade
Order by Count(*) desc;

/*INFORMAÇÃO 10 - Modelo de rastreadores instalador por marca de veiculo*/
SELECT nome_marca, Modelo, count(*)
FROM marca
INNER JOIN Modelo on marca.id_marca = modelo.id_modelo
INNER JOIN veiculo on modelo.id_modelo = veiculo.id_modelo
INNER JOIN instalacoes on veiculo.Placav = instalacoes.Placav
INNER JOIN Rastreador on rastreador.id_rastreador = instalacoes.id_rastreador
INNER JOIN ModeloRastreador on rastreador.id_ModeloRastreador = Rastreador.id_ModeloRastreador
Group by Marca.nome_marca, ModeloRastreador.Modelo
Order by count(*) desc;
