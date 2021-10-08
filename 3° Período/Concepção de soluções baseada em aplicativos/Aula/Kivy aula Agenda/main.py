from kivy.app import App
from kivy.core.window import Window
from kivy.uix.screenmanager import ScreenManager, Screen
from kivy.uix.boxlayout import BoxLayout
from kivy.properties import StringProperty, NumericProperty                
from AgendaIntegrada import BancodeDadosContatos, Contatos
class Linha(BoxLayout):
    #cada atributo da classe linha está vinculado a uma chave  dos dicionários de dados
    nome = StringProperty("")
    id = NumericProperty(0)
    telefone = StringProperty("")
    
    #evento chamado quando clico em um contato da lista. exibe os detalhes do contato pressionado
    def exibir_detalhes(self):
    #armazena na classe app o id do contato
         App.get_running_app().id_atual = self.id
    
    #exibe a tela de detalhes
         App.get_running_app().sm.current = 'detalhes'   
       
        
class Principal(Screen):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        
    def popular_listagem(self,busca):
        #limpar a listagem atual
        self.ids.listagem.data = list()
        
        #obter a listagem do banco de dados
        db = BancodeDadosContatos()
        lista = db.ListarContatosPorNome(busca)
        
        #preencher a listagem com os registros do banco
        for c in lista:
            self.ids.listagem.data.append({'id': c.id, 'nome': c.nome})
       
    def novo_contato(self):
        #informa o app que é um novo contato
        App.get_running_app().id_atual = 0
        #muda para tela de detalhes
        self.manager.current = 'detalhes'
class Visualizar(Screen):
    #evento para preencher os dados do contato
    def preenche_dados(self):
        #obtem o id do contato fornecido
        id = App.get_running_app().id_atual
        
        #verificar se estou visualizando um registro ou criando um novo
        if id == 0: #novo
            self.ids.txNome.text =  ''
            self.ids.txTelefone.text = ''
            self.ids.txEmail.text = ''
            self.contato_atual = None
            
        #exibir o banco de dados
        else:
            db = BancodeDadosContatos()
            #buscar registro com id
            self.contato_atual = db.BuscaContatoPorId(id)
            
            #mostrar os dados
            self.ids.txNome.text =  self.contato_atual.nome
            self.ids.txTelefone.text = self.contato_atual.telefone
            self.ids.txEmail.text = self.contato_atual.email        
            self.bloquear_campos(True)
            
            
    def bloquear_campos(self, bloquear):
        self.ids.txNome.disabled = bloquear
        self.ids.txTelefone.disabled = bloquear
        self.ids.txEmail.disabled = bloquear
        if bloquear:
            self.ids.btEditar.text = 'Editar'
            self.ids.btExcluir.disabled = False
        else:
            self.ids.btEditar.text = 'Salvar'
            self.ids.btExcluir.disabled = True
    
    def editar(self):
        if self.ids.btEditar.text == 'Editar':
            self.bloquear_campos(False)
        else: 
            #acesso ao banco de dados
            db = BancodeDadosContatos()
            #quer salvar um registro já existente ou um novo?
            if self.contato_atual == None:
                novo = Contatos(None, self.ids.txNome.text
                                ,self.ids.txTelefone.text,
                                self.ids.txEmail.text)
                db.CadastrarContato(novo)
                self.voltar()
            else:
                self.contato_atual.nome = self.ids.txNome.text
                self.contato_atual.telefone = self.ids.txTelefone.text
                self.contato_atual.email = self.ids.txEmail.text
                db.AtualizarContato(self.contato_atual)
                self.bloquear_campos(True)
    def excluir(self):
        db = BancodeDadosContatos()
        db.ExcluirContato(self.contato_atual)
        self.voltar()
        
    #evento para retornar a tela principal
    def voltar(self):
        self.manager.current = 'principal'
        
class AgendaContatosApp(App):
    def build(self):
        
        Window.size = (300, 400)
        
        #id do contato que está sendo exibido
        self.id_atual = 0
        
        self.sm = ScreenManager()
        self.sm.add_widget(Principal(name='principal'))
        self.sm.add_widget(Visualizar(name='detalhes'))
        return self.sm
    
AgendaContatosApp().run()