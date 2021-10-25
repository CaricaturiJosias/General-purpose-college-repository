#include "ListaJosefo.cpp"
#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <bits/stdc++.h>

void passagem_externa(Lista* listas){
    cout << "Criando arq.jcripto" << endl;
    ofstream arquivo;
    arquivo.open("arq.jcripto");
    for(int i=0;i<listas->tam();i++){
        arquivo << (listas[i].imprime()) << endl;
    }
    arquivo.close();
}
  

void Lista::josefo (int m){
    cout << imprime() << endl;
    Lista novaLis;
    Lista auxiLis;
    // tira itens de 3 em 3 até a lista estiver vazia
    // quantidade de iterações = numero de itens * m por razoes obvias
    // retirada de espaço vazio padrão residual
    remove();
    int duracao_listas = tam();
    for (int j=1; j < (duracao_listas*m) ; j++) {
        // sempre haverá remoção, só resta dizer onde irá
        TipoDado x = remove();       
        // caso só tenha 1 ou 2 itens ele devolve pra fazer a seleção
        if (x == "Erro"){       
            // ultimo item disponivel
            if (auxiLis.tam() == 1)
            {
                j = (duracao_listas*m+1)*3;
                x = auxiLis.frente();
            // tem 2 itens diferentes, o primeiro deve ir de volta para a lista então o 
            //segundo irá eventualmente ir para o primeiro caso do if
            } else {
                insere(auxiLis.remove());
            }
        }


        //se ele deve ser recolocado na outra lista, faz isso e devolve os auxiLis de volta
        ///////////////////////////////////////////////////////////////////////
        ///////// ESTA PARTE É RESPONSÁVEL PELO PROBLEMA //////////////////////
        //////////////////E EU NÃO SEI PORQUE//////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        if ((j%3) == 0){
            //guarda na final
            novaLis.insere(x);
            // devolve os outros 2 itens na inicial
            while(!(auxiLis.vazia())){
                TipoDado inserir = auxiLis.removeFim();
                insereFrente(inserir);
            }
        } else {
            auxiLis.insere(x);
        }
        ///////////////////////////////////////////////////////////////////////
        ///////// ESTA PARTE É RESPONSÁVEL PELO PROBLEMA //////////////////////
        //////////////////E EU NÃO SEI PORQUE//////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    }
    // REVERSAO DO FEITO ATRÁS, OU SEJA, DA LISTA novaLis PARA LISTAS
    // tira os itens de 1 em 1 até a lista auxiliar estiver vazia
    cout << "NovaLis: " << novaLis.imprime() << endl;
    while(novaLis.tam() != 0)
        insere(novaLis.remove());
    cout << imprime() << endl;
    return;
}

void itens(TipoDado nome_arquivo, int m)
{
    // inicialização da função com declarações
    TipoDado linha;
    ifstream arquivo(nome_arquivo+".txt");

    // Realização da passagem de dados do arquivo para string
    istreambuf_iterator<char> inputIt(arquivo), emptyInputIt;
    back_insert_iterator<TipoDado> stringInsert(linha);
    copy(inputIt, emptyInputIt, stringInsert);
    
    // definidor de quantidade de linhas baseado em quebra de linhas('\n') + 1
    int Qntd_Linhas = 0;
    for (int i = 0; i < linha.length(); i++)
        if (linha[i] == '\n') Qntd_Linhas++;
    Qntd_Linhas++;
    //formando varias strings para passagem posterior para listas
    TipoDado palavras[Qntd_Linhas];

    int j = 0;
    for (int i = 0;i<linha.length();i++){
        if (linha[i] == '\n' || linha[i] == '\0')
            j++;
        else if (linha[i] == ' ')
            continue;
        else{
            if (palavras[j].empty()){
                
                palavras[j].assign(1, linha[i]);
            }
            else
                palavras[j].push_back(linha[i]);
        }
    }
    //passagem de strings para listas
    Lista listas[Qntd_Linhas];
    for (int i = 0;i<Qntd_Linhas;i++){
        for (int j = 0;j< palavras[i].length();j++){
            stringstream aux;
            TipoDado a;
            aux << palavras[i][j];
            aux >> a;
            cout << a << endl;
            listas[i].insere(a);
        }
    }
    for (int i = 0;i< Qntd_Linhas;i++)
        listas[i].josefo(m);
    passagem_externa(listas);
}

using namespace std;

int main()
{
    TipoDado nome_arquivo;
    int M;
    cout << "Insira o nome do arquivo"<< endl;
    cin >> nome_arquivo;
    cout << "Insira o numero da criptografia" << endl;
    cin >> M;
    itens(nome_arquivo, M);
}
