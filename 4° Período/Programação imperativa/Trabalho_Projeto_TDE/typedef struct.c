typedef struct {

      int  x;

      int  y;

} sPonto;

 

typedef struct {

      sPonto pInicial;

      sPonto pFinal;

} sLinha;

 
sPonto *pon;

int main (){
    lePonto(pon);
    return 0;

}
void lePonto(sPonto *pon) {
      int valor;
      pon = (sPonto *) malloc(sizeof(sPonto));
      printf ("x: ");
      scanf (" %d", &valor);
      printf("vai se foder  %d", valor);
      pon->x = valor;
      printf("\nvaiseferrar"); 
      printf ("y: ");
      scanf (" %d", &valor);
      pon->y = valor; 
      printf ("x: %d\n y: %d ",pon->x, pon->y);
      return 0;

}