#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float Distancia (int x1, int y1, int x2, int y2) {
    return sqrt((x2-x1) *(x2-x1) + (y2-y1) * (y2-y1));
}

int Posicao(int a, int b){
  if(a == 0 && b == 0){
    printf("origem\n");
  }
  else if(a == 0 && b > 0){
    printf("eixo y positivo\n");
  }
  else if(a > 0 && b == 0){
    printf("eixo x positivo\n");
  }
  else if(a == 0 && b < 0){
    printf("eixo y negativo\n");
  }
  else if(a < 0 && b == 0){
    printf("eixo x negativo\n");
  }
  else if(a > 0 && b > 0){
    printf("quadrante 1\n");
  }
  else if(a < 0 && b > 0){
    printf("quadrante 2\n");
  }
  else if(a < 0 && b < 0){
    printf("quadrante 3\n");
  }
  else if(a > 0 && b < 0){
    printf("quadrante 4\n");
  }
  return 0;
}

int testaPar(int x) {
    if (x == 0){
        return 1;
    }
    return 0;
}

int main() {
    int a, b, c, d, x;
    
    printf("\n");
    scanf("%d", &x);

    if (testaPar(x) == 0){
        for(int n = 0; n < x; n++){
            scanf("%d", &a);
            scanf("%d", &b);
            scanf("%d", &c);
            scanf("%d", &d);
            if(n == 0){
                printf("%.2f\n", Distancia(a, b, c, d));
            }
            Posicao(a, b);
            Posicao(c, d);
        }
    }
    
    return 0;
}