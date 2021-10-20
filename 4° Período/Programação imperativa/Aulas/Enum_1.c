#include <stdio.h>

// tipo enumerado
// domingo recebe valor 0
// os demais, conta de 1 em 1
enum dias {domingo, segunda, terca, quarta, quinta, sexta, sabado};
           
char *nome[] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"};

main () {
	int d = terca; // atribui 2 a d
	printf ("d = %d\n", d);
	d++; // d incrementa para 3
	printf ("d = %d\n", d);

	printf ("dia %d = %s\n", d, nome[d]);
    printf ("dia %d = %s\n", sabado, nome[sabado]);
	
	printf ("\nLoop:\n");
	for (d=domingo; d<=sabado; d++) {
	   printf ("  d = %d (%s)\n", d, nome[d]);		
	}	
}

