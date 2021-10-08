#include<iostream>
using namespace std;
//Hanoi wower
//Suponha que existem 64 discos na torre A, e el es precisam ser transferidos
//para torre B

void torre(int n, char TOrig, char Tdest, char Taux)
{
    if (n==1){
        cout << " mova o disco " << n << " da torre " << TOrig << " para a torre " << Tdest << endl;
    }   else    {
        //1. mover N-1 Discos de torig -> taux
        torre(n-1, TOrig, Taux, Tdest);
        cout << " mova o disco " << n << " da torre " << TOrig << " para a torre " << Tdest << endl;
        //2. mover o disco N de orig -> tdest
        torre(n-1, Taux, Tdest, TOrig);
    }
}

//pega valor
int main(){
    cout << endl << "Quantidade de discos: ";
    int n;
    cin >> n;
    torre(n, 'A', 'C', 'B');
    return 0;
}


