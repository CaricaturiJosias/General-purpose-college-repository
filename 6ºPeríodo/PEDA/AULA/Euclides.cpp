
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>

using namespace std;

int euclides(int i, int j)
{
    cout<< endl << "Iteracao " << i << " e " << j<< endl;
    if (i==j)
        return i;
    else
        if (i>j)
            if (i%j==0)
                return euclides(i-((i/j)-1)*j, j);
            else
                return euclides(i-j,j);
        else
            if (j%i == 0)
                return euclides(i,j-((j/i)-1)*i);
            else
                return euclides(i,j-i);
}

int main()
{
    cout << endl << 10%3 << endl;
    int entrada, entrada2;
    cout << "Bota o numero ai faz o favor: "<<endl;
    cin >> entrada;
    cout << "Bota o segundo ai faz o favor: "<<endl;
    cin >> entrada2;
    cout << endl << entrada%entrada2 <<endl;
    cout << endl << "Resultado: "<< euclides(entrada, entrada2);
    return 0;
}

