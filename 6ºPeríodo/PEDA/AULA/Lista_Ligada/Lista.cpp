#include "Lista.h"
#include <iostream>

using namespace std;

Lista::Lista()
{
    lista = nullptr;
    numnos = 0;
}

Lista::~Lista()
{
    cout << "Liberando memoria da lista" << endl;
    while (!vazia())
        remove();
}

void Lista::insere(TipoDado x)
{
    No *novono = new No;
    novono->info = x;
    novono->lista = lista;
    lista = novono;
    numnos++;
}

TipoDado Lista::remove()
{
    TipoDado aux;
    if (!vazia()){
        No *rem = lista;
        lista = rem->lista;
        TipoDado aux = rem->info;
        delete rem;
        --numnos;
    } else {
        cerr << "Erro! A lista está vazia" << endl;
    }
    return aux;
}

unsigned int Lista::tam()
{
    return numnos;
}

bool Lista::vazia()
{
    return (lista == nullptr);
}

void Lista::imprime()
{
    cout << "Imprimindo..." << endl;
    No* aux;
    if (vazia()){
        cerr << "A lista está vazia!" << endl;
        return;
    }   else    {
        aux = lista;
        cout << lista->info << endl;
        while (!(aux->lista == nullptr)){
            cout << aux->lista->info << endl;
            aux->lista = aux->lista->lista;
        }    
    }
}