#include <stdio.h>
// não recebe e não devolve
void printBomDia(){
    printf("Bom dia, sim?\n");
}
// declarou o ponteiro msg como char 
// VOID INDICA QUE NÃO DEVOLVE NADA
//recebe e não devolve
void printMensagem(char *msg){
    printf("%s\n", msg);
}
// pedagógico, não é pra fazer algo tão merda assim em um prog de verdade
//não recebe e devolve (valor em float)
float scanAltura(){
    float altura;
    printf("Qual sua altura (*.** metros)?\nR:");
    scanf("%f", &altura);
    return altura;
}
//recebe e devolve
float aumentaPor(float valor, float porcentagem){
    float valorFinal;
    valorFinal = valor + (valor * porcentagem/100);
    return valorFinal;
}

//Funções

int main() {
    char adeus[] = "Tchau, sim";
    float h;

    printBomDia();

    h = scanAltura();
    printf ("Caso tivesse 20 a mais, teria %.2f m de altura\n", aumentaPor(h, 20)); 
    
    printMensagem(adeus);
    return 0;
}