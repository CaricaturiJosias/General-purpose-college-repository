# cenário: registro de uso de ferramentas em uma oficina da urbs

create database urbs;
use urbs;


create table marca(
	id_marca int unique,
    nome_marca varchar(30),
    primary key(id_marca)
);

create table modelo(
	id_modelo int unique,
    id_marca int,
    nome_modelo varchar(50),
    primary key(id_modelo, id_marca),
    foreign key (id_marca) references marca(id_marca)
);

create table onibus(
	chassi char(17) unique,
    id_modelo int,
    primary key (chassi),
    foreign key (id_modelo) references modelo(id_modelo)
);

create table ferramenta(
	id_ferramenta int unique,
    id_modelo int,
    nome_ferramenta varchar(50),
    primary key (id_ferramenta),
    foreign key (id_modelo) references modelo (id_modelo)
);
/*
drop table onibus;
drop table conserto;
drop table ferramentas_conserto;
drop table uso_ferramenta;
drop table ferramenta;
*/
create table mecanico(
	CPF char(11) unique,
    nome varchar(100),
    telefone char(9),
    afiliacao varchar(10),
    primary key(CPF)
);
# tabelas MXN

create table uso_ferramenta (
	id_ferramenta int,
    CPF char(11),
    data_uso date,
    primary key(id_ferramenta, CPF, data_uso),
    foreign key (id_ferramenta) references ferramenta(id_ferramenta),
    foreign key (CPF) references mecanico(CPF)
);

create table conserto(
	chassi char(17),
    CPF char(11),
    data_conserto date,
    primary key(chassi, CPF, data_conserto),
    foreign key (chassi) references onibus(chassi),
    foreign key (CPF) references mecanico(CPF)
);

create table ferramentas_conserto(
	chassi char(17),
    id_ferramenta int,
    data_utilizacao date,
    primary key (chassi, id_ferramenta, data_utilizacao),
	foreign key (id_ferramenta) references ferramenta(id_ferramenta),
    foreign key (chassi) references onibus(chassi)
);

# populacao das tabelas

insert into marca values  (1, 'Mercedes'), (2, 'Bosch');
insert into modelo values (1, 1, 'OF-1722M'),
						  (2, 1, 'OF-1721 BlueTec 5'),
                          (3, 1, 'O-500RSD BlueTec 5'),
                          (4, 1, 'O-500RSD'), 
                          (5, 1,'O-400RSD'),
                          (6, 2, 'BOSCH-GKF-550'),
						  (7, 2, 'BOSCH-GKS-150-2D'),
                          (8, 2, 'BOSCH-GST-650'),
                          (9, 2, 'BOSCH-GWS-850-3D'), 
                          (10, 2, 'BOSCH-2607017398-0');
                          
insert into onibus values ('327FA8xW9c1bU7519', 1),
						  ('3JXfW57uBlhlB6532', 2),
                          ('1A9XW3A34Kel66464',3),
                          ('4KLZghhwfseMe2290',4),
                          ('5A5WRs7RRmPfF9720',5);
                          
insert into mecanico values('70260678503', 'Barceon', '936472488', 'URBS'),
						   ('88628826297', 'Elmya', '934145460', 'URBS'),
                           ('69622376509', 'Pinin', '924699444', 'URBS'),
                           ('09681187555', 'Darsi', '921216915', 'URBS'),
                           ('97812260488', 'Gimar', '938563273', 'URBS');
                           
insert into ferramenta values (1, 6, 'Tupia'),
							  (2, 7, 'Serra circular'),
                              (3, 8, 'Serra tico tico'),
                              (4, 9, 'Esmirilhadeira angular'),
                              (5, 10, 'Jogo de pontas de broca');
                              
insert into uso_ferramenta values
								 #não presente em conserto
                                 (1, '09681187555', '2020-06-15'),
                                 #não presente em conserto
								 (4, '70260678503', '2021-08-22'),
								 (2, '69622376509', '2021-10-02'),
								 (1, '88628826297', '2021-10-02'),
								 (2, '70260678503', '2020-03-22'),
                                 (1, '69622376509', '2021-07-31'),
                                 (1, '88628826297', '2019-12-15'),
                                 #não presente em conserto
                                 (5, '88628826297', '2020-11-24'),
                                 (3, '09681187555', '2020-05-12'),
                                 (1, '70260678503', '2021-04-21');

