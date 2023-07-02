clear; close all; clc; 

N = [10];

for i = 1:size(N,2)
    figure();
    subplot(2,1,1);
    entrada = N(i);

    Lista = randperm(entrada, entrada);
    stem(0:(N(i)-1), Lista);
    timeSpent = SelectSort(Lista);

    fprintf("Tempo gasto no merge sort com entrada f(%d) = %3.f", entrada, timeSpent);
end