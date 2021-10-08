#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << endl << "Insira a equacao:  " << endl;
    string equa;
    cin >> equa;
    int pare = 0;
    for (int i=0; i<equa.size();i++){
        if (equa[i]==')')
            pare--;
        else if (equa[i]=='(')
            pare++;
    }
    string resul;
    if (pare==0){
        resul = "Certo";
    } else {
        resul = "Errado";}
    cout << "Total: " << pare << endl << "Resultado: " << resul << endl;
}