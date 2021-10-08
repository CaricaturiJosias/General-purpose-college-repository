/* Avaliacao Somativa 1 - SIMULACAO 

1. identificar se o modelo atende Ã s tres Formas Normais, inclusive evitando inconsistencias
Caso nao esteja adequado, justifique (em formato de comentÃ¡rio) e realize as alteracoes necessarias
Para tal, deixe em comentario a versÃ£o NAO CORRETA e na sequencia apresente fora do comentÃ¡rio a versao CORRETA

2. identificar se a tipagem e magnitude adotadas para os atributos estao adequadas
Caso nao esteja adequado, ustifique (em formato de comentÃ¡rio) e realize as alteracoes necessarias
Para tal, deixe em comentario a versÃ£o NAO CORRETA e na sequencia apresente fora do comentÃ¡rio a versao CORRETA

3. identificar se a integridade referencial esta garatida
Caso nao esteja adequado, ustifique (em formato de comentÃ¡rio) e realize as alteracoes necessarias
promova as alteracoes necessarias
Para tal, deixe em comentario a versÃ£o NAO CORRETA e na sequencia apresente fora do comentÃ¡rio a versao CORRETA

4. Propor 3 informaÃ§Ãµes a serem extraidas que:
 4.1 exija a utilizacao de 2 tabelas
 4.2 exija a utilizacao de 3 tabelas
 4.3 exija a utilizacao do Operador de diferenca entre conjuntos

5. Implementar as 3 instrucoes SELECT (ITEM 4)

6. Representar o correspondente DER a partir do modelo fisico COMPLETO (CORRIGIDO)
*/
CREATE DATABASE Hospital;
USE Hospital;
/*Definir unique e not null para chave primaria*/
create table Convenio(
    codigo_convenio int unique not null,
    nome varchar(50),
    primary key (codigo_convenio)
);
/*create table Convenio(
    codigo_convenio int , <<------------------
    nome varchar(50),
    primary key (codigo_convenio)
);*/
/*O endereco está errado, é necessário criar entidades de localização como pais, estado, cidade. Logo é mais viável incluir cep e número de residência, definir unique e not null para numero do paciente
  É preciso definir documentos como char*/
create table Paciente(
    numero_paciente int unique not null,
    nome varchar(100),
    RG int,
    CPF double,
    codigo_convenio int,
    CEP int,
    numeroCasa int,
    primary key (numero_paciente),
    foreign key (codigo_convenio) references Convenio(codigo_convenio)
);
/*
create table Paciente(
    numero_paciente int,
    nome varchar(100),
    RG int,
    CPF int,
    codigo_convenio int,
    endereco varchar(200), <<------------
    primary key (numero_paciente),
    foreign key (codigo_convenio) references Convenio(codigo_convenio)
);
/*

/*Ã©(?) necessidade dos profissionais de saude identificarem quais sao as doencas mais frequentes*/
/*Quebra da segunda forma normal ao gerar código doença e descricao-doença, é necessário possuir uma tabela para registrar doenças e manter descrição na tabela de doencas do paciente,
pois pode ser variado o efeito da doenca no paciente*/
create table Doenca(
    codigo_doenca int,
    nome varchar(30),
    primary key (codigo_doenca)
);

create table Paciente_doencas(
    numero_paciente int,
    codigo_doenca int,
    descricao_doenca varchar(100),
    primary key (numero_paciente, codigo_doenca),
    foreign key (numero_paciente) references Paciente(numero_paciente),
    foreign key (codigo_doenca) references doenca(codigo_doenca)
);
/*
create table Paciente_doencas(
    numero_paciente int,
    codigo_doenca int,
    descricao_doenca varchar(100),
    primary key (numero_paciente, codigo_doenca),
    foreign key (numero_paciente) references Paciente(numero_paciente)
);
*/

