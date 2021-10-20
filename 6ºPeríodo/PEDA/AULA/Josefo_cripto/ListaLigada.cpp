#include "ListaLigada.h"
#include <iostream>
#include <string>
#include <fstream>
#include <array>
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
        cerr << "A lista esta vazia!" << endl;
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

void josefo (Lista listas[], int m){
    Lista *novaLis;
    Lista *auxiLis[2];
    // loop por todos os itens na lista
    for (int i = 0;i<listas->tam();i++){
        // tira itens de 3 em 3 até a lista estiver vazia
        int duracao_listas = listas[i].tam();
        for (int j=1; duracao_listas ; ++j) {
            // sempre haverá remoção, só resta dizer onde irá
            TipoDado x = listas[i].remove();
            
            // se ele deve ser recolocado na outra lista, faz isso e devolve os auxiLis de volta
            if (j%3 == 0){
                novaLis->insere(x);
                // devolve os outros 2 itens
                for (int k = 0; k<2;k++){
                    listas[i].insere(auxiLis[k]->remove());
                }
            }
            
            
            else
                auxiLis[(j%3)-1]->insere(x);
        }
        // REVERSAO DO FEITO ATRÁS, OU SEJA, DA LISTA novaLis PARA LISTAS
        // tira os itens de 1 em 1 até a lista auxiliar estiver vazia
        for (int j=1; novaLis[i].tam() == 0 ; ++j) {
            listas[i].insere(novaLis->remove());
        }
    }
}


Lista *tratamento_do_arquivo(Lista *listas,string nome_arquivo, int M)
{
    // inicialização da função com declarações
    array<string, MAXPILHA> linhas;
    string linha;
    fstream arquivo;
    // abertura do arquivo
    arquivo.open(nome_arquivo+".txt");
    // começo da separação das linhas em listas
    if (arquivo.is_open()){
        for (int i = 0;getline(arquivo, linha);i++){
            //array de strings
            linhas[i] = linha;
            i++;
        }
    }
    //preciso passar os arrays de strings para as listas
    for(int i = 0;i< linhas.size() ;i++){
        for (int j = 0;j<linhas[i].length();j++){
            listas[i].insere(linhas[i].substr(j,1));
        }
    }
    return listas;
}

