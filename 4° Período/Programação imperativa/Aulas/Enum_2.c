#include <stdio.h>

// tipo enumerado com atribuicao de valor
enum dias {segunda=2, terca, quarta, quinta, sexta, sabado, domingo};
// neste caso, terca vale 3, e assim por diante           

main () {
	int d = terca + quarta;
	printf ("d = %d\n", d);
	d++;
	printf ("d = %d\n", d);
	
}
