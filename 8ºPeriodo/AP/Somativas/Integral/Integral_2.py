# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
import random
import numpy as np
import matplotlib.pyplot as plt

rand_points = list()
rand_index = list()
valores_reais = list()

def func(t):
    return (1-t**2)**0.5

def main():
    qnt_pontos = 200000
    a = 0
    b = 1
    H = 1
    index = np.arange(a, b, 1/qnt_pontos)
    tot_area = (b-a)*H
    real_points = 0

    for i in np.arange(a, b, 1/qnt_pontos):
        valores_reais.append(func(i))
    
    for i in range(qnt_pontos):
        
        x = random.uniform(a, b)
        rand_points.append(x)
        
        y = random.uniform(0, H)
        rand_index.append(y)

        guess = func(x)
        if guess >= y:
            real_points = real_points + 1

    print("Area total: {}".format(tot_area))
    print("Fração da área correspondente à função x^2: {}".format(real_points/qnt_pontos))
    print("Area aproximada da integral: {}".format((real_points/qnt_pontos)*tot_area))

    plt.scatter(rand_points, rand_index, s = 1)
    plt.scatter(index, valores_reais, s = 5)
    plt.show()
            
main()