/*Chave primeria composta por CRM, UF Ã© imperativa
CRM Ã© um numero representado por atÃ© 8 caracteres mais o dÃ­gito verificador*/
/*UF utiliza varchar*/
create table Medico(
    CRM int,
    UF char(2),
    nome varchar(20),
    RG int,
    CPF double,
    primary key(CRM, UF)
);
/*
create table Medico(
    CRM char(9),
    UF varchar(2),
    nome varchar(20),
    RG char(9),
    CPF char(11),
    primary key(CRM, UF)
);
*/
/* Ã© padrao da instituicao manter a chave primaria composta, nao deve ser modificada*/
create table Medico_convenio(
    codigo_convenio int,
    CRM int,
    UF varchar(2),
    primary key (codigo_convenio, CRM, UF),
    foreign key (codigo_convenio) references Convenio(codigo_convenio),
    foreign key (CRM, UF) references Medico(CRM, UF)
);
/*descrição pequena demais*/
create table Exames(
    codigo_exame int,
    descricao varchar(100),
    primary key (codigo_exame)
);
/*
create table Exames(
    codigo_exame int,
    descricao varchar(20), <<---------
    primary key (codigo_exame)
);
*/

/*Ã© necessidade dos profissionais de saude identificarem quais sao as queixas mais frequentes*/
/* Ã© padrao da instituicao manter a chave primaria composta, nao deve ser modificada*/
/*existe uma chamada confusa de foreign key sobre o código de convênio, pois a primary key do paciente é número_paciente, então seria um erro de dependência funcional chamar codigo_convênio de um paciente e não sua primary key
	é estranho o tamanho da queixa ser tão pequeno, não seria possível uma descrição real se o paciente sofresse de alguma dor + algum sintoma, não caberia
    DATETIME é necessário para registrar a hora
create table Consulta(
    numero_paciente int,
    CRM int,
    UF varchar(2),
    data_hora date, <<-----------
    queixas varchar(40), <<-------
    primary key (numero_paciente, CRM, UF, data_hora),
    foreign key (numero_paciente) references Paciente(codigo_convenio), <<---------
	foreign key (CRM, UF) references Medico(CRM,UF)
);*/

create table Consulta(
    numero_paciente int,
    CRM int,
    UF varchar(2),
    data_hora datetime,
    queixas varchar(200),
    primary key (numero_paciente, CRM, UF, data_hora),
    foreign key (numero_paciente) references Paciente(numero_paciente),
	foreign key (CRM, UF) references Medico(CRM,UF)
);

/* Ã© padrao da instituicao manter a chave primaria composta, nao deve ser modificada*/
/*Existe um problema na dependência transitiva, chamar consulta para pegar um numero_paciente  é uma violação disso
, incluindo a chamada de crm e uf, que são de médico, o data_hora é o único que deve ser chamado por consulta para manter a terceira forma normal*/

create table Consulta_exames(
    numero_paciente int,
    CRM int,
    UF varchar(2),
    data_hora datetime,
    codigo_exame int,
    resultado varchar(100),
    primary key (numero_paciente, CRM, UF, data_hora, codigo_exame),
    foreign key (numero_paciente, CRM, UF, data_hora) references Consulta(numero_paciente, CRM, UF, data_hora),
    foreign key (codigo_exame) references Exames (codigo_exame)
);

/*POPULANDO AS TABELAS*/
INSERT INTO CONVENIO VALUES (1, "Convênio 3D");
INSERT INTO CONVENIO VALUES (2, "Convênio ValParaiso");
INSERT INTO CONVENIO VALUES (3, "Convênio Josias Mequetrefe");

INSERT INTO PACIENTE VALUES (1, "Matheus canela", 122003883, 49394195092, 1, 29112395, 2031);
INSERT INTO PACIENTE VALUES (2, "Roberto marcos", 465781111, 45034625040, 2, 59123029, 321);
INSERT INTO PACIENTE VALUES (3, "Leticia maria", 195917315, 65481327007, 3, 78130695, 734);
INSERT INTO PACIENTE VALUES (4, "Suzana alencar", 166710106, 86670036035, 1, 97574240, 832);
INSERT INTO PACIENTE VALUES (5, "Horácio carneiro", 113591342, 38825615051, 2, 33115039, 1065);
INSERT INTO PACIENTE VALUES (6, "Eliana jussara", 192652114, 22071036093, 1, 79843005, 1235);
	
