#ifndef ARVGEN_H
#define ARVGEN_H

struct No{
    char info;
    No* pai;
    No* filho;
    No* prox;
};

class Arvore{
private:
    No *raiz;
    void destrutor(No* raiz);
    No* irmao(No* no);
    bool vazia();
    bool temprox(No* no);
    void imprime(No *referencia);
    int checagem(char *tabuleiro[3][3]); 
    int comparacao(char *tabuleiro[3][3], char *comparado[3][3]);
    void insere(char info, No* no);
public:
    Arvore();
    ~Arvore();
    void insere(char info);
    void imprime();  
    int  avalia(char *tabuleiro[3][3], char *jogador);
};
#endif