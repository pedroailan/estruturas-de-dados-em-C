
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

void insere_ordenado (LISTA *l, int n) {
  celula *nova, *atual;
  nova = malloc(sizeof(celula));
  nova->conteudo = n;

  atual = l->inicio;
  
  if (atual == NULL) {
    nova->prox = l->inicio;
    l->inicio = nova;
    return;
  } else {
    for (atual = l->inicio; atual != NULL ; atual = atual->prox) {

      if (nova->conteudo < atual->conteudo){
        nova->prox = atual;
        l->inicio = nova;
        return;
      } else if ((nova->conteudo > atual->conteudo) && (atual->prox == NULL)) {
        nova->prox = atual->prox;
        atual->prox = nova;
        return;
      } else if ((nova->conteudo >= atual->conteudo) && (nova->conteudo <= atual->prox->conteudo)) {
          if((nova->conteudo == atual->conteudo) || (nova->conteudo == atual->prox->conteudo)){
            printf("Elemento não pode ser adicionado");
            return;
          }
        nova->prox = atual->prox;
        atual->prox = nova;
        return;
      }
    } 
  }
}


void imprime(LISTA *l) {

  celula *p;
  for (p = l->inicio ; p != NULL ; p = p->prox) {
       printf("Conteudo: %d\n", p->conteudo);
  }
}

int main() {
  LISTA l;

  inicializarLista(&l);


  //insere(&l, 2);
  //insere(&l, 3);
  //insere(&l, 7);
  
  insere_ordenado(&l, 5);
  insere_ordenado(&l, 8);
  insere_ordenado(&l, 1);
  insere_ordenado(&l, 10);
  insere_ordenado(&l, 9);
  insere_ordenado(&l, 2);

  imprime(&l);
     
  getchar();
return 0;
}