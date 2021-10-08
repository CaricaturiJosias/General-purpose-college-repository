#include <stdio.h>
int main()
{
    int pn ; 
    int un ;
    int m, n, ccao = 0;

    while (ccao != 1)
    {
        printf("Insira um numero: \n");
        scanf("%d", n);
        if (un == NULL)
        {
            if (pn == NULL)
            {
                pn = n;
            }
            else if (n>pn)
            {
                un = n;
            }
            else
            {
                pn = n;
            }
        }
        else
        {
            if (n>pn)
            {
                if (n>un)
                {
                    ccao = 1;
                }
                else
                {
                    pn = n;
                    un = NULL;
                }
            }
            else
            { 
            pn = n;
            un = NULL;
            }
        }
    }
    m = ((n+un+pn)/3);
    printf("A media dos 3 ultimos numeros e: %d", m);
    return 0;
}
    

