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
} tLista;

// funcoes ok com nova abordagem 
tLista *criarFila();
int addEstudante (tLista *, tEstudante);
tEstudante *getEstudante (tLista *, int);
tEstudante *getEstudantes (tLista *);
void imprimirTurma (tLista *);
tEstudante lerEstudante();
void imprimirEstudante (tEstudante *);
void exportaArquivo(tEstudante *, tLista*, FILE *);
void importaArquivo(tLista*, FILE *);
void removeEstudante(tLista*);
void ordenaAlfabeto(tLista*);
// ---------

int main() {
    tLista *turma; // turma eh uma lista dinamica de estudantes array-like
    tEstudante estudante;
    tEstudante *est;
    int opcao;
    int pos;
    FILE *fin, *fout;

    turma = criarFila();
    if (turma == NULL) {
        printf ("Problema na alocacao de memoria da lista!\n");
        exit (1);
    }

    do {
        printf ("\n--- Menu ---\n\n");
        printf ("0 - sair\n");
        printf ("1 - cadastrar um estudante\n");
        printf ("2 - consultar estudante pelo indice\n");
        printf ("3 - consultar estudante pelo nome\n");
        printf ("4 - remover estudante pelo indice\n");        
        printf ("5 - imprimir turma inteira\n");
        printf ("6 - ordenar alfabetica A-Z\n");
        printf ("7 - exportar para arquivo CSV\n");
        printf ("8 - importar de arquivo CSV\n");
        printf ("\nQual sua opcao? ");    
        scanf ("%d", &opcao);
        switch (opcao) {
            case 0:
                exit(0);
                break;
            case 1:
                estudante = lerEstudante();
                if (addEstudante (turma, estudante) != 0){
                    printf ("Ocorreu um problema, %s nao pode ser adicionado\n", estudante.nome);
                } printf ("\n\n<%s> adicionado na lista!\n", estudante.nome);
                break;
            case 2:
                printf ("\n--- Consultar Estudante ---\n\n");
                printf ("Qual posicao? ");
                scanf ("%d", &pos);
                est = getEstudante(turma, pos);
                imprimirEstudante(est);
                break;
            case 3: 
                getEstudantes(turma);
                break;                            
            case 4:               
                removeEstudante(turma);
                break;                
            case 5:
                imprimirTurma(turma);                
                break;
            case 6: 
                ordenaAlfabeto(turma);              
                break;                            
            case 7:
                exportaArquivo(est, turma, fout);
                break;                  
            case 8:    
                importaArquivo(turma, fin);     
                break;                                  
            default:
                printf ("Opcao inexistente! Escolha entre <0>..<4>!");
                break;
        }  
    } while (opcao != 0);  
    return 0;
}

tLista *criarFila(){
    tLista *fila;
    // alocacao dinâmica ha struct tLista
    fila = (tLista *) malloc (sizeof(tLista));
    if (fila == NULL) // erro na alocacao, volta NULL
        return NULL;
    // passou, entao inicializar os campos da tLista
    fila->ini = NULL;
    fila->fim = NULL;
    fila->qtde = 0;
    return fila;
}

int addEstudante (tLista *turma, tEstudante estudante){
    tEstudante *e;
    // verificar se turma existe
    if (turma == NULL){
        // se a turma nao existe na memoria
        printf("\nNao existe turma para adicionar o aluno que deseja registrar!");
        return 1;
    }
    e = (tEstudante *) malloc (sizeof(struct sEstudante));
    if (e == NULL){
        printf ("Problema na alcoacao de memoria para o novo estudante!\n");
        return 2;
    }
    // passou daqui, entao inicializa os campos
    strcpy (e->nome, estudante.nome); 
    e->n1 = estudante.n1;
    e->n2 = estudante.n2;
    e->prox = NULL;    
    if (turma->ini == NULL) { // lista esta vazia, coloca e em primeiro
        turma->ini = e;
        turma->fim = e;
    } else {  // lista ja possui elementos, entra por ultimo
       turma->fim->prox = e;
       turma->fim = e;   
    }
    turma->qtde++;
    return 0;
}

