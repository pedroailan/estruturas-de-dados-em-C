#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct reg {
    int conteudo;
    struct reg *prox;
} celula;


void insere(int a, celula *p){
    celula *aux;
    aux = p;

    while(aux->prox != NULL){
        aux = aux->prox;
    }
    
    celula *nova;
    nova = malloc( sizeof(celula));
    nova->conteudo = a;
    nova->prox = aux->prox;
    aux->prox = nova;
}

int busca (int x, celula *le)
{
   celula *p;
   p = le;
   
   if(p == NULL) return 2;
   
   while (p != NULL){
      p = p->prox;
      if(p->conteudo == x) return 1;
    }
    
    return 0;
}

void novaL (celula *le, celula *li, celula *lu) {
    celula *p;
    celula *r;
    r = le->prox;
    for (p = le->prox; p != NULL; p = p->prox){
          if(p->conteudo == r->conteudo){
              if(busca(p->conteudo, lu) == 0){
                  insere(p->conteudo, lu);
              } else if(busca(p->conteudo, lu) == 2){
                  insere(p->conteudo, lu);
              }
              r = r->prox;
          }
   }
    
}


celula *ordena(celula *p) {

    celula *aux = p;
    celula *t;
    int c;

    if (p == NULL || p->prox == NULL)
        return NULL;

    while (aux != NULL) {
        t = aux->prox;
        while (t != NULL) {
            if (aux->conteudo > t->conteudo) {
                c = aux->conteudo;
                aux->conteudo = t->conteudo;
                t->conteudo = c;
            }
            t = t->prox;
        }
        aux = aux->prox;
    }
    return p;
}



int main() {

    celula *le;
    celula *li;
    celula *lu;
    
    int t;
    
    lu = malloc(sizeof(celula));
    lu->prox = NULL;
    
    le = malloc(sizeof(celula));
    le->prox = NULL;
    
    li = malloc(sizeof(celula));
    li->prox = NULL;
    
    int n, i, y;
    
    while(i < 20){
        scanf("%d", &n);
        insere(i, le);
        i++;
    }
    
    i = 0;
    while(i < 20){
        scanf("%d", &n);
        insere(i, li);
        i++;
    }
    
    //le = ordena(le);
    //li = ordena(li);
    novaL(le, li, lu);
    //y = compara(le, li);
    
    /*if(y == 0) {
        printf("VAZIO");
    } else if(y == 2) {
        printf("%d", li->conteudo);
    } else { 
        imprime(le,li);
    }*/
    
    //imprime(lu);
    
    
    return 0;
}