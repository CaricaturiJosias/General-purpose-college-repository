#include "mapa.h"
#include <iostream>
#include <string>
#include <string.h>
#include <limits>
using namespace std;

Mapa::Mapa()
{   
    TipoDado constante = "Nada";
    n = 0;
    for(int i = 0; i < MAXNOS; i++){
        nomes[i] = constante;
        for(int j = 0; j < MAXNOS; j++){
            adj[i][j] = false;
            peso[i][j] = 0;
        }
    }
}

Mapa::~Mapa(){
    delete[]  &peso;
    delete[]  &adj;
    delete[]  &nomes;
}

void Mapa:: adiciona(TipoDado novoNome)
{
    TipoDado constante = "Nada";
    if (n+1 != MAXNOS)
    {
        nomes[n] = novoNome;
        n++;
    }   else    {
        cerr << "Erro! Não existe mais espaço para nomes!" << endl;}
    return;
}

bool Mapa::validos(TipoDado a, TipoDado b)
{
    TipoDado constante = "Nada";
    return (a.compare(constante) != 0 && b.compare(constante) != 0);
};


void Mapa::une(TipoDado a, TipoDado b, float p)
{
    if(validos(a,b))
        adj[valor(a)][valor(b)] = true;
        adj[valor(b)][valor(a)] = true; 
        peso[valor(a)][valor(b)] = p;
        peso[valor(b)][valor(a)] = p;
};

void Mapa::rmv(TipoDado a, TipoDado b)
{
    if(validos(a,b) && adj[valor(a)][valor(b)] == 0 && peso[valor(a)][valor(b)] == 0)
        adj[valor(a)][valor(b)] = false;
        adj[valor(b)][valor(a)] = false;
        peso[valor(a)][valor(b)] = 0;
        peso[valor(b)][valor(a)] = 0;
};

bool Mapa::adjacente(TipoDado a, TipoDado b)
{
    if(validos(a,b))
        return adj[valor(a)][valor(b)];
    else
        return false;
};

int Mapa::valor(TipoDado nome)
{
    for(int i = 0; i < n;i++){
        if (nome.compare(nomes[i]) == 0)
            return i;
    }
    cerr << "Nada encontrado" << endl;
    return (-1);
};

void Mapa::imprime() const
{
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < n ; j++)
            cout << adj[i][j];
        cout << endl;
    }
};

void Mapa::imprimePesos() const
{
    for (int i = 0; i < n ; i++){
        if (nomes[i].compare("Nada") == 0)
            return;
        for (int j = 0; j < n ; j++){
            if (i > j)
                if (peso[i][j] != 0)
                    cout << nomes[i] << " -> " << nomes[j] << " = " << peso[i][j] << endl;}
            // não printara se i = j ou se a distancia for 0
    }
};


void Mapa::imprimeN() const
{
    for (int i = 0; i < n ; i++){
        if (nomes[i] != "Nada")
            cout << nomes[i] << endl;
    }
};

void Mapa::MenorCaminho(TipoDado orig, TipoDado fi)
{
    //contador para no mínimo outro único caminho (mínimo de 2 conexoes por cidade)
    int limite = 0;
    // passagem das strings para seus valores em vetor
    int fim = valor(fi);
    int origem = valor(orig);

    // declaracao de arrays para realizar acompanhamento
    float distancia[n];
    bool calculado[n];
    int caminho[n];
    // variacao 2 para distancia
    float distancia_Passada;
    // variacao 2 para caminho
    int rota_Anterior[n];
    // zera os valores dos arrays
    for (int i = 0; i < n; i++){
        distancia[i] = numeric_limits<float>::max();
        calculado[i] = false;
        caminho[i] = -1;
    }

    // limpa os valores da origem para que não sejam checados

    distancia[origem] = 0;
    calculado[origem] = true;
    int referencia = origem;
    // ordem mais eficiente até o fim
    int rota[n];
    // indicador de quantas buscas o programa podia fazer para achar alguma solução
    int contagem = 0;
    while (referencia != fim){
        //int distanciaObt = 0;

        // valor da menor distancia registrada
        float MenorDist = numeric_limits<float>::max();
        // valor para ser passado para a referencia
        int k;

        // valor atual a ser adicionado no fim de cada interação em distancia
        // a primeira é 0
        float dc = distancia[referencia];

        // loop para checar todos os valores ligados a referencia
        for (int i = 0; i < n; i++){
            if (adj[referencia][i]){
                // não checa valores já checados
                float novaDis;
                if (!calculado[i]){
                    if (peso[referencia][i] != 0)
                        novaDis = dc + peso[referencia][i];
                    else
                        novaDis = numeric_limits<float>::max();
                    // checa os valores comparado a outros passados   
                    
                    if (novaDis < distancia[i]){
                        distancia[i] = novaDis;
                        caminho[i] = referencia;
                    }       
                    if (distancia[i] < MenorDist){
                        MenorDist = distancia[i];
                        k = i;
                    }
                }
            }
        }
        cout << "Cidade: " << nomes[k] << endl;
        /* se existir caminho ele vai ser diferente de -1,
            pois caminho indica o número da cidade que chega em fim*/
        if (caminho[fim] == -1){
            // se eu chego no fim e houve mudança(dc é o antigo valor)
            if (MenorDist != dc){
                calculado[referencia] = true;
                referencia = k;
                /* se ele não obteve mudança, o último item antes desse 
                    apontado por caminho[referencia] é recuperado*/
            }   else    {
                calculado[referencia] = true;
                // retorna a referencia posterior
                referencia = caminho[referencia];
            }
        }   else    {
            if (limite == 0){
                rota_Anterior[n];
                distancia_Passada = distancia[fim];
                int i = fim;
                while (caminho[i] != -1)
                {
                        rota_Anterior[i] = caminho[i];
                        i = caminho[i];
                } 
                limite++;
                calculado[referencia] == true;
                referencia = origem;
                caminho[fim] = -1;

            }   else    {
                
                int i = fim;
                int c = 0;
                    
                if (distancia_Passada > distancia[fim]){
                    cout << endl <<  "Menor caminho = " << fi ;
                    // caso o segundo caminho seja mais curto
                    if (caminho[fim] == origem)
                        cout << " <- " << orig << endl; 
                    else    {
                        while (caminho[i] != -1 && c < n){
                            cout << " <- " << nomes[caminho[i]];
                            i = caminho[i];
                            c++;
                        } 
                    }
                    cout << endl << "Distancia total: " << distancia[fim] << " Km" << endl;
                    return;
                }   else    {
                    // caso o primeiro caminho seja mais curto
                    cout << endl <<  "Menor caminho = " << fi ;
                    if (rota_Anterior[fim] == origem)
                        cout << " <- " << orig << endl; 
                    else    {
                        while (rota_Anterior[i] != -1 && c < n){
                            cout << " <- " << nomes[rota_Anterior[i]];
                            i = rota_Anterior[i];
                            c++;
                        } 
                    }
                    cout << endl << "Distancia total: " << distancia_Passada << " Km" << endl;
                    return;
                }
            }
        }                
    }
};
