#ifndef LISTA_H
#define LISTA_H

using TipoDado = char;

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
};

#endif