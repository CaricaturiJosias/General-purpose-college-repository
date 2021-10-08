CREATE DATABASE LocacaoCar;

use LocacaoCar;

/*
INFORMAÇÂO  

-- quantos carros modelo Parati estao cadastrados
      
-- quantos carros "COLORIDO" do modelo Parati estao cadastrados

*/

-- MODELO QUE PERMITE INCONSISTENCIA - NAO REPRESENTA BOA PRATICA


/*CRIAR AS TABELAS*/

CREATE TABLE tbModelo(
codigo int,
descricao varchar(50),
primary key (codigo));

INSERT INTO tbModelo
VALUES
(1, 'PARATI'),
(2, 'FIT'),
(3, 'espacial4');

CREATE TABLE tbCor(
codigo int,
descricao varchar(50),
primary key (codigo));

INSERT INTO tbCor
VALUES
(1,'FUCSIA'),
(2, 'BORDO'),
(3,'COLORIDO'),
(4, 'INVISIVEL');

CREATE TABLE tbTipo(
codigo int,
descricao varchar(50),
primary key (codigo));

INSERT INTO tbTipo
VALUES
(1, 'CAMINHONETA'),
(2, 'SEDAN'),
(3, 'CONVERSIVEL');

CREATE TABLE tbAcessorio(
codigo int,
descricao varchar(50),
primary key (codigo));

INSERT INTO tbAcessorio
VALUES
(1, 'Ar Condicionado'),
(2, 'Acessibilidade');

CREATE TABLE tbCambio(
codigo int,
descricao varchar(50),
primary key (codigo));

INSERT INTO tbCambio
VALUES
(1, 'MAUAL'),
(2, 'AUTOMATICO');
  
CREATE TABLE tbCarro (
  chassi char(17),
  Modelo int,
  nmPlaca char(8),
  nrAno int,
  Cor int,
  Cambio int,
  nrPortas int,
  Tipo int,
  PRIMARY KEY (chassi),
  FOREIGN KEY (modelo)
    REFERENCES tbModelo(codigo),
  FOREIGN KEY (cor)
    REFERENCES tbCor(codigo),
  FOREIGN KEY (Tipo)
    REFERENCES tbTipo(codigo),
  FOREIGN KEY (Cambio)
    REFERENCES tbCambio(codigo)
    );

INSERT INTO tbCarro
VALUES
('111AAA', 1, 'ACJW2623', 2020, 1, 1, 3, 1),
('222BBB', 1, 'ACJW2323', 2020, 2, 1, 4, 1),
('333CCC', 2, 'XCJW2323', 2020, 3, 1, 4, 1),
('444DDD', 2, 'RCJW2323', 2020, 3, 1, 4, 1),
('555EEE', 1, 'TCJW2323', 2020, 4, 1, 4, 1);

CREATE TABLE tbCarro_Acessorio(
   chassi char(17),
   Acessorio int,
   primary key (chassi, Acessorio),
   FOREIGN KEY (chassi)
    REFERENCES tbCarro(chassi),
   FOREIGN KEY (Acessorio)
    REFERENCES tbAcessorio(codigo));

INSERT INTO tbCarro_Acessorio
VALUES
('111AAA', 1),
('222BBB', 1),
('333CCC', 2),
('333CCC', 1);

CREATE TABLE tbUF(
codigo int,
descricao varchar(50),
primary key (codigo));

INSERT INTO tbUF
VALUES
(1, 'Parana'),
(2, 'Santa Catarina');

CREATE TABLE tbMunicipio(
codigo int,
Nome varchar(50),
UF int,
primary key (codigo),
FOREIGN KEY (UF)
    REFERENCES tbUF(codigo));

INSERT INTO tbMunicipio
VALUES
(1, 'Curitiba',1),
(2, 'Londrina',1);


/*

endereco é um atributo composto (DER) - ENDERECO

a partir do modelo logico/fisico

    endereco foi decomposto
        rua
        numero
        complemento...

*/
CREATE TABLE tbCliente (
  email varchar(250),
  nmCliente varchar(250),
  nrTelefone_DDD char(3),
  nrTelefone char(9),
  nrCelular_DDD char(3),
  nrCelular char(9),
  nmEndereco_rua varchar(250),
  nmEndereco_numero varchar(10),
  nmEndereco_complemento varchar(250),
  nmEndereco_municipio int,
  nmEndereco_CEP char(8),
  dtNascimento date,
  nrTelefone_Contato_DDD char(3),
  nrTelefone_Contato char(9),
  PRIMARY KEY (email),
  FOREIGN KEY (nmEndereco_municipio)
    REFERENCES tbMunicipio(codigo));
 
