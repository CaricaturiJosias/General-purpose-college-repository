import etcd3
import sys
import time

etcd = etcd3.client()

num_processos = int(sys.argv[1])

# Checar se existe uma execucao completa anterior
leitura = etcd.get("process_count")[0]
if leitura != None:
	if  int(leitura.decode('utf-8')) >= num_processos:
		etcd.delete("process_count")

# instancia para acessar a chave com uma guarda de memoria critica
lock = etcd.lock("process_lock")

for i in range(10, 0, -1):
    print(i)
    time.sleep(1)

print("Chegou na barreira")


with lock:
	val = etcd.get("process_count")[0]
	if val == None: # só para ter certeza
		val = b'0' # para o decode depois não dar erro
	val = int(val.decode('utf-8'))
	etcd.put("process_count", str(val+1))


while int(etcd.get("process_count")[0].decode('utf-8')) != num_processos:
    pass

print("Passou da barreira")

# Possui um TTL na chave pois foi criada com um lock (Deveria ser de 60 segundos)