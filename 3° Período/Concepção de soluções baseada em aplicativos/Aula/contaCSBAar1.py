class Contabancaria(object):
    def __init__(self,nom, **lista):
        self.__nome       = nom
        self.__saldoini   = lista.pop('saldoinicial', 0)
        self.__saldoatual = self.__saldoini
        self.__agencia    = lista.pop('conta',0000)
        self.__numero     = lista.pop('num', 0000-0)
    def sacar(self,valor):
        self.__saldoatual -= valor
    
    def deposito(self,*val):
        for valor in val:
            self.__saldoatual += valor
    def trocarnome(self,nomenovo):
        self.__nome = nomenovo
    
    def obtersaldo(self):
        return self.__saldoatual
    
    def obternome(self):
        return self.__nome
    
    def obternumero(self):
        return self.__numero
    
    def obteragencia(self):
        return self.__agencia

class Cliente():
    def __init__(self,nom,**lista):
        self.__nome   = nom
        self.__contas = dict()
        self.__cpf    = lista.pop('documento','000.000.000-0') 
        
    def Adicionarconta(self, novaConta):
        self.contas[novaConta.obternome()] = novaConta
    def Depositar(self,nomeConta,valor):
        if nomeConta in self.contas:
            self.contas[nomeConta].Depositar(valor)
        else:
            return 'conta inexistente'
    def Obtersaldo(self,nomeConta):
        if nomeConta in self.contas:
            return self.contas[nomeConta].obtersaldo()
        else:
            return 'Conta inexistente'
conta = Contabancaria('Alabamo', conta = '1287', saldoinicial = 54444, num = '11111-2')
conta.deposito(14,6,123,67754,111110)
print(conta.obtersaldo())
conta.sacar(int(input('insira valor para saque: ')))
print(conta.obtersaldo())
print('Agencia: '+conta.obteragencia())
santander = Contabancaria('Jamelao', saldoinicial = 123)
santander.obtersaldo()

Cliente1 = Cliente('Josias')
Cliente1.Adicionarconta(Contabancaria('Alabamo'))
Cliente1.Depositar('Alabamo',200)
Cliente1.Depositar('joaosabadao',300)
Cliente1.Obtersaldo('Alabamo')
Cliente1.Obtersaldo('joaosabadao')