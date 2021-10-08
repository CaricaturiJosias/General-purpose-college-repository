#include <stdio.h>
#include <string.h>
// criando apelido pra struct de estudante (typedef nome  apelido)
typedef struct sEstudante {
    char nome[200];
    float n1, n2;
    struct sEstudante *prox;
} tEstudante;

typedef struct {
    tEstudante *ini;
    tEstudante *fim;
    int qntd;
}   tFila;

tFila *criarFila();


//cabecalho das funcoes
void lerTurma(tEstudante t[], int tam);
void imprimirTurma(tEstudante t[], int tam);
tEstudante lerEstudante();
void imprimirEstudante(tEstudante e); 

// para as abaixos saberem da existencia delas antes de serem declaradas

int main(){
    int opcao;
    int pos = 0;
    tFila *turma;
    turma = criarFila();
    if (turma == NULL){
        printf("Problema de alocacao de memoria");
        return 0;
    }


    do{   
        printf("\n------ Menu ------\n");
        printf("\n0 - Sair\n");
        printf("\n1 - Cadastrar um estudante\n");
        printf("\n2 - Imprimir um estudante\n");
        printf("\n3 - Mostrar uma turma inteira\n");
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
                break;
            case 2:

                break;
            case 3:
                imprimirTurma(turma, pos);
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

tFila *criarFila(){
    tFila *fila;
    //alocacao dinamica da struct tFila
    (tFila*) malloc(sizeof(tFila));
    if (fila == NULL) //Erro na alocacao, volta NULL
        return NULL;
    // passou, entao vamos iniciar os campos da tFila
    fila->ini = NULL;
    fila->fim = NULL;
    fila->qntd = 0;
    return fila;
}

void imprimirEstudante(tEstudante e){
    printf("\n\nNome do estudante: %s", e.nome);
    printf("\nMedia final do estudante: %.2f\n", (e.n1+e.n2)/2);
}

