#include<iostream>
using namespace std;
//Hanoi wower
//Suponha que existem 64 discos na torre A, e eles precisam ser transferidos
//para torre B

void torre(int n, char TOrig, char Tdest, char Taux)
{
    if (n==1)
        cout << "mova disco da torre " << TOrig << " para torre " << Tdest << endl;
}

//pega valor
int main(){
    cout << endl << "Quantidade de discos: ";
    int n;
    cin >> n;
    torre(n, 'A', 'C', 'B');
    return 0;
}


