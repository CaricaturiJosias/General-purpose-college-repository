#include <stdio.h>

int main(){
    
    // i, K e C = Contadores
    int num, i, cubo, res, C;

    // pega o valor n
    printf("\nInsira o valor N: ");
    scanf("%d", &num);
    
    int K = 1;
    
    //faz o contador de i até is
    for (i=1;i<(num+1);i++){
        
        //define n³
        cubo = (i*i*i);
        
        C = 0;       
        res = 0;
        
        int seq[i];

        printf("\n\nSequencia para %d",i);

        //enquanto a sequencia não ter soma = n³ ele continua
        for(;res!=cubo;K++){
            //checa se é impar
            if (K%2 != 0){
                //se é impar junta na soma e volta pra comparação
                res = res + K;
                seq[C]= K;
                printf("\nValor %d: %d", C, seq[C]);
                C++;
            }  
        }
    } 
    return 0;  
}