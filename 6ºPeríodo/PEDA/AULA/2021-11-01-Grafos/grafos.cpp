#include "grafos.h"
#include <iostream>

using std::cout;
using std::endl;


Grafo::Grafo(int num_pos)
{
    int n = num_pos;
    for (int i=0; i< n; i++)
        for(int j=0; j<n; j++)
            adj[i][j] = false;  
};

bool Grafo::validos(int a, int b) const
{
    return (a>=0 && a<n &&  b>= 0 && b<n);
};

void Grafo::une(int a, int b)
{
    if(validos(a,b))
        adj[a][b] = true;
};

void Grafo::une(int a, int b, float p)
{
    //exercicio
};

void Grafo::rmv(int a, int b)
{
    if(validos(a,b))
        adj[a][b] = false;
};

bool Grafo::adjacente(int a, int b) const
{
    if(validos(a,b))
        return adj[a][b];
    else
        return false;
};

void Grafo::imprime() const
{
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < n ; j++)
            cout << adj[i][j];
        cout << endl;
    }
};
