#include <iostream>
#include "ListaLigada.cpp"
#include <string>
using namespace std;

int main()
{
    cout << "Inicio" << endl;
    Lista a;
    a.insere("A");
    a.insere("B");
    a.insere("C");
    a.insere("D");
    a.insere("E");
    a.insere("F");
    a.insere("G");
    a.imprime();
    //a.codifica(2);
}