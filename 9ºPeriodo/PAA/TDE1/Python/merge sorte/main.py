import random
from matplotlib import pyplot as plt
import time

def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left = arr[:mid]
    right = arr[mid:]

    left = merge_sort(left)
    right = merge_sort(right)

    return merge(left, right)

def merge(left, right):
    result = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result += left[i:]
    result += right[j:]

    return result

def calc_time():
    list_sizes = [10000, 100000, 1000000]
    times = []

    for size in list_sizes:
        arr = random.sample(range(size), size)
        start = time.time()
        merge_sort(arr)
        end = time.time()
        times.append((end - start) * 1000)
        print(f"Tempo para ordenar {size} elementos: {(end - start) * 1000:.5f} ms")

    plt.plot(list_sizes, times)
    plt.xlabel('Tamanho da lista')
    plt.ylabel('Tempo (ms)')
    plt.title('Merge Sort em Python')
    plt.show()

def main():
    calc_time()

if __name__ == '__main__':
    main()