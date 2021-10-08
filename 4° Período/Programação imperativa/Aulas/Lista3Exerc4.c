#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    
    //Reconhecer / validar dentre 1 a 999 numeros
    int num, cent, deze, unid;
    printf("\nInsira um numero de 1 a 999: ");
    scanf("%d", &num);
    if (num<1||num>999){
        printf("\nNumero invalido, nao esta entre 1 e 999 ");
        return 1;
        }
    //indentificar numeros
    
    //centena
    cent = num/100;
    printf("\nCentena: %d", cent);
    //dezena
    deze = (num-cent*100)/10;
    printf("\nDezena: %d", deze);
    //unidade
    unid = num-10*(deze+10*cent);
    printf("\nUnidade: %d", unid);

    //Nomenclatura dos numeros
    char *cen[] = {"","Cento","Duzentos","Trezentos","Quatrocentos","Quinhentos", "Seicentos", "Setecentos", "Oiticentos", "Novecentos"};
    char *dez[] = {"","dez","vinte","trinta","quarenta","cinquenta","sessenta","oitenta","noventa"};
    char *uni[] = {"", "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito","nove"};
    char *estranhos[] = {"cem","onze","doze","treze","quatorze","quinze","dezesseis", "dezessete", "dezoito", "dezenove"};

    //imprime e define quando colocar E ou os estranhos
    printf("\nNumero digitado: %d",num);
    printf("\nEm extenso: ");
    
    //centenas
    //exceções no [estranhos] na centenas
    if (cent  == 1 && deze == 0 && unid == 0){
        printf("%s", estranhos[0]);
        return 0;}
    printf("%s", cen[cent]);
    
    //dezenas
    //exceções nas dezenas
    if ((cent!=0) && (deze != 0 || unid != 0)){printf(" e ");}
    
    // esse if já insera ambas dezena e unidade
    if ((deze == 1) && (unid>0)){
        printf("%s", estranhos[unid]);
    }
    else {
        printf("%s", dez[deze]);
        //unidades
        
    if (unid != 0){printf(" e ");}}
    if (deze != 1 && unid != 0){
    printf("%s", uni[unid]);}
    
    return 0;
}
