//Nome do estudante: Gabriel Vitor Cezário
//Turma: Bernoulli/Kepler
//Link vídeo: https://youtu.be/GRgQ0sNOkWI

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
//Headers
typedef struct tm tempo;
char *imprimeM(tempo *);
char *m(int mes);
char *y(int ano);
char *mostrarHoje();
void exportaTexto(char *output, FILE *arqBinario, char *nomeArquivo);
//

int main(int argC, char *argV[]){
    FILE *arqCalendario;
    char *argString, *output;
    int valor, i;
    if (argV[1] == NULL||(strcmp(argV[1],"f")==0)){ 
        output = mostrarHoje();
    }
    else if (strcmp(argV[1],"y")==0){
        valor = atoi(argV[2]);
        output = y(valor);
    }
    else if (strcmp(argV[1],"m")==0){
        valor = atoi(argV[2]);
        output = m(valor);
    }
    else{
        printf("\nParametros invalidos!");
        exit(1);
    }
    //casos arquivo
    for (i=1;i<=argC;i++){
        if (strcmp(argV[i],"f") == 0){
            if(argV[i+1] == NULL){
                printf("\nErro! nao foi detectado um nome para o arquivo");
            }
            else{
                exportaTexto(output, arqCalendario, argV[i+1]);
            }
        }
    }
    return 0;
}

char *y(int ano){
    int i;
    char *output;
    time_t tempoTick = 0;
    tempo *StempoMesDaVez;
    time (&tempoTick);
    StempoMesDaVez = localtime(&tempoTick);

    StempoMesDaVez->tm_hour = 0;
    StempoMesDaVez->tm_min = 0;
    StempoMesDaVez->tm_sec = 0;
    StempoMesDaVez->tm_mon = 0;
    StempoMesDaVez->tm_mday = 1;
    StempoMesDaVez->tm_year = ano-1900;

    for (i=0;i<12;i++,StempoMesDaVez->tm_mon++){
        if (i==0){
        output = (char*) calloc(3000, sizeof(char[1]));
        strcpy(output, "\n        Imprimindo Ano inteiro         \n---------------------------------------");
        strcat(output ,imprimeM(StempoMesDaVez));
        }
        else{
            strcat(output, imprimeM(StempoMesDaVez));
        }
    }
    return output;
}

char *m(int mes){
    char *output;
    time_t tempoTicks;
    tempo *tStruct;
    time (&tempoTicks);
    tStruct = localtime(&tempoTicks);

    tStruct->tm_mon = mes-1;
    tStruct->tm_hour = 0;
    tStruct->tm_min = 0;
    tStruct->tm_sec = 0;
    tStruct->tm_mday = 1;

    output = imprimeM(tStruct);
    return output;
}

char *imprimeM(tempo *Stempo){
    int primeiroDia, i, diasMes, duracaoMes;
    char *output, *quebraLinha[5], *vazio[5];
    strcpy(quebraLinha,"\n   ");
    strcpy(vazio,"    ");
    tempo *aux;  

    // encontra a duração do mês
    aux = (tempo *) malloc(sizeof(tempo));
    aux->tm_year = Stempo->tm_year; aux->tm_mon = (Stempo->tm_mon+1);
    aux->tm_hour = 0;   aux->tm_min = 0;
    aux->tm_sec = 0; aux->tm_mday = 1; 
    
    if (Stempo->tm_mon == 11 || Stempo->tm_mon == 0){
        duracaoMes = 31;
        double diferenca = difftime(mktime(aux),mktime(Stempo));}
    else{   
        double diferenca = difftime(mktime(aux),mktime(Stempo));
        duracaoMes = diferenca/86400;
    }
    free(aux);

    primeiroDia = Stempo->tm_wday;
    // torna diasMes o ultimo dia do mes
   
    output = (char*) calloc(250, sizeof(char[1]));
    sprintf(output,"\n\n--- Mes %d do ano de %d---",Stempo->tm_mon+1,Stempo->tm_year+1900);
    strcat(output, "\n\n   DOM SEG TER QUA QUI SEX SAB\n");
    strcat(output,quebraLinha);
    for(i=0, diasMes = 1;i<=(duracaoMes+primeiroDia-1);i++){
        if (i<primeiroDia)
            strcat(output,vazio);
        else{
            char diaNumero[4];
            char adicao[4];
            if (diasMes<10)
                sprintf(&diaNumero," %d  ",diasMes);
            else 
                sprintf(&diaNumero," %d ",diasMes);
            strcat(output,&diaNumero);   
            diasMes++; 
            if ((i+1)%7 == 0)
                strcat(output, quebraLinha);
        }
    }
    printf("%s\n", output); 
    return(output);
}

char *mostrarHoje(){
    char *output;
    time_t tempAtual;
    tempo *Hoje;
    time (&tempAtual);
    Hoje = localtime(&tempAtual);
    Hoje->tm_hour = 0;
    Hoje->tm_min = 0;
    Hoje->tm_sec = 0;
    Hoje->tm_mday = 1;
    printf("\n\nCalendario do mes:\n");
    output = imprimeM(Hoje);
    return output;
}

void exportaTexto(char *output, FILE *arqCalendario, char *nomeArquivo){
    arqCalendario = fopen(nomeArquivo, "w");
    fputs(output, arqCalendario);
    fclose(arqCalendario);
    printf("\nArquivo em texto registrado com sucesso");
}