from kivy.app import App
from kivy.core.window import Window
from kivy.uix.screenmanager import ScreenManager, Screen
from kivy.uix.boxlayout import BoxLayout
import SQLPET as sql
from kivy.properties import StringProperty

class Inicial(Screen):
    #esvazia os campos caso deslogue
    def esvazia_campos(self):
        self.ids.usuario.text = ''
        self.ids.senha.text = ''   
    def btn_login(self):        
        #associa uma variavel para checar o login e senha
        bd = sql.BancoDeDados        
        #testa usuario e senha e devolve o id caso exista
        App.get_running_app().Login = bd.Checa_Login(self.ids.usuario.text)
        self.Login = App.get_running_app().Login
        Senha = bd.Checa_Senha(self.ids.senha.text)
        #login correto
        if self.Login != None and Senha != None and self.Login == Senha:
            #passa para a proxima tela
            self.ids.mensagem_inicial.text = '[b][color=#000000]BEM-VINDO[/color][/b]'
            self.manager.transition.direction = 'left' 
            self.manager.current = 'MeusPetinhos'
        #Mensagens de erro disponíveis
        #caso usuário e senha estejam errados
        elif self.Login == None and Senha == None:
            self.ids.mensagem_inicial.text = '[b][color=#FF0000]Usuario e senha incorretos[/color][/b]'
        #caso somente o usuario esteja errado
        elif self.Login == None:
            self.ids.mensagem_inicial.text = '[b][color=#FF0000]Usuário incorreto[/color][/b]'
        #caso somente a senha esteja errada
        elif Senha == None:
            self.ids.mensagem_inicial.text = '[b][color=#FF0000]Senha incorreta[/color][/b]'
    
    def btn_cadastro(self):
        
        self.manager.transition.direction = 'left'
        self.manager.current = 'Cadastro'
    
    def btn_sair(self):
        App.get_running_app().stop
        
class Cadastro(Screen):
    def btn_cadastrar(self):
        bd = sql.BancoDeDados
        novo = sql.Informacao(self.ids.novo_usuario.text, self.ids.novo_senha.text, self.ids.novo_data_nascimento.text, self.ids.novo_email.text)
        cadastro = bd.Cadastrar_Usuario(novo)
        if cadastro == True:
            self.ids.Cadastro_mensagem.text = '[b][color=#000000]Cadastro realizado com sucesso[/color][/b]'
        self.manager.transition.direction = 'right'
        self.manager.current = 'Inicio'
    def btn_cancelar(self):
        self.manager.transition.direction = 'right'
        self.manager.current = 'Inicio'

class Pets(BoxLayout,Screen):
    
    nomepet = StringProperty("")
   
    def VerPets(self):
        App.get_running_app().sm.transition.direction = 'left'
        App.get_running_app().sm.current = 'VerPet' 
        
class MeusPetinhos(Screen):
    def checa_pets(self):
        #checar os pets que o usuario tem 
        pass
    def btn_deslogar(self):
        self.manager.transition.direction = 'right'
        self.manager.current = 'Inicio'
        
    def btn_cadastrapet(self):
        self.manager.transition.direction = 'left'
        self.manager.current = 'CadastroPet'
    def popular_pets(self):
       self.ids.petslistagem.data = list()
       bd = sql.BancoDeDados
       lista = bd.Checa_Pets(App.get_running_app().Login)
       
       #preencher a listagem com os registros do banco
       for c in lista:
           if c.nome_pet == None:
               self.ids.petslistagem.data.append({'nomepet': 'Novo'})
           else:
               self.ids.petslistagem.data.append({'nomepet': c.nome_pet}) 
    
class CadastroPet(Screen):
    imagem_pet = StringProperty('dogoy.png')
    
    def btn_voltar(self):
        self.manager.transition.direction = 'right'
        self.manager.current = 'MeusPetinhos'
        
    def btn_regpet(self):
        bd = sql.BancoDeDados
        novo_pet = [App.get_running_app().Login, self.ids.nomepet.text, self.ids.mudapet.text]
        bd.Cadastrar_Pet(novo_pet)
        self.manager.transition.direction = 'left'
        self.manager.current = 'MeusPetinhos'
        
    def mudaPet(self,valor):
        if valor == 'Cachorro':
            self.imagem_pet = 'dogoy.png'
        elif valor == 'Gato':
            self.imagem_pet = 'gato.png'

class VisualizaPet(Screen):
    pass    
                   
class Pet(App):
    def build(self):
        
        Window.size = (300,500)
        
        self.Login = ''
        
        self.sm = ScreenManager()
        self.sm.add_widget(Inicial(name='Inicio'))
        self.sm.add_widget(Cadastro(name='Cadastro'))
        self.sm.add_widget(MeusPetinhos(name='MeusPetinhos'))
        self.sm.add_widget(CadastroPet(name='CadastroPet'))
        self.sm.add_widget(VisualizaPet(name='VerPet'))
        return self.sm
    
Pet().run()
    