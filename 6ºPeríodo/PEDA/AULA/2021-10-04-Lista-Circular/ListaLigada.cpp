#include "ListaLigada.h"
#include <iostream>
#include <string>
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
    if (vazia()){
        No *novono = new No;
        novono->info = x;
        novono->lista = novono;
        lista = novono;
        numnos++; 
    }
    else{
        No *novono = new No;
        novono->info = x;
        novono->lista = lista->lista;
        lista->lista = novono;
        numnos++;
    }
}

TipoDado Lista::remove()
{
    TipoDado aux;
    if (!vazia()){
        No *rem = lista->lista;
        lista->lista = rem->lista;
        TipoDado aux = rem->info;
        delete rem;
        --numnos;
        if (numnos == 0){
            lista = nullptr;
        }
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
        aux = lista->lista;
        cout << aux->info << endl;
        while (!(aux->lista == lista->lista)){
            cout << aux->lista->info << endl;
            aux = aux->lista;
        return;
        }    
    }
}

// void Lista::codifica(int M){
//     cout << "Codificando..." << endl;
//     No* aux;
//     if (vazia()){
//         cerr << "A lista está vazia!" << endl;
//         return;
//     }   else    {
//         aux = lista->lista;
//         while (!(aux->lista == lista->lista)){
//             aux->info[0] += M;
//             aux = aux->lista;    
//         }
//         imprime();
//     }
// }