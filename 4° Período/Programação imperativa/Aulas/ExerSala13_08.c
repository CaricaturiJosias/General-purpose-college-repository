#include <stdio.h>


#define tam 10
int main(){
    int vetor[tam], vetorf[tam], num;
    int valor,i;

    for(i=0; i<tam-1; i++ ){
        printf("Entre com um numero !\n");
        scanf("%d", &valor);
        if(valor >= 0){
            vetor[i] = valor;
        }else{
            i--;
        }
    }
    for(i = 0; i < tam -1 ; i++){
        printf("%d\n",vetor[i]);
        if (vetor[i]%2 == 0)
        {
            vetorf[i] = vetor[i];
            num = i;
        }
    }
    for(; i < tam -1 ; i++){
        printf("%d\n",vetor[i]);
        if (vetor[i]%2 == 1)
        {
            vetorf[i] = vetor[i];
        }
    }
    for(i=num;i<10;i++){
        printf("\nAntes: %d",vetor[i]);
    }
    for(i=0;i<10;i++){
        printf("\nDepois: %d",vetorf[i]);    
    }
    return 0;
}