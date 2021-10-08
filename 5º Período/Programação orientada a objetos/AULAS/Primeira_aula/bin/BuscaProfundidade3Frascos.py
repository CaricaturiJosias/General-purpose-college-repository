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
	#checa os dois
	pos_tira = checatira(estado, a)
	pos_coloca = checacoloca(estado, b)
	#checa os valores:
	if not(pos_tira == None or pos_coloca == None):
		#executa a troca
		passagem = copy.deepcopy(estado)
		retorno = troca(passagem, a, b, pos_tira,pos_coloca)
		return retorno
	return None


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
	transfere = estado[tira][pos_tira]
	estado[tira][pos_tira] = 0
	estado[coloca][pos_coloca] = transfere
	return estado

def vazia(fila):
	if fila == None:
		return True
	else:
		return False

class filho:
	def __init__(self, estadodado, no_pai, acao):
		self.estado = estadodado
		self.no_pai = no_pai
		self.acao = acao

class no:
	def __init__(self, estadodado):
		self.estado = estadodado

class problema:
	def __init__(self, inicial, operadores):
		self.estado = inicial
		self.operadores = operadores
		self.explorados = []

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

#BuscaemProfundidade

def busca_em_profundidade(problem):
	noc = no(problem.estado)
	return dls_recursivo(noc,problem)

def dls_recursivo(no, problem):
	if problem.teste_objetivo(no.estado) == True:
		return no
	else:
		for acao in problem.operadores:
			passagem = copy.deepcopy(no.estado)
			estado = checagem(passagem, acao)
			if not(estado == None):
				nof = filho(estado, no, acao)
				resultado = dls_recursivo(nof, problem)
				if not(resultado==None):
					return resultado
		return None


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
print("Estado inicial: ", Inicial)

#definir operadores
Combinações = []
for i in [0,1,2]:
	for j in [0,1,2]:
		if not(i==j):
			Combinações.append([i,j])
print("Combinações utilizadas: ", Combinações)

busca = problema(Inicial, Combinações)
if not(busca.teste_objetivo(busca.estado)):
	resolucao = busca_em_profundidade(busca)
	if resolucao == "Erro":
		print("erro")
		exit()
	else:
		print("Finalizado!")
		print("Estado final: ")
		print(resolucao.estado)