import AlfaBeta as ab
import random, copy

#arquivo para funcoes variadas, apenas para simplificar a main

def pede_jogadores():
    input_jogadores = int(input("Indique o número de jogadores\nR: "))
    if input_jogadores not in range(1,6):
        while input_jogadores not in range(1,6):
            input_jogadores = int(input("Indique o número de jogadores\nR: "))
    return input_jogadores

def pede_rodadas():
    num_rodadas = int(input("Indique o número de rodadas\nR: "))
    if num_rodadas not in range(1,6):
        while num_rodadas not in range(1,6):
            num_rodadas = int(input("Indique o número de rodadas\nR: "))
    return num_rodadas

def criaJogadores(qntd_jogadores):
    total_jogadores = list()
    lista = list()
    lista = random.sample(['josias','renan','jooj','tristão','renansko'],qntd_jogadores)
    for nomes in lista:
        novo_jogador = ab.Jogador(nomes)
        print("Jogador "+novo_jogador.nome+" Criado")
        total_jogadores.append(novo_jogador)
    return total_jogadores
