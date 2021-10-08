#include <iostream>
#include "Fila.cpp"

using namespace std;

int main()
{
    Fila f1; //1,2,3    
    int input;
    cout << "Insira um numero: ";
    cin >> input;
    f1.inserepdc(input);
    while(input != 0 || f1.cheia()){
        cout << "Insira um numero: ";
        cin >> input;
        if (input != 0)
            f1.inserepdc(input);
    }
    cout << "Frente";
    while (!(f1.vazia())){
        cout << " - " << f1.frente();
        f1.remove();
    }
    cout << " fim" << endl;
    // cout << endl << "Fila 2" << endl;
    // while (!(f2.vazia())){
    //     cout << f2.frente();
    //     f2.remove();
    // }

    // cout << endl << "Fila 3" << endl;
    // while (!(f3.vazia())){
    //     cout << f3.frente();
    //     f3.remove();
    // }
}