#include <iostream>
#include <math.h>

using namespace std;

int main(){
    float a;
    cout << "Insira o numero: ";
    cin >> a;
    a = a/100;
    float resultado = ((200000/(1+a))+((200000/(pow(1+a,2))))+((200000/(pow(1+a,3))))+((400000/(pow(1+a,4))))+((500000/(pow(1+a,5)))))-1000000;
    cout << "Resultado: " << resultado << endl;

}