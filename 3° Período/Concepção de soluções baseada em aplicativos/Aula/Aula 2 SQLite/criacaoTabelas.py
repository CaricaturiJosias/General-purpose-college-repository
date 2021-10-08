import sqlite3
from sqlite3 import Error

def criacao_conexao(bdfile):
    conn = None
    try:
        conn = sqlite3.connect(bdfile)
        print(sqlite3.version)
        return conn
    except Error as e:
        print(e)
    return conn

def criacao_tabela(conn,sql_criacao):
    try:
        crs=conn.cursor()
        crs.execute(sql_criacao)
    except Error as e:
        print(e)
        
def main():
    database = r"PROJETOS.db"
    sql_projeto = """CREATE TABLE IF NOT EXISTS projeto(
                                id INTEGER PRIMARY KEY,
                                nome TEXT NOT NULL,
                                dt_inicio TEXT,
                                dt_fim    TEXT
    );"""
    
    sql_tarefa  = """CREATE TABLE IF NOT EXISTS tarefa(
                                id INTEGER PRIMARY KEY,
                                nome TEXT NOT NULL,
                                prioridade INTEGER,
                                status INTEGER NOT NULL,
                                id_projeto_FK INTEGER,
                                dt_inicio TEXT NOT NULL,
                                dt_fim    TEXT NOT NULL,
                                FOREIGN KEY(id_projeto_FK) REFERENCES projeto(id)
    );"""
    
    conn = criacao_conexao(database)
    if conn is not None:
        criacao_tabela(conn,sql_projeto)
        criacao_tabela(conn,sql_tarefa)
        print('Conexão e criação de tabelas realizadas com sucesso !!! ')
    else:
        print('Erro ! Conexão não realizada!!!')
if __name__ == '__main__':
    main()