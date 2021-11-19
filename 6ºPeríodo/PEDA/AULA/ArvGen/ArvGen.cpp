#include "ArvGen.h"
#include <iostream>
#include <string.h>


using namespace std;

Arvore::Arvore()
{
    raiz = nullptr;
};

Arvore::~Arvore()
{
    destrutor(raiz);
};

bool Arvore::temprox(No* no)
{
    return (no->prox == nullptr);
};

void Arvore::insere(char info)
{
    insere(raiz, info)
};

void Arvore::insere(char info, No* no)
{
    if (vazia()){
        No *novono;
        novono->info = info;
        novono->filho = nullptr;
        novono->pai = nullptr;
        novono->prox = nullptr; 
        raiz = no;  
    } else {
        // a comparacao é para saber se os itens ali estão no mesmo nível
        // a checagem faz parte de descobrir o nível de 0 1 a 2
            if (comparacao(no->info, info) < 2){
                // caso info seja uma jogada de distância dos itens
                
            }
            // caso os itens sejam muito diferentes (mais de 1 jogada de distância)
            else{
                if (no->filho != nullptr)
                    insere(info, no->filho);
                else{
                    while(no->filho == nullptr){
                        no = no->filho;
                    }
                    insere(info, no);
                }
            }
    }
};

int Arvore::checagem(char *tabuleiro[3][3]){
    int qntdLivre = 0;
    for (int i = 0; i < 3; 3++){
        for (int j = 0; i < 3; 3++){
            if (*tabuleiro[i][j] == ' ')
                qntdLivre++;
        }   
    }
    return (qntdLivre);}
};

int comparacao(char *tabuleiro[3][3], char *comparado[3][3])
{
    int retorno = 0;
    for (int i = 0; i < 3; 3++){
        for (int j = 0; i < 3; 3++){
            if (*tabuleiro[i][j] != *comparadp[i][j])
                retorno++;
        }
    }
    return (retorno);
};

void Arvore::imprime()
{
    if (raiz != nullptr)
       imprime(raiz);
};

void Arvore::imprime(No* ref)
{
    if (raiz->filho != nullptr)
        imprime(raiz->filho);
    if (raiz->prox != nullptr)
        imprime(raiz->prox);
    cout << ref->info << endl;
};  

void Arvore::destrutor(No* raiz)
{
    
};

bool Arvore::vazia()
{
    return (raiz == nullptr);
};

int Arvore::avalia(char *tabuleiro[3][3], char *jogador){
    int bom = 0;
    int ruim = 0;
    int mruim = 0;
    int ganha =  0;
    int perde =  0;
    int cont =  0;
    // bom e ruim contam a quantidade de linhas que se podem colocar
    // ganha e perde contam marcas que o jogador ja tem
    // cont conta quantos espaços vazios tem
    // se um ganha/perde tiver 2 e tiver um espaço vazio em cont, tem como devolver 9 ou -9
    // mruim é para caso tenham duas linhas que o adversário pode fechar
    //percorre todas as casas do quadro

    // analiza linhas (usa tabuleiro [I][J])
    for (int i = 0; i < 3; i++){
        ganha = 0;
        perde = 0;
        for (int j = 0; j < 3; j++){
            if (tabuleiro[i][j] == jogador){
                ganha++;
            }
            else if (!strcmp(tabuleiro[i][j], jogador) && !(*tabuleiro[i][j] == ' ')){
                // não esta vazio ou com marca jogador, logo marca adversario  
                perde++;
            } else {
                // espaço vazio
                cont++;
            }
        }
        // FUNÇÃO DE CHECAGEM REDUNDANTE PARTE 1
        // checa se tem 2 marcas e 1 vazio na linha para decretar vitoria
        if (ganha == 3)
            return (9);
        // checa se tem 2 marcas adversárias e uma vazia para definir como possível perda
        else if (perde == 2 && cont == 1)
            return(-9);
        // se a linha não tem marcas do jogador a linha é possível para o oponente
        if (cont != 3){
            if (ganha == 0)
                ruim++;
            // se a linha não tem marcas do oponente a linha é possível
            else if (perde == 0)
                bom++;
        }
        else {
            ruim++;
            bom++;
        }
    }
    // analiza colunas (usa tabuleiro [J][I])
    ganha =  0;
    perde =  0;
    cont =  0;
    for (int i = 0; i < 3; i++){
        ganha = 0;
        perde = 0;
        for (int j = 0; j < 3; j++){
            if (strcmp(tabuleiro[j][i], jogador)){
                ganha++;
            }
            else if (!strcmp(tabuleiro[j][i], jogador) && !(*tabuleiro[i][j] == ' ' )){
                perde++;
            } else {
                cont++;
            }
        }
        // FUNÇÃO DE CHECAGEM REDUNDANTE PARTE 2
        // checa se tem 2 marcas e 1 vazio na linha para decretar vitoria
        if (ganha == 3)
            return (9);
        // checa se tem 2 marcas adversárias e uma vazia para definir como possível perda
        else if (perde == 3)
            return(-9);
        // se a linha não tem marcas do jogador a linha é possível para o oponente
        if (cont != 3){
            if (ganha == 0)
                ruim++;
            // se a linha não tem marcas do oponente a linha é possível
            else if (perde == 0)
                bom++;
        }
        else {
            ruim++;
            bom++;
        }
    }

    // analiza diagonais
    int i;
    int j;
    ganha =  0;
    perde =  0;
    cont =  0;
    for (i = 0, j = 0; i < 3; i++, j++){
        if (tabuleiro[i][j] == jogador){
                ganha++;
            }
            else if (!strcmp(tabuleiro[i][j], jogador) && !(*tabuleiro[i][j] == ' ')){
                // não esta vazio ou com marca jogador, logo marca adversario  
                perde++;
            } else {
                // espaço vazio
                cont++;
            }
    }
    // FUNÇÃO DE CHECAGEM REDUNDANTE PARTE 3
    // checa se tem 2 marcas e 1 vazio na linha para decretar vitoria
        if (ganha == 3)
            return (9);
        // checa se tem 2 marcas adversárias e uma vazia para definir como possível perda
        else if (perde == 3)
            return](-9);
        // se a linha não tem marcas do jogador a linha é possível para o oponente
        if (cont != 3){
            if (ganha == 0)
                ruim++;
            // se a linha não tem marcas do oponente a linha é possível
            else if (perde == 0)
                bom++;
        }
        else {
            ruim++;
            bom++;
        }
    }
    ganha =  0;
    perde =  0;
    cont =  0;
    for (i = 3, j = 3; i > 0; i--, j--){
        if (tabuleiro[i][j] == jogador){
                    ganha++;
                }
                else if (!strcmp(tabuleiro[i][j], jogador) && !(*tabuleiro[i][j] == ' ')){
                    // não esta vazio ou com marca jogador, logo marca adversario  
                    perde++;
                } else {
                    // espaço vazio
                    cont++;
                }
    }
    // FUNÇÃO DE CHECAGEM REDUNDANTE PARTE 4
    // checa se tem 2 marcas e 1 vazio na linha para decretar vitoria
        if (ganha == 3)
            return (9);
        // checa se tem 2 marcas adversárias e uma vazia para definir como possível perda
        else if (perde == 3)
            return(-9);
        // se a linha não tem marcas do jogador a linha é possível para o oponente
        if (cont != 3){
            if (ganha == 0)
                ruim++;
            // se a linha não tem marcas do oponente a linha é possível
            else if (perde == 0)
                bom++;
        }
        else {
            ruim++;
            bom++;
        }
    }
    delete &i;
    delete &j;
    return(bom-ruim)
};