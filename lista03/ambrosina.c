#include <stdio.h>
#include <stdlib.h>

void imprime (float *p, int n) {
    for (int i = 0; i < n ; ++i)
    {
      printf("%.2f\n", p[i]);

    }
}

void ordena (float *p, int n) {
    int i, j, z, m;

    z = 1;
    for (j = n - 1; (j>=1) && (z==1); j--)
    {
        z = 0;
        for (i = 0; i < j; ++i)
        {
            if (p[i] > p[i+1])
            {
                m = p[i];
                p[i] = p[i+1];
                p[i+1] = m;
                z = 1;
            }
        }
    }
}

int maior (float *p, int n)  {
    int i = 0;
    int c, aux = 0;
    while (i < (n-1)) {
        if( p[aux] >= p[i+1]){
            c = p[aux];
        } else{
          aux++;
        }
    i++;
    }
    return c;
}

int menor (float *p, int n)  {
    int i = 0;
    int c, aux = 0;
    while (i < n) {
        if( p[aux] <= p[i]){
            c = p[aux];
        } else{
          aux++;
          c = p[i];
        }
    i++;
    }
    return c;
}
int maior_esq (float *p, int n)  {
    int i = 0;
    int c, x, aux = 0;
    x = maior(p, n);
    while (i < (n-1)) {
        if( p[aux] >= p[i+1] && p[aux] < x){
            c = p[aux];
        } else{
          aux++;
        }
    i++;
    }
    return c;
}

int maior_dir (float *p, int n)  {
    int i = 0;
    int c, x, aux = 0;
    x = maior_esq(p, n);
    while (i < (n-1)) {
        if( p[aux] >= p[i+1] && p[aux] < x){
            c = p[aux];
        } else{
          aux++;
        }
    i++;
    }
    return c;
}
void ordena_ambrosina (float *p, int n) {
    int max, min, max_esq, max_dir;
    
    max = maior(p, n);
    min = menor(p, n);
    max_esq = maior_esq(p, n);
    max_dir = maior_dir(p, n);
    
    
    p[2] = max;
    p[0] = min;
    p[1] = max_esq;
    p[3] = max_dir;
}

void ordena_ambrosina1 (float *p, int n) {
    int c;
    for (int i = 0; i < (n-1); ++i)
    {
        if(p[i] > p[i+1]) {
            c = p[i];
            p[i] = p[i+1];
            p[i+1] = c;
        } else if ( i == 2 && p[i] < p [i+1]) {
            c = p[i];
            p[i] = p[i+1];
            p[i+1] = c;
            if(p[i-1] < p[i+1]) {
                c = p[i-1];
                p[i-1] = p[i+1];
                p[i+1] = c;
            }
        }
    }
}

int main()
{
    float *v;
    int n;

    v = malloc (4 * sizeof(float));
        
    scanf("%f", &v[0]);
    scanf("%f", &v[1]);
    scanf("%f", &v[2]);
    scanf("%f", &v[3]);

    ordena(v, 4);
    ordena_ambrosina(v, 4);
    imprime(v, 4);
    
    return 0;
}