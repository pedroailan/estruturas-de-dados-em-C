#include <stdio.h>
#include <stdlib.h>
//#include "arvore.h"
//#include "arvbin.c"
typedef struct arv Arv;
struct arv 
{
    int info;
    struct arv* esq;
    struct arv* dir;
};

Arv* criar_vazia() {
    return NULL;
}

int vazia (Arv* a)
{
    return a == NULL;
}

Arv* inserir(int c, Arv* a){
    Arv* p;
    if(a == NULL)
    {
        p = (Arv*)malloc(sizeof(Arv));
        p->info = c;
        p->esq = NULL;
        p->dir = NULL;
    } else {
      if(c < a->info)
      {
        p = a;
        p->esq = inserir(c, p->esq);
      }
      if(c > a->info)
      {
        p = a;
        p->dir = inserir(c, p->dir);
      }
    }
    return p;
}

//retorna 1 quando encontra o elemento 
int busca(Arv* a, int c)
{
    if(vazia(a))
        return 0;
    return (a->info == c) || busca(a->esq, c) || busca(a->dir, c);
}

Arv* busca_cp(Arv* a, int c)
{    
    if(vazia(a) || a->info == c)
    {
        return a;
    } else if(c < a->info){
        busca_cp(a->esq, c);
    } else if(c > a->info){
        busca_cp(a->dir, c);
    }
}

Arv* busca_noh(Arv* a,  int c)
{
    Arv* paidele = NULL;
    
    while(a != NULL) {
        if(a->info == c)
        {
            return a;
        }

        paidele = a;
        if(a->info > c) {
             a = a->esq;
        } else {
            a = a->dir;
        }
    }
    return paidele;
}

Arv* remover(Arv* a, int c)
{
    Arv* k = busca_cp(a, c);
    if (k->esq == NULL && k->dir == NULL){
        free(k);
    }
}


Arv* liberar(Arv* a)
{
    if(!vazia(a))
    {
        liberar(a->esq);
        liberar(a->dir);
        free (a);
    }
    return NULL;
}


void imprime_arvore(Arv* a)
{
    printf("<");
    if(!vazia(a))
    {
        printf("%d", a->info);
        imprime_arvore(a->esq);
        imprime_arvore(a->dir);
    }
    printf(">");
}

int main()
{
    Arv* a = criar_vazia();
    
    a = inserir(90, a);
    a = inserir(10, a);
    a = inserir(100, a);
    a = inserir(20, a);
    a = inserir(1, a);
    a = inserir(1000, a);

    imprime_arvore(a);
    printf("\n");
    
    //if(busca(a, 1000)) printf("Encontrado!\n");
    //else printf("Não Encontrado!\n");

    printf("%d\n", busca_cp(a, 1));

    //remover(a, 1);

    printf("%d\n", busca_noh(a, 20));
    return 0;
}