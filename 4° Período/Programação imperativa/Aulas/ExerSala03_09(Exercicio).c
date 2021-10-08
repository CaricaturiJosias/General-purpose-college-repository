#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randint(int v1,int v2){
    int num;
    num = v1 + rand()%v2;
    return num;
}

int sum(int *p, int tamanho){
    int i, soma = 0;
    for (i=0;i<tamanho;i++){
        soma = soma + *(p+i); 
    }
    return soma;
}

int main(){    
    int i, v[10];
    srand(time(NULL));
    for (i=0;i<10;i++){
        v[i] = randint(100,900); 
        printf("%d %d",i,v[i]);}
    printf("\nSoma = %d",sum(v, 10));
    return 0;
}