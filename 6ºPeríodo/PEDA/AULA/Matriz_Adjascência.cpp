#include <iostream>

class Grafo{
    public:
        Grafo(int num_pos);
        void une(int a, int b);
        void une(int a, int b, float p);
        void rmv(int a, int b);
        bool adjacente(int a, int b) const;
        void imprime() const;
        void Madjascencia() const;
    private:
        bool adj[MAXNOS][MAXNOS];
        bool validos(int a, int b) const;
        int n;
};

