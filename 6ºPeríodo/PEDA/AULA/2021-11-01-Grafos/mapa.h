#ifndef MAPA_H
#define MAPA_H
#include<string>
using namespace std;
using TipoDado = string;

constexpr int MAXNOS = 15;


class Mapa{        
protected:
    TipoDado    lista[MAXNOS];
    TipoDado    nomes[MAXNOS];
    bool        adj[MAXNOS][MAXNOS];
    float       peso[MAXNOS][MAXNOS];
    bool adjacente(TipoDado a, TipoDado b);
    bool validos(TipoDado a, TipoDado b);
    int  n;
    int     valor(TipoDado nome);
public:
    Mapa();
    ~Mapa();
    void une(TipoDado a, TipoDado b, float p);
    void rmv(TipoDado a, TipoDado b);
    void imprime()  const;
    void imprimeN() const;  // imprime os nome presentes
    void imprimePesos() const; // nome autoexplicativo
    void adiciona(TipoDado nome);
    void MenorCaminho(TipoDado origem, TipoDado fim);
};


#endif