#include <stdio.h>
#include <string.h>
#define TAM 3
// criando apelido pra struct de estudante (typedef nome  apelido)
typedef struct{
    char nome[200];
    float n1, n2;
} tEstudante;
// criando apelido pra struct de estudante (typedef nome  apelido)

//cabecalho das funcoes
void lerTurma(tEstudante t[], int tam);
void imprimirTurma(tEstudante t[], int tam);
tEstudante lerEstudante();
int procuraEstudante(estudante);
void imprimirEstudante(tEstudante e); 

// para as abaixos saberem da existencia delas antes de serem declaradas

int main(){
    tEstudante turma[TAM];
    int opcao;
    int pos = 0;
    char estudante[50];
    int encontrado;
    do{   
        printf("\n------ Menu ------\n");
        printf("\n0 - Sair\n");
        printf("\n1 - Mostrar uma turma inteira\n");
        printf("\n2 - Cadastrar um estudante\n");
        printf("\n3 - Imprimir um estudante\n");
        printf("\n4 - ordenar alfabeticamente\n");
        printf("\nQual sua opcao?\n");
        scanf("%d", &opcao);
        // pegar o seleção direta ja feito e adaptar para ordenar A-Z
        switch (opcao)
            {
            case 0:
                exit(0);
                break;
            case 1:
                imprimirTurma(turma, pos);
                break;
            case 2:
                turma[pos] = lerEstudante();
                pos++;
                break;
            case 3:
                printf("\nInsira o nome do estudante: \n");
                setbuf(stdin, NULL);
                fgets(estudante, 50, stdin);
                encontrado = procuraEstudante(turma, estudante, pos);
                if (encontrado < 0) {break;}
                else{
                    imprimirEstudante(turma[encontrado]);}
                break;
            case 4:
            
                break;
            default:
                printf("Opcao inexistente!");
                break;
            }  
    }
    while (opcao !=0);
    return 0; 
}

void lerTurma(tEstudante t[], int tam){
    int i;
    for (i=0;i<tam;i++){
        t[i] = lerEstudante();
    }
}

void imprimirTurma(tEstudante t[], int tam){
    printf("\n------ Turma ------\n");
    int i;
    for (i=0;i<tam;i++){
        imprimirEstudante(t[i]);
    }
}

tEstudante lerEstudante(){
    tEstudante e;
    printf("\nInsira o nome do estudante: ");
    setbuf(stdin, NULL);
    fgets(e.nome, 200, stdin);
    e.nome[strcspn(e.nome, "\n")] = 0; 
    setbuf(stdin, NULL);
    printf("\nInsira as notas do estudante: \n");
    scanf("%f\n%f", &e.n1,&e.n2);
    return e;
}

int procuraEstudante(tEstudante t[], char estudante[50], int tam){
    int i;
    for (i=0;i<tam;i++){
        if (t[i].nome == estudante){
            return i;
        }
    }
    printf("\nEstudante nao valido, insira um estudante existente");
    return -1;
} 

void imprimirEstudante(tEstudante e){
    printf("\n\nNome do estudante: %s", e.nome);
    printf("\nMedia final do estudante: %.2f\n", (e.n1+e.n2)/2);
}

