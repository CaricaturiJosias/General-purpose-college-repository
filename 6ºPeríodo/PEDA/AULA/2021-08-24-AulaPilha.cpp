#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

constexpr int MAXPILHA = 10;

using TipoDados = int; //em C: typedef int TipoDados

//------Pilha.h
class Pilha{
private:
    TipoDados dados[MAXPILHA];
    array<TipoDados,MAXPILHA> dado;
    int topo_;

public:
    Pilha(); //construtor
    ~Pilha(); //destructor
    void push(TipoDados elem);
    void pop();
    TipoDados topo();
    bool vazia();
    bool cheia();
};

//----- Main.cpp

int main()
{
    Pilha p;
    p.push(5);
    p.push(10);
    cout << p.topo() << endl;
    p.push(15);
    cout << p.topo() << endl;
}



//----- Pilha.cpp
Pilha :: Pilha()
{
    topo_ = -1;
}; //construtor

void Pilha::push(TipoDados elem)
{
    if (!cheia()){
        ++topo_;
        dados[topo_] = elem;
    }
    else
        cerr << "A pilha já está cheia!" << endl;
};
void Pilha::pop()
{
    if (!vazia()){
        --topo_;    
    }
    else{
        cerr << "A pilha está vazia e não pode executar";
    }
};

TipoDados Pilha::topo(){
    if (!vazia())
    return dados[topo_];
    else
        cerr<< "Pilha Vazia" << endl;
};
bool Pilha::vazia(){
    if (topo_==-1)
        return true;
    else
        return false;
};
bool Pilha::cheia(){
    return (topo_ == MAXPILHA - 1);
};
