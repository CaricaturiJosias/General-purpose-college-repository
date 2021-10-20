#include <stdio.h>

// operadores bit a bit ----------------------------
// & realiza um E bit a bit
// | realiza um OU bit a bit  
// ^ realiza um OU EXCLUSIVO bit a bit (xou)
// ~ faz o complemento (troca 1 por 0 e vice-versa)
// >> desloca n bits a direita (10110>>2 = 101)
// << desloca n bits a esquerda (10110<<2 = 1011000)
// --------------------------------------------------
 
void imprime(int);  

int main() {
	unsigned int a = 0xFAF; // 0x para iniciar numero em hexadecimal
	int b = 0xABC; // int eh 4 bytes 00 00 0A BC
	int c = 8;
	int d = 32;
	int x = 1024;
	
	// FAF   1111 1010 1111
	// ABC   1010 1011 1100
	//  &    1010 1010 1100
	//  |    1111 1011 1111 

	// c = 8   0000 1000
	// d = 32  0010 0000
	//  c^d    0010 1000  (decimal 40)    

	// ABC   1010 1011 1100 
    //  ~    0101 0100 0011
	//         5    4    3

	printf ("a & b: %x \n", a&b);
	printf ("a | b: %X \n", a|b);   
	printf ("c ^ d: %d \n", c^d);   
	printf ("b: %X,  ~b: %X \n", b, ~b);
   
   	printf ("\n\n%X: ", a);
   	imprime (a);
    printf ("\n%X deslocado 4 bits a esq: %X \n", a, a<<4);
    printf ("%X: ", a<<4);
    imprime (a<<4);

  	printf ("\n\n%X: ", b);
   	imprime (b);
    printf ("\n%X deslocado 4 bits a dir: %X \n", b, b>>4);
    printf ("%X: ", b>>4);
    imprime (b>>4);

 	printf("\n\n");

	while (x >= 1) {
		printf ("%d - ", x);
		imprime (x);
		printf ("\n");
		x = x << 1;
	}

    return 0;  
}

void imprime(int x) {  
	if (x<=1) 
		printf("%d", x);  
	else {     
		imprime (x/2); // / div 
		printf ("%d", x%2);  
	}
} 












