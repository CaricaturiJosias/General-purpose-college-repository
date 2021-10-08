import pandas as pd

def Le_Curitiba(curitiba):
    dados = pd.read_csv(curitiba,sep=';')
    datas_df=dados['Data']
    hora_df=dados['Hora']
    temp_df=dados['Temperatura']
    return datas_df,hora_df,temp_df
    
    
####### Escolha cidade/meses #######   
def menu():
    print('###############- Olá! Escolha qual cidade deseja ver -###############')
    print('1- Curitiba')
    print('2- Londrina')
    print('3- Paranaguá')
    print('0- Encerra o programa')
    print('#############################')
def menuA():
    print('#########################- Olá! Escolha qual Ano deseja ver -#######################')
    print('1- 2018')
    print('#################################################')
def menuMC():
    print('###########- Olá! Escolha entre quais Meses deseja ver -############')
    print('Insira somente entre os meses 1-5 e 8-12')
    print('Insira 0 para finalizar a escolha dos meses')
    print('##################################')
####### Escolha horários #######
def menuH():
    print('Escolha qual intervalo deseja considerar na média, máxima e mínima das temperaturas')
    print('1- Um horário específico (0h - 12h - 18h)')
    print('2- Todos os valores e uma média deles')
    print('#############################')
def menuHU():
    print('##-Escolha qual horário deseja considerar na média, máxima e mínima das temperaturas-##')
    print('1- 0h (Meia-noite)')
    print('2- 12h (Meio-dia)')
    print('3- 18h')
    print('########################################################################')
def MesesEsc(m):
    mN=list()
    if '01' in m:
        mN.append('Janeiro')
    if '02' in m:
        mN.append('Fevereiro')
    if '03' in m:
        mN.append('Março')
    if '04' in m:
        mN.append('Abril')
    if '05' in m:
        mN.append('Maio')
    if '08' in m:
        mN.append('Agosto')
    if '09' in m:
        mN.append('Setembro')
    if '10' in m:
        mN.append('Outubro')
    if '11' in m:
        mN.append('Novembro')
    if '12' in m:
        mN.append('Dezembro')
    return mN
### Funções Mínima Máxima e Média
def TMin(H,m,datasC,tempC,horaC):
    minim = 0    
    for M in range(len(datasC)):
        if datasC[M][3:5] in m:
            if horaC[M] == H:
                if minim == 0:
                    minim = tempC[M]
                elif minim > tempC[M]:
                    minim = tempC[M]
    return minim
def TMax(H,m,datasC,tempC,horaC):
    minim = 0    
    for M in range(len(datasC)):
        if datasC[M][3:5] in m:
            if horaC[M] == H:
                if minim == 0:
                    maxi = tempC[M]
                elif maxi < tempC[M]:
                    maxi = tempC[M]
    return maxi
def TMed(H,m,datasC,tempC,horaC):
    conta = 0
    soma = 0
    for M in range(len(datasC)):
        if datasC[M][3:5] in m:
            if horaC[M] == H:
                conta += 1
                soma += tempC[M]
    return round(soma/conta,2)