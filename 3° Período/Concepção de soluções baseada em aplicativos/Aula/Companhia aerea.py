class Voo:
    def __init__(self,num,orig,dest):
        self.__numero  = num
        self.__origem  = orig
        self.__destino = dest
    def get_origem(self):
        return self.__origem
    def get_destino(self):
        return self.__destino
    def get_numero(self):
        return self.__numero
class Companhia_aerea:
    def __init__(self,cnpj,nom,qntd,lista):
        self.__CNPJ           = cnpj
        self.__nome             = nom
        self.numero_aeronaves = qntd
        self.__lista_voos       = lista
    def get_nome(self):
        return self.__nome
    def get_lista_voos(self):
        return self.__lista_voos
    def add_voo(self,novo_voo):
        self.__lista_voos.append(novo_voo)

Jatodoneymar  = Voo(1,'Travessia elevada','Disney')
Jatodomarrone = Voo(2,'Pedreira','Travessão')
Jatodolula    = Voo(3,'Rodeio','Longe')
Jatodogandhi   = Voo(4,'Churrasco','Rotatória')

Companhia  = Companhia_aerea('12.123.123/7001-01','Restart',15,[Jatodoneymar,Jatodomarrone,Jatodolula])
Companhia2 = Companhia_aerea('46.357.674/2002-23','Tang',160,[Jatodogandhi])

for voos in Companhia.get_lista_voos():
    print(Companhia.get_nome(),'É responsável por: ',voos.get_numero())

JatodoMeirelles = Voo(5,'Praiera','Futera')

Companhia2.add_voo(JatodoMeirelles)

for voos in Companhia2.get_lista_voos():
    print(Companhia2.get_nome(),' é responsável por:',voos.get_numero())