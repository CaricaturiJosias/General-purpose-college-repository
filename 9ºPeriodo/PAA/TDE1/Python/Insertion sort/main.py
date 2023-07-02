import random
from matplotlib import pyplot  as plt

import time

def Insert(lista):
 
    for i in range(1, len(lista)):
        # store the current element in a variable
        key = lista[i]
        # set j to the previous index of i
        j = i - 1
        # compare key with each element to its left, until a smaller element is found or j goes out of bounds
        while j >= 0 and lista[j] > key:
            # shift the larger element to the right
            lista[j+1] = lista[j]
            # decrement j
            j -= 1
        # place the key in its correct position
        lista[j+1] = key
    return lista

def calcTime():
    lista = []
    len_list = [10000,100000,1000000]
    tempos = []

    for size in len_list:
        lista = random.sample(range(1, size), size-1)

        time_s = time.time()
        Insert(lista)
        time_e = time.time()
        tempos.append(time_e - time_s)
        print(f"Tempo para ordenar {size} elementos: {(time_e - time_s) * 1000:.5f} ms")

    plt.show()

def main():
    calcTime()

if __name__ == '__main__':
    main()