INSERT INTO tbCliente
VALUES
('1@1.com', 'Joao', '041', '23442', '041', '445544', 'longe', '123', '12551',1,'80000000', '2001-01-01', '041', '334747'),
('1@2.com', 'Maria', '041', '23442', '041', '445544', 'longe', '123', '12551',1,'80000000', '2001-01-01', '041', '334747'),
('1@3.com', 'Joao', '041', '23442', '041', '445544', 'longe', '123', '12551',1,'80000000', '2001-01-01', '041', '334747');


-- quantos carros modelo Parati estao cadastrados

-- TBMODELO ("PARATI") + TBCARRO (CONTAR O NUMERO DE CARROS)
-- SEMPRE QUE EU PRECISO DE 2 TABELAS (ESTAO VINCULADAS PELA FK)

/*

SELECT O QUE EU QUERO
FROM ONDE EU CONSIGO
WHERE FILTRO 

*/

SELECT count(*)
FROM tbCarro, tbModelo
where tbModelo.descricao = 'PARATI' 
AND
      tbCarro.modelo = tbModelo.codigo;

/* POC - confirmar se o modelo esta correto e o resultado tambem
TBMODELO

CODIGO (1, 'PARATI'),

TBCARRO
('111AAA', *****1, 'ACJW2623', 2020, 1, 1, 3, 1),
('222BBB', *****1, 'ACJW2323', 2020, 2, 1, 4, 1),
('333CCC', 2, 'XCJW2323', 2020, 3, 1, 4, 1),
('444DDD', 2, 'RCJW2323', 2020, 3, 1, 4, 1),
('555EEE', *****1, 'TCJW2323', 2020, 4, 1, 4, 1);

EXCECUCAO NO SQL DEVE DAR RESULTADO DA CONTAGEM = 3

*/


/* quantos carros estao cadastrados
 TBCARRO (CONTAR O NUMERO DE CARROS)

TBCARRO
('111AAA', 1, 'ACJW2623', 2020, 1, 1, 3, 1),
('222BBB', 1, 'ACJW2323', 2020, 2, 1, 4, 1),
('333CCC', 2, 'XCJW2323', 2020, 3, 1, 4, 1),
('444DDD', 2, 'RCJW2323', 2020, 3, 1, 4, 1),
('555EEE', 1, 'TCJW2323', 2020, 4, 1, 4, 1);

EXCECUCAO NO SQL DEVE DAR RESULTADO DA CONTAGEM = 5

*/

SELECT count(*)
FROM tbCarro;



/* quantos carros estao cadastrados com dado referente a placa (dado valido = diferente de NULL)
TBCARRO (CONTAR O NUMERO DE CARROS)


TBCARRO
('111AAA', 1, 'ACJW2623', 2020, 1, 1, 3, 1),
('222BBB', 1, 'ACJW2323', 2020, 2, 1, 4, 1),
('333CCC', 2, 'XCJW2323', 2020, 3, 1, 4, 1),
('444DDD', 2, 'RCJW2323', 2020, 3, 1, 4, 1),
('555EEE', 1, 'TCJW2323', 2020, 4, 1, 4, 1);

EXCECUCAO NO SQL DEVE DAR RESULTADO DA CONTAGEM = 5

*/


SELECT count(nmPlaca)
FROM tbCarro;

/*
RESULTADO DA CONSULTA
5
*/
-- todos os dados cadastrados para os carros
-- TBCARRO 

SELECT *
FROM tbCarro;

/*
RESULTADO DA CONSULTA

('111AAA', 1, 'ACJW2623', 2020, 1, 1, 3, 1),
('222BBB', 1, 'ACJW2323', 2020, 2, 1, 4, 1),
('333CCC', 2, 'XCJW2323', 2020, 3, 1, 4, 1),
('444DDD', 2, 'RCJW2323', 2020, 3, 1, 4, 1),
('555EEE', 1, 'TCJW2323', 2020, 4, 1, 4, 1);
*/


-- quantos carros estao cadastrados, com mais de 2 anos (nrAno)
-- TBCARRO (CONTAR O NUMERO DE CARROS)

SELECT count(*)
FROM tbCarro
WHERE nrAno < 2019;

      
-- quantos carros por modelo estao cadastrados
-- TBMODELO + TBCARRO (CONTAR O NUMERO DE CARROS)
-- SEMPRE QUE EU PRECISO DE 2 TABELAS (ESTAO VINCULADAS PELA FK)


SELECT tbModelo.descricao, count(*)
FROM tbCarro, tbModelo
where tbCarro.modelo = tbModelo.codigo
group by tbModelo.descricao
order by tbModelo.descricao;
      
      
      