INSERT INTO DOENCA VALUES (1, "Febre amarela");
INSERT INTO DOENCA VALUES (2, "Tuberculose");
INSERT INTO DOENCA VALUES (3, "AIDS");
INSERT INTO DOENCA VALUES (4, "HPV");
INSERT INTO DOENCA VALUES (5, "Doenca de chagas");
INSERT INTO DOENCA VALUES (6, "gripe suina (H1N1)");

INSERT INTO PACIENTE_DOENCAS VALUES (1, 1, "Febre e suadouro");
INSERT INTO PACIENTE_DOENCAS VALUES (1, 2, "Tosse, dores no torax, dificuldade em respirar e em se mover muito");
INSERT INTO PACIENTE_DOENCAS VALUES (1, 3, "Fragil a outras doenças, pega gripes constantemente");
INSERT INTO PACIENTE_DOENCAS VALUES (2, 6, "Tosse forte, febre, dores musculares, inchaco nas pernas e na garganta");
INSERT INTO PACIENTE_DOENCAS VALUES (3, 5, "Dificuldade em se exercitar, falta de folego, pressao baixa");
INSERT INTO PACIENTE_DOENCAS VALUES (4, 2, "Tosse recorrente, geracao de muco excessivo na falange");
INSERT INTO PACIENTE_DOENCAS VALUES (4, 6, "Febre e tosse cronica, feridas no interior da falange, vias respiratorias fragilizadas");
INSERT INTO PACIENTE_DOENCAS VALUES (5, 3, "Dificuldade em ganhar peso, febres constantes");
INSERT INTO PACIENTE_DOENCAS VALUES (6, 4, "Feridas cutaneas nas pernas e no quadril");

INSERT INTO MEDICO VALUES (102753982, "PR", "Jovinaldo josias", 468325268, 86431796047);
INSERT INTO MEDICO VALUES (227322472, "SP", "Regina pereto", 173873972, 22684268070);
INSERT INTO MEDICO VALUES (156170449, "PR", "Amatercio decio", 313331613, 85555597070);
INSERT INTO MEDICO VALUES (205618376, "SC", "Liana rodrigues", 212678425, 23830253052);
INSERT INTO MEDICO VALUES (190596405, "PR", "Dandara 3D",367679346, 15072847055);

INSERT INTO MEDICO_CONVENIO VALUES (1,227322472, "SP");
INSERT INTO MEDICO_CONVENIO VALUES (2,227322472, "SP");
INSERT INTO MEDICO_CONVENIO VALUES (3,227322472, "SP");
INSERT INTO MEDICO_CONVENIO VALUES (1,102753982, "PR");
INSERT INTO MEDICO_CONVENIO VALUES (2,102753982, "PR");
INSERT INTO MEDICO_CONVENIO VALUES (3,102753982, "PR");
INSERT INTO MEDICO_CONVENIO VALUES (3,156170449, "PR");
INSERT INTO MEDICO_CONVENIO VALUES (2,190596405, "PR");
INSERT INTO MEDICO_CONVENIO VALUES (2,205618376, "SC");
INSERT INTO MEDICO_CONVENIO VALUES (1,190596405, "PR");

