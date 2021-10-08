#include <iostream>
#include <string.h>
using namespace std;

constexpr int MAX = 100;

struct musica{
    char nome[MAX];
    float duracao;
    unsigned int nvtocada;
};

int main(){
    std::cout<<"Comecando";
    struct musica lista[MAX] = {0};
    for (int i=0;i<MAX;i++){
        std::cout << endl << "Insira o nome da musica: ";
        char entrada[MAX];
        cin >> entrada;
        for(int j;j<MAX;j++){
            entrada[j] = char(tolower(entrada[j]));
        }
        if (strcmp("fim", entrada) == 0){
            break;
        }
        struct musica musicaNova;
        strcpy(musicaNova.nome, entrada);
        int duracao;
        std::cout << "Insira a duracao da musica: ";
        std::cin >> musicaNova.duracao;
        std::cout << "Insira a quantidade de vezes que a musica foi tocada: ";
        std::cin >> musicaNova.nvtocada;
        lista[i] = musicaNova;
    }
    for (int i=0;i<MAX;i++){
        if ((lista[i].duracao == 0) && (lista[i].nvtocada == 0)){
            break;
        }
        cout << endl << "Nome da musica: " << lista[i].nome << endl
                     << "Duracao: " << lista[i].duracao << endl
                     << "Numero de vezes que a musica foi tocada: " << lista[i].nvtocada;
    }
}
