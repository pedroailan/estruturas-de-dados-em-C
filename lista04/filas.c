#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int conteudo;
    struct reg *prox;
} celula;

celula *fi; 
celula *fa;

void criafila(){
    fi = malloc (sizeof (celula));
    fi->prox = fi;
}
void criafila2() {
    fa = malloc (sizeof (celula));
    fa->prox = fa;
}

void imprime (celula *le, celula *li) {
    celula *p;
    celula *r;
    r = li->prox;
    for( p = le->prox; p!= le; p = p->prox) {
            printf("%d\n", p->conteudo);
            printf("%d\n", r->conteudo);
            r =  r->prox;
    }
}

int tiradafila (celula *fi) {
   celula *p;
   p = fi->prox;  // o primeiro da fila
   int x = p->conteudo;
   fi->prox = p->prox;
   free (p);
   return x;  
}

celula *colocanafila (int y, celula *fi) { 
   celula *nova;
   nova = malloc (sizeof (celula));
   nova->prox = fi->prox;
   fi->prox = nova;
   fi->conteudo = y;
   return nova;
}

int main()
{
    criafila();
    int n, m, k;
    int a;
    scanf("%d" "%d" "%d",  &n, &m, &k);
    
    for (int i = 0; i < n; i++){
        scanf("%d", &a);
        fi = colocanafila(a, fi);
    }
    if(k == 2) criafila2();
    
    for (int i = 0; i < m; i++){
        scanf("%d", &a);
        fa = colocanafila(a, fa);
    }
    
    imprime(fi, fa);


    return 0;
}