insert into conserto values ('327FA8xW9c1bU7519', '69622376509', '2021-10-02'),
							('327FA8xW9c1bU7519', '88628826297', '2021-10-02'),
							('3JXfW57uBlhlB6532', '69622376509', '2021-07-31'),
                            ('5A5WRs7RRmPfF9720', '09681187555', '2020-05-12'),
                            ('5A5WRs7RRmPfF9720', '70260678503', '2021-04-21'),
                            ('4KLZghhwfseMe2290', '88628826297', '2019-12-15'),
                            ('327FA8xW9c1bU7519', '70260678503', '2020-03-22');

insert into ferramentas_conserto values('327FA8xW9c1bU7519', 1, '2021-10-02'),
									   ('3JXfW57uBlhlB6532', 1, '2021-07-31'),
                                       ('5A5WRs7RRmPfF9720', 3, '2020-05-12'),
                                       ('5A5WRs7RRmPfF9720', 1, '2021-04-21'),
                                       ('4KLZghhwfseMe2290', 1, '2019-12-15'),
                                       ('327FA8xW9c1bU7519', 2, '2020-03-22');

#informacao: quantas ferramentas um modelo de ônibus teve que utilizar para ser consertado
select modelo.nome_modelo "Modelo do onibus", count(*) "quantidade de ferramentas"
# SELECT É PROJEÇÃO
from modelo
# CADA INNER JOIN É UMA JUNÇÃO
inner join onibus on
	onibus.id_modelo = modelo.id_modelo
inner join ferramentas_conserto on
	onibus.chassi = ferramentas_conserto.chassi
inner join ferramenta on 
	ferramentas_conserto.id_ferramenta = ferramenta.id_ferramenta
# GROUP E ORDER BY SÃO SELECAO
group by ferramenta.nome_ferramenta, modelo.nome_modelo
order by count(*) desc;

#POC - numero de mecanicos que fizeram o conserto de algum modelo de onibus dia 2 do 10 de 2021
select modelo.nome_modelo, count(*)
from modelo
INNER JOIN onibus
	on onibus.id_modelo = modelo.id_modelo
INNER JOIN conserto
	on conserto.chassi = onibus.chassi
INNER JOIN mecanico 
	on mecanico.CPF = conserto.CPF
where conserto.data_conserto = '2021-10-02';


# QUESTÃO 5 - Utilizar o operador <>
# informação - mecanicos que não utilizaram a ferramenta de id 1 e consertou um onibus nos últimos 6 meses
select mecanico.nome
from mecanico
INNER JOIN uso_ferramenta
	on mecanico.CPF = uso_ferramenta.CPF
INNER JOIN ferramenta
	on uso_ferramenta.id_ferramenta = ferramenta.id_ferramenta
INNER JOIN conserto
	on mecanico.CPF = conserto.CPF
where
 ferramenta.id_ferramenta <> 1 and
 # deixar como comentário a linha acima para atestar a veracidade da operação comparando resultados
 conserto.data_conserto > DATE_SUB(curdate(), interval 12 month)
order by mecanico.nome;

# QUESTÃO 6 - Utilizar o operador de diferença entre conjuntos
# informação - mecânicos que emprestaram ferramentas e não as usaram num conserto 
#(emprestimos de ferramentas que não batem com consertos)
SELECT mecanico.nome, ferramenta.nome_ferramenta, uso_ferramenta.data_uso
from mecanico
INNER JOIN uso_ferramenta
	on mecanico.CPF = uso_ferramenta.CPF
INNER JOIN ferramenta
	on ferramenta.id_ferramenta = uso_ferramenta.id_ferramenta
INNER JOIN modelo
	on modelo.id_modelo = ferramenta.id_modelo
where (mecanico.CPF, uso_ferramenta.data_uso) not in (select CPF, data_conserto from conserto)
group by mecanico.nome, ferramenta.nome_ferramenta;