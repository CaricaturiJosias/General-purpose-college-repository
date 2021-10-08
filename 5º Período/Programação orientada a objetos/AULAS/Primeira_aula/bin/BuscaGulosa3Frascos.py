import copy, operator, string
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

def get_heuristica(no):
	return no.heuristica

def checagem_heuristica(no):
	for i in range(3):
		if no.estado[i][0] == no.estado[i][1]:
			no.heuristica += 1

def ordemheuristica(lista):
	lista.sort(reverse=True, key = get_heuristica)	

class filho:
	def __init__(self, estadodado, no_pai, acao, heuristicadada):
		self.estado = estadodado
		self.no_pai = no_pai
		self.heuristica = heuristicadada
		self.acao = acao

class no:
	def __init__(self, estadodado, limite, heuristicadada):
		self.estado = estadodado
		self.limite = limite
		self.heuristica = heuristicadada

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

#BuscaGulosa

def busca_gulosa(problem, limite):
	heuristica = 0
	sequencia = []
	return dls_recursivo(no(problem.estado[:], limite, heuristica),problem, limite, sequencia,)
def dls_recursivo(nod, problem, limite, sequencia):
	if problem.teste_objetivo(nod.estado) == True:
		return nod, sequencia
	elif limite == 0:
		return 1, sequencia
	else:
		#lista para comparação heurística
		lista = []
		for acao in problem.operadores:
			passagem = copy.deepcopy(nod.estado)
			checado = checagem(passagem,acao)
			nof = filho(checado, nod, acao, 0)
			#muda o valor da heuristica do nó por referência
			checagem_heuristica(nof)
			lista.append(nof)
		#faz com que todos os nof.heuristica sejam colocados em ordem decrescente para priorizar a mais alta
		ordemheuristica(lista)
		for item in lista:	
			sequencia.append(item.acao)
			resultado = dls_recursivo(item, problem, (limite-1), sequencia)			
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
		while not(k in range(3)):
			k=int(input("Insira uma cor válida para cor "+str(i+1)+" do frasco "+str(j+1)+": "))
		Inicial[j][i] = (k)	
print(Inicial)
erro1 = "Valor inválido! inserir um dos valores a seguir -> 0|1|2\n(Insira 0 para terminar a criação de ações)\n"
msgTira = "Insira o frasco que tera a tinta retirada na ação:  1|2|3\n(Insira 0 para terminar a criação de ações)\n"
msgColoca = "Insira o frasco que receberá a tinta na ação:  1|2|3\n"
#definir operadores
Combinações = []
k = input("Nova combinação? (1-S/0-N)\n")
#python se recusa a comparar K com 1 

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
limite = int(input("Insira um limite de interações válido: "))
busca = problema_limitado(Inicial, Combinações)
if not(busca.teste_objetivo(busca.estado)):
	resolucao = busca_gulosa(busca, limite)
	if resolucao == 1:
		print("O resultado não foi encontrado, provavelmente por interações insuficientes, experimente colocar mais!")
	else:
		print("Solução encontrada dentro do limite de "+str(limite)+" interação(ões): ")
		if not(resolucao[0] == 1):
			print(resolucao[0].estado)
			print("Sequência detectada para o estado acima:")
			print(resolucao[1])
		else: 
			print("Nenhuma combinação válida encontrada, talvez colocar mais ações ajudaria?")