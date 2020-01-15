#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int indice;
    int conteudo;
    struct reg *prox;
}  celula;

typedef struct {
   celula* inicio;
   int sent;
 
} LISTA;

celula* busca(LISTA *l, int posicao);


void inicializarLista(LISTA *l) {
  l->inicio = NULL;
  l->sent = 0;
}

void organiza_indice(LISTA *l) {
  celula *p = l->inicio;
  for(int i = 1; i <= l->sent; i++){
    p->indice = i;
    p = p->prox;
  } 
}

void insere(LISTA *l, int n) {
  celula *nova;
  nova = malloc(sizeof(celula));
  nova->conteudo = n;
  nova->prox = l->inicio;
  l->inicio = nova;
  l->sent += 1;
  organiza_indice(l);
}
  
  

celula* busca(LISTA *l, int posicao) {
  celula *p = l->inicio;

  for (p ; p != NULL ; p = p->prox) {
         if(p->prox->indice == posicao) return p;
  }
  return NULL;
}



void busca_insere(LISTA *l, int elem, int posicao) {
  celula *p = busca(l, posicao);

  printf("%d\n", p->conteudo);

  celula *nova = malloc(sizeof(celula));
  nova->conteudo = elem;
  nova->indice = posicao;
  nova->prox = p->prox;
  p->prox = nova;
  l->sent++;
}

void imprime(LISTA *l) {

  celula *p;
  for (p = l->inicio ; p != NULL ; p = p->prox) {
       printf("Indice %d:  / Conteudo: %d\n", p->indice, p->conteudo);
  }
}

int main() {
  LISTA l;

  inicializarLista(&l);


  insere(&l, 2);
  insere(&l, 3);
  insere(&l, 7);

  busca_insere(&l, 5, 2);
  organiza_indice(&l);

  imprime(&l);
     
  getchar();
return 0;
}