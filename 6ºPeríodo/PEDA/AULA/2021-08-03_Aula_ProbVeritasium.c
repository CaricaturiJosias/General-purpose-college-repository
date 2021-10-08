#include <stdio.h>

int main(int argc, char *argv[]){
    int x = argv[1];
    while (x != 1){
        if (x%2 == 1){
            x = 3*x+1;
        }   else    {
            x = x/2;
        }
    }
    printf("\nO número de interações foi de %i", x);
    return 0;
}