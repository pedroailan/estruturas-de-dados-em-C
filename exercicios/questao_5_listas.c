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


void imprime(LISTA *l) {

  celula *p;
  for (p = l->inicio ; p != NULL ; p = p->prox) {
       printf("Indice %d:  / Conteudo: %d\n", p->indice, p->conteudo);
  }
}

int tamanho_lista (LISTA *l) {
  celula *p;
  int i = 0;
  for (p = l->inicio; p != NULL ; p = p->prox) {
    i += 1;
  }
  return i;
}

void teste_tamanho (LISTA *l, LISTA *k) {
  int x, z;

  x = tamanho_lista(l);
  z = tamanho_lista(k);

  if (x == z && x != 0){
        printf("Listas Iguais\n");
     } else if ( x > z) {
        printf("\nLista 1 possui mais elementos\n");
        printf("Lista 1 possui %d elementos\n", x);
        printf("Lista 2 possui %d elementos\n", z);
     } else if (x < z) {
        printf("\nListas 2 possui mais elementos\n");
        printf("Lista 1 possui %d elementos\n", x);
        printf("Lista 2 possui %d elementos\n", z);
     } else {
        printf("\nListas vazias\n");
     }
}

int main() {
  LISTA l, k;

  inicializarLista(&l);
  inicializarLista(&k);


  insere(&l, 2);
  insere(&l, 3);
  insere(&l, 7);

  insere(&k, 2);
  insere(&k, 3);

  organiza_indice(&l);
  organiza_indice(&k);

  imprime(&l);
  printf("\n");
  imprime(&k);

  teste_tamanho(&l, &k);
     
  getchar();
return 0;
}