INSERT INTO CONSULTA VALUES (1, 227322472, "SP", "2021-03-01 15:04:00", "Dores de cabeca, pressao baixa");
INSERT INTO CONSULTA VALUES (1, 102753982, "PR", "2014-12-11 18:54:24", "Sensacao de sono excessivo, suadouro, dores musculares");
INSERT INTO CONSULTA VALUES (1, 190596405, "PR", "2021-07-21 09:54:11", "Perda de peso, febre e tosse excessiva");
INSERT INTO CONSULTA VALUES (2, 227322472, "SP", "2021-03-01 14:10:30", "Tropecando bastante, senso de equilibrio debilitado, tosse cronica");
INSERT INTO CONSULTA VALUES (2, 102753982, "PR", "2005-11-21 10:10:30", "Febre e suadouro, pressao baixa");
INSERT INTO CONSULTA VALUES (2, 190596405, "PR", "1996-01-23 10:42:51", "Dores musculares, febre");
INSERT INTO CONSULTA VALUES (2, 205618376, "SC", "1990-01-30 20:15:27", "Pressao baixa, excesso de muco nas vias aereas");
INSERT INTO CONSULTA VALUES (3, 227322472, "SP", "2020-05-10 20:15:27", "Pressao baixa, caiu da escada");
INSERT INTO CONSULTA VALUES (3, 102753982, "PR", "2005-02-25 20:15:27", "Perdeu a chave de casa");
INSERT INTO CONSULTA VALUES (3, 156170449, "PR", "2021-07-31 20:15:27", "Pediu para nao registrar as ligacoes como consulta, pois o medico e seu marido");
INSERT INTO CONSULTA VALUES (4, 227322472, "SP", "2012-03-01 15:04:00", "Caiu da escada");
INSERT INTO CONSULTA VALUES (4, 102753982, "PR", "2016-12-11 18:54:24", "Caiu da escada novamente");
INSERT INTO CONSULTA VALUES (4, 190596405, "PR", "2019-07-21 09:54:11", "Caiu ao descer da calcada, nao tem mais escada em casa");
INSERT INTO CONSULTA VALUES (5, 227322472, "SP", "2009-07-21 19:52:11", "Trabalho de parto, registrado como constipacao");
INSERT INTO CONSULTA VALUES (5, 227322472, "SP", "2010-02-20 12:27:11", "Trabalho de parto novamente, individuo foi lembrado que era homem, registrado novamente como constipacao");
INSERT INTO CONSULTA VALUES (5, 227322472, "SP", "2011-12-02 18:32:11", "Trabalho de parto novamente, individuo foi lembrado que era homem novamente, registrado como constipacao");
INSERT INTO CONSULTA VALUES (6, 227322472, "SP", "2020-10-01 15:04:00", "Pele com cor alterada, recomendada a usar filtro solar");
INSERT INTO CONSULTA VALUES (6, 102753982, "PR", "2012-02-11 18:54:24", "Manchas na pele semelhante a suco de uva, recomendado tomar um banho");
INSERT INTO CONSULTA VALUES (6, 190596405, "PR", "2011-11-21 09:54:11", "Reclamacao de queda de cabelo, recomendado lavar o cabelo após corta-lo");

INSERT INTO EXAMES VALUES (1, "Analise em 3d");
INSERT INTO EXAMES VALUES (2, "Pesagem");
INSERT INTO EXAMES VALUES (3, "Checagem de credito no celular");
INSERT INTO EXAMES VALUES (4, "Checagem de passagens de onibus");
INSERT INTO EXAMES VALUES (5, "Teste do pezinho");
INSERT INTO EXAMES VALUES (6, "Teste de reflexo utilizando cadeiras");
INSERT INTO EXAMES VALUES (7, "Luta em octogono");
INSERT INTO EXAMES VALUES (8, "Teste do detran");

