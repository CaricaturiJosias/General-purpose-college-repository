#include <stdio.h>

typedef struct {
	unsigned b0 : 1; 
	unsigned b1 : 1; 
	unsigned b2 : 1; 
	unsigned b3 : 1; 
	unsigned b4 : 1; 
	unsigned b5 : 1; 
	unsigned b6 : 1; 
	unsigned b7 : 1; 
} sBits;
 
// com a union o espaço de memória é único e compartilhado pelos campos
// logo, v e bits ocupam o mesmo byte
typedef union {
	unsigned char v;
	sBits bits;
} uValor;

int main () {
	uValor x;
	x.v = 0xF;
	printf ("v: %X\n", x.v);
	printf ("b0: %d\n", x.bits.b0);
	printf ("b1: %d\n", x.bits.b1);
	printf ("b2: %d\n", x.bits.b2);
	printf ("b3: %d\n", x.bits.b3);
	printf ("b4: %d\n", x.bits.b4);
	printf ("b5: %d\n", x.bits.b5);
	printf ("b6: %d\n", x.bits.b6);
	printf ("b7: %d\n", x.bits.b7);
	
	// alterando apenas o bit mais à esquerda, bit b0
	x.bits.b0 = 0;
	printf ("\nv: %X\n", x.v);
	printf ("b0: %d\n", x.bits.b0);
	printf ("b1: %d\n", x.bits.b1);
	printf ("b2: %d\n", x.bits.b2);
	printf ("b3: %d\n", x.bits.b3);
	printf ("b4: %d\n", x.bits.b4);
	printf ("b5: %d\n", x.bits.b5);
	printf ("b6: %d\n", x.bits.b6);
	printf ("b7: %d\n", x.bits.b7);

}


