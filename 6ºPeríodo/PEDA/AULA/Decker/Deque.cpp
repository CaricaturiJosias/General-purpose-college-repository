#include "Deque.h"
#include <iostream>

using namespace std;

int prox(int i){
    return ((i+1)%MAXFILA);
}

int ant(int i){
    return ((i-1+MAXFILA)%MAXFILA);
}

Deque::Deque()
{
    frente_ = MAXFILA - 1;
    fim_     = MAXFILA - 1;
};

void Deque::insere(TipoDado elemento){
    if (!cheia()){
        fim_ = prox(fim_);
        dados[fim_] = elemento;
    } else  { 
        cerr << "Fila cheia" << endl;}
}

void Deque::insere_frente(TipoDado elemento){
    if (!cheia()){
        frente_ = ant(frente_);
        dados[prox(frente_)] = elemento;
    }   else 
        cerr << "Fila cheia" << endl;

}

void Deque::inserepdc(TipoDado elemento){
    if (!cheia()){
        // 1. busca posição i para inserção do elemento
        TipoDado posmen = 11;
        TipoDado men = 0;
        for(int i = prox(frente_); i!=prox(fim_); i++){
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
        for (int i = -1; prox(fim_-i)!= posmen; i++){
            dados[prox(fim_-i-1)] = dados[fim_-i-1];
        }
        fim_ = prox(fim_);
        // 3. insere elemento na posição i
        dados[posmen] = elemento;
    } 
    else 
        cerr << "A fila está cheia!" << endl;
}


TipoDado Deque::frente()
{
    if (vazia()){
        cerr << "Fila vazia" << endl;
        return -1;
    } else
        return dados[prox(frente_)];
}

TipoDado Deque::fim()
{
    if (vazia()){
        cerr << "Fila vazia" << endl;
        return -1;
    }   else
        return dados[fim_];
}

void Deque::remove()
{
    if (!vazia())
        frente_ = prox(frente_);
    else 
        cerr << "Fila Vazia" << endl;
}

void Deque::remove_fim()
{
    if (!vazia())
        fim_ = ant(fim_); 
    else 
        cerr << "Fila vazia" << endl;
}

bool Deque::vazia()
{
    return (frente_ == fim_);    
}

bool Deque::cheia()
{
    return (prox(fim_)==frente_);
}