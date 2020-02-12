#include <stdio.h>
#include <stdlib.h>

typedef struct reg
{
    int info;
    struct reg *esq;
    struct reg *dir;

} Arv;

Arv* criar_vazia()
{
    return NULL;
}

int vazia(Arv* a)
{
    return a == NULL;
}

Arv* inserir(Arv* a, int c) 
{
    if(a == NULL)
    {
        a = malloc(sizeof(Arv));
        a->info = c;
        a->esq = a->dir = NULL;
    } else {
        if (c < a->info) 
        {
            a->esq = inserir(a->esq, c);
        } 
        else 
        {
            a->dir = inserir(a->dir, c);
        }
    }
    return a;
}

void imprime (Arv* a)
{
    printf("<");
    if(!vazia(a))
    {
        printf("%d", a->info);
        imprime(a->esq);
        imprime(a->dir);
    }
    printf(">");
}

int main()
{
    Arv* a = criar_vazia();
    
    a = inserir(a, 9);
    a = inserir(a, 8);
    a = inserir(a, 5);
    a = inserir(a, 7);
    a = inserir(a, 11);


    imprime(a);
    printf("\n");
    
    
    return 0;
}

