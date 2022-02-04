#include <stdio.h>

int Contagem (int x) {
    if (x > 0) {
        for (int n = 1; n <= x; n++){
            printf("%d", x);
                if(n < x){
                    printf("-");
                }
                if(n == x) {
                    printf("\n");
                    x = x-1;
                    Contagem(x);
                }
            } 
        } 
}


int main()
{
    int *n, x;
    scanf("%d", &x);
    n = &x;
    Contagem(*n);
    return 0;
}