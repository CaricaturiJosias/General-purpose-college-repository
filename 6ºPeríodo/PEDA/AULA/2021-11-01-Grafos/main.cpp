#include "mapa.cpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
    Mapa m;   // inicializa tabela adj, nomes, peso
    
    m.adiciona("Londrina");
    m.adiciona("Itarare");
    m.adiciona("Sao Paulo");
    m.adiciona("Registro");
    m.adiciona("Curitiba");
    m.adiciona("Ponta Grossa");
    m.adiciona("Joinville");
    m.adiciona("Mafra");
    m.adiciona("Porto Uniao");
    m.adiciona("Itajai");
    m.adiciona("Blumenau");
    m.adiciona("Florianopolis");
    m.adiciona("Lages");
    
    m.une("Londrina", "Itarare", 310);
    m.une("Londrina", "Ponta Grossa", 271);
    m.une("Itarare", "Ponta Grossa", 174);
    m.une("Itarare", "Sao Paulo", 342);
    m.une("Itarare", "Curitiba", 208);
    m.une("Sao Paulo", "Registro", 185.9);
    m.une("Curitiba", "Registro", 221.2);
    m.une("Curitiba", "Ponta Grossa", 114);
    m.une("Curitiba", "Mafra", 115);
    m.une("Curitiba", "Joinville", 132);
    m.une("Ponta Grossa", "Mafra", 155);
    m.une("Ponta Grossa", "Porto Uniao", 209);
    m.une("Porto Uniao", "Mafra", 143);
    m.une("Porto Uniao", "Lages", 271);
    m.une("Mafra", "Joinville", 136);
    m.une("Mafra", "Lages", 349);
    m.une("Mafra", "Blumenau", 165);
    m.une("Itajai", "Blumenau", 52.3);
    m.une("Itajai", "Florianopolis", 102);
    m.une("Itajai", "Joinville", 86.2);
    m.une("Lages", "Florianopolis", 231);
    m.une("Lages", "Blumenau", 310);
    TipoDado cidade1 = "Joinville";
    TipoDado cidade2 = "Lages";
    system("cls");
    cout << "Cidade A: " << cidade1 << endl << "Cidade B: " << cidade2 << endl;
    m.MenorCaminho(cidade1, cidade2);
}