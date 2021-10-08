/*

O usuario definiu que algumas informaÃ§Ãµes devem ser extraidas a partir do sistema, tais como:

INFORMACAO 1 - Quantos foram os servicos consumidos para o cliente "Joao das Couves"?

INFORMACAO 2 - Quais os clientes fizeram checkin no dia 2/3/2021?

INFORMACAO 3 - Proponha uma informaÃ§Ã£o que exija o acesso a duas tabelas.

1. Complementar o modelo fisico com mais tabelas/atributos caso julgue necessario, bem como popule as tabelas.

2. Corrigir o modelo caso nao atenda Ã s tres Formas Normais, inclusive evitando inconsistencias 
   VOCE DEVE PROPOR AS DEPENDENCIAS FUNCIONAIS

3. Corrigir problemas de integridade referencial, tipagem e magnitude adotadas para os atributos, caso nao estejam adequados

4. Implementar a instruÃ§Ã£o SELECT para extrair as 3 INFORMACOES.

5. Depois de ajustado o modelo fisico, representar o DER.

*/

create database hotel;
use hotel;

create table Quarto(
	numero int,
	preco  float,
	andar int,
	numero_de_camas int,
	primary key (numero)
);

create table Estado(
	cod int,
	nome varchar(50),
	primary key(cod)
);

create table Cidade(
	cod int,
	nome varchar(50),
	estado int,
	primary key(cod),       
	foreign key(estado) references Estado(cod)
);
    
/* o modelo de dados deve permitir armazenar mais de um telefone e mais de um e-mail por cliente*/    
create table Cliente(
	rg char(9),
	nome varchar(70),
	rua varchar(30),
	numero int,
	cep char(8),
    cidade int,
    sexo char(10),
    primary key(rg),
    foreign key(cidade) references Cidade(cod)
);
        
create table Telefone(
	rg char(9),
	telefone int,
	primary key (rg),
	foreign key(rg) references Cliente(rg)
);

create table Email(
	rg char(9),
	email varchar(50),
	primary key(rg),
	foreign key(rg) references Cliente(rg)
);
        
       
create table CheckIn(
	codigo int,
	rg char(9),
	quarto int,
	horaEntrada datetime,
	motivo varchar(50),
	primary key (codigo),
	foreign key(rg) references Cliente(rg),
	foreign key(quarto) references Quarto(numero)
);
        
create table Servico(
	codigo int,
	valor int,
	descricao varchar(50),
	primary key(codigo)
);
     
create table ServicoPedido(
	checkin int,
    codigo int,
    foreign key(checkin) references CheckIn(codigo),
    foreign key(codigo) references Servico(codigo)
);     
     
create table CheckOut(
	checkin int,
	valor_a_pagar float,
	hora_de_saida datetime,
	primary key(checkin),
	foreign key(checkin) references CheckIn(codigo)
);

insert into Quarto values(1, 70.0, 1, 2);
insert into Quarto values(2, 100.0, 1, 4);
insert into Quarto values(3, 200.0, 2, 2);
insert into Quarto values(4, 350.0, 2, 4);

insert into Estado values(1, 'Paraná');
insert into Estado values(2, 'São Paulo');
insert into Estado values(3, 'Santa Catarina');

insert into Cidade values(1, 'Curitiba', 1);
insert into Cidade values(2, 'Morretes', 1);
insert into Cidade values(3, 'Londrina', 1);
insert into Cidade values(4, 'Cascavél', 1);

insert into Cidade values(5, 'São paulo' ,2);
insert into Cidade values(6, 'Campinas', 2);
insert into Cidade values(7, 'Guarulhos', 2);
insert into Cidade values(8, 'Osasco', 2);

insert into Cidade values(9, 'Florianópolis' ,3);
insert into Cidade values(10, 'Joinville', 3);
insert into Cidade values(11, 'Blumenau', 3);
insert into Cidade values(12, 'Balneário Camboriú', 3);

