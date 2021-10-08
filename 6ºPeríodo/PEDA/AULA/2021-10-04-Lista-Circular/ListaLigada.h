#ifndef LISTA_H
#define LISTA_H
#include <string>
using namespace std;
using TipoDado = string;

struct No{
    TipoDado info;
    No *lista;
};

class Lista{
protected:
    No *lista;
    unsigned int numnos;
public:
    Lista();
    ~Lista();
    void insere(TipoDado x);
    TipoDado remove();
    unsigned int tam();
    bool vazia();
    void imprime();
    //void codifica(int M);
};

#endif