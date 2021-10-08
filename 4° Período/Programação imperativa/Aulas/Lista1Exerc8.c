#include <stdio.h>
int main(){
    int i, x, lista[10];
    int k = 0;
    for (i=0;i<10;i++){
        printf("\nValor: ");
        scanf("%d",&lista[i]);
    }
    i=0;
    do{
        if (lista[i]>lista[i+1]){
            x = lista[i];
            lista[i] = lista[i+1];
            lista[i+1] = x;
            k--;i--;}
        else{k++;i++;}        
    }while (k<10);
    for (i=0;i<10;i++){printf("\n%d",lista[i]);}
    return 0;

}