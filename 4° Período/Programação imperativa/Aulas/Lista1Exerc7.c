#include <stdio.h>

int main(){
    int lista[20];
    int me, n, menor, i, k, tam;
    int c = 0;
    tam = 5;
    for (i=0;i<tam;i++){
        printf("\nValor: ");
        scanf("%d", &lista[i]);
    }
    //procura o menor
    do {
        for (i=c;i<tam;i++){
            if (c==0){
                menor = 0;
                me = lista[menor];
                i++;
            }
            if (lista[i]<lista[menor]){
                me = lista[i];
                lista[i] = lista[menor];
                lista[menor] = me;
            }
        }
        c++;
        //ordena os outros
        lista[menor] = lista[tam-1];
        for (i=tam;i>1;i--){
            lista[tam-i] = lista[tam-(i-1)];
            lista[0] = me;
            
          //  for (i=0;i<menor;i++){
          //       if (menor!=0){
          //           lista[menor-i] = lista[menor-(i+1)];
          //           lista[0] = me;
          //       }
          //   }
        
            for (i=0;i<tam;i++){printf("\nPosicao %d :%d\n",i ,lista[i]);}
        } 
    }while(c<tam);

    return 0;
}