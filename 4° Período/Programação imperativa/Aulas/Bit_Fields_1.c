#include <stdio.h>
#include <string.h>

typedef struct {
	char pNome[100];
	int pIdade;	
	unsigned pEstCivil : 2; // gastar apenas 2 bits para representar o estado civil
	// 00(0)-solteiro  01(1) casado
	// 10(2)-viuvo     11(3) divorciado
} sPessoa;
 
int main () {
	// inicializando campo a campo
	// durante a declaracao da variavel
	sPessoa p1 = {"Fulano de Tal", 50, 2};
	printf ("Nome: %s\n", p1.pNome);
	
	// inicializando apos declaracao da variavel
	sPessoa p2;
	strcpy (p2.pNome, "Ciclano de Tal");
	p2.pIdade = 65;
	p2.pEstCivil = 1; // Ciclano eh casado
	
	printf ("Tamanho de sPessoa: %lu\n", sizeof(sPessoa));
	
	return 0;
}


