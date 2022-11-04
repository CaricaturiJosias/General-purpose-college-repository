#Nome dos integrantes: Ana Paula Menezes Florencio, Gabriel Vitor Cezário, Giordano Bruno Carvalho Santos Brasil Pompeo , Guilherme Mayer Junqueira, Rodrigo Alvarez Cunha Donato
#proporção do item: 3.657 (sem unidade de medida)
#proporção das regras da nascar: 3.655 (sem unidade de medida)
#fonte: http://www.puntataco.com.br/index.php/turismo/blancpain/520-entenda-tudo-sobre-a-nascar-2017
import matplotlib.pyplot as plt
import math
base = float(input('Insira o intervalo entre os pontos (entre 0 a 1):\n'))
while base <= 0 or base > 1 :
    print('Erro! Insira um valor válido')
    base = float(input('Insira o intervalo entre os pontos (entre 0 a 1):\n'))
vi = float(input('Insira o valor inicial (0.01):\n'))
while vi != 0.01:
    print('Erro! Insira um valor válido')
    vi = float(input('Insira o valor inicial (0.01):\n'))
vf = float(input('Insira o valor final (12.8):\n'))
while vf != 12.8:
    print('Erro! Insira um valor válido')
    vf = float(input('Insira o valor final (12.8):\n'))
areacalculada =35.2065
soma = 0
x = vi
plt.axis((0,12.8,0.6,5))
while x < vf:
    if x< 3.00:
        y= (0.7*(math.log(x)/2))+ 1.55
    elif x< 4.50: 
        y= (x-1)
    elif x< 5.90:
        y= 3.5
    elif x< 7.80:
        y= math.log10(63.50-x*7)+2.15
    elif x< 10.50:
        y = -x*0.2 + 4.68
    elif x< 11.90:
        y= x*0.65 - 4.25
    else: 
        y= 3.50
    plt.plot(x,y,marker='o',color = 'Blue')
    plt.bar(x,y,base)
    x = x+base
    soma = soma+(base*y)
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Relampago marquinhos')
plt.show()
MargemErro = 0
if areacalculada > soma:
    MargemErro = ((areacalculada-round(soma,2))/areacalculada)*100
else:
    MargemErro = ((round(soma,2)-areacalculada)/areacalculada)*100
print('***********************************************\n')
print('A area da figura é de:',round(soma,3),' cm²\n')
print('A area real é de: ',round(areacalculada,3),'cm²\n' )
print('A margem de erro é de: ',round(MargemErro,4),'%\n' )
print('***********************************************')