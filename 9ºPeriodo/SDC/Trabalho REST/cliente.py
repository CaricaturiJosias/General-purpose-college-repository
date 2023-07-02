from requests import get, post, put, delete
from sys import argv, stderr
def main():
	while (True):
		operacao = input("Selecione uma opcao: \n\tsaldo\n\tdeposito\n\tsaque\n>")
		try:
			url = 'http://127.0.0.1:45256/contas/1234-5'
			if ("saldo" in operacao):
				r = get(url).json()
				print(f"Saldo: {float(r['saldo'])}")
			elif ("saque" in operacao or "deposito" in operacao):		
				val = float(input("\nInsira um valor:\n>"))
				msgData = {
					'op' : operacao,
					'valor': val
				}
				r = put(url, json = msgData).json()
				print(r['Resposta'])
		except Exception as e:
			print(e)
			
if __name__ == '__main__':
	main()
	