tEstudante *getEstudante (tLista * turma, int pos){
    tEstudante *e;
    int i;
    // turma==NULL          lista nao foi criada
    // turma->qtde==0       lista existe mas esta vazia
    if (turma==NULL || turma->qtde==0){
        return NULL;
    }
    // pos<0                nao existe posicao negativa na lista, ef zero-based
    // pos>=turma->qtde     nao existe posicao alem da quantidade existente
    if (pos<0 || pos>=turma->qtde){
        return NULL;
    }
    // passou, entao procura o estudante da posicao pos
    e = turma->ini;  // endereco do primeiro estudante, posicao ZERO da lista
    i = 0;
    while (i < pos){
        e = e->prox; // pega o proximo estudante da lista
        i++;         // incrementa o indice ate achar a pos pedida  
    }
    return e;
}

tEstudante *getEstudantes (tLista * turma){
    tEstudante *e;
    tEstudante teste;
    printf ("\n--- Ler Estudante ---\n\n");
    printf ("\nNome: ");
    setbuf (stdin, NULL); 
    fgets (teste.nome, 200, stdin);
    teste.nome[strcspn(teste.nome, "\n")] = 0;
    int i;
    int achou = 0;
    char *subs;
    e = turma->ini;
    // se qntd(letras em comum com estudante atual) = qntd(letras do nome dado)
    // significa que existe algo igual no nome do estudante atual
    for (i=0;i<turma->qtde;i++){     
        subs = strstr(e->nome,teste.nome);
        subs[strcspn(teste.nome, "\n")] = 0;
        printf("\na = %d",strlen(e->nome));
        printf("\nb = %d",strlen(subs));
        printf("\nc = %d",strlen(teste.nome));
        if (strlen(subs) == strlen(teste.nome)){
            printf("\n\nEstudante encontrado!");
            imprimirEstudante(e);
            achou++;}
        e = e->prox;}
    if (achou == 0){printf("\nNenhum estudante com o nome dado foi encontrado");}
}

tEstudante lerEstudante(){
    tEstudante e;
    printf ("\n--- Ler Estudante ---\n\n");
    printf ("\nNome: ");
    setbuf (stdin, NULL); 
    fgets (e.nome, 200, stdin);  
    e.nome[strcspn(e.nome, "\n")] = 0;
    printf("\nInsira a nota 1: ");
    setbuf (stdin, NULL); 
    scanf(" %f",&e.n1);
    printf("\nInsira a nota 2: ");
    setbuf (stdin, NULL); 
    scanf("%f",&e.n2);
    printf("\nnotas: %.2f %.2f", e.n1, e.n2);
    return e;
}

void imprimirTurma (tLista  *turma){
    tEstudante *e;
    int i;

    // teste de NULL para a lista
    if (turma==NULL){
        printf ("Turma inexistente!\n");
        return;
    }

    printf ("\n--- Turma ---\n\n");
    printf ("Total de estudantes: %d\n", turma->qtde);
    //1a. opcao: usando a qtde de elementos da lista para efetuar um loop for
    e = turma->ini; 
    for (i=0; i<turma->qtde; i++){
        imprimirEstudante(e);
        e = e->prox;
    }
    // 2a. opcao: usando o fato de que o ultimo aponta para NULL
    /*
    e = turma->ini; 
    while (e != NULL){
        imprimirEstudante(e);
        e = e->prox;
    }
    */
}

void imprimirEstudante (tEstudante *e){
    if (e == NULL){
        printf ("\nEstudante inexistente!\n");
        return;
    }
    printf ("\n\nNome: %s", e->nome);
    printf("\nNota 1: %.2f", e->n1);
    printf("\nNota 2: %.2f", e->n2);
    printf("\nMedia: %.2f", (e->n1+e->n2)/2);
}

void exportaArquivo(tEstudante *est, tLista * turma, FILE *fout){
    char nome[40];
    printf("\n------ Exportar arquivo para CSV ------");    
    printf("\nQual o nome do arquivo(sem espacos e com extensao)?\n");
    scanf("%s", &nome);
    fout = fopen(nome, "w");
    if (fout == NULL){
        printf("Nao foi possivel criar o arquivo saida <%s>", nome);
    } else {
        est = turma->ini;
        while(est != NULL){
            fprintf(fout, "%s;%.2f;%.2f;\n", est->nome,est->n1,est->n2);
            est = est->prox;
            }
        fclose(fout);}     
}

