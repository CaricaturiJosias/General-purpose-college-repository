#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sEstudante {  
    char nome[200];
    float n1, n2;
    struct sEstudante *prox;
} tEstudante;

typedef struct {
    tEstudante *ini;
    tEstudante *fim;
    int qtde;
} tFila;

tFila *criarFila();

int addEstudante (turma, estudante);

// funções para modificar 
void imprimirTurma (tFila *turma);
tEstudante lerEstudante();
void imprimirEstudante (tEstudante *e);
// ---------

int main() {
    tFila *turma; // turma eh uma fila dinamica de estudantes
    tEstudante estudante;
    int opcao;

    turma = criarFila();
    if (turma == NULL) {
        printf ("Problema na alocacao de memoria da FILA!\n");
        exit (1);
    }

    do {
        printf ("\n--- Menu ---\n\n");
        printf ("0 - sair\n");
        printf ("1 - cadastrar um estudante\n");
        printf ("2 - imprimir estudante\n");
        printf ("3 - imprimir turma inteira\n");
        printf ("4 - procurar um estudante");
        printf ("5 - ordenar alfabetica A-Z\n");
        printf ("\nQual sua opcao?\n");    
        scanf ("%d", &opcao);
        switch (opcao) {
            case 0:
                printf ("Quantidade de elementos: %d\n", turma->qtde);
                exit(0);
                break;
            case 1:
                estudante = lerEstudante();
                addEstudante (turma, estudante);
                break;
                // 2 possibilidades: é o primeiro ou final da fila  
            case 2:
                
                break;
            case 3:
                imprimirTurma(turma);
                break;
            case 4:
                
                break; 
            case 5:
                
                break;                
            default:
                printf ("Opcao inexistente! Escolha entre <0>..<4>!");
                break;
        }  
    } while (opcao != 0);  
    return 0;
}

tFila *criarFila(){
    tFila *fila;
    // alocacao dinâmica ha struct tFila
    fila = (tFila*)  malloc (sizeof(tFila));
    if (fila == NULL) // erro na alocacao, volta NULL
        return NULL;
    // passou, entao inicializar os campos da tFila
    fila->ini = NULL;
    fila->fim = NULL;
    fila->qtde = 0;
    return fila;
}

void imprimirTurma (tFila *turma){
    int i;
    tEstudante *e;
    printf ("\n--- Turma ---\n\n");
    printf ("Total de estudantes: %d\n", turma->qtde);
    e = turma->ini;
    for (i=0; i<turma->qtde; i++){
        imprimirEstudante(e);
        e = e->prox;
    }
}

int addEstudante (tFila *turma, tEstudante estudante){
    tEstudante *e;
    e = malloc (sizeof(tEstudante));//tamanho
       // calloc() tamanho e quantas vezes eu quero esse tamanho e limpa o espaço que eu não usar
    if (e == NULL){
        printf("\nProblema de alocação de memória para o novo estudante\n");
        return 1;
    }
    strcpy(e->nome, estudante.nome);
    e->n1 = estudante.n1;
    e->n2 = estudante.n2;
    e->prox = NULL;
    if (turma->ini == NULL) {
        turma->ini = e;
        turma->fim = e;
    } else {
        turma->fim->prox = e;
        turma->fim = e;
    }
    turma->qtde++;
    return 0;
    }


tEstudante lerEstudante(){
    tEstudante e;
    setbuf (stdin, NULL); 
    printf ("\n--- Ler Estudante ---\n\n");
    printf ("Nome: ");
    fgets (e.nome, 200, stdin);  
    e.nome[strcspn(e.nome, "\n")] = 0;
    // ler as notas
    return e;
}

void imprimirEstudante (tEstudante *e){
    printf ("Nome: %s\n", e->nome);
    // mostrar notas e média
}