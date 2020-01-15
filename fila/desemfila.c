#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct reg {

    int conteudo;
    struct reg *prox;
} celula;

typedef struct {
    celula* inicio;
    celula* fim;
} Fila;

void inicializar_Fila (Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void emfila (Fila *f, int n) {
    celula *nova, *q;
    nova = malloc(sizeof(celula));
    nova->conteudo = n;

    q = f->fim;

    if (f->fim == NULL) {
        f->fim = nova;
        f->inicio = nova;
        nova->prox = NULL;
    } else {
      q->prox = nova;
      f->fim = nova;
      nova->prox = NULL;
      
  }
}

void desemfila (Fila *f) {
    celula *q;
    q = f->inicio;
    f->inicio = q->prox;
    free(q);
}

void imprime (Fila *f) {
    celula *p;
    printf("Primeiro:");
    for (p = f->inicio ; p != NULL ; p = p->prox) {
        printf("%d\n", p->conteudo);
    }
    printf("Ultimo:");
}

int main()
{
    Fila f;

    inicializar_Fila(&f);

    emfila(&f, 4);
    emfila(&f, 8);
    emfila(&f, 10);
    emfila(&f, 4);
    emfila(&f, 8);
    emfila(&f, 10);

    desemfila(&f);

    imprime(&f);

    return 0;
}