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














print("\nciano = 1, vermelho = 2, lilas = 3, vazio = 0")
for j in range(4):
	for i in range(4):
		i = int(input("\nInsira a cor "+str(i)+" do frasco "+str(j)+": "))
        

frasco1 = []
frasco2 = []
frasco3	= []
frasco4 = []			


Inicial = [frasco1,frasco2,frasco3,frasco4]

	
print(Inicial)

Combinações = []
for i in [0,1,2,3]:
	for j in [0,1,2,3]:
		Combinações.append([i,j])
inicio = [1,2]
Visitados = []