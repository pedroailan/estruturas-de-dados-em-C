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

/*void empilha (Pilha *p, int n) {
    celula *nova, *q;
    nova = malloc(sizeof(celula));
    nova->conteudo = n;
    
    q = p->topo;
    
    if (q == NULL) {
      nova->prox = p->topo;
      p->topo = nova;
      p->tamanho++;
    } else {
      nova->prox = p->topo;
      p->topo = nova;
    }
}*/

void empilha (Pilha *p, int n) {
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->conteudo = n;
    nova->prox = p->topo;
    p->topo = nova;
    p->tamanho++;
}

void imprime (Pilha *p) {
    celula *pp;
    printf("Topo:");
    for (pp = p->topo ; pp != NULL ; pp = pp->prox) {
        printf("\t%d\n", pp->conteudo);
    }
}

int tamanho_pilha (Pilha *p) {
    celula *pp;
    int i=0;
    for (pp = p->topo ; pp != NULL ; pp = pp->prox) {
        i += 1;
    }
    return i;
}

void teste_tamanho (Pilha *p, Pilha *k){
    int x, z;
     x = tamanho_pilha(p);
     z = tamanho_pilha(k);

     if (x == z && x != 0){
        printf("Pilhas Iguais\n");
     } else if ( x > z) {
        printf("\nPilha 1 possui mais elementos\n");
        printf("Pilha 1 possui %d elementos\n", x);
        printf("Pilha 2 possui %d elementos\n", z);
     } else if (x < z) {
        printf("\nPilhas 2 possui mais elementos\n");
        printf("Pilha 1 possui %d elementos\n", x);
        printf("Pilha 2 possui %d elementos\n", z);
     } else {
        printf("\nPilhas vazias\n");
     }

}

int main(){
    Pilha p, k;

    inicializarPilha(&p);
    inicializarPilha(&k);

    empilha(&p, 1);
    empilha(&p, 3);
    empilha(&p, 5);
    empilha(&p, 7);

    //empilha(&k, 1);
    //empilha(&k, 3);
    //empilha(&k, 5);

    imprime(&p);
    
    printf("Pilha 2\n");
    imprime(&k);
    
    teste_tamanho(&p, &k);
    
        
    getchar();
    return 0;
}