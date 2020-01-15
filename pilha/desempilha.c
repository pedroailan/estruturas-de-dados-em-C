#include <stdio.h>
#include <stdlib.h>



typedef struct reg
{
    int conteudo;
    struct reg *prox;
} celula;

typedef struct
{
    celula* topo;
    int tamanho;
} Pilha;

void inicializarPilha(Pilha *p)
{
    p->topo = NULL;
    p->tamanho = 0;
}

celula *empilha (Pilha *p, int n) {
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->conteudo = n;
    nova->prox = p->topo;
    p->topo = nova;
    p->tamanho++;
}

celula *desempilha (Pilha *p) {
    celula *pp;
    pp = p->topo;
    p->topo = pp->prox;
    free (pp);
}


void imprime (Pilha *p) {
    celula *pp;
    printf("Topo:");
    for (pp = p->topo ; pp != NULL ; pp = pp->prox) {
        printf("\t%d\n", pp->conteudo);
    }
}

int main(){
    Pilha p;

    inicializarPilha(&p);

    empilha(&p, 1);
    empilha(&p, 3);
    empilha(&p, 5);
    empilha(&p, 7);

    desempilha(&p);

    imprime(&p);
        
    getchar();
    return 0;
}