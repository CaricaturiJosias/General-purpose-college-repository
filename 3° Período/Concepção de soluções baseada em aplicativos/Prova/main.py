from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.core.window import Window
import sqlite3

class Principal(BoxLayout):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.id_edicao = 0
    
    def limpa_Campos(self):
        self.ids.nome_aluno.text =  ''
        self.ids.curso_aluno.text =  ''
        self.ids.idade_aluno.text =  ''
    
    def preenche_Campos(self,id_busca,nome,curso,idade):
        self.ids.nome_aluno.text = str(nome)
        self.ids.curso_aluno.text = str(curso)
        self.ids.idade_aluno.text = str(idade)
        
        
    def busca_aluno(self):
        conn = sqlite3.connect('aluno.db')
        crs = conn.cursor()
        crs.execute("""
                    SELECT * FROM aluno 
                    WHERE id LIKE '%{}%'
                """ .format(self.ids.id_busca.text))
        
        resultado = crs.fetchone()
        conn.close()
        if resultado == None:
            self.ids.mensagem.text = '[b]INEXISTENTE[/b]'
            self.limpa_Campos()
        else: 
            self.ids.mensagem.text = 'ENCONTRADO'
            self.preenche_Campos(resultado[0],resultado[1],resultado[2],resultado[3])
            
    def Salvar(self):
        conn = sqlite3.connect('aluno.db')
        crs = conn.cursor()
        crs.execute("""
                    UPDATE aluno SET
                    nome = ?, curso = ?, curso = ?
                    WHERE id = ?""",(self.ids.nome_aluno.text,self.ids.curso_aluno.text,self.ids.idade_aluno.text,self.ids.id_busca.text)
        )
        conn.commit()
        conn.close() 
        self.ids.mensagem.text = 'ATUALIZADO'          

class ProvaApp(App):
    def build(self):
        Window.size = (300,400)
        return Principal()
ProvaApp().run()
