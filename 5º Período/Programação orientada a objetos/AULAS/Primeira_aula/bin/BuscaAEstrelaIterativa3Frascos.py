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
#nó -----------
#problema.testeObjetivo -----------
#filho -----------
#problema.Acoes --------


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
		passagem = copy.deepcopy(estado)
		retorno = troca(passagem, a, b, pos_tira,pos_coloca)
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

def troca(estadodado, tira, coloca,pos_tira, pos_coloca):
	transfere = estadodado[tira][pos_tira]
	estadodado[tira][pos_tira] = 0
	estadodado[coloca][pos_coloca] = transfere
	return estadodado

def get_custo(no):
	return no.custo

def checagem_heuristica(no):
	for i in range(3):
		if no.estado[i][0] == no.estado[i][1]:
			no.heuristica += 1

def ordem_custo(lista):
	lista.sort(reverse=True, key = get_custo)

class filho:
	def __init__(self, estadodado, no_pai, acao, heuristicadada):
		self.estado     = estadodado
		self.no_pai     = no_pai
		self.heuristica = heuristicadada
		self.acao       = acao
		self.custo      = 0
class no:
	def __init__(self, estadodado, heuristicadada, custo):
		self.estado = estadodado
		self.heuristica = heuristicadada
		self.custo = custo

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

#BuscaemProfundidadeIterativa

def busca_a_estrela_iterativa(problem):
	sequencia   = []
	noi = no(problem.estado, 0, 0)
	fraiz = 10
	while(True):
		resultado = dls_contorno(noi,problem,  fraiz, sequencia)
		print("Loop")
		fraiz = resultado[1]
		if not(resultado==None):
			retorno = resultado
			break
		if fraiz > 15:
			retorno = None
			break
	return retorno


def dls_contorno(nod, problem, fcusto, sequencia):
	proxf = fcusto+3
	if problem.teste_objetivo(nod.estado) == True:
		return sequencia, fcusto, nod.estado
	elif nod.custo>fcusto:
		return None, nod.custo, nod.estado
	else:
		for acao in problem.operadores:
			#declara nó filho
			passagem = copy.deepcopy(nod.estado)
			nof = filho(checagem(passagem,acao), nod, acao, nod.heuristica)
			#rotina de checagem euristica e definição do nó.custo
			
			checagem_heuristica(nof)
			nof.custo += 1
			nof.custo += nof.heuristica
			print(nof.custo)
			
			sequencia.append(nof.acao)
			resultado = dls_contorno(nof, problem, fcusto, sequencia)			
			if not(resultado[0] == None):
				return resultado
			sequencia.pop()
			proxf = min(proxf, resultado[1])
		return None, proxf, nof.estado


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
		while not(isinstance(k, int)) or (k not in range(3)):
				k=int(input("Insira uma cor válida para cor "+str(i+1)+" do frasco "+str(j+1)+": "))
		Inicial[j][i] = (k)	
			
print(Inicial)
erro1 = "Valor inválido! inserir um dos valores a seguir -> 1|2|3\n(Insira 0 para terminar a criação de ações)\n"
msgTira = "Insira o frasco que tera a tinta retirada na ação:  1|2|3\n(Insira 0 para terminar a criação de ações)\n"
msgColoca = "Insira o frasco que receberá a tinta na ação:  1|2|3\n"
#definir operadores
Combinações = []
k = input("Nova combinação? (1-S/0-N)\n")
while (k == '1') or (k.lower() == "s") :
	i = int(input(msgTira))
	while i-1 not in range(3):	
		i = int(input(erro1))	
	if i == 0:
		break
	j = int(input(msgColoca))
	while j-1 not in range(3):	
		j = int(input(erro1))	
	if j == 0:
		break
	while ([i-1,j-1] in Combinações):
		print("Sequencia já inserida! Por favor insira outra sequência")
		i = int(input(msgTira))
		while i-1 not in range(3):	
			i = int(input(erro1))	
		if i == 0:
			break
		j = int(input(msgColoca))
		while j-1 not in range(1,3):	
			j = int(input(erro1))		
		if j == 0:
			break
	if (i==0) or (j==0):
		break
	Combinações.append([i-1,j-1])
	k = input("Nova combinação? (1-S/0-N)\n")
print(Combinações)

busca = problema_limitado(Inicial, Combinações)
if not(busca.teste_objetivo(busca.estado)):
	resolucao = busca_a_estrela_iterativa(busca)
	if resolucao == None:
		print("O resultado não foi encontrado, provavelmente por interações insuficientes, experimente colocar mais!")
	else:
		print("Solução encontrada dentro do contorno de "+str(resolucao[1]))
		if not(resolucao == None):
			print(resolucao[2])
			print("Sequencia usada: ")
			print(resolucao[0])
		else: 
			print("Nenhuma combinação válida encontrada, talvez colocar mais ações ajudaria?")
else: 
	print("Um sistema já resolvido foi inserido!")