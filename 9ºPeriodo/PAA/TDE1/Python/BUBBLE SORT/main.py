import random
from matplotlib import pyplot  as plt

import time

def Bubble(lista):
    N = len(lista)
    for i in range(N):
        for j in range(0,N-i-1):
            if lista[j] > lista[j+1]:
                lista[j], lista[j+1] = lista[j+1], lista[j]
    return lista

def calcTime():
    lista = []
    len_list = [10000, 100000, 500000]
    tempos = []

    for size in len_list:
        lista = random.sample(range(1, size), size-1)
        time_s = time.time()
        Bubble(lista)
        time_e = time.time()
        print(f"Tempo para entrada [{size}] == {time_e-time_s}")
        tempos.append(time_e - time_s)

    plt.plot(len_list,tempos)
    plt.xlabel('interações')
    plt.ylabel('Tempo')
    plt.title('Bubble sort em python')

    plt.show()

def main():
    calcTime()

if __name__ == '__main__':
    main()
