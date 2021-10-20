#include <stdio.h>
#include <stdlib.h>

int main (int argC, char *argV[]) {
	// recebendo parametros na chamada do programa
	// argC : argument Count
	// argV : argumento Values
	int i;
	
	if (argC == 1) {
		// argV é sempre maior ou igual a 1.
		printf ("Nenhum parametro enviado para <%s>\n", argV[0]);
		// argV[0] sempre aponta para o nome do programa
	} else {
		printf ("Parametros passados para o programa <%s>\n", argV[0]) ;
		for (i=1; i<argC; i++) {
 			printf ("Parametro %d : %s\n", i, argV[i]) ;
 			// char *argV[]: é um ponteiro para um vetor de strings
 		}
  	}
  	printf("\n\n");
 		
 	return 0;
}



