#include <stdio.h>
// struct
// definição do tipo construido struct
struct tDados {
    char nome[200];
    float peso;
};



int main(){
    //declaração de variavel
    int i;
    struct tDados pessoa1 = {"Fulano de Tal", 75.2};
    struct tDados pessoa2;
    struct tDados familia[4];
    printf("Insira seu nome: ");
    fgets(pessoa2.nome, 200, stdin);
    printf("Insira seu peso: ");
    scanf("%f",&pessoa2.peso);
    printf("%s (%.2f kg)\n", pessoa1.nome, pessoa1.peso);
    printf("%s (%.2f kg)\n", pessoa2.nome, pessoa2.peso);
    
    familia[0] = pessoa1;
    familia[1] = pessoa2;
    for (i=0;i<2;i++){
        printf("%s",familia[i].nome);
    }
    return 0;
}