class Funcionario:
    def __init__(self,nome,cpf,salarioBase):
        self.nome          = nome
        self.__cpf         = cpf
        self.__salariobase = salarioBase
    def Get_cpf(self):
        return self.__cpf
    def Get_salario(self):
        return self.__salariobase

class Gerente(Funcionario):
    def __init__(self,nome, cpf, salarioBase, senha,*gerenciadosLista):
        super().__init__(nome, cpf, salarioBase)
        self.__senha = senha
        self.gerenciados = list()
        for g in gerenciadosLista:
            self.gerenciados.append(g)
    def Autencita_senha(self,tentativaSenha):
        return tentativaSenha == self.__senha
    def Adiciona_Gerenciado(self,NovoGerenciado):
        self.gerenciados.append(NovoGerenciado)
        print('Funcionarios gerenciados:')
        for g in self.gerenciados:
            print (g.nome)

Renansko = Funcionario('Renan','2937819283','2k')
BereuJogaFacil = Gerente('Bereu', '2345678','30k','bereuzin',Renansko)
Renansko.Get_cpf()
Renansko.Get_salario()
Renansko.nome

if BereuJogaFacil.Autencita_senha('bereuzin') == True:
    print('A senha esta correta')
else: 
    print('iiiiiiiiiii')
Joaozin = Funcionario('Joao','2345678','2.5k')
BereuJogaFacil.Adiciona_Gerenciado(Joaozin)