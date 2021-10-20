//
// Implementação de Árvores Binárias de Busca
// (Representação Explícita por Nós)
//
// PEDA - EC
// Prof. Luiz Lima Jr.
//

#include <iostream>
#include "ArvBin.cpp"

using namespace std;

int main()
{
    ArvBin ab;
    ab.adiciona(20);
    ab.adiciona(40);
    ab.adiciona(22);
    ab.adiciona(10);
    ab.adiciona(5);
    ab.adiciona(60);
    ab.adiciona(50);
    cout << "SIMETRIA" << endl;
    ab.percorre();
}
