import biblioteca2 as bib
curitiba = 'Curitiba.csv'
londrina = 'Londrina.csv'
paranagua = 'Paranagua.csv'

[datasC,horaC,tempC]= bib.Le_Curitiba(curitiba)
'''
[datasL,horaL,tempL]= Le_Londrina(londrina)
[datasP,horaP,tempP]= Le_Paranagua(paranagua)
'''
m = list()
bib.menu()
Op = int(input('Digite sua opção: '))
if Op == 0:
    print('Programa sendo encerrado')
##### CURITIBA #####
elif Op == 1:
    print('Você selecionou Curitiba')
    bib.menuA()
    A = int(input('Digite sua opção: '))
    while A != 1:
        print('Valor inválido, insira o valor antes da opção (Ex: em "1-2018", insira 1)')
        A = int(input('Digite sua opção (Somente o número do mês): '))
    bib.menuMC()
    EM = int(input('Insira um mês para visualização: '))
    Nmeses = 0
    while EM != 0:
        while EM > 12 or EM < 0 or EM == 6 or EM == 7:
            print('\nErro, insira um mês disponível')
            EM = int(input('Insira um mês para visualização: '))    
        if 1<=EM<=9:
            meses = '0' + str(EM)
        else:
            meses = str(EM)
        m.append(meses)
        Nmeses += 1
        EM = int(input('Insira um mês para visualização: '))
    print('\nVocê selecionou',Nmeses,'Meses')
    print('\nEstes sendo:',bib.MesesEsc(m))
elif Op == 2:
    print('Você selecionou Londrina')
    bib.menuA()
    A = int(input('Digite sua opção: '))
    while A != 1:
        print('Valor inválido, insira o valor antes da opção (Ex: em "1-2018", insira 1)')
        A = int(input('Digite sua opção (Somente o número do mês): '))
    bib.menuMC()
    EM = int(input('Insira um mês para visualização: '))
    Nmeses = 0
    while EM != 0:
        if 1<=EM<=9:
            meses = '0' + str(EM)
        else:
            meses = str(EM)
        m.append(meses)
        Nmeses += 1
        EM = int(input('Insira um mês para visualização: '))
    print('\nVocê selecionou',Nmeses,'Meses')
    print('\nEstes sendo:',bib.MesesEsc(m))
elif Op == 3:
    print('Você selecionou Paranaguá')
    bib.menuA()
    A = int(input('Digite sua opção: '))
    while A != 1:
        print('Valor inválido, insira o valor antes da opção (Ex: em "1-2018", insira 1)')
        A = int(input('Digite sua opção (Somente o número do mês): '))
    bib.menuMC()
    EM = int(input('Insira um mês para visualização: '))
    Nmeses = 0
    while EM != 0:
        if 1<=EM<=9:
            meses = '0'+str(EM)
            print (meses)
        else:
            meses = str(EM)
        m.append(meses)
        Nmeses += 1
        EM = int(input('Insira um mês para visualização: '))
    print('\nVocê selecionou',Nmeses,'Meses')
    print('\nEstes sendo:',bib.MesesEsc(m))
#### Opção de horário ####
bib.menuH()
EscH = int(input('Digite sua escolha: '))
while EscH > 2 or EscH < 1:
    print('Erro! Escolha um valor válido')
    EscH = int(input('Digite sua escolha: '))
if EscH == 1:
    bib.menuHU()
    H = int(input('Escolha um horário para ser considerado: '))
    while H!=0 and H!=12 and H!=18:
        print('Erro! Insira um número válido (digite somente o horário selecionado, sem "h")')
        H = int(input('Escolha um horário para ser considerado: '))
    print('Temperatura mínima: ',bib.TMin(H,m,datasC,tempC,horaC))
    print('Temperatura máxima: ',bib.TMax(H,m,datasC,tempC,horaC))
    print('Temperatura média: ',bib.TMed(H,m,datasC,tempC,horaC))
    