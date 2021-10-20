//
// Implementação da classe ArvBin
// PEDA - PUCPR
//

#include "ArvBin.h"
#include <iostream>

using namespace std;

TipoDado ArvBin::info(No *p)
{
    return p->info;
}

No *ArvBin::esq(No *p)
{
    return p->esq;
}

No *ArvBin::dir(No *p)
{
    return p->dir;
}

No *ArvBin::pai(No *p)
{
    return p->pai;
}

No *ArvBin::irmao(No *p)
{
    //checar se tem irmão
    if (eh_esq(p))
        return dir(pai(p));
    return esq(pai(p));
}

bool ArvBin::eh_esq(No *p)
{
    if (p != raiz)
        return (esq(pai(p)) == p);
    else
        return false;
}

bool ArvBin::eh_dir(No *p)
{
    if (p != raiz)
        return (dir(pai(p)) == p);
    else
        return false;
}

void ArvBin::cria_no_esq(No *pai, TipoDado x)
{
    if (pai->info < x){
        cria_no_dir(pai, x);
    }
    if (esq(pai)==nullptr){
        No *novono = new No;
        novono->info=x;
        novono->pai = pai;
        novono->esq = novono->dir = nullptr;
        pai->esq = novono;
    }
}

void ArvBin::cria_no_dir(No *pai, TipoDado x)
{
    if (pai->info > x){
        cria_no_esq(pai, x);
    }
    if (dir(pai)==nullptr){
        No *novono = new No;
        novono->info = x;
        novono->pai = pai;
        novono->dir = novono->esq = nullptr;
        pai->dir = novono;
    }
}

void ArvBin::adiciona(No *r, TipoDado x)
{
    if (x == info(r))
        cout << "REPETIDO!" << endl;
    else if (x < info(r)){
        if (esq(r) == nullptr)
            cria_no_esq(r, x);
        else
            adiciona(esq(r),x);
    } else {
        //exercicio
        //adiciona pra direita
        if (dir(r) == nullptr)
            cria_no_dir(r, x);
        else
            adiciona(dir(r),x);
    }
} 

void ArvBin::percorresim (No *r)
{
    //ordem simétrica
    if (r != nullptr){
        // ordem dos 3 itens define se é pré, pós ordem ou simétrica
        // dessa forma é simétrica
        //simetrica - esquerda -> raiz -> direita
        //cout << "SIMETRIA" << endl;
        percorresim(esq(r));
        cout << info(r) << endl;
        percorresim (dir(r));
    }
}

void ArvBin::percorrepre(No *r)
{
    if (r != nullptr){
        //pre ordem - raiz -> esquerda -> direita
        cout << "PRÉ ORDEM" << endl;
        cout << info(r) << endl;
        percorrepre(esq(r));
        percorrepre (dir(r));        
    }
}

void ArvBin::percorrepos(No *r)
{
    if (r != nullptr){
        // pos ordem - esquerda -> direita -> raiz
        cout << "PÓS ORDEM" << endl;
        percorrepos(esq(r));
        percorrepos (dir(r));
        cout << info(r) << endl;       
    }
}


ArvBin::ArvBin()
{
    raiz = nullptr;
}

ArvBin::~ArvBin()
{
    destrutor(raiz);
}

void ArvBin::destrutor(No * no)
{
    if (esq(no)!= nullptr){
        destrutor(esq(no));
    }    
    if (dir(no) != nullptr){
        destrutor(dir(no));
    }
    delete(no);
}

void ArvBin::adiciona(TipoDado x)
{
    if (raiz == nullptr){
        raiz = new No;
        raiz->info = x;
        raiz->pai = nullptr;
        raiz->esq = raiz->dir = nullptr;
    }
    else{
        adiciona(raiz, x);
    }
}

void ArvBin::percorre()
{
    percorresim(raiz);
}

