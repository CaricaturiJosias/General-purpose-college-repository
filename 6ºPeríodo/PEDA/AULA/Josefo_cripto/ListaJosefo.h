#ifndef LISTA_H
#define LISTA_H
#include <string>
#include <array>
using namespace std;
using TipoDado = string;
constexpr int MAXCIRCULAR = 15;

class Lista{
protected:
    std::array<TipoDado, MAXCIRCULAR> dados;
    int frente_;
    int fim_;
public:
    Lista();
    ~Lista();
    int tam();
    void insere(TipoDado x);
    void insereFrente(TipoDado x);
    TipoDado frente();
    TipoDado fim();
    TipoDado remove();
    TipoDado removeFim();
    bool vazia();
    bool cheia();
    TipoDado imprime();
    void josefo (int m);
};
#endif