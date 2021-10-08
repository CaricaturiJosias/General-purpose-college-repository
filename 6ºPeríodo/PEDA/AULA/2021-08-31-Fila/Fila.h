#ifndef Fila_H
#define Fila_H

#include <array>

constexpr int MAXFILA = 10;
using TipoDado = int;

class Fila {
private:
    std::array<TipoDado, MAXFILA> dados;
    int frente_;
    int fim;
public:
    Fila();
    void insere(TipoDado elemento);
    void inserepdc(TipoDado elemento);
    TipoDado frente();
    void remove();
    bool vazia();
    bool cheia();
};

#endif