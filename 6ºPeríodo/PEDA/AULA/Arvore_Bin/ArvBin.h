//
// Definição da classe ArvBin
// PEDA - PUCPR
//

#ifndef ARVBIN_H
#define ARVBIN_H

using TipoDado = int;

struct No {
	TipoDado info;
	No *pai;
	No *esq;
	No *dir;
};

class ArvBin {
protected:
	No *raiz;
protected:
	// Operações básicas
	TipoDado info(No *p);
	No *esq(No *p);
	No *dir(No *p);
	No *pai(No *p);
	No *irmao(No *p);
	bool eh_esq(No *p);
	bool eh_dir(No *p);
	void cria_no_esq(No *pai, TipoDado x);
	void cria_no_dir(No *pai, TipoDado x);
	void destrutor(No *no);					// destrutor recursivo
	void adiciona(No *r, TipoDado x);		// adiciona recursivo
	void percorresim(No *r);					// percorre recursivo
	void percorrepos(No *r);	
	void percorrepre(No *r);	
public:
	ArvBin();            // constrói árvore binária vazia
	~ArvBin();			 // libera memória utilizada pelos nós
	void adiciona(TipoDado x);  // cria nova árvore ou adiciona à existente
	void percorre();
};
#endif
