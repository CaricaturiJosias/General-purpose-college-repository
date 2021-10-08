// ESSE ARQUIVO FOI MODIFICADO PARA TESTAR IMPLEMENTAÇÃO DO GITHUB PARA O TDE-1 de PEDA

#include "Fila.h"
#include <iostream>

using namespace std;

int prox(int i){
    return ((i+1)%MAXFILA);
}

Fila::Fila()
{
    frente_ = MAXFILA - 1;
    fim     = MAXFILA - 1;
};

void Fila::insere(TipoDado elemento){
    if (!cheia()){
        fim = prox(fim);
        dados[fim] = elemento;
    } else  { 
        cerr << "Fila cheia" << endl;}
}

void Fila::inserepdc(TipoDado elemento){
    if (!cheia()){
        // 1. busca posição i para inserção do elemento
        TipoDado posmen = 11;
        TipoDado men = 0;
        for(int i = prox(frente_); i!=prox(fim); i++){
            if (dados[i] < elemento){
                if  ((dados[i] > men) || (men == 0)){ // deixa passar se o dados[i] for maior que MEN e menor que elemento (checado no if anterior na linha 29), ou se men não tiver registro
                    posmen = i;
                    men = dados[i];
                }
            }
            else if (elemento == dados[i]){
                posmen = i;
                men = dados[i];               
            }
        }
        // 2. abre espaço para inserção do elemento na posição i
        if (posmen == 11){ 
            insere(elemento); // se elemento for o menor item ele será inserido no fim por padrao em insere
            return;
        }
        // se o item não for o menor, deslocara todos os items a partir de prox(fim) até chegar a posição aonde será colocado o novo item (posmen), deixara o prox(posmen) sem modificação e por isso ele é o limite do for
        for (int i = -1; prox(fim-i)!= posmen; i++){
            dados[prox(fim-i-1)] = dados[fim-i-1];
        }
        fim = prox(fim);
        // 3. insere elemento na posição i
        dados[posmen] = elemento;
        return;
    } 
    else 
        cerr << "A fila está cheia!" << endl;
}


TipoDado Fila::frente()
{
    if (vazia()){
        cerr << "Fila vazia" << endl;
        return -1;
    } else
        return dados[prox(frente_)];
}

void Fila::remove(){
    if (!vazia())
        frente_ = prox(frente_);
}

bool Fila::vazia()
{
    return (frente_ == fim);    
}

bool Fila::cheia(){
    return (prox(fim)==frente_);
}