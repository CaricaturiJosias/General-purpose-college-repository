//palindrome
#include <stdio.h>
#include <string.h>
int main(){
    int i, compr;
    int palindrome = 0;
    char string1, string2;
    char *pc, *pc2;
    pc = string1;
    pc2 = string2;
    
    printf("Insira a palavra: ");
    scanf("%s", string1);
    
    compr = (strlen(*pc)-1);
    //checagem caps lock
    
    for (i=0;i<compr+1;i++) {
        *pc[i] = tolower(*pc[i]);
    }
    
    for (i=0;i<compr+1;i++) {
        *pc2[i] = *pc[compr-i];
    } 
    
    for (i=0;i<compr+1;i++){
        if (*pc[i] != *pc2[i]){
            palindrome = 1;
        }
    }
    
    if (palindrome==1){printf("A palavra nao e palindrome");}
    else {printf("A palavra e palindrome");}
    
    return 0;
}


#include<stdio.h>
#include<string.h>
#include<locale.h>
#include <ctype.h>

int main() {
 setlocale(LC_ALL, "");
 int i, valor = 0;
 char palavra[15], inversa[15];
 printf("\nDigite uma palavra: ");
 gets(palavra);
 for(i = 0; palavra[i]; i++){
   palavra[i] = tolower(palavra[i]);
 }
 strcpy(inversa, palavra);
 strrev(inversa);
 valor = strcmp(palavra, inversa);
 if (valor == 0)
   printf("\nA palavra %s é palíndroma\n",palavra);
 else
   printf("\nA palavra %s não é palíndroma\n", palavra);
 return 0;
}