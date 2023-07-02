clear; close all; clc; 

N = [1e3];

for i = 1:size(N,2)
    figure();
    subplot(2,1,1);
    entrada = N(i);
    Lista = randperm(entrada, entrada);
    stem(0:(N(i)-1), Lista);
    timeSpent = BubbleSort(Lista);
    fprintf("Tempo gasto no bubble sort com entrada f(%d) = %3.f", entrada, timeSpent);
end