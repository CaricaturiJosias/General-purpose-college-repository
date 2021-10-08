#ifndef DEQUE_H
#define DEQUE_H

#include <array>

constexpr int MAXFILA = 10;
using TipoDado = int;

class Deque {
private:
    std::array<TipoDado, MAXFILA> dados;
    int frente_;
    int fim_;
public:
    Deck();
    void insere(TipoDado elemento);
    void insere_frente(TipoDado elemento);
    void inserepdc(TipoDado elemento);
    TipoDado frente();
    TipoDado fim();
    void remove();
    void remove_fim();
    bool vazia();
    bool cheia();
};

#endif