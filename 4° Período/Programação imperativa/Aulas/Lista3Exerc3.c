#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char *leet[] = {"4","|R", "&", "g", "/-;"};
    char frase[10];
    int i;
    i = 0;
    printf("Qual sua frase? \n");
    // scanf("%s", frase); //sem & para uma palavra
    // printf("%s",frase);
    // printf("?");
    // gets(frase); não é seguro pois pode invadir lugares aleatórios da memória
    fgets(frase, 10, stdin); // (quem; quantos char; origem)
    
    for (i=0;i<strlen(frase);i++){
        printf("\n%c -",frase[i]);
        printf("%s",leet[ toupper(frase[i])-65]);
    }
    
    printf("\n%s",frase);
    return 0;
}