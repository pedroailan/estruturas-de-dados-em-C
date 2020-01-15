#include <stdio.h>
#include <stdio.h>
#include "arvore.h"
#include "arvbin.c"


int main()
{
	Arv* a1 = criar('m', criar_vazia(), criar_vazia());
	Arv* a2 = criar('a', criar_vazia(), a1);
	Arv* a3 = criar('o', criar_vazia(), criar_vazia());
	Arv* a4 = criar('p', a3, a2);

	//printf("%d", vazia(criar_vazia()));

	imprime_arvore(a4);
	printf("\n");
	printf("%d\n", busca(a4, 'm'));
	printf("%d\n", busca(a4, 'z'));
	liberar(a4);
	return 0;
}