#include <stdio.h>
#include <stdlib.h>

typedef struct reg
{
    int info;
    struct reg *esq;
    struct reg *dir;
    int altura;
} Arv;

Arv* criar_vazia()
{
    return NULL;
}

int vazia(Arv* a)
{
    return a == NULL;
}

int height (Arv* a)
{
    if (a == NULL) return 0;
    return a->altura;
}

int profundidade(Arv* a)
{
	if(a == NULL) return 0;
	return(height(a->esq) - height(a->dir));
}

int maior(int a, int b)
{
	return (a > b)? a : b;
}

Arv* rotDireita(Arv* a)
{
	Arv* aux = a->esq;
	Arv* auz = a->dir;

	aux->dir = a;
	a->esq = auz;

	a->altura = maior(height(a->esq), height(a->dir)) + 1;
	aux->altura = maior(height(aux->esq), height(aux->dir)) + 1;
	return a;
}

Arv* rotEsquerda(Arv* a)
{
	Arv* aux = a->dir;
	Arv* auz = aux->esq;

	aux->esq = a;
	a->dir = auz;

	a->altura = maior(height(a->esq), height(a->dir))+1;
	aux->altura = maior(height(aux->esq), height(aux->dir));

	return a;
}




Arv* inserir(Arv* a, int c) 
{
    if(a == NULL)
    {
        a = malloc(sizeof(Arv));
        a->info = c;
        a->altura = 1;
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
    a->altura = 1 + maior(height(a->esq), height(a->dir));

    int balanco = profundidade(a);

    if (balanco > 1 && c < a->esq->info) return rotDireita(a);
    if (balanco < -1 && c > a->dir->info) return rotEsquerda(a);
    if (balanco > 1 && c > a->esq->info)
    {
    	a->esq = rotEsquerda(a->esq);
    	return rotDireita(a);
    }

    if(balanco < -1 && c < a->dir->info)
    {
    	a->dir = rotDireita(a->dir);
    	return rotEsquerda(a);
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