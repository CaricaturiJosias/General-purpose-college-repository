file = open('senhas.txt', 'r')
f = file.readlines()
usuario = []
senha = []
valido = False
input_usuario = int(input("0 - Sair\n1 - Cadastrar\n2 - Logar\n3 - Printa tudo\nR:"))
while input_usuario != 0:
    if input_usuario == 2:
        contador = 0
        while not valido:
            usuario_input = input("Insira um usuario:\n")
            senha_input = input("Insira uma senha:\n")
            if contador >= 5:
                print("Tentativas demais, terminando o código...")
                quit(2)

            elif (usuario_input not in usuario or senha_input not in senha):
                print("Alguma informação não está correta, tente novamente")
                contador += 1
            else:
                print("Login feito com sucesso!")
                quit(1)

    elif input_usuario == 1:
        usuario_cadastrar = input("Nos dê um usuario:\n")
        senha_cadastrar = input("Nos de uma senha:\n")
        if (usuario_cadastrar+'\n') in f or (senha_cadastrar+'\n') in f:
            print("Uma das informações é extremamente frágil, para sua proteção tente novamente com credenciais mais seguras")
        else:
            usuario.append(usuario_cadastrar)
            senha.append(senha_cadastrar)
            print("Cadastro feito com sucesso!")
    
    elif input_usuario == 3:
        print("Usuarios:\n")
        print(usuario)
        print("\nSenhas:\n")
        print(senha)
    input_usuario = int(input("0 - Sair\n1 - Cadastrar\n2 - Logar\n3 - Printa tudo\nR:"))
quit(0)