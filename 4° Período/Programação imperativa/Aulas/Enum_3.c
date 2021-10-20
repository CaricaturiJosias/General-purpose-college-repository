#include <stdio.h>

// tipo enumerado com atribuicao de valor
enum dias {segunda=1, terca, quarta, quinta, sexta, sabado, domingo=0};
// neste caso, ate sabado a numeracao a automatica, sabado eh 6
// domingo foi atribuido individualmente 0
    
enum horario {s14, s16, s18, s20, s22};
// neste caso, s14 eh 0... s22 eh 4

enum horario2 {s1=14, s2=16, s3=18, s4=20, s5=22};
// neste daso cada item do enum tem um valor atribuido individualmente

enum logico {F, V}; // F eh 0 e V eh 1
typedef enum logico logico;

typedef enum {
	WORKING = 1,
	STANDBY = 2,
	FAIL    = 4
} status;

main () {
	enum horario2 s;
	enum dias hoje;
	enum logico flag1;  // usando o id da struct
	logico flag2 = F; // usando o id do typedef
	status e;

	flag1 = V;
	e = WORKING;
	while (flag1) {
		printf ("e = %d\n", e);
		if (e == FAIL) flag1 = F;
		e = FAIL;
	}

	s = s5;
	printf ("Valor %d\n", s);
	
	hoje = segunda;
	printf ("%d\n", hoje);
	hoje++;
	printf ("%d\n", hoje);	
	hoje=domingo;	
	printf ("%d\n", hoje);
}
