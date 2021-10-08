from kivy.app import App
from kivy.uix.boxlayout import BoxLayout

class Principal(BoxLayout):
    def __init__(self,**kwargs):
        super().__init__(**kwargs)

    def add_num(self,conta):
        pass
    
    #spinner de conta
    def muda_conta(self,conta):
        pass    

#        if conta == 'soma':
#           self.ids.tela_conta.text = "Soma"
#       elif conta == 'subtracao':
#           self.ids.tela_conta.text = "Subtração"
#       elif conta == 'multiplicacao':
#          self.ids.tela_conta.text = "Multiplicação"
#       elif conta == 'divisao':
#           self.ids.tela_conta.text = "Divisão"
#       elif conta == 'media':
#           self.ids.tela_conta.text = "Média"
 


class CalculadoraApp(App):
    def build(self):
        self.title = 'Calculadora'
        return Principal()
calc = CalculadoraApp()
calc.run()