INSERT INTO CONSULTA_EXAMES VALUES (1, 102753982, "PR", "2014-12-11 18:54:24", 1, "Esta em 3 dimensoes");
INSERT INTO CONSULTA_EXAMES VALUES (1, 102753982, "PR", "2014-12-11 18:54:24", 2, "70 kg");
INSERT INTO CONSULTA_EXAMES VALUES (1, 102753982, "PR", "2014-12-11 18:54:24", 3, "apenas 15 reais, recomendado usar um orelhao preventivamente");
INSERT INTO CONSULTA_EXAMES VALUES (1, 102753982, "PR", "2014-12-11 18:54:24", 4, "Recomendado a usar uber, apenas 3 passagens");
INSERT INTO CONSULTA_EXAMES VALUES (1, 102753982, "PR", "2014-12-11 18:54:24", 5, "Reprovado");
INSERT INTO CONSULTA_EXAMES VALUES (1, 102753982, "PR", "2014-12-11 18:54:24", 6, "Reprovado, desmaiou ao receber a cadeirada");
INSERT INTO CONSULTA_EXAMES VALUES (1, 102753982, "PR", "2014-12-11 18:54:24", 7, "Perdeu no terceiro round");

INSERT INTO CONSULTA_EXAMES VALUES (2, 190596405, "PR", "1996-01-23 10:42:51", 8, "Reprovado por atraso");
INSERT INTO CONSULTA_EXAMES VALUES (2, 190596405, "PR", "1996-01-23 10:42:51", 2, "102 kg, recomendado cortar a coca e substituir por coca zero");
INSERT INTO CONSULTA_EXAMES VALUES (2, 190596405, "PR", "1996-01-23 10:42:51", 3, "apenas 2 reais, recomendado usar pombo correio");
INSERT INTO CONSULTA_EXAMES VALUES (2, 190596405, "PR" ,"1996-01-23 10:42:51", 4, "orientado a andar de bicicleta, 0 passagens");
INSERT INTO CONSULTA_EXAMES VALUES (2, 205618376, "SC", "1990-01-30 20:15:27", 5, "Reprovado");
INSERT INTO CONSULTA_EXAMES VALUES (2, 205618376, "SC", "1990-01-30 20:15:27", 6, "Aprovado com demerito, Utilizou o cotovelo para bloquear a cadeirada");
INSERT INTO CONSULTA_EXAMES VALUES (2, 205618376, "SC", "1990-01-30 20:15:27", 7, "Vitoria por nocaute");

INSERT INTO CONSULTA_EXAMES VALUES (3, 156170449, "PR", "2021-07-31 20:15:27", 8, "Reprovado por atraso");
INSERT INTO CONSULTA_EXAMES VALUES (3, 156170449, "PR", "2021-07-31 20:15:27", 2, "102 kg, recomendado cortar a coca e substituir por coca zero");
INSERT INTO CONSULTA_EXAMES VALUES (4, 102753982, "PR", "2016-12-11 18:54:24", 3, "apenas 2 reais, recomendado usar pombo correio");
INSERT INTO CONSULTA_EXAMES VALUES (4, 102753982, "PR" ,"2016-12-11 18:54:24", 8, "orientado a andar de bicicleta, 1 passagem");
INSERT INTO CONSULTA_EXAMES VALUES (6, 227322472, "SP", "2020-10-01 15:04:00", 5, "Reprovado por desistencia");
INSERT INTO CONSULTA_EXAMES VALUES (6, 227322472, "SP", "2020-10-01 15:04:00", 6, "Aprovado com demerito, Utilizou o cotovelo para bloquear a cadeirada");
INSERT INTO CONSULTA_EXAMES VALUES (6, 227322472, "SP", "2020-10-01 15:04:00", 7, "Vitoria por nocaute");

/*INFORMAÇÃO 1 envolvendo 2 tabelas - Número de pacientes por convênio*/
/*INFORMAÇÃO 2 envolvendo 3 tabelas - Maior quantidade de exames POR médico POR unidade federal*/
/*INFORMAÇÃO 3 envolvendo Operação de diferença entre conjuntos - Quantidade de exames que NÃO foram seguidos de uma consulta exame*/

/*Implementação da informação 1*/
SELECT convenio.nome, count(*)
from convenio
INNER JOIN paciente on paciente.codigo_convenio = convenio.codigo_convenio
group by convenio.nome
order by count(*) desc;
