import random
from matplotlib import pyplot  as plt

import time

def Selection(lista):
    n = len(lista)
    
    # Traverse through all array elements
    for i in range(n):
        
        # Find the minimum element in remaining 
        # unsorted array
        min_idx = i
        for j in range(i+1, n):
            if lista[min_idx] > lista[j]:
                min_idx = j
        
        # Swap the found minimum element with 
        # the first element
        lista[i], lista[min_idx] = lista[min_idx], lista[i]

def calcTime():
    lista = []
    len_list = [10000,100000,500000]
    tempos = []

    for size in len_list:
        lista = random.sample(range(1, size), size-1)

        time_s = time.time()
        Selection(lista)
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
