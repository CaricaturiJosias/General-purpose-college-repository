class Artista:
    def __init__(self,nome,nacionalidade):
        self.nome          = nome
        self.nacionalidade = nacionalidade

artista1 = Artista('Revitanos','Brasileiro')
print('A nacionalidade de ',artista1.nome,' é ',artista1.nacionalidade)

class Ator(Artista):
    def __init__(self,data_inicio,nome,nacionalidade,filmes):
        super().__init__(nome,nacionalidade)
        self.data_inicio = data_inicio
        self.filmes      = filmes
        
class Filme:
    def __init__(self,titulo,ano,descricao,genero):
        self.__titulo    = titulo
        self.ano       = ano
        self.descricao = descricao
        self.genero    = genero
    def get_titulo(self):
        return self.__titulo

filme1 = Filme('Jango preso','2001','Prenderam o jango por excesso de crime','Acao')
filme2 = Filme('Rambo','1997','Rambo quebra tudo, parece o hulk','Aventura')
filme3 = Filme('50 tons de crime','2014','Revitanos entra na soloQ','Terror')

ator1 = Ator('13/04/1997','Revitanos','Brasileiro',[filme1,filme2,filme3])

for filmes in ator1.filmes:
    print(ator1.nome,' atuou em ',filmes.get_titulo())
    
     
        