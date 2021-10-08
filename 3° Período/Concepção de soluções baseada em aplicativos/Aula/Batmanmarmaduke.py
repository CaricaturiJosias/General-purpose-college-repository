class Endereco:
    def __init__(self,r,num,c,e,cep):
        self.rua    = r
        self.numero = num
        self.cidade = c
        self.estado = e
        self.__CEP  = cep
    def get_cep(self):
        return self.__CEP
class Pessoa:
    def __init__(self,n,end,i,cpf,nick):
        self.__nome     = n
        self.__endereço = end
        self.__idade    = i
        self.__CPF      = cpf
        self.nickname    = nick
    def get_nome(self):
        return self.__nome
    def get_endereço(self):
        return self.__endereço
    def get_CPF(self):
        return self.__CPF
    def set_nome(self,novo_nome):
        self.__nome = novo_nome
    def get_idade(self):
        return self.__idade
#criar objetos
localdoesconderijo = Endereco('Alcapao josias',811,'Curitiba','Paraná',12332-231)
Batman = Pessoa('Marmaduke','Joao ribas','12','103.123.123.123-12','JooJ')

print('Rua: ',localdoesconderijo.rua,', n°: ',localdoesconderijo.numero,'Cep: ',localdoesconderijo.get_cep())
print('Nome: ',Batman.get_nome(),'Idade: ',Batman.get_idade())