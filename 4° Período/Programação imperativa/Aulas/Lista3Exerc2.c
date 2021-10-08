//Conjugador
#include <stdio.h>
#include <string.h>
int main(){
    char verbo[25];
    char radical[23];
    int p, i, t;
    char vt;


    char *pronomes[] = {"eu","tu","ele","nos","vos","eles"};
    
    //sufixo por conjugação e tempo
    char *PresenteAr[] = {"o","as","a","amos","ais","am"};            //presente
    char *PreteritoAr[] = {"ei","aste","ou","amos","astes","aram"};   //preterito
    char *FuturoAr[] = {"arei","aras","ara","aremos","areis","arao"}; // futuro

    char *PresenteEr[] = {"o","es","e","emos","eis","em"};            //presente
    char *PreteritoEr[] = {"i","este","eu","emos","estes","eram"};   //preterito
    char *FuturoEr[] = {"er","eras","era","eremos","ereis","erao"}; //futuro

    char *PresenteIr[] = {"o","es","e","imos","is","em"};            //presente
    char *PreteritoIr[] = {"i","iste","iu","imos","istes","iram"};   //preterito
    char *FuturoIr[] = {"irei","irias","iria","iriamos","iireis","iriam"}; //futuro

    
    // baseado na conjugação
    char *finalAr[] = {PreteritoAr, PresenteAr, FuturoAr};
    char *finalEr[] = {PreteritoEr, PresenteEr, FuturoEr};
    char *finalIr[] = {PreteritoIr, PresenteIr, FuturoIr};

    char *conjugacoes[3] = {finalAr, finalEr, finalIr};

    printf("\nInsira um verbo: ");
    scanf("%s", verbo);
    i = strlen(verbo);
    //strcpy(radical, verbo) destino, origem
    strncpy(radical, verbo, i-2); //destino, origem, tamanho
    radical[i-1] = '\0'; //termina a string
    vt = verbo[i-2];
    printf("%s",radical);
    printf("\nVogal tematica: %c",vt);
    // switch sobre vogal tematica para chamar função de conjugação 
    
    for (t=0;t<3;t++){
        for (p=0;p<6;p++){
            printf("\n%s %s%s ", pronomes[p], radical, finalAr[t][p]);
        }
    }
    
    return 0;
}