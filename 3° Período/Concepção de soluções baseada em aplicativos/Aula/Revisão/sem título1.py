class Livros:
    def __init__(self, **dados):
        self.isbn    = dados['isbn']
        self.titulo  = dados['titulo']
        self.autor   = dados['autor']
        self.editor  = dados['editor']
        self.paginas = dados['paginas']
        self.preco   = dados['preco']
        self.copias  = dados['copias']
    def em_estoque(self):
        return self.copias > 0
    def em_vendas(self):
        if self.copias > 0:
            self.copias -= 1
            print('Vendido!')
        else:
            print('Nao ha copias disponiveis')
Vinicius8 = Livros(isbn='123',titulo='revitanos16',autor='joao',editor='sabadao',paginas='30',preco='30k',copias=2)
Vinicius8.em_vendas()
if Vinicius8.em_estoque() == True:
    print('Ha copias no estoque!')
else:
    print('Nao ha copias no estoque')
class Cliente:
    def __init__ (self,nome,cpf,*livros):
        self.nome   = nome
        self.__cpf  = cpf
        self.__livros = list()
        for l in livros:
            self.__livros.append(l)
    def get_listaLivros(self):
        return self.__livros
Bereu = Cliente('BereuJogaFacil','123',Vinicius8)
for livro in Bereu.get_listaLivros():
    print(livro.titulo)