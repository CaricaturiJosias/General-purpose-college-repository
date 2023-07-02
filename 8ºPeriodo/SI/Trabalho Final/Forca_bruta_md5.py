import hashlib as hash
import string
from breached import Breached
from datetime import datetime

def breach():
    breach_count = 0
    breaches = list()
    i = 0
    file = open('senhas.txt', 'r')
    senhas = file.readlines()
    
     for usernames in senhas:
        for password in senhas:
            found_user = password.split("\n")[0].split("+++")[0]
            cleaned_password_attemp = hash.md5((password.split[0]).encode()).hexdigest()
            if cleaned_password_attemp == cleaned_password_real:
                breach_count += 1
                print("[{}] User '{}' was breached on {}, and took {} seconds ({} minutes) to occurr, complete information on the breach later on the final report".format(
                    datetime.now().strftime("%m/%d/%Y %H:%M:%S")
                    , found_user
                    , datetime.now().strftime("%m/%d/%Y %H:%M:%S")
                    , round((datetime.now() - start).total_seconds(), 2)
                    , round((datetime.now() - start).total_seconds()/60, 2)
                ))
                breaches.append(Breached(start, found_user, original_try, cleaned_password_real))
                if breach_count == 4:
                    return breaches

f = open("teste.txt", "w+")
attemps = 0
valid = False
for _ in range(4):
    while(not valid):
        user = input("Insira um usuario: ")
        senha = hash.md5(input("Insira uma senha: ").encode())
        if user != senha:
            valid = True
        else:
            print("Favor não repetir")
    valid = False
    f.writelines(f"{user}+++{senha.hexdigest()}\n")

f = open("teste.txt", "r")

breaches = breach()

print("\nFinal report:")
if breaches == []:
    print("Failed :c")
    exit()
for breach in breaches:
    breach.get_breach_info()