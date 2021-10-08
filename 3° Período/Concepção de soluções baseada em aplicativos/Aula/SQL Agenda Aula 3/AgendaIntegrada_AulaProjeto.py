import sqlite3

class Contatos:
    def __init__(self,ids,nome,telefone,email):
        self.id       = ids
        self.nome     = nome
        self.telefone = telefone
        self.email    = email
        
class BancodeDadosContatos:
    def cadastrarContato(self,novoContato):
        # cria objeto conn para conexão
        conn   = sqlite3.connect('AGENDA.db')
        # cria cursor da classe cursor do sqlite para poder executar o SQL        
        cursor = conn.cursor()
        cursor.execute("""
                       INSERT INTO contatos(id, nome, telefone,email)
                       VALUES (?,?,?,?)
                       """,
                       (novoContato.id,novoContato.nome,novoContato.telefone,novoContato.email)
                )
        # grava no banco de dados (atualiza)        
        conn.commit()
        # fecha conexão com banco
        conn.close()

    def listarContatosPorNome(self,parteDoNome):
        conn   = sqlite3.connect('AGENDA.db')
        cursor = conn.cursor()
        cursor.execute("""
                       Select * 
                       FROM contatos
                       WHERE nome LIKE '%{}%'
                       """.format(parteDoNome)
                       )
        listagem = list()
        for registro in cursor.fetchall():
            c = Contatos(registro[0],registro[1],registro[2],registro[3])
            listagem.append(c)
        conn.close() 
        if listagem != None:
            return listagem
        else:
            return None
        """
            Aqui o comando SELECT deve ser utilizado
            para pesquisar TODOS os registros que tiverem como parte do nome
            a string fornecida pelo usuário
            na tabela: contatos
            de uma base de dados chamada AGENDA.db"""
        # WHERE nome LIKE '%parteDoNome%'
        # retorna uma lista de nomes
        
        # usar o cursor.fetchall() # traz da tabela todos os registros que satisfazem a condição do WHERE
        
        
    def listarContatosPorId(self,id):
        """Aqui o comando SELECT deve ser utilizado
            para pesquisar UM registro que tiver como ID o número
            fornecido pelo usuário
            na tabela: contatos
            de uma base de dados chamada AGENDA.db"""
        #garante acesso ao sql
        conn   = sqlite3.connect('AGENDA.db')
        #garante a interação com o sql
        cursor = conn.cursor()
        #interage com o sql
        cursor.execute("""
                       SELECT *
                       FROM contatos
                       WHERE id = ?""",(str(id),)
                )
        #pega um dado do sql
        registro = cursor.fetchone()   # lista um único registro            
        #se desconecta do sql
        conn.close()
        #testa o dado pego
        if registro != None:
            return Contatos(registro[0],registro[1],registro[2],registro[3])
        else:
            return None
       
    def atualizarContato(self,dadosContato):
        """ Aqui o comando UPDATE deve ser utilizado
            para alterar algum campo de um registro, conforme ID
            fornecido pelo usuário
            na tabela: contatos
            de uma base de dados chamada AGENDA.db"""
        
        conn  = sqlite3.connect('AGENDA.db')
       
        cursor= conn.cursor()
        
        cursor.execute("""
                       UPDATE contatos
                       SET nome = ?, telefone = ?, email = ?
                       WHERE id = ?""",
                       (dadosContato.nome, dadosContato.telefone,dadosContato.email,dadosContato.id)
                       # NESSA MESMA ORDEM em que está sendo usado cada campo no
                       # UPDATE
                       )
        conn.commit()
        conn.close()
       
    def excluirContato(self,contato):
        """ Aqui o comando DELETE deve ser utilizado
            para apagar (excluir ou eliminar) um registro, conforme ID
            fornecido pelo usuário
            na tabela: contatos
            de uma base de dados chamada AGENDA.db"""
        conn  = sqlite3.connect('AGENDA.db')
        cursor= conn.cursor()
        cursor.execute("""
                       DELETE
                       FROM contatos
                       WHERE id = ?""",(str(contato.id),)
                       )
        conn.commit()
        conn.close()
        
