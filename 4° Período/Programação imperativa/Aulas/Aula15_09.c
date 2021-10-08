//Conjugador
#include <stdio.h>
#include <string.h>
char LerVerbo(char verbo[]){
    
    int  ultimo, caso = 0;
    char final;
    ultimo = (strlen(verbo) -1);
    final = ("%c", verbo[ultimo-1]);
    printf("\nfinal: %c == a",final);
    if (final == "a"){caso=1;}
    printf(final=="a");
    if (final == "e"){caso=2;}
    if (final == "i"){caso=3;}
    else {caso=0;}

    printf("\ncaso %d\n",caso);
    return caso;
}

int main(){
    char verbo[25];
    char output;
    int final, i; 
    char *sas;
    sas = verbo;
    
    char *pronomes[6] = {"eu","tu","ele","nos","vos","eles"};
    
    //sufixo por conjugação e tempo
    char *PresenteAr[6] = {"o","as","a","amos","ais","am"};            //presente
    char *PreteritoAr[6] = {"ei","aste","ou","amos","astes","aram"};   //preterito
    char *FuturoAr[6] = {"arei","aras","ara","aremos","areis","arao"}; // futuro

    char *PresenteEr[6] = {"o","es","e","emos","eis","em"};            //presente
    char *PreteritoEr[6] = {"i","este","eu","emos","estes","eram"};   //preterito
    char *FuturoEr[6] = {"er","eras","era","eremos","ereis","erao"}; //futuro

    char *PresenteIr[6] = {"o","es","e","imos","is","em"};            //presente
    char *PreteritoIr[6] = {"i","iste","iu","imos","istes","iram"};   //preterito
    char *FuturoIr[6] = {"irei","irias","iria","iriamos","iireis","iriam"}; //futuro

    
    // baseado na conjugação
    char *finalAr[3] = {PreteritoAr, PresenteAr, FuturoAr};
    char *finalEr[3] = {PreteritoEr, PresenteEr, FuturoEr};
    char *finalIr[3] = {PreteritoIr, PresenteIr, FuturoIr};

    char *conjugacoes[3] = {finalAr, finalEr, finalIr};

    printf("\nInsira um verbo: ");
    scanf("%s", verbo);
    printf("%s", verbo);
    final = LerVerbo(verbo);
    printf("%d",final);
 
 //conjuga
    //pronome
    for (i=0;i<6;i++){
    output = "%s ",pronomes[i];
    printf(output);

    }
}