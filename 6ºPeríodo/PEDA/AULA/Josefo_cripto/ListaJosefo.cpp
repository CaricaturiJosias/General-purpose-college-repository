#include "ListaJosefo.h"
#include <iostream>
#include <string>
#include <fstream>
#include <array>
// usado para teste
#include <typeinfo>
using namespace std;

int prox(int i){
    return ((i+1)%MAXCIRCULAR);
}

int ant(int i){
    if (i = 0)
        return (MAXCIRCULAR-1);
    return ((i-1+MAXCIRCULAR)%MAXCIRCULAR);
}

Lista::Lista()
{
    frente_ = MAXCIRCULAR - 1;
    fim_    = MAXCIRCULAR - 1;
}

Lista::~Lista()
{
    while (!vazia())
        remove();
}

void Lista::insere(TipoDado elemento)
{
    if (cheia())
    { 
        cerr << "Fila cheia" << endl;
        return;
    }
    fim_ = prox(fim_);
    dados[fim_] = elemento;
    return;
}

void Lista::insereFrente(TipoDado elemento)
{
    
    if (cheia()){
        cerr << "Fila cheia" << endl;
        return;
    }
    frente_ = ant(frente_);
    dados[frente_] = elemento;
    return;
}

TipoDado Lista::remove()
{
    if (vazia())
    {
        cerr << "Fila Vazia" << endl;
        return "";
    } 
    TipoDado output = frente();
    frente_ = prox(frente_);
    return output;
}

TipoDado Lista::removeFim()
{
    if (vazia())
    {
        cerr << "Fila Vazia" << endl;
        return "";
    }
    TipoDado output = fim();
    fim_ = ant(fim_);
    return output;
}

bool Lista::vazia()
{
    return (frente_ == fim_);    
}

bool Lista::cheia()
{
    return (prox(fim_)==frente_);
}

TipoDado Lista::imprime()
{
    TipoDado output;
    if (vazia()){
        cerr << "A lista esta vazia!" << endl;
        return "Erro!\n";
    } else {
        int parametro = frente_;
        output = dados[frente_];
        parametro = prox(parametro);        
        while (parametro != prox(fim_)){
            output += dados[parametro];
            parametro = prox(parametro);
        }    
        return output;
    }
}

TipoDado Lista::frente()
{
    return dados[frente_];
}

int Lista::tam()
{
    if (vazia())
        return 0;
    int auxiliar = prox(frente_);
    int contagem = 1;
    while(auxiliar != prox(fim_))
    {
        contagem++;
        auxiliar = prox(auxiliar);
    }
    return contagem;
}

TipoDado Lista::fim()
{
    return dados[fim_];
}
