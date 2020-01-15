#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int indice;
    int conteudo;
    struct reg *prox, *ant;
}  celula;

typedef struct {
   celula* inicio;
   celula* fim;
   int sent;
 
} LISTA;


void inicializarLista(LISTA *l) {
  l->inicio = NULL;
  l->fim = NULL;
  l->sent = 0;
}

void organiza_indice(LISTA *l) {
  celula *p = l->inicio;
  for(int i = 1; i <= l->sent; i++){
    p->indice = i;
    p = p->prox;
  } 
}

celula* busca(LISTA *l, int elem) {
  celula *p = l->inicio;

  for (p ; p != NULL ; p = p->prox) {
         if(p->prox->conteudo == elem) return p;
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

void insere_dp(LISTA *l, int n) {
  celula *nova = malloc(sizeof(celula));
  nova->conteudo = n;
  if(l->inicio == NULL) {
    nova->prox = l->inicio;
    nova->ant = NULL;
    l->inicio = nova;
    l->fim = nova;
  } else {
    nova->prox = l->inicio;
    nova->ant = NULL;
    l->inicio->ant = nova;
    l->inicio = nova;
  }
  organiza_indice(l);
}

void busca_insere_dp(LISTA *l, int n, int elem) {
  celula *nova = malloc(sizeof(celula));
  nova->conteudo = elem;
  celula *p = busca(l, n);

  celula *atual = p->prox;


  printf("%d\n", p->conteudo);
  if(l->inicio == NULL) {
    nova->prox = l->inicio;
    nova->ant = NULL;
    l->inicio = nova;
    l->fim = nova;
  } else {
    nova->prox = p;
    nova->ant = p->ant;
    l->inicio->ant = nova;
    l->inicio = nova;
  }
  organiza_indice(l);
}


void imprime(LISTA *l) {

  celula *p;
  for (p = l->inicio ; p != NULL ; p = p->prox) {
       printf("Indice %d:  / Conteudo: %d\n", p->indice, p->conteudo);
  }
  printf("\n");
  printf("Inicio: %d\n", l->inicio->conteudo);
  printf("Fim: %d\n", l->fim->conteudo);
}

int main() {
  LISTA l;

  inicializarLista(&l);


  insere_dp(&l, 2);
  insere_dp(&l, 3);
  insere_dp(&l, 7);

  busca_insere_dp(&l, 3, 4);

  organiza_indice(&l);

  imprime(&l);
     
  getchar();
return 0;
}