#include <iostream>
#include "Lista.cpp"

using namespace std;

int main()
{
    cout << "Inicio" << endl;
    Lista a;
    a.insere('A');
    a.insere('B');
    a.insere('C');
    a.insere('D');
    cout << a.remove() << endl;
    a.insere('B');
    a.imprime();
}