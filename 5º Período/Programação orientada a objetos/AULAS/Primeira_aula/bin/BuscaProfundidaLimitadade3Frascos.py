import copy
#function busca em profundidade(problema)
	#return dls recursivo(criarnó(problema.estado, problema))
	#nó  = um nó com estado = problema.EstadoInicial, custo=0
	# if problema.testeObjetivo(nóestado) then return solução
	#fronteira - fila FIFO com o nó sendo único elemento
	#explorados - conjunto vazio
#function dls recursivo(nó, problema)
		#if problema.testeObjetivo(nó.estado) then return solução
		#else if limite = 0 then return corte
		#else 
			#ocorreu corte? <-- falso
			#for each acao in problema.acoes(no.estado) do
				#filho <- nofilho(problema,no,acao)
				#resultado <- dls recursivio(filho, problema)
				#if resultado = corte then ocorreu_corte <- verdadeiro
				#else if resultado != falha then return resultado
			#if ocorreu_corte? then return corte else return falha
#ciano = 1, vermelho = 2, lilas = 3, vazio = 0
#nó
#problema.testeObjetivo
#fronteira
#explorados -------
#filho
#inserirFronteira
#problema.Acoes


	#return solução ou falha

#realiza a troca
def checagem(estado, operadores):
	a = operadores[0]
	b = operadores[1]
	retorno = estado
	#checa os dois
	pos_tira = checatira(estado, a)
	pos_coloca = checacoloca(estado, b)
	#checa os valores:
	if not(pos_tira == None or pos_coloca == None):
		#executa a troca
		retorno = troca(estado, a, b, pos_tira,pos_coloca)
	return retorno


def checatira(estado, pos):
	retorno = None
	for k in range(3):
		if (estado[pos][k] == 0):
			if k == 0:
				retorno = None
				break
			else: 
				retorno = k-1
				break
		elif (k==2):
			retorno = 2
	return retorno

def checacoloca(estado, pos):
	retorno = None
	for k in range(3):
		if estado[pos][k] == 0:
			retorno = k
			break
	return retorno

def troca(estado, tira, coloca,pos_tira, pos_coloca):
	estadodado = copy.deepcopy(estado)
	transfere = estadodado[tira][pos_tira]
	estadodado[tira][pos_tira] = 0
	estadodado[coloca][pos_coloca] = transfere
	return estadodado


class filho:
	def __init__(self, estadodado, no_pai, acao):
		self.estado = estadodado
		self.no_pai = no_pai
		self.acao = acao

class no:
	def __init__(self, estadodado, limite):
		self.estado = estadodado
		self.limite = limite

class problema_limitado:
	def __init__(self, inicial, operadores):
		self.estado = inicial
		self.operadores = operadores

#Teste-objetivo
	def teste_objetivo(self, estado):
		teste = 0
		for i in range(3):
			if estado[i][0] == estado[i][1]:
				teste += 1
		if teste == 3:
			return True
		else: 
			return False

#BuscaemProfundidadeLimitada

def busca_em_profundidade_limitada(problem, limite):
	sequencia = []
	return dls_recursivo(no(problem.estado[:], limite),problem, limite, sequencia)
def dls_recursivo(nod, problem, limite, sequencia):
	if problem.teste_objetivo(nod.estado) == True:
		return nod, sequencia
	elif limite == 0:
		return 1, sequencia
	else:
		for acao in problem.operadores:
			sequencia.append(acao)
			passagem = copy.deepcopy(nod.estado)
			checado = checagem(passagem,acao)
			nof = filho(checado, nod, acao)
			resultado = dls_recursivo(nof, problem, (limite-1), sequencia)			
			if resultado[0] == 1:
				sequencia.pop()
			elif not(resultado[0]==None):
				return resultado
		return 1, sequencia


#Declarar estado inicial com input
frasco1 = [None]*3
frasco2 = [None]*3
frasco3 = [None]*3	
frasco4 = [None]*3	
Inicial = [frasco1,frasco2,frasco3]
print("\nciano = 1, lilás = 2, vazio = 0")
for j in range(3):
	for i in range(3):
		k=int(input("Insira a cor "+str(i+1)+" do frasco "+str(j+1)+": "))
		Inicial[j][i] = (k)	
print(Inicial)

#definir operadores
Combinações = []
for i in [0,1,2]:
	for j in [0,1,2]:
		if not(i==j):
			Combinações.append([i,j])
print(Combinações)
limite = int(input("Insira um limite de interações válido: "))

busca = problema_limitado(Inicial, Combinações)
if not(busca.teste_objetivo(busca.estado)):
	resolucao = busca_em_profundidade_limitada(busca, limite)
	if resolucao == 1:
		print("O resultado não foi encontrado, provavelmente por interações insuficientes, experimente colocar mais!")
	else:
		print("Solução encontrada dentro do limite de "+str(limite)+" interação(ões): ")
		print(resolucao[0].estado)
		print("Sequência detectada para o estado acima:")
		print(resolucao[1])