void importaArquivo(tLista *turma, FILE *fin){
    tEstudante estudante;
    char nome[40], str[215], pvirg[2] = ";";
    char *tok, *tol, *spc;
    int i;
    float num;
    printf("\n------ Importar de arquivo CSV ------");    
    printf("\nQual o nome do arquivo(sem espacos e com extensao)?\n");
    setbuf (stdin, NULL); 
    fgets (nome, 200, stdin);
    nome[strcspn(nome, "\n")] = 0;
    fin = fopen(nome, "r");
    if (fin == NULL){
        printf("Nao foi possivel abrir o arquivo <%s>", nome);
    } else {                       
        while (fgets(str, 215, fin) != NULL){
            tok = strtok(str,pvirg);
            for (i=0;i<3;i++){
                switch (i){
                    case 0:
                        strcpy(estudante.nome, tok);
                        break;
                    case 1:
                        num = strtof(tok, &tol);
                        estudante.n1 = num;
                        break;
                    case 2:
                        num = strtof(tok, &tol);
                        estudante.n2 = num;
                        break;
                }
                tok = strtok(NULL,pvirg);
            }    
            addEstudante (turma, estudante);
        }
        fclose(fin);
    }
}

void removeEstudante(tLista *turma){
    int indice, i, qntd;
    tEstudante *e, *aux;
    printf("\n\n---------- Remover estudante ----------");
    printf("\n - Insira o indice do estudante que deseja remover: ");
    setbuf(stdin, NULL);
    scanf("%d",&indice);
    qntd = turma->qtde;
    // verifica existencia
    if ((indice < 0)||(indice >qntd-1)){
        printf("\n\nValor invalido!");
        exit (1);
    }
    e = turma->ini;
    // se for 1 aluno
    if (qntd==1){
        turma->ini = NULL;
        turma->fim = NULL;
        printf("\n\nAluno removido com sucesso");        
        free(e);
        turma->qtde=0;
    }
    //ultimo aluno
    else if ((indice-1) == qntd){
        for (i=0;i<qntd;i++){
            //chega no penultimo e sai
            e = e->prox;
        }
        //coloca o penultimo como ultimo
        turma->fim = e;
        //coloca o ultimo no E para limpar
        e = e->prox;
        //limpa o prox do penultimo (que vai virar ultimo)
        turma->fim->prox = NULL;
        //limpa o ultimo
        printf("\n\nAluno removido com sucesso");
        free(e);
        turma->qtde--;
    }
    //primeiro 
    else if (indice == 0){
        e = turma->ini;
        turma->ini = e->prox;
        printf("\n\nAluno removido com sucesso");        
        free(e);
        turma->qtde--;
    }
    
    // busca o aluno (nao e primeiro nem ultimo)
    else {
        for (i=0;i<(indice-1);i++){
            // chega no anterior
            if (i==(indice-2)){
                aux = (tEstudante *) malloc (sizeof(tEstudante));
                aux = e->prox;
                e->prox = e->prox->prox;
                printf("\n\nAluno removido com sucesso");
                free(aux);
                turma->qtde--;
            }
            e = e->prox;
        }
    }
    
}

void ordenaAlfabeto(tLista *turma){
    int i, resultado, contagem, qntd = turma->qtde;
    tEstudante *e, *t, *aux;
    t = turma->ini;
    e = t->prox;
    for (i=0;i<qntd;i++){ 
        if (i>0){
            contagem = qntd-i;
            if (t->prox->prox == NULL){
                contagem=1;}
            else{
                t=t->prox;
                e = t->prox;
            }
        }
        while (contagem>0){
            resultado = strcmp(t->nome,e->nome);
            if (resultado>0){
                aux = (tEstudante *) malloc (sizeof(tEstudante));
                strcpy(aux->nome,e->nome);
                aux->n1 = e->n1;
                aux->n2 = e->n2;    
                strcpy(e->nome,t->nome);
                e->n1 = t->n1;
                e->n2 = t->n2;    
                strcpy(t->nome,aux->nome);
                t->n1 = aux->n1;
                t->n2 = aux->n2;          
                free(aux);
                contagem = qntd-i;
                e = t->prox;}        
            else{
                if (e->prox == NULL){
                    contagem = 0;}
                else{
                    e = e->prox;
                    contagem--;
                }
            }
        }

    }
}
