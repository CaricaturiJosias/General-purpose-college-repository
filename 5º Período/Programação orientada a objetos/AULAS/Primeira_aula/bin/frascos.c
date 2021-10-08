typedef struct fra {
    char a;
    char b;
    char c;
} frasco;

// declaração do ambiente inicial

frasco *Um;
frasco *Dois;
frasco *Tres;
frasco *Quatro;

//////////////////////////////////// Funções necessárias
// Checar Estado

// Checar se pode transferir

// Transferir de um pro outro

int main(){
    // Declaração de estado inicial
    Um->a = 'L';
    Um->b = 'C';
    Um->c = ' ';
    Dois->a = 'L';
    Dois->b = 'V';
    Dois->c = ' ';
    Tres->a = 'V';
    Tres->b = 'C';
    Tres->c = ' ';
    Quatro->a = 'V';
    Quatro->b = 'L';
    Quatro->c = ' ';   
}