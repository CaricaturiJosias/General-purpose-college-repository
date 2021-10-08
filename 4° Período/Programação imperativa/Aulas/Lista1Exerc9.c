#include <stdio.h>
#include <time.h>
#define TAM 12

int main(){
    int m[TAM][TAM], valor, *p, i, j, n, pos, erro;
    p = m;
    erro = n = 0;
    // quero ler 16 numeros, que não se repitam
    //passos: 1-ler o numero, 2-checar, 2.1se for repetido negar, 2.2se não continuar
    srand(time(NULL));
    for (i=0;i<TAM;i++){
        for (j=0;j<TAM;j++){
            valor = 1 + rand() % (TAM*TAM);
            //valor inicial
            if ((&m[i][j])==(&m[0][0])){m[0][0]=valor;n++;}
            //checagem
            else{
                pos = n;
                do{
                    if (valor==*p){
                        printf("ERRO!\nValor repitido.\n"); 
                        if (j== 0){i--;j=(TAM-1);}
                        else {j--;} 
                        erro = 1; 
                        p = &m[i][j];
                    }                   
                    else {p--;n--;}
                }while((erro==0) && (n>0));
                n = pos;

                //se não repete, insere o valor, volta o ponteiro pra ultima posição e termina a volta no laço
                if (erro==0) {m[i][j]=valor; p= &m[i][j];n++;}      
            }// else   
            erro = 0;
        } // segundo for
    } //primeiro for
    for (i=0;i<TAM;i++){
        printf("\nLinha %d:",i+1);
        for (j=0;j<TAM;j++){
            printf("  [%d]", m[i][j]);
        }
    }
    //para checar: ler as posições previás a n até 0 (&(n-1)->&0) com contador n
    //para comparar os numeros: guardar o valor a ser checado (var) e pular as posições(ponteiro)
    //se repetir: colocar valor em cond como 1
    
    return 0;
}