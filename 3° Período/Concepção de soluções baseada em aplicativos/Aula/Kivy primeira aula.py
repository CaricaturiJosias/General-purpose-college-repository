from kivy.app import App
from kivy.uix.label import Label

class PrimeiroApp(App):
     def build(self):
         return Label(text="Olá a todos")

Novo_App = PrimeiroApp()
Novo_App.run()
