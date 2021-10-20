#include <iostream>
#include "ListaLigada.cpp"
#include <string>


using namespace std;

int main()
{
    Lista listas[10];
    string nome_arquivo;
    int M;
    cout << "Insira o nome do arquivo"<< endl;
    cin >> nome_arquivo;
    cout << "Insira o numero da criptografia" << endl;
    cin >> M;
    tratamento_do_arquivo(listas, nome_arquivo, M);
    for (int i = 0; i < listas->tam();i++){
        listas[i].imprime();
    }
}

// void passagem_externa(Lista* listas){
//     ofstream arquivo("arq.jcripto");
//     for(int i=0;listas->tam;)
// }