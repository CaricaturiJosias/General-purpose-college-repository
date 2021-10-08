#include<iostream>

using namespace std;
struct jamelao{
   int esfiha, vaga, manobrista; 
};

int main(){
    cout << "Teste";
    int *ptr = new int;
    char *s = new char[64];
    jamelao *d;
    d = new jamelao;
    d->esfiha = 10;
    cout << endl << d->esfiha;
    delete d;
    delete ptr;
    delete []s;
    d = nullptr;
}