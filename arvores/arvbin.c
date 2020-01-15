#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

struct arv 
{
	char info;
	struct arv* esq;
	struct arv* dir;
};

Arv* criar_vazia() {
	return NULL;
}



Arv* criar(char c, Arv* sae, Arv* sad) {
	Arv* p = (Arv*)malloc(sizeof(Arv));
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;

}

int vazia (Arv* a)
{
	return a == NULL;
}

void imprime(Arv* a)
{
	if(!vazia(a))
	{
		printf("%c", a->info);
		imprime(a->esq);
		imprime(a->dir);
	}
}

void imprime_arvore(Arv* a)
{
	printf("<");
	if(!vazia(a))
	{
		printf("%c", a->info);
		imprime_arvore(a->esq);
		imprime_arvore(a->dir);
	}
	printf(">");
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

int busca(Arv* a, char c)
{
	if(vazia(a))
		return 0;
	return (a->info == c) || busca(a->esq, c) || busca(a->dir, c);
}