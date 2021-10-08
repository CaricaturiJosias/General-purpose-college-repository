#ifndef PILHA_H
#define PILHA_H

#include <array>
#include <vector>
#include <string>

constexpr int MAXPILHA = 10000;
using namespace std;
class Pilha
{
private:
    array<int, MAXPILHA> caminho;
    vector<string> labirinto;
    int topo_;
public:
    Pilha(std::vector<string> labirinto);
    std::vector<int> encontra();
    std::vector<int> encontraFim();
    std::vector<int> procura(vector<int> posicao);
    void push(int i);
    void pop();
    bool vazia();
    bool cheia();
    void printaLab();
};
#endif