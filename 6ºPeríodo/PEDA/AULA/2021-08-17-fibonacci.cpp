// fibonacci

#include<iostream>

using namespace std;

int fibo(int i)
{
    if (i == 1 || i == 2)
        return 1;
    else
        return fibo(i-1)+fibo(i-2);
}

double pot(double b, double e){
    if (e==0)
        return 1;
    else
        return b*pot(b,e-1);
}

int main(){
    cout << endl << pot(2, 8) << endl;
    return 0;
}

