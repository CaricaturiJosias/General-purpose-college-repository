class Livros:
    def __init__(self, isbn, titulo, autor, editor, paginas, preco, copias):
        self.isbn    = isbn
        self.titulo  = titulo
        self.autor   = autor
        self.editor  = editor
        self.paginas = paginas
        self.preco   = preco
        self.copias  = copias
    def ver_estoque(self):
        return (self.copias > 0)
    def vender_livro(self):
        if self.copias > 0:
            self.copias -= 1
            return "Vendido!"
        else:
            return "Livro indisponível"
    def get_titulo(self):
        return self.titulo
livro1 = Livros(123,1,'sabadao',1,3,2,1)
livro2 = Livros(123,'jaja',3,2,1,3,21)
print (livro1.ver_estoque())
print (livro1.vender_livro())
print (livro1.vender_livro())

class Cliente :
    def __init__(self, nome, cpf, **livros):
        self.nome = nome
        self.__cpf = cpf
        self.__lista_livros = list()
        for cada1 in livros:
            self.__lista_livros.append(livros)
    def get_lista_livros(self):
        for livro in self.__lista_livros:
            return livro
joao = Cliente('joao', 123312130-12,livro = [livro1.titulo, livro2.titulo])
print (joao.get_lista_livros())
