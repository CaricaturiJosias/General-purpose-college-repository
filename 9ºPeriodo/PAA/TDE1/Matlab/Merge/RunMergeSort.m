clear; close all; clc; 

N = [5e5];

for i = 1:size(N,2)
    figure();
    subplot(2,1,1);
    entrada = N(i);
    Lista = randperm(entrada, entrada);
    stem(0:(N(i)-1), Lista);

    tic
    Result= MergeSort(Lista);
    timeSpent = toc;

    subplot(2,1,2);
    stem(0:(N(i)-1), Result);

    fprintf("Tempo gasto no merge sort com entrada f(%d) = %3.f", entrada, timeSpent);
end