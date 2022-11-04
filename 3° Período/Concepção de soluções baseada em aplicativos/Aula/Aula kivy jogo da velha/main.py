from kivy.app import App
from kivy.core.window import Window
from kivy.uix.screenmanager import ScreenManager, Screen
from kivy.core.audio import SoundLoader

#classe para informar nome dos players
class Jogadores(Screen):
    #evento executado antes de mostrar a tela para preencher o nome dos jogadores
    def verifica_jogadores(self):
        self.ids.jogador1.text = App.get_running_app().nome_jogador1
        self.ids.jogador2.text = App.get_running_app().nome_jogador2
        
    #evento para mudar a tela de jogo
    def jogar(self):
        
        #atualiza os nomes
        App.get_running_app().nomejogador1 = self.ids.jogador1.text
        App.get_running_app().nomejogador2 = self.ids.jogador2.text
        
        #audio para inicio do jogo
        App.get_running_app().som_inicio.play()
        
        #transição diferente
        self.manager.transition.direction = 'left'
        
        #transição para a tela de jogo
        self.manager.current = 'jogo'
         
#tela para o jogo
class Jogo(Screen):
    
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        
        self.botoes = (
                (self.ids.bt00, self.ids.bt01, self.ids.bt02),
                (self.ids.bt10, self.ids.bt11, self.ids.bt12),
                (self.ids.bt20, self.ids.bt21, self.ids.bt22)
                )
        self.simbolo_atual = 'X'
        self.jogador_atual = ''
        self.total_jogadas = 0
        self.quem_comeca = 1
        #definir jogador atual
    def inicia_jogo(self):
        #define quem começa
        if self.quem_comeca == 1:
            #define e mostra o nome do primeiro jogador
            self.jogador_atual = App.get_running_app().nomejogador1
            self.simbolo_atual = 'X'
            self.quem_comeca = 2
        else:
            self.jogador_atual = App.get_running_app().nomejogador2
            self.simbolo_atual = 'O'
            self.quem_comeca = 1
        self.ids.jogadoratual.text = self.jogador_atual
        self.total_jogadas = 0
        

        for linha in self.botoes:
            for botao in linha:
                botao.text = ''
    #evento que indica clique em uma das casas do tabuleiro
    def jogou_posicao(self,linha,coluna):
        
        #verificar se a casa já está preenchida
        if self.botoes[linha][coluna].text != '':
            return
        
        #preenche o botao com o simbolo do jogador atual
        self.botoes[linha][coluna].text = self.simbolo_atual
        
        #incrementa total de jogadas 
        self.total_jogadas += 1
        
        #verifica se houve vitoria
        if self.checa_vitoria():
            self.vitoria()
        elif self.total_jogadas == 9 :
             self.empate()
        #alternar o jogador
        if self.simbolo_atual == 'X':
            self.simbolo_atual = 'O'
            self.jogador_atual = App.get_running_app().nomejogador2
        else:
            self.simbolo_atual = 'X'
            self.jogador_atual = App.get_running_app().nomejogador1
            
        #mostrar o nome do próx jogador
        self.ids.jogadoratual.text = self.jogador_atual
        
    def checa_vitoria(self):
        #verifica as linhas 0,1,2
        for i in range(3):  
            if self.botoes[i][0].text == self.botoes[i][1].text == self.botoes[i][2].text == self.simbolo_atual:
                return True
                
        #verifica as colunas 0,1,2 
            if self.botoes[0][i].text == self.botoes[1][i].text == self.botoes[2][i].text ==  self.simbolo_atual:
                return True
        
        #verifica a diagonal principal
        if self.botoes[0][0].text == self.botoes[1][1].text == self.botoes[2][2].text == self.simbolo_atual:
            return True
        
        #verifica a diagonal secundária
        elif self.botoes[2][0].text == self.botoes[1][1].text == self.botoes[0][2].text == self.simbolo_atual:
            return True
        
        #não houve vencedor
        return False
    
    #evento para vitória
    def vitoria(self):
       
        App.get_running_app().resultado = 'vitoria'
        App.get_running_app().som_vitoria.play()       
        App.get_running_app().vencedor = self.jogador_atual
        #mudar para a tela final
        self.manager.current = 'telaresultado'
        
    #evento para empate
    def empate(self):
        #indicar que houve empate
        App.get_running_app().resultado = 'empate'
        
      
        self.manager.current = 'telaresultado'

#tela para final
class Final(Screen):
    #evento para verificar se houve vitoria ou empate
    def verifica_resultado(self):
        
        if App.get_running_app().resultado == 'vitoria':
        
            self.ids.mensagem.text = App.get_running_app().vencedor +  ' ganhou!'
            
            #indicar para o app que houve vitoria
            App.get_running_app().resultado = 'vitoria'
        
        else: 
            App.get_running_app().som_empate.play()    
            App.get_running_app().som_empate.seek(9)
            self.ids.mensagem.text = 'Empatou ´-´'
            
    #evento para iniciar um novo jogo
    def novo_jogo(self):
    
        #vai para a tela de jogadores denovo
        self.manager.current = 'playername'
    
    #evento para encerrar o app
    def sair(self):
        App.get_running_app().stop()
        
        
class JogoDaVelhaApp(App):
    def build(self):
        
        Window.size = (300,400)
        
        #informações do jogo
        self.resultado = ""
        self.nome_jogador1 = "joao"
        self.nome_jogador2 = "maria"
        self.vencedor = ""
        
        #implementação do screen manager
        sm = ScreenManager()
        sm.add_widget(Jogadores(name='playername'))
        sm.add_widget(Jogo(name='jogo'))
        sm.add_widget(Final(name='telaresultado'))
        

      
        #carregar arquivos de audio
        self.som_inicio = SoundLoader.load("here-we-go.wav")
        self.som_vitoria = SoundLoader.load("cheer.wav")
        self.som_empate = SoundLoader.load("tie.wav")
        self.som_beep = SoundLoader.load("beep.wav")

  
        
        return sm
    
JogoDaVelhaApp().run()