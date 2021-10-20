#include <stdio.h>
int main(){
    
    int m[][4] ={{1, 5, 8, 7},
                 {3, 3, 6, 2},
                 {5, 3, 7, 9},
                 {8, 5, 4, 6}};
    int *esq, *dir, imp, par, num, i, j;

    esq = &m[0][0];
    dir = &m[3][3];

    // demonstração ponteiro e endereço
    /*
    printf("\nValor 0,0: %d \nvalor 3,3: %d\n", m[0][0], m[3][3]);
    printf("\n(Ponteiro)\nValor 0,0: %d \nvalor 3,3: %d\n", *esq, *dir);
    printf("\nEndereco do 0,0: %p \nEndereco do 3,3: %p\n", &m[0][0], &m[3][3]);
    printf("\n(Ponteiro)\nEndereco do 0,0: %p \nEndereco do 3,3: %p\n", esq, dir);
    //incrementar para o prox valor
    esq++;
    printf("\n(Ponteiro)\nValor 0,1: %d\nEndereco do 0,1: %p" , *esq, esq);
    */
    do{
        printf("\nEsquerda - Endereco %p - Valor: %d", esq, *esq);
        printf("\nDireita  - Endereco %p - Valor: %d", dir, *dir);
        if (*esq%2==1){imp=1;}
        else{esq++;}
        //aumentar esquerda até achar um impar
        if (*dir%2==0){par=1;}
        else{dir--;}
        //diminuir até achar um par
        if ((par==1) && (imp==1)){
             num = *dir;
            *dir = *esq;  *esq = num;
             par = 0;      imp = 0;
             dir--;        esq++;}
        //if achou um par e um impar, troca os 2
    }while(esq<dir);
    for (i=0;i<4;i++){
        printf("\nLinha %d: ",i);
        for(j=0;j<4;j++){
            printf("[%d]",m[i][j]);
        }
    }
    return 0;
}