#include <stdio.h>

int main(){
    //calcular c, d ,u usando mod e div
    char *uni[] = {"", "I", "II", "III", "IV"}; //até 9
    char *dez[] = {"", "X", "XX", "XXX", "XL"}; //até 90
    char *cen[] = {"", "C", "CC", "CCC", "CD"}; //até 900
    printf("%s%s%s", uni[4], dez[4], cen[4]); // c, d e u são indices dos vetores
 
    return 0;
}