class Documento:
    def __init__(self,texto,autor,*lista_daut):
        self.autor                = autor
        self.texto                = texto
        self.lista_autores        = list()
        self.lista_autores.append(autor)
        for a in lista_daut:
            self.lista_autores.append(a)
    def get_lista_autores(self):
        return self.lista_autores
    def add_autor(self,novo_autor):
        self.lista_autores.append(novo_autor)
    def get_texto(self):
        return self.texto
class Livro(Documento):
    def __init__(self,titul,texto,autor,*lista_daut):
        super().__init__(texto,autor,*lista_daut)
        self.titulo          = titul
        self.__numero_copias = 0
    def get_numero_copias(self):
        return self.__numero_copias
    def add_copia(self,nova_copia):
        self.__numero_copias += 1


livro1 = Livro('Vento','Esta ventando','Ar','Poluicao')
print(livro1.get_texto())


class Email(Documento):
    anexos = list()
    def __init__(self, assunto, destinatario, texto, autor,
                 *demais_destinatarios,**anexos):
        super().__init__(texto,autor)
        self.assunto       = assunto
        self.destinatarios = list()
        self.destinatarios.append(destinatario)
        for a in demais_destinatarios:
            self.destinatarios.append(a)
        self.anexos        = list()
        if 'anexos' in anexos:
            for a in anexos['anexos']:
                self.anexos.append(a)      

email1 = Email('Ar','Todo mundo','Saas','Todo mundo mesmo','Joaozinho', anexos = ['Joao','Corona'])
print(email1.anexos)


class Tese(Documento):
    def __init__(self,ncaps,hip,texto,autor,*lista_daut,**lista_abrev):
        super().__init__(texto,autor,*lista_daut)
        self.lista_abreviações = list()
        if 'abrev' in lista_abrev:
            for a in lista_abrev['abrev']:
                self.lista_abreviações.append(a)
        self.numero_capitulos  = ncaps
        self.__hipotese        = hip    
    def get_hipotese(self):
        return self.__hipotese
    def set_hipotese(self,nova_hipotese):
        self.__hipotese = nova_hipotese

tese1 = Tese(12,'hipotese saas','Jamelao','Joao','Maria',abrev = ['jooj','Jam','Mam'])
print(tese1.get_lista_autores())
print(tese1.get_hipotese())
tese1.set_hipotese('Talvez siis, talvez soos')
print(tese1.get_hipotese())
        