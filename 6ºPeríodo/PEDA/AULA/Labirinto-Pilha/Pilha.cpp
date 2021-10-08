#include "Pilha.h"
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

Pilha::Pilha(std::vector<string> lab)
{
    labirinto = lab;
    topo_ = -1;
    caminho = {0};
}

//  posicoes no lab -> 
//  1 - Para cima ^
//  -1 - Para baixo v
//  2 - Para esquerda <
//  -2 - Para direita >

// funcao recursiva 
// começo
// olha em volta
    //tenta entrar em cada um dos casos
    //olha para 1
    //olha para -1
    //olha para 2
    //olha para 3
// se move dando push no caminho
    // return
// se só parede volta e da pop
    // return
// se labirinto[pos 1][pos 2] == 'S' volta tudo

std::vector<int> Pilha::procura(vector<int> posicao)
{
    vector<int> retorno;
    if (labirinto[posicao[0]][posicao[1]] == 'S'){
        return posicao;
    }
    if (labirinto[posicao[0]][posicao[1]] == 'X'){
       pop();
       return posicao;
    }
        // funcao recursiva 
        // começo
        // olha em volta
            //tenta entrar em cada um dos casos
            //olha para 1 (cima)
    if (!((posicao[0]-1) < 0) && (caminho[topo_] != 4) && !(labirinto[posicao[0]-1][ posicao[1]] == 'E') && (caminho[topo_+1] != 1) && !(labirinto[posicao[0]-1][ posicao[1]] == '*')) // o && serve para evitar que o item reverta o comando e entre em loop infinitamente
    {
        push(1);
        if (labirinto[posicao[0]][posicao[1]] != 'E')    
            labirinto[posicao[0]][posicao[1]] = '*';
        retorno = procura({posicao[0]-1, posicao[1]});
        if (labirinto[retorno[0]][retorno[1]] == 'S')
            return retorno;
        if (labirinto[posicao[0]][posicao[1]]!= 'E')   
            labirinto[posicao[0]][posicao[1]] = ' ';  
    }
    //olha para 4 (baixo)
    if (!((posicao[0]+1) > 19) && (caminho[topo_] != 1) && !(labirinto[posicao[0]+1][posicao[1]] == 'E') && (caminho[topo_+1] != 4) && !(labirinto[posicao[0]+1][posicao[1]] == '*'))
    {
        push(4);
        if (labirinto[posicao[0]][posicao[1]] != 'E')  
            labirinto[posicao[0]][posicao[1]] = '*';
        retorno = procura({posicao[0]+1, posicao[1]});
        if (labirinto[retorno[0]][retorno[1]] == 'S')
            return retorno;
        if (labirinto[posicao[0]][posicao[1]] != 'E')   
            labirinto[posicao[0]][posicao[1]] = ' ';
    }
    //olha para 2 (esquerda)
    if (!((posicao[1]-1) < 0) && (caminho[topo_] != 3) && !(labirinto[posicao[0]][posicao[1]-1] == 'E') && (caminho[topo_+1] != 2) && !(labirinto[posicao[0]][posicao[1]-1] == '*'))
    {
        push(2);
        if (labirinto[posicao[0]][posicao[1]]!= 'E')    
            labirinto[posicao[0]][posicao[1]] = '*';
        retorno = procura({posicao[0], posicao[1]-1});
        if (labirinto[retorno[0]][retorno[1]] == 'S')
            return retorno;
        if (labirinto[posicao[0]][posicao[1]]!= 'E')   
            labirinto[posicao[0]][posicao[1]] = ' ';
    }
    //olha para 3 (direita)
    if (!((posicao[1]+1) > 20) && (caminho[topo_] != 2) && !(labirinto[posicao[0]][posicao[1]+1] == 'E') && (caminho[topo_+1] != 3) && !(labirinto[posicao[0]][posicao[1]+1] == '*'))
    {
        push(3);
        if (labirinto[posicao[0]][posicao[1]]!= 'E')   
            labirinto[posicao[0]][posicao[1]] = '*';
        retorno = procura({posicao[0], posicao[1]+1});
        if (labirinto[retorno[0]][retorno[1]] == 'S')
            return retorno;
        if (labirinto[posicao[0]][posicao[1]]!= 'E')   
            labirinto[posicao[0]][posicao[1]] = ' ';
    }
    labirinto[posicao[0]][posicao[1]] = ' ';
    pop();
    return posicao;
};

vector<int> Pilha::encontra()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (labirinto[i][j] == 'E')
            {
                return {i,j};
            }
        }
    }
    cerr << "Erro, nao foi encontrada uma entrada" << endl;
    return {0,0};
};

std::vector<int> Pilha::encontraFim()
{
    vector<int> retorno;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if ((labirinto[i][j] == 'S') == 1)
            {
                retorno = {i, j};
                return retorno;
            }
        }
    }
    cerr << "Erro, nao foi encontrada uma saida" << endl;
    return {0,0};
};

void Pilha::pop()
{
    if (!vazia())
        topo_--;
    else 
        cerr << "Erro, a fila esta vazia" << endl;
};

void Pilha::push(int i)
{
    if (!cheia()){
        topo_++;
        caminho[topo_] = i;
        }
    //cerr << "Erro, a fila esta cheia" << endl;
};

bool Pilha::vazia()
{
    return (topo_ == -1);   
};

bool Pilha::cheia()
{
    return (topo_== (MAXPILHA-1));
};

void Pilha:: printaLab() 
{
    cout << "_______________" << endl;
    cout << "***labirinto***" << endl;
    cout << "PEDA - Ativ. P1" << endl;
    cout << "Aluno          " << endl;
    cout << "Gabriel Vitor C" << endl;
    cout << "entrada = (" << encontra()[0] << ", " << encontra()[1] << ")" << endl;
    for (int i = 0;i<20;i++)
	{
		cout << labirinto[i] << endl;
	}
}