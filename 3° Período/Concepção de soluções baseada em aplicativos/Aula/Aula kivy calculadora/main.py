from kivy.app import App
from kivy.uix.boxlayout import BoxLayout

#subclasse para o layout
class Quadro(BoxLayout):
    def botao_operacao(self):
        #obter primeiro valor
        n1 = int(self.ids.num1.text)
        #obter segundo valor
        n2 = int(self.ids.num2.text)
        #obter terceiro valor
        #realiza uma operação com base no valor spinner
        tipo = self.ids.tipo_operacao.text
        if tipo == 'soma':
            resultado = n1 + n2
        elif tipo == 'subtracao':
            resultado = (n1 - n2)
        elif tipo == 'multiplicacao':
            resultado = n1*n2
        elif tipo == 'divisao':
            resultado = n1/(n2)
        #mostrar resultado
        self.ids.saida.text = str(resultado)
    def muda_frase(self,valor):
        if valor == 'soma':
            self.ids.botao.text = 'clique aqui para SOMAR'
        elif valor == 'subtracao':
            self.ids.botao.text = 'clique aqui para SUBTRAIR'
        elif valor == 'multiplicacao':
            self.ids.botao.text = 'clique aqui para MULTIPLICAR'
        elif valor == 'divisao':
            self.ids.botao.text = 'clique aqui para DIVIDIR'
    
class CalculadoraApp(App):
    def build(self):
        return Quadro()
    
#instancia da calculadora
calc = CalculadoraApp()
#mostrar a aplicação
calc.run()
#tarefa
'''criar um boxlayout para permitir que o usuario coloque um 
terceiro numero
criar mais um botao para subtração
nos eventos dos botoes, fazer a conta dos 3
'''