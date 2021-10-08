### construir a classe que é superclasse de todas
class Documento:
    def __init__(self,data,autor,*lista_autores):
        self.data         = data
        self.lista_autores = list()
        self.lista_autores.append(autor)
        for a in lista_autores:
            self.lista_autores.append(a)
    def get_lista_autores(self):
        return self.lista_autores
    def add_autor(self,novo_autor):
        self.lista_autores.append(novo_autor)


#========== Documento ===================================================================================
documento1 = Documento('19/09/1850','Rafa Moreira','Rafinha Bastos','Pedro Álvares Cabral')
print('Autor(es): ',documento1.get_lista_autores())
      
### Subclasse de documento

class Livro(Documento):
    def __init__ (self, titulo, data, autor, *lista_autores):
        super().__init__(data,autor,*lista_autores)
        self.titulo        = titulo
        self.__numero_copias = 0
    def get_numero_copias(self):
        return self.__numero_copias
    def add_numero_copias(self):
        self.__numero_copias += 1


#========= Livro ========================================================================================
livro1 = Livro('Revitanos16','14/06/2001','Arenansko')
livro1.add_autor('Joao Hatukquei')
print(livro1.lista_autores)
print(livro1.titulo)

"""
Emails só tem 1 autor, mas podem ter vários destinatários (é obrigatório ter 1), sera o *
anexos não são obrigatórios, mas podem ser vários (como é a segunda lista será **),
terá como palavra chave ['anexo']
"""
class Email(Documento):
    def __init__(self, autor, assunto, data, destinatario, *destinatarios, **anexos):
        super().__init__(data,autor)
        self.assunto      = assunto
        self.data         = data
        self.autor        = autor
        self.destinatario = list()
        self.destinatario.append(destinatario)
        for a in destinatarios:
            self.destinatario.append(a)
        self.anexos       = list()
        if 'anexo' in anexos:
            for a in anexos['anexo']:
                self.anexos.append(a)

#========= Email ========================================================================================
email1 = Email('Joaozin','Conexão josias','27/03/2020','Sala inteira','Professores da turma',anexo = ['Livro '+livro1.titulo,'O mundo é dos net'])
print('Autor:',email1.autor)
print('Assunto:',email1.assunto)
print('Data:',email1.data)
print('Anexos:',email1.anexos)