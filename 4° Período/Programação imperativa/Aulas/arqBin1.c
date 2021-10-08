#include <stdio.h>

typedef struct sLivro {
        int     lCodigo;       
        char    lTitulo[50];  
        int     lPaginas;      
        float   lPreco;      
} tLivro;
   
void mostrarLivro(tLivro livro);

int main () {
	
	printf ("Tamanho da struct: %lu \n", sizeof(tLivro));
     
	//----- Gravar 3 registros no arquivo
    tLivro liv1 = {100, "Calculo III", 249, 39.90};  
    tLivro liv2 = {101, "Fisica", 327, 44.30};  
    tLivro liv3 = {102, "Desenho Tecnico para Leigos", 249, 27.15};    
    tLivro liv4 = {103, "Python para Iniciantes", 380, 88.15};        
    tLivro liv5 = {104, "Java para Iniciantes", 560, 102.99};        
    FILE *fp;   // ponteiro para arquivo
    
	// atualizar caminho
	char arqLivro[] = "livros.dat";  
    fp = fopen (arqLivro, "wb"); // falta testar retorno NULL
    fwrite (&liv1, sizeof(tLivro), 1, fp); // bloco de bytes
    fwrite (&liv2, sizeof(tLivro), 1, fp);
    fwrite (&liv3, sizeof(tLivro), 1, fp);
    fwrite (&liv4, sizeof(tLivro), 1, fp);
    fwrite (&liv5, sizeof(tLivro), 1, fp);
    fclose (fp);
    
    return 0;
}