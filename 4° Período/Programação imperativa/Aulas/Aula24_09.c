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
    struct tDados *ps;

    printf("Insira seu nome: ");
    fgets(pessoa2.nome, 200, stdin);
    printf("Insira seu peso: ");
    scanf("%f",&pessoa2.peso);
    
    printf("%s (%.2f kg)\n", pessoa1.nome, pessoa1.peso);
    printf("%s (%.2f kg)\n", pessoa2.nome, pessoa2.peso);
    
    familia[0] = pessoa1; // ISSO É UMA COPIA NÃO UMA REFERENCIA (POSSO MUDAR 1 SEM MUDAR O OUTRO)
    familia[1] = pessoa2;

    ps = &pessoa2; //referencia (aponta para o msm local de pessoa2)
    ps->peso += 10;
    printf("\n%s (%.2f)",pessoa2.nome, pessoa2.peso);

    printf("\nTamanho de dados: %d", sizeof(struct tDados));
    printf("\nTamanho de dados: %d", sizeof(pessoa1));
    printf("\nTamanho de dados: %d", sizeof(pessoa2));
    printf("\nTamanho de dados: %d", sizeof(familia[0]));
    printf("\nTamanho de dados: %d", sizeof(*ps));
    printf("\nTamanho de dados: %d", sizeof(familia)); // 4x o espaço de familia[algo]
    printf("\n&ps: %X -  ps:%X  -  *pesssoa2: %X - &familia[0] = %X",
    &ps, ps, &pessoa2, &familia[1]); //ponteiro em memoria
    return 0;
}