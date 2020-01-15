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

void empilha (Pilha *p, int n) {
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->conteudo = n;
    nova->prox = p->topo;
    p->topo = nova;
    p->tamanho++;
}

celula *desempilha (Pilha *p) {
    celula *pp, *k;
    pp = p->topo;
    k = p->topo;
    p->topo = pp->prox;
    return k;
}

celula *inverter_pilha (Pilha *p) {
    Pilha k;
    celula *j;
    inicializarPilha(&k);
    for (j = p->topo ; j != NULL ; j = j->prox) {
        celula *l = desempilha(p);
        empilha(&k, l->conteudo);
    }
    p->topo = k.topo;
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

    imprime(&p);

    inverter_pilha(&p);
    
    printf("\n\n");
    imprime(&p);
    
    getchar();
    return 0;
}