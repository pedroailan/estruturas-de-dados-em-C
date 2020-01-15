#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct no{
     //dado
    int num;
    //informacao da celula
    int info;
    //referencia para o proximo no
    struct no *prox;
} celula;

typedef struct {
    celula *inicio;
    int info;
} lista;

celula* busca(lista *l, int posicao);
void remover(lista *l, int posicao);

void inicializarLista(lista *l) {

    l->info = 0;
    l->inicio = NULL;
}

void inserirListaInicio(lista *l, int elem) {

    //cria uma variavel e aponta para o endereco de memoria
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->num = elem;
    nova->prox = l->inicio;
    l->info++;
    nova->info = 1;
    l->inicio = nova;
}

//caso esteja errado lembrar de colocar &
void inserirListaMeio(lista *l, int elem, int posicao) {

    celula *atual = busca(l, posicao);

    if(atual != NULL) {
        celula *anterior = busca(l, (posicao - 1));

        celula *p = malloc(sizeof(celula));
        p->info = posicao;
        p->num = elem;

        anterior->prox = p;
        p->prox = atual;
        l->info++;

    }     
}

//posso fazer um ponteiro apontar para uma lista, mas n posso fazer ele receber dados,
//porem como ele aponta para o endereco ele pode navegar entre as celulas usando prox
void inserirListaFim(lista *l, int elem) {
    celula *atual;
    atual = l->inicio;

    celula *nova = malloc(sizeof(celula));
    nova->num = elem;

    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    l->info++;
    atual->prox = nova;
    nova->prox = NULL;
    nova->info = l->info;

}

celula* busca(lista *l, int posicao) {
        
    if((posicao >= 0) && (posicao < l->info)) {

        int i;
        celula *p;
        p = l->inicio;

        for(i = 0; i < posicao; i++) p = p->prox;

        return p;
    }

    return NULL;    

}

void remover(lista *l, int posicao) {
    celula *remover = busca(l, posicao);
    celula *anterior = busca(l, (posicao - 1));
    
    anterior->prox = remover->prox;
    free(remover);

}

int main() {
    lista l;

    //celula *p = (celula *)malloc(sizeof(celula)); // cria um novo n� na mem�ria, apontado por p
    //free(p); // a �rea de mem�ria apontada por p � liberada;

    inicializarLista(&l);
    inserirListaInicio(&l, 4);
    inserirListaInicio(&l, 5);
    inserirListaInicio(&l, 7);
    inserirListaInicio(&l, 8);
    inserirListaMeio(&l, 2, 1);
    //inserirListaFim(&l, 6);

    //remover(&l, 2);
    return 0;
}