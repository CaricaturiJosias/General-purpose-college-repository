#include <stdio.h>
int main(){
    int tam = 10;
    int i, media, mediaD, lista[tam], desvio[tam];
    for (i=0,media=0;i<10;i++){
        printf("\nValor: ");
        scanf("%d", &lista[i]);
        media += lista[i];
    }
    for (i=0,mediaD=0;i<10;i++){
        desvio[i] = lista[i] - (media/10);
        mediaD += desvio[i];
    }
    printf("\nMedia: %f", (media/10.0));
    printf("\nDesvio Absoluto medio: %f", (mediaD/10.0));
    return 0;
}