#include <stdio.h>

struct Str {
	char c;
	int i;
	float f;
};

union Uni {
	char c;	
	int i;
	float f;
};
 
int main (){
   struct Str s;
   // usando struct, cada campo eh independente, tem
   // seu espaco unico reservado
   
   union Uni u;
   // usando union o espaco de memoria eh unico e compartilhado pelos campos
   // o tamanho total da union sera o tamanho do maior campo 
   
   printf ("Tamanho do c (char): %lu bytes\n", sizeof(s.c)); 	
   printf ("Tamanho do i (int): %lu bytes\n", sizeof(s.i));
   printf ("Tamanho do f (float): %lu bytes\n\n", sizeof(s.f));

   printf ("Tamanho do s (struct): %lu bytes\n", sizeof(struct Str));
   printf ("Tamanho do u (union): %lu bytes\n", sizeof(union Uni));
   
   u.f = 12345.6;
   printf ("Valores da union: char:'%c' int:%d float:%f \n", u.c, u.i, u.f); 	
   u.c = 'A';
   printf ("Valores da union: char:'%c' int:%d float:%f \n", u.c, u.i, u.f); 	
   u.i = 9876;
   printf ("Valores da union: char:'%c' int:%d float:%f \n", u.c, u.i, u.f); 	
   
   return 0;
   
}




