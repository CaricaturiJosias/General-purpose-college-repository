#function busca em largura
	#nó  = um nó com estado = problema.EstadoInicial, custo=0
	# if problema.testeObjetivo(nóestado) then return solução
	#fronteira - fila FIFO com o nó sendo único elemento
	#explorados - conjunto vazio

	#loop do
		#if fronteira estiver vazia then returns falha
		#nó -> Pop(fronteira) /escolhe o nó mais superior da fronteira/
		#adiciona nó estado ao explorados
		#for each ação em problema.Acoes(nó, estado)
			#filho -> nó filho(prob,nó,ação)
			#if filho.estado não esta em explorados ou fronteira
				#if problema.testeObjetivo(filho.eatado) then return solução(filho)
				#fronteira -> inserir(filho,fronteira)
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
		estado = troca(estado, a, b, pos_tira,pos_coloca)
	return estado


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
	def __init__(self, estadodado, no_pai):
		self.estado = estadodado
		self.no_pai = no_pai

class problema:
	def __init__(self, inicial, operadores):
		self.inicio = inicial
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

#BuscaemLargura

def busca_em_largura(problem):
	numrepeticoes = 0
	no = filho(problem.inicio, problem)	
	fila = []
	fila.append(no)
	cond = False
	while cond == False:
		if vazia(fila):
			cond = True
			retorno = no.estado
			break
		no = fila.pop(0)
		for acao in problem.operadores:
			estado = checagem(no.estado, acao)
			nof = filho(estado, no)
			if (nof not in problem.explorados) or (nof not in fila):
				problem.explorados.append(acao)
				numrepeticoes += 1
				if problem.teste_objetivo(nof.estado):
					problem.inicio = nof.estado
					cond = True
					retorno = problem
					break
				else:
					fila.append(nof)
	print(numrepeticoes)
	return retorno


#Declarar estado inicial com input
frasco1 = [None]*3
frasco2 = [None]*3
frasco3 = [None]*3	
frasco4 = [None]*3	
Inicial = [frasco1,frasco2,frasco3]
print(len(Inicial))
print(len(Inicial[0]))
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

busca = problema(Inicial, Combinações)
if not(busca.teste_objetivo(busca.inicio)):
	resolucao = busca_em_largura(busca)
	if resolucao == "Erro":
		print("erro")
		exit()
	else:
		print("Encontrou!")
		print("Sequencia: ")
		print(resolucao.explorados)