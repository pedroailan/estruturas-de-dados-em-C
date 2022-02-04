#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
	int conteudo;
	struct reg *prox;
} celula;

void inserir(int a, celula *p){
    celula *aux;
    aux = p;

    while(aux->prox != NULL){
        aux = aux->prox;
    }
    
    celula *nova;
    nova = malloc( sizeof(celula));
    nova->conteudo = a;
    nova->prox = aux->prox;
    aux->prox = nova;
}


void imprime (celula *le) {
	celula *p;
	for (p = le->prox; p != NULL; p = p->prox)
	{
		printf("%d ", p->conteudo );
	}
}


int main()
{
	celula *le;


	le = malloc(sizeof(celula));
	le->conteudo = 0;
	le->prox = NULL;
	
	int b;

	for (int i = 0; i < 9; ++i)
	{
		scanf("%d", &b);
		inserir(b, le);
	}
	

	return 0;
}