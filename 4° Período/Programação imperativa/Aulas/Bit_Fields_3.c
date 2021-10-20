#include <stdio.h>

typedef struct {
	unsigned h0 : 4; 
	unsigned h1 : 4; 
} sBits;
 
// com a union o espaço de memória é único e compartilhado pelos campos
// logo, v e bits ocupam o mesmo byte
typedef union {
	unsigned char v;
	sBits bits;
} uValor;

int main () {
	uValor x;
	x.v = 0xFF;
	printf ("v: %X\n", x.v);
	
	x.bits.h1 = 0xA;
	printf ("b0: %X\n", x.bits.h0);
	printf ("b1: %X\n", x.bits.h1);
	printf ("v: %X\n", x.v);
	
	return 0;
}


