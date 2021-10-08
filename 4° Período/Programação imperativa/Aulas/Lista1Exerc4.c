#include <stdio.h>

int main(){
   
    int lista[10], valor, i;

    do{
        printf("Valor?\n");
        scanf("%d",&valor);
        i++;
    } while (i < 10);
    
    return 0;
}