import trucoJogo as game
import copy
from operator import attrgetter

class Jogador:
    def __init__(self, nome):
        #mao_atual = estado
        self.nome = nome
        self.mao_atual = list()
        self.pontos = 5
        self.tamanho_mao = len(self.mao_atual)    
        self.vitorias_declaradas = 0
        self.vitorias_necessarias = 0
        self.vitorias = 0

    def quero_ganhar(self, mesa):
        #caso 1: não quero ganhar porque já ganhei o declarado
        if (self.vitorias_necessarias ==0):
            return False

        #caso 2: quero "ferrar" com outro jogador (obrigatório acontecer antes do caso #3)
        #vai analisar as cartas na mesa, e se uma das cartas tem uma certa chance de ser uma das únicas fortes,
        #vai tentar atrapalhar
        if not mesa:
            return False
                #procedimento padrao, não tem quem ferrar, retorna False
        for carta in mesa.cartas:
            if (carta.dono.vitorias_necessarias >0):
                if carta.chance_vitoria >= 0.70:
                    for cartaPlayer in self.mao_atual:
                        if cartaPlayer.chance_vitoria > carta.chance_vitoria:
                            return True
                    return False
            #olha a carta, olha as vitorias declaradas, decide se é uma carta que é importante
            #se for importante, olha se pode atrapalhar sem sair no prejuizo, se puder, retorna True

            #segunda possibilidade complementado pelo segundo: olha a carta, vitorias declaradas, decide se é
            #importante, se não for, olha se o próprio jogador precisa ganhar, se puder, retorna true

            #terceira possibilidade: olha as coisas, é importante, mas o jogador não precisa mais ganhar, 
            #ou outros jogadores podem ferra-lo, devolve False
            #caso 3: quero ganhar porque ainda faltam vitórias
        
        #opção 3: ele não consegue ferrar ninguém mas precisa ganhar
        if (self.vitorias_necessarias>0):
            return True

    def max(self, mesa):
        retorno = None
        aceitavel =  list()
        for cartaPlayer in self.mao_atual:
            if mesa:
                if mesa.cartas != []:
                    cartaMesa = sorted(mesa.cartas, key = attrgetter('chance_vitoria')).pop()
                    if cartaMesa.chance_vitoria >= 0.70:
                        if cartaPlayer.chance_vitoria > cartaMesa.chance_vitoria:
                            #caso haja mais de uma carta válida, será devolvida a primeira e não se analisara
                            # a segunda
                            aceitavel.append(cartaPlayer)
                        #primeiro for tem o if para usar cartas boas para tentar ganhar
                        #segundo for tem função de gastar uma carta caso não queira 
                elif cartaPlayer.chance_vitoria >= 0.70:
                    aceitavel.append(cartaPlayer)
            elif cartaPlayer.chance_vitoria > 0.70:
                aceitavel.append((sorted(self.mao_atual, key = attrgetter('chance_vitoria'))).pop())
        if aceitavel == []:
                aceitavel.append((sorted(self.mao_atual, key = attrgetter('chance_vitoria'))).pop())
        retorno = sorted(aceitavel, key = attrgetter('chance_vitoria')).pop()
        self.mao_atual.remove(retorno)
        mesa.cartas.append(retorno)
        return retorno

    def min(self, mesa):
        aceitavel  = list()
        retorno = None
        for cartaPlayer in self.mao_atual:
            if mesa != None:
                if mesa.cartas != []:
                    cartaMesa = sorted(mesa.cartas, key = attrgetter('chance_vitoria')).pop()
                    if cartaPlayer.chance_vitoria <= 0.70:
                        if cartaPlayer.chance_vitoria < cartaMesa.chance_vitoria:
                            #caso haja mais de uma carta válida, será devolvida a primeira e não se analisara
                            # a segunda
                            aceitavel.append(cartaPlayer)
                        #primeiro for tem o if para usar cartas boas para tentar ganhar
                        #segundo for tem função de gastar uma carta caso não queira
                elif cartaPlayer.chance_vitoria <= 0.70:
                    aceitavel.append(cartaPlayer)
            else:
                aceitavel.append((sorted(self.mao_atual, key = attrgetter('chance_vitoria'),reverse=True)).pop())
        if retorno == None:
                aceitavel.append((sorted(self.mao_atual, key = attrgetter('chance_vitoria'),reverse=True)).pop())
        retorno = (sorted(aceitavel, key = attrgetter('chance_vitoria'),reverse=True)).pop()
        mesa.cartas.append(retorno)
        self.mao_atual.remove(retorno)
        return retorno

    #mesa = estado
    #jogadores = alfa,beta,omega.......
    def min_max_jogada(self, mesa):
        #a heuristica pra definir se quer max e min vai ser uma função quer ganhar
        #essa função decide se vai ser uma boa ideia tentar ganhar a rodada
        if (self.quero_ganhar(mesa) == True):
            escolha = self.max(mesa)
        else:
            escolha = self.min(mesa)
        return escolha
        #return carta

    def algoAlfaBeta(self, mesa):
        #nesse momento o jogador já tem todos os dados que ele precisa saber para a função
        #suas cartas, quantas cada escolheu e quais cartas estão na mesa
        return self.min_max_jogada(mesa)