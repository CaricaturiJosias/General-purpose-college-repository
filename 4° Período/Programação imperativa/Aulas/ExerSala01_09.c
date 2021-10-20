#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 4

int main(){
    int m[TAM][TAM];
    int i, j, achou; 
    // quero ler 16 numeros, que não se repitam
    //passos: 1-ler o numero, 2-checar, 2.1se for repetido negar, 2.2se não continuar
    srand((unsigned)time(NULL));
    int *p;
    p = &m;

    for (i=0; i<TAM*TAM; i++){
        *(p+i) = 1 + rand() % 16;
        achou = 0;
        printf("Num %d: ",*(p+i));
        
        for (j=0;j<i;j++){
            printf("[%d] ", *(p+j));
            if (*(p+j) == *(p+i)){
                achou = 1;
                printf("R");
            }
        }
        printf("\n");
        if (achou){
            i--;
        }
    return 0;
    }
}