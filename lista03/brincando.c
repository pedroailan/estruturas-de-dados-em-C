#include <stdio.h>
#include <stdlib.h>

void imprime (int *p, int n) {
    for (int i = 0; i < n ; ++i)
    {
        if(i == (n-1)){ 
            printf("%d", p[i]);
            return;
        } else{ 
            printf("%d ", p[i]);
        }
    }
}

void inverte (int *p, int n) {
    int i, c, d;
    int tam = n;
    n = n-1;
    for (i = 0; i <= n; ++i)
    {
        c = p[i];
        d = p[n];
        p[i] = d;
        p[n] = c;
        n = n - 1;
    }
    imprime(p, tam);
}

void deslocamento (int *p, int n) {
    int c, b;
    b = n;
    n = n-2;

    for (int i = 0; i < n; ++i)
    {
        c = p[n];
        p[n] = p[i];
        p[i] = c;
        n = n-1;
    }
    
    imprime(p, b);
}

void ordena (int *p, int n) {
    int i, j, z, m;

    z = 1;
    for (j = n - 1; (j>=1) && (z==1); j--)
    {
        z = 0;
        for (i = 0; i < j; ++i)
        {
            if (p[i] < p[i+1])
            {
                m = p[i];
                p[i] = p[i+1];
                p[i+1] = m;
                z = 1;
            }
        }
    }
    imprime(p, n);
}


int main()
{
    int n;
    
    scanf("%d", &n);
    int *v;
    v = malloc (n * sizeof (int));
    
    for(int i = 0; i <=n; i++){
      scanf("%d", &v[i]);
    }
    
    //printf("%d\n", n);
    inverte(v, n);
    printf("\n");
    deslocamento(v, n);
    printf("\n");
    ordena(v, n);
    
    return 0;
}