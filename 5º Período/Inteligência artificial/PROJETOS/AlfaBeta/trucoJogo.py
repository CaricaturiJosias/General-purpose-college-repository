import random, copy
import AlfaBeta as player
import funcoes as func 
from operator import attrgetter

class Carta:
    def __init__(self, naipe, num):
        self.dono = None
        self.chance_vitoria = None
        self.naipe = naipe
        self.numero = num
        self.naipes = {1 : "Ouros", 2 : "Espadas", 3 : "Copas", 4 : "Paus"}
        self.cartasNomeadas = {1: "As",8:"Rainha", 9: "Valete", 10: "Rei"}
class Mesa:
    def __init__(self):
        self.cartas =  list()
        #define o estado da mesa
    
    def cartas_a_mesa(self, jogadores):
        for jogador in jogadores:
            jogador.mostra_cartas()
            for carta in jogador.mao_atual:
                self.cartas.append(carta)

class Truco:
    def __init__(self, num_jogadores, num_rodadas):
        self.jogadores = num_jogadores
        self.rodadas = num_rodadas
        self.baralho = list()
        self.participantes = list()
        self.ordemForca = [4,5,6,7,8,9,10,1,2,3]

    #tratar q = 8, j = 9, k = 10
    #naipes => 1 = Ouros; 2 = Espada; 3 = Copas; 4 = paus

    def cria_baralho(self):
        for i in self.ordemForca:
            for j in range(1,5):
                self.baralho.append(Carta((j),(i)))

    def da_cartas(self):
        baralho = copy.copy(self.baralho)
        copias = random.sample(baralho,self.rodadas*self.jogadores)
        for jogador in self.participantes:  
            for i in range(self.rodadas):
                copia = random.choice(copias)
                copia.dono = jogador
                jogador.mao_atual.append(copia)
                copias.remove(copia)

    def calculaChances(self):
        for jogador in self.participantes:
            for carta in jogador.mao_atual:
                carta.chance_vitoria = (self.baralho.index(carta)+1)/len(self.baralho)        

    def prepara_partida(self):
        #cria um baralho de 10 números com 4 naipes para cada número na ordem de força (3,3,3,3,2,2,2,2,1,1,1,1...,4,4,4,4)
        self.cria_baralho()
        #cria os jogadores
        self.participantes = func.criaJogadores(self.jogadores)
        #da a quantidade de cartas = qntidade de rodadas para cada jogador retirando sem devolver do baralho
        self.da_cartas()
        #da um valor de 0 a 1 de chance de ganhar
        self.calculaChances()
        #decide a ordem de pessoas
        random.shuffle(self.participantes)
    
    #heurística
    def declara_vitorias(self,jogador, outros):
        #minimo é a chance de vitória mínima que a carta deve ter para considerar que ele vai ganhar
        if outros<self.rodadas and outros>0:
            minimo = 0.50
        elif outros == self.rodadas or outros == 0:
            minimo = 0.65
        elif outros > self.rodadas:
            minimo = 0.80
        for carta in jogador.mao_atual:
            if carta.chance_vitoria >= minimo:
                jogador.vitorias_declaradas += 1
                jogador.vitorias_necessarias += 1
                outros += 1
        print(jogador.nome + " declarou que ira ganhar "+str(jogador.vitorias_declaradas))

    def anuncia_resultado(self, mesa):
        vencedor = (sorted(mesa.cartas, key = attrgetter('chance_vitoria'))).pop()
        print("Vencedor da rodada: "+vencedor.dono.nome)
        return vencedor.dono


    def executa_rodada(self):
        #pega os jogadores na ordem do shuffle 
        mesa = Mesa()
        for player in self.participantes:
            resultado = player.algoAlfaBeta(mesa)
            print("Escolha: "+str(resultado.numero)+" de "+resultado.naipes[resultado.naipe]+" do "+resultado.dono.nome)
            print(str(resultado.chance_vitoria))
        
        vencedor = self.anuncia_resultado(mesa)
        vencedor.vitorias_necessarias += -1
        vencedor.vitorias += 1
        for player in self.participantes:
            if player.pontos == 0:
                self.participantes.remove(player)

    def jogar(self):
        #registra na Mesa (classe do estado) as cartas que os jogadores possuem )
        anterioresDeclaradas = 0
        #força os jogadores a declararem quantas vitórias terão conforme a ordem aleatória do shuffle feito atrás
        #reseta a mesa para começar as rodadas
        for jogadordaVez in self.participantes:
            self.declara_vitorias(jogadordaVez, anterioresDeclaradas)
        for i in range(self.rodadas):
            self.executa_rodada()
        for jogador in self.participantes:
            ganhou = jogador.vitorias_declaradas-jogador.vitorias_necessarias
            pontosTotal = jogador.vitorias_declaradas-jogador.vitorias
            if pontosTotal < 0:
                pontosTotal = pontosTotal*(-1)
            jogador.pontos += -pontosTotal
            print(jogador.nome+" Ganhou "+str(ganhou)+" de "+str(jogador.vitorias_declaradas)+", logo, ele perdera "+ str(pontosTotal)+" ponto(s)")
        podium = sorted(self.participantes, key = attrgetter('pontos'),reverse=True)
        print("Podium: ")
        for resultado in podium:
            print(resultado.nome+" - "+str(resultado.pontos)+" pontos")