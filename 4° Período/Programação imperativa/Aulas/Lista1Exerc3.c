#include <stdio.h>
int main(){
    int ma, me, amp, i;
    int lista[10];

    for (i=0;i<10;i++){
        printf("Insira um valor: \n");
        scanf("%d",&lista[i]);
        if (i==0){
            ma = lista[i];
            me = lista[i];
        }
        else
        {
            if (lista[i]<me){
                me = lista[i];
            }
            else if (lista[i]>ma){
                ma = lista[i];
            }
        }
    }   
    amp = ma-me;
    printf("A amplitude amostral e: %d\n", amp);
    printf("O maior valor dado foi %d\n",ma);
    printf("O menor valor dado foi %d",me);
    return 0;
}