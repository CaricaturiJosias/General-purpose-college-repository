#include <iostream>
#include "Pilha.cpp"
#include <vector>
#include <array>

using namespace std;

int main()
{
	vector<std::string> labirinto = {
		"XXXSXXXXXXXXXXXXXXXXX",
		"X     X     X     X X",
		"XX XX XXXXX X X X   X",
		"X   X       XXX XXX X",
		"X X X XXXXXXX   X   X",
		"X X   X   X X X   X X",
		"X XXXXX X X   XXXXX X",
		"X X     X XXX  X    X",
		"X X X X X   XX XX XXX",
		"X X XXX X X     X   X",
		"X X X X X XXXXX XXX X",
		"X     X X   X X X   E",
		"X XXXXX XXX X XXX X X",
		"X X       X X   X X X",
		"X   XXX X X XXX X X X",
		"XXX X X X X X X X XXX",
		"X X   X X   X   X   X",
		"X XXX XXXXXXXXX XXX X",
		"X                 X X",
		"XXXXXXXXXXXXXXXXXXXXX"
	};

	Pilha sas(labirinto);
	sas.encontraFim(); // preventivo
	vector<int> retorno = sas.procura(sas.encontra());
	sas.printaLab();
}

