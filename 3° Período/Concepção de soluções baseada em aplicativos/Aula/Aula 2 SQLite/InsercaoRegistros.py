import sqlite3
from sqlite3 import Error

def criacao_conexao(bdfile):
    conn = None
    #usamos try porque pode dar erro
    try: 
        #conecta um arquivo sql
        conn = sqlite3.connect(bdfile)
        #imprime a versão do sql
        print(sqlite3.version)
        return conn
    except Error as e:
        print(e)
    return conn 

def registros_projeto(conn,projeto):
    sql = """ INSERT INTO projeto(nome,dt_inicio,dt_fim)
                    VALUES(?, ?, ?);"""
    crs = conn.cursor()
    crs.execute(sql,projeto)
    return crs.lastrowid

def registros_tarefa(conn,tarefa):
    sql = """ INSERT INTO tarefa(nome,prioridade,status,id_projeto_FK,dt_inicio,dt_fim)
                    VALUES(?, ?, ?, ?, ?, ?);"""
    crs = conn.cursor()
    crs.execute(sql,tarefa)
    return crs.lastrowid
def obtem_id_projeto(conn):
    sql = "SELECT id FROM projeto;"
    crs = conn.cursor()
    ids = list()
    ids.append(crs.execute(sql))
    return ids
# inserção de dados pelo usuário a serem cadastrados nas respectivas tabelas do banco de dados
class Projeto:
    def __init__(self,nome, dt_inicio, dt_fim):
        self.nome      = nome
        self.dt_inicio = dt_inicio
        self.dt_fim    = dt_fim

class Tarefa:
    def __init__(self, nome, prioridade, status, id_projeto_FK, dt_inicio, dt_fim):
        self.nome          = nome
        self.prioridade    = prioridade
        self.status        = status
        self.id_projeto_FK = id_projeto_FK
        self.dt_inicio     = dt_inicio
        self.dt_fim        = dt_fim
        
def main():
    database = r"PROJETOS.db"
    print('============= Bem vindo, O que deseja? ============='
    '\n    1) Criar novo projeto'
    '\n    2) Acessar projeto existente'
    '\n     Insira sua opcao: ')
    escolha = int(input(''))
    if escolha == 1:
        conn = criacao_conexao(database)
        with conn:
          # tela para inserção de dados do projeto fornecidos pelo usuário
          print('\n\n==== Digite os dados do projeto ====')
          nvp = Projeto(
                  nome      = input('Nome do projeto: '),
                  dt_inicio = input('Data de início  (aaaa/mm/dd): '),
                  dt_fim    = input('Data de término (aaaa/mm/dd): ')
                  )
          projeto = (nvp.nome, nvp.dt_inicio, nvp.dt_fim)
          idProj  = registros_projeto(conn, projeto)
          
          Qtarefas = int(input('\nEscolha quantas tarefas deseja colocar: '))
          i = 0
          while i < Qtarefas:
              # tela para inserção de dados do projeto fornecidos pelo usuário
              print('\n\n==== Digite os dados da Tarefa ====')
              nvt = Tarefa(
                      nome          = input('Nome da tarefa: ')              ,
                      prioridade    = int(input('Prioridade do projeto: '))  ,
                      status        = int(input('Status: '))                 ,
                      id_projeto_FK = idProj                                 ,
                      dt_inicio     = input('Data de início  (aaaa/mm/dd): '),
                      dt_fim        = input('Data de término (aaaa/mm/dd): ')
                      )
              tarefa = (nvt.nome, nvt.prioridade, nvt.status, nvt.id_projeto_FK, nvt.dt_inicio, nvt.dt_fim)
              idProj  = registros_tarefa(conn, tarefa)      
              print('\n\n')  
              i += 1
    elif escolha == 2:
        #obtem os ids dos projetos disponiveis
        conn = criacao_conexao(database)
        idprojeto = int(input('Insira o ID do projeto que deseja acessar (números arábicos (ex: 1, 2,3...): '))    
        Qtarefas = int(input('\nNumero de tarefas que deseja inserir: ' ))
        i = 0
        while i < Qtarefas:
            print('\n\n==== Digite os dados da Tarefa ====')
            nvt = Tarefa(
                        nome          = input('Nome da tarefa: ')              ,
                        prioridade    = int(input('Prioridade do projeto: '))  ,
                        status        = int(input('Status: '))                 ,
                        id_projeto_FK = int(idprojeto)                         ,          
                        dt_inicio     = input('Data de início  (aaaa/mm/dd): '),
                        dt_fim        = input('Data de término (aaaa/mm/dd): ')
                    )
            tarefa = (nvt.nome, nvt.prioridade, nvt.status, nvt.id_projeto_FK, nvt.dt_inicio, nvt.dt_fim)
            idProj  = registros_tarefa(conn, tarefa) 
            i += 1
if __name__ == '__main__':
    main()