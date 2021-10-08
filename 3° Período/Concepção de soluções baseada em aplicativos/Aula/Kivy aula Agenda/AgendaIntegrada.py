import sqlite3

class Contatos(object):
    def __init__(self, id, nome, telefone, email):
        self.id = id
        self.nome = nome
        self.telefone = telefone
        self.email = email
    
class BancodeDadosContatos:    
    def CadastrarContato(self, novocontato):
        conn = sqlite3.connect('agenda.db')
        cursor = conn.cursor()
        
        cursor.execute("""
                INSERT INTO contatos (id, nome, telefone, email)
                VALUES (?, ?, ?, ?)
                """,
                (novocontato.id, novocontato.nome, novocontato.telefone, novocontato.email)
                )
        
        conn.commit()
        conn.close()
        
        #print('Dados do contato cadastrados com sucesso!!  :-)') 
        #input('Digite uma tecla para continuar...')

    def ListarContatosPorNome(self, parteNome):
        conn = sqlite3.connect('agenda.db')
        cursor = conn.cursor()

        cursor.execute("""
                       SELECT * 
                       FROM contatos
                       WHERE nome LIKE '%{}%'
                """ .format(parteNome)
                )
        
        #print("Listagem dos registros cadastrados \n")
        #print("Codigo | Nome | Telefone | Email")
        #for registro in cursor.fetchall():
        #    print(registro)
        listagem = list()
        for registro in cursor.fetchall():
            c = Contatos(registro[0],registro[1],registro[2],registro[3])
            listagem.append(c)
        
        conn.close()
        
        return listagem
    
        #input('Digite uma tecla para continuar...')
   
    def AtualizarContato(self, dadosContato):
        conn = sqlite3.connect('agenda.db')
        cursor = conn.cursor()
        cursor.execute("""
               UPDATE contatos
               SET nome = ?, telefone = ?, email = ?
               WHERE id = ? """, 
               (dadosContato.nome, dadosContato.telefone, dadosContato.email, dadosContato.id)
        )

        conn.commit()
        conn.close()
        #print('Dados do contato atualizados com sucesso.')
        #input('Digite uma tecla para continuar...')
        

    def ExcluirContato(self, contato):
        conn = sqlite3.connect('agenda.db')
        cursor = conn.cursor()
        cursor.execute("DELETE FROM contatos WHERE id = ?", (str(contato.id),))
        
        conn.commit()
        conn.close()
        
        #print ('Registro excluído com sucesso')
        #input('Digite uma tecla para continuar...')
    
    def BuscaContatoPorId(self, id):
        conn = sqlite3.connect('agenda.db')
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM contatos WHERE id = ?", (str(id),))
        
        registro = cursor.fetchone()
        conn.close()

        if registro != None:
            return Contatos(registro[0], registro[1], registro[2], registro[3])
        else:
            return None
        
"""class Utilidades:
    def LimparTela(self):
        print('\n' * 30)

util = Utilidades()
agendaIntegrada = BancodeDadosContatos()

opcao = ' '
while (opcao != 0):
    util.LimparTela()
    print('Sistema de Agenda')
    print('1 - Cadastrar Contato')
    print('2 - Listar os Contatos')
    print('3 - Atualizar o Contato')
    print('4 - Excluir o contato')
    print('0 - Encerrar o sistema')
    opcao = int(input('Escolha a opção desejada: '))        
        
    if opcao == 1:
        print('1 - Cadastrar Contato')
        print('Digite abaixo os dados do contato: ')
        novoCtt = Contatos(
                id = None,
                nome = input('Nome do contato: '),
                telefone = input('Telefone: '),
                email = input('E-mail: ')
                )

        agendaIntegrada.CadastrarContato(novoCtt)
        
    elif opcao == 2:
        print('2 - Listar os Contatos') 
        buscaCtt = Contatos(
                id = None,
                nome = input('Nome do contato: '),
                telefone = None,
                email = None
                )
        agendaIntegrada.ListarContatosPorNome(buscaCtt.nome)
             
    elif opcao == 3:
        print('3 - Atualizar o Contato')
        altContato = Contatos(
                id = input('Digite o código do contato para alterar (Id): '),
                nome = input ('Novo nome do contato: '),
                telefone = input ('Novo telefone do contato: '),
                email = input ('Novo email do contato: ')
                )

        agendaIntegrada.AtualizarContato(altContato)
    
    elif opcao == 4:
        print('4 - Excluir o contato')
        delCtt = Contatos(
                id = int(input('ID do contato: ')),
                nome = None,
                telefone = None,
                email = None
                )
         
        agendaIntegrada.ExcluirContato(delCtt.id)
    
    elif opcao == 0:
        print('0 - Encerrar o sistema')
        
"""        