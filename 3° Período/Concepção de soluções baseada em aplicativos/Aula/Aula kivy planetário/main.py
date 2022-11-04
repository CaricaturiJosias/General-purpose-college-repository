from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.core.window import Window
from kivy.properties import StringProperty
from kivy.core.audio import SoundLoader
from kivy.clock import Clock


class Principal(BoxLayout):
    
    imagem_planeta = StringProperty('terra.jpg')
    
    def __init__(self,**kwargs):
        super().__init__(**kwargs)
        
        #dimensão do quadro
        Window.size = (300,400)
        
        #carregar arquivos de áudio
        self.som_terra   = SoundLoader.load("dog_terra.wav")
        self.som_lua     = SoundLoader.load("catmeow_lua.wav")
        self.som_saturno = SoundLoader.load("chipmonk_saturno.wav")
        self.som_jupiter = SoundLoader.load("DK_Grunt_1_jupiter.wav")
        self.som_saida   = SoundLoader.load("kzding_sair.wav")

        #executa o método irritante a cada 2s
        Clock.schedule_interval(self.irritante, 2)
        
    def irritante(self,valor):
        self.som_saida.play()
    
    def botao_sair(self):
        self.som_saida.play()
        
        #criar um evento acionado daqui a 2s
        Clock.schedule_once(self.parar, 1)
    
    def parar(self,valor):
        #acessa a instância do app aberto (PlanetaApp no caso)
        App.get_running_app().stop()
        
    def controle_som(self,som_ligado):
        if som_ligado:
            self.som_terra.volume = 0.2
            self.som_lua.volume = 0.2
            self.som_saturno.volume = 0.2
            self.som_jupiter.volume = 0.2
            self.som_saida.volume = 0.2
        else:
            self.som_terra.volume   = 0
            self.som_lua.volume     = 0
            self.som_saturno.volume = 0
            self.som_jupiter.volume = 0
            self.som_saida.volume   = 0
            
            
    def muda_planeta(self,novo_planeta):
        if   novo_planeta   == 'Terra':
            self.imagem_planeta      = 'terra.jpg'
            self.ids.mensagem.text   = "Terra"
            self.som_terra.play()
        elif novo_planeta == 'Lua':
            self.imagem_planeta      ='moon.jpg'
            self.ids.mensagem.text   = "Lua"
            self.som_lua.play()
        elif novo_planeta == 'Saturno':
            self.imagem_planeta      = 'saturno.jpg'
            self.ids.mensagem.text   = "Saturno"
            self.som_saturno.play()
        elif novo_planeta == 'Jupiter':
            self.imagem_planeta      = 'jupiter.jpg'
            self.ids.mensagem.text   = "Jupiter"
            self.som_jupiter.play()
        elif novo_planeta == 'Wap':
            self.imagem_planeta      = 'wap.jpg'
            self.ids.mensagem.text   = "[b][i][u]Wap[/b][/i][/u]"     
        
class PlanetaApp(App):
    def build(self):
        self.title = 'Planetas'
        return Principal()
    
PlanetaApp().run()    
        
