#include "grafos.cpp"
#include <iostream>

using std::cout;
using std::endl;

int main(){
    Grafo g(5);
    g.une(0,1);
    g.une(1,2);
    g.une(2,3);
    g.une(3,4);
    g.une(4,5);
    g.imprime();
}