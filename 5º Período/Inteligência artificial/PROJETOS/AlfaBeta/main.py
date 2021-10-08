import trucoJogo as jogo
import AlfaBeta as player
import funcoes as func

#inicia o jogo
num_jogadores = func.pede_jogadores()
num_rodadas = func.pede_rodadas()
truco = jogo.Truco(num_jogadores, num_rodadas)
truco.prepara_partida()
truco.jogar()