#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
	int conteudo;
	struct reg *prox;
} celula;

void insere (int n, celula *p) {
	celula *nova;
	nova = malloc(sizeof(nova));
	nova->conteudo = n;
	nova->prox = p->prox;
	p->prox = nova;
}

int compara(celula *le, celula*li) {
    celula *p;
    celula *r;
    p = le->prox;
    r = li-> prox;
    
    while (r != NULL){
        for(p; p != NULL; p = p->prox){
            if (p->conteudo == r->conteudo) return 1;
        }
        r = r->prox;
    }
    return 0;
}

/*void imprime (celula *le) {
	celula *p;
	for (p = le->prox; p != NULL; p = p->prox)
	{
		printf("%d ", p->conteudo );
	}
}*/


int main()
{
	celula *le;
	celula *li;

	le = malloc(sizeof(celula));
	le->conteudo = 0;
	le->prox = NULL;
	int n, b;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &b);
		insere(b, le);
	}
	
	li = malloc(sizeof(celula));
	li->conteudo = 0;
	li->prox = NULL;
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &b);
		insere(b, li);
	}

	//imprime(le);
	//printf("\n");
	//imprime(li);
	printf("%d", compara(le,li));

	return 0;
}