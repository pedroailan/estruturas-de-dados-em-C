#include <stdio.h>
#include <stdlib.h>

typedef struct reg 
{
  int conteudo[50];
} celula;

int R(int x, int y) {
    int r, *z;
    r = ((3*x) * (3*x)) + (y * y);
    z = &r;
    return *z;
}

int B(int x, int y) {
    int r, *z;
    r = 2*(x*x) + (5*y) *(5*y);
    z = &r;
    return *z;
}

int C(int x, int y) {
    int r, *z;
    r = (-100 * x) + (y * y * y);
    z = &r;
    return *z;
}

int tamanho (int *x) {
    int c;
    c = &x;
    if (c == 0)  {
        return 1;
    } else  {
        return 0;
    }
}



int main()
{
    
    int t, x, y, v;
   
    celula *p;
    
    p = (celula*) malloc(sizeof(celula));
    scanf("%d", &t);
    if(tamanho(t) == 0) {
      for(int i = 0; i < (t); i++){
          scanf("%d %d", &x, &y);
          if (R(x, y) > B(x, y) && R(x, y) > C(x, y)){
              p->conteudo[i] = R(x, y);
              printf("Rafael ganhou\n");
          }else if (B(x, y) > R(x, y) && B(x, y) > C(x, y)) {
              p->conteudo[i] = B(x, y);
              printf("Beto ganhou\n");
          }else if (C(x, y) > B(x, y) && C(x, y) > R(x, y )){
              p->conteudo[i] = C(x, y);
              printf("Carlos ganhou\n");
          }
          
        }

    }
    return 0;

}