import random
from matplotlib import pyplot  as plt

import time

def Quick(lista):
    if len(lista) <= 1:
        return lista
    else:
        pivot = lista[0]
        left = []
        right = []
        for i in range(1, len(lista)):
            if lista[i] < pivot:
                left.append(lista[i])
            else:
                right.append(lista[i])
        return Quick(left) + [pivot] + Quick(right)

def calcTime():
    lista = []
    len_list = [10000,100000,500000]
    tempos = []

    for size in len_list:
        lista = random.sample(range(1, size), size-1)

        time_s = time.time()
        Quick(lista)
        time_e = time.time()
        print(f"Tempo para entrada [{size}] == {time_e-time_s}")
        tempos.append(time_e - time_s)

    plt.plot(len_list,tempos)
    plt.xlabel('interações')
    plt.ylabel('Tempo')
    plt.title('Insert sort em python')

    plt.show()

def main():
    calcTime()

if __name__ == '__main__':
    main()