insert into Cliente values('123456123', 'João das Couves', 'Rua do joão', 1387, '14530674', 1, 'Masculino');
insert into Cliente values('123482183', 'Sandra das colinas', 'Rua do Sandra', 235, '84252174', 5, 'Feminino');
insert into Cliente values('523258324', 'Josefina parafina', 'Avenida 3D', 567, '78438520', 1, 'Feminino');
insert into Cliente values('123426123', 'José Bonifácio', 'Rua do zé', 832, '35664404', 3, 'Masculino');
insert into Cliente values('123126123', 'Selena Aurora', 'Avenida limpol', 2729, '03664404', 1, 'Feminino');
insert into Cliente values('312261213', 'Romário em 3D', 'Rua flamengo', 39, '22579804', 7, 'Masculino');

insert into Telefone values('123456123', 923123225);
insert into Telefone values('123482183', 123482183);
insert into Telefone values('523258324', 523258324);
insert into Telefone values('123426123', 123426123);
insert into Telefone values('123126123', 123126123);
insert into Telefone values('312261213', 312126123);

insert into CheckIn values(1,'123456123', 2, '2021-08-30 18:09:47', 'Quer viajar pelo mundo');
insert into CheckIn values(2,'123482183', 1, '2021-03-02 10:35:57', 'Viagem de negócios');
insert into CheckIn values(3,'523258324', 4, '2021-03-02 20:09:47', 'Turismo');
insert into CheckIn values(4,'123426123', 4, '2021-03-02 20:10:42', 'Turismo');
insert into CheckIn values(5,'123126123', 2, '2021-08-30 20:59:47', 'Quer seguir o João das Couves');
insert into CheckIn values(6,'312261213', 3, '2014-02-11 15:24:02', 'Quer jogar futebol');

insert into Servico values (1, 20.0, 'Prato feito no quarto');
insert into Servico values (2, 0.0, 'Limpeza diária do quarto');
insert into Servico values (3, 35.0, 'Almoço no restaurante do hotel');
insert into Servico values (4, 80.0, 'Spa exclusivo');
insert into Servico values (5, 52.20, 'Aluguel da quadra de esportes');

insert into ServicoPedido values (1,1);
insert into ServicoPedido values (1,1);
insert into ServicoPedido values (1,5);
insert into ServicoPedido values (5,4);
insert into ServicoPedido values (6,5);
insert into ServicoPedido values (6,5);
insert into ServicoPedido values (6,5);
insert into ServicoPedido values (6,5);
insert into ServicoPedido values (6,5);
insert into ServicoPedido values (6,2);
insert into ServicoPedido values (3,4);
insert into ServicoPedido values (4,3);
insert into ServicoPedido values (3,3);

insert into CheckOut values(6, 123520.99, '2015-01-02 07:15:02');
insert into CheckOut values(3, 463.50, '2021-03-05 09:09:47');
insert into CheckOut values(4, 103.99, '2021-03-05 09:08:20');

/*INFORMAÇÃO 1 - SERVIÇOS CONSUMIDOS POR JOÃO DAS COUVES*/
SELECT nome, descricao, COUNT(*)
from Cliente
INNER JOIN CheckIn on CheckIn.rg = Cliente.rg
INNER JOIN ServicoPedido on ServicoPedido.checkin = CheckIn.codigo
INNER JOIN Servico on Servico.codigo = ServicoPedido.codigo
WHERE Cliente.rg = '123456123'
GROUP BY Cliente.nome, Servico.descricao
ORDER BY count(*) desc;

/* INFORMAÇÃO 2 - QUAIS CLIENTES FIZERAM CHECKIN NO DIA 02/03/2021? */
SELECT nome, horaEntrada
from Cliente
INNER JOIN CheckIn on CheckIn.rg = Cliente.rg
WHERE CheckIn.horaEntrada BETWEEN '2021-03-02 00:00:00' AND '2021-03-02 23:59:59'
GROUP BY Cliente.nome;

/* INFORMAÇÃO 3 - QUAIS CLIENTES FIZERAM CHECKIN NO MESMO QUARTO?*/
SELECT nome, Quarto.numero
from Cliente
INNER JOIN CheckIn on CheckIn.rg = Cliente.rg
INNER JOIN Quarto on Quarto.numero = CheckIn.quarto
GROUP BY Quarto.numero