def telaPrincipal():
    print('\n'*50)
    print('****** ESCOLHA OPÇÃO ******')
    print('<1> INCLUIR   REGISTRO')
    print('<2> ALTERAR   REGISTRO')
    print('<3> CONSULTAR REGISTRO - por ID')
    print('<4> CONSULTAR REGISTRO - por NOME')
    print('<5> EXCLUIR   REGISTRO')
    print('<0> SAIR  DO  PROGRAMA')        
    print('***************************')        

def main():
    db = BancodeDadosContatos()
    while True:
        telaPrincipal()        
        op = int(input('Digite opção desejada: '))
        while op not in range(6):
            op = int(input('ERRO!!!\nDigite opção desejada: '))
        if op == 0:
            print('Encerrando programa......')
            break
        elif op == 1:
            contato = Contatos(
                    None,
                    nome      = input('Nome.......: '), 
                    telefone  = input('Telefone...: '),
                    email     = input('email......: '),
                    )
            db.cadastrarContato(contato)
        elif op == 2:
            #pass
            # ALTERAR REGISTRO
            id_busca = int(input('Digite o ID do contato a ser alterado: '))
            if  db.listarContatosPorId(id_busca) == None:
                print('ID inexistente!!')
            else:
                contato = db.listarContatosPorId(id_busca)
                print('ID..............: ',contato.id)
                print('Nome............: ',contato.nome)
                print('Telefone........: ',contato.telefone)
                print('email...........: ',contato.email)
                opA = input('O que deseja alterar: <N>ome, <T>elefone ou <E>mail? ')
                while opA.upper() not in 'NTE':
                    print('Escolha uma das opções: N, T ou E !!')
                    opA = input('O que deseja alterar: <N>ome, <T>elefone ou <E>mail? ')
                if opA.upper() == 'N':
                    contato.nome = input('Novo Nome...: ')
                elif opA.upper() == 'T':
                    contato.telefone = input('Novo telefone...: ')                    
                else:
                    contato.email = input('Novo e-mail...: ')
                db.atualizarContato(contato)
            input('Tecle <ENTER> para continuar....')    

        elif op == 3:
            # pass
            # CONSULTAR POR ID
            id_busca = int(input('Digite o ID do contato a ser exibido: '))
            #pega o return do def e olha o que veio
            if  db.listarContatosPorId(id_busca) == None:
                print('ID inexistente!!')
            else:
                contato = db.listarContatosPorId(id_busca)
                print('ID..............: ',contato.id)
                print('Nome............: ',contato.nome)
                print('Telefone........: ',contato.telefone)
                print('email...........: ',contato.email)
            input('Tecle <ENTER> para continuar....')    
        elif op == 4:
            # CONSULTAR POR PARTE DO NOME
            nome_busca = input('Digite a parte do nome do contato a ser exibido: ')
            #pega o return no def e olha o que veio
            if db.listarContatosPorNome(nome_busca) == None:
                print('O nome não existe ou esta escrito incorretamente!')
                print(nome_busca)
            else:
                print(nome_busca)
                contato = db.listarContatosPorNome(nome_busca)
                for c in contato:
                    print('Contato:')
                    print('ID.............: ',(c.id))
                    print('Nome............: ',(c.nome))
                    print('Telefone........: ',(c.telefone))
                    print('email...........: ',(c.email))
            input('Tecle <Enter> para continuar....')
        else:
            #pass
            # APAGAR OU EXCLUIR REGISTRO
            id_busca = int(input('Digite o ID do contato a ser excluído: '))
            if  db.listarContatosPorId(id_busca) == None:
                print('ID inexistente!!')
            else:
                contato = db.listarContatosPorId(id_busca)
                print('ID..............: ',contato.id)
                print('Nome............: ',contato.nome)
                print('Telefone........: ',contato.telefone)
                print('email...........: ',contato.email)
                opE = input('Deseja apagar esse contato(S/N)? ')
                while opE.upper() not in 'SN':
                    opE = input('ERRO!!\nDeseja apagar esse contato(S/N)? ')
                if opE.upper() == 'S':
                    db.excluirContato(contato)
                else:
                    print('Nenhum contato foi apagado!!!')
            input('Tecle <ENTER> para continuar....')    
if __name__ == '__main__':
    main()        
        
        
        