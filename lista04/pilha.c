#include <stdio.h>
#include <stdlib.h>

typedef struct reg
{
    int conteudo;
    struct reg *prox;

} celula;

void imprime (celula *le) {
    celula *p;
    for( p = le->prox; p!= NULL; p = p->prox) {
        if(p->prox == NULL){
            printf("%d", p->conteudo);
            printf("\n");
            return;
        }
        printf("%d ", p->conteudo);
    }
}

celula *pi;

void criapilha (void) {
   pi = malloc (sizeof (celula)); // cabe�a
   pi->prox = NULL; 
}

void empilhar (int n) { 
   celula *nova;
   nova = malloc (sizeof (celula));
   nova->conteudo = n;
   nova->prox  = pi->prox;
   pi->prox = nova; 
}

char desempilhar (void) {
   celula *p;
   p = pi->prox;
   int x = p->conteudo;
   pi->prox = p->prox;
   free (p);
   return x; 
}

int main()
{
    criapilha();
    char s, t = 'g';
    int n;
  
    while(t != 'F') {
        scanf("%s" "%d", &s, &n);
        if(s == 'E') empilhar(n);
        if(s == 'I') imprime(pi);
        if(s == 'D') desempilhar();
        if(s == 'F') t = 'F';
    }
    
    return 0;
}