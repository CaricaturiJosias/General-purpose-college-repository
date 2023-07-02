import time
import matplotlib.pyplot as plt

def insertion_sort(lst):
    for i in range(1, len(lst)):
        current_val = lst[i]
        j = i - 1
        while j >= 0 and lst[j] > current_val:
            lst[j + 1] = lst[j]
            j -= 1
        lst[j + 1] = current_val
    return lst

input_sizes = [10, 100, 1000]
execution_times = []

for size in input_sizes:
    lst = list(range(size, 0, -1))  # gera uma lista decrescente de tamanho size
    start_time = time.time()
    insertion_sort(lst)
    end_time = time.time()
    execution_time = end_time - start_time
    execution_times.append(execution_time)

plt.plot(input_sizes, execution_times)
plt.xlabel('Tamanho da entrada')
plt.ylabel('Tempo de execução (segundos)')
plt.show()
