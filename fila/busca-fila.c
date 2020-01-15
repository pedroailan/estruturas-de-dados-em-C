#include <stdio.h>
#include <stdlib.h>

typedef struct reg {

	int conteudo;
	struct reg *prox;
} celula;

typedef struct {

	celula* inicio;
	celula* fim;
} Fila;

void inicializarFila (Fila *f) {

	f->inicio = NULL;
	f->fim = NULL;
}

void emfila (Fila *f, int n){
	celula *nova, *q;
	nova = malloc(sizeof(celula));
	nova->conteudo = n;

	q = f->fim;

	if (f->fim == NULL) {
		f->fim = nova;
		f->inicio = nova;
		nova->prox = NULL;
	} else {
		q->prox = nova;
		f->fim = nova;
		nova->prox = NULL;
	}
}


celula *busca (Fila *f, int n) {
 	celula *p;
 	p = f->inicio;
 	while(p!=NULL && p->conteudo != n) {
 		p = p->prox;
 		if(p->conteudo == n) {
 			printf("Encontrado\n");
 		}
 	}
}

void imprime (Fila *f) {
    celula *p;
    for (p = f->inicio ; p != NULL ; p = p->prox) {
        printf("%d\n", p->conteudo);
    }
}

int main()
{
	Fila f;

	inicializarFila(&f);

	emfila(&f, 2);
	emfila(&f, 5);
	emfila(&f, 9);
	emfila(&f, 8);

	imprime(&f);

	busca(&f, 9);


	getchar();
	return 0;
}
