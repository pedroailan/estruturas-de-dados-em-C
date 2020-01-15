#include <stdio.h>
#include <stdlib.h>

typedef struct reg
{
	int conteudo;
	struct reg *prox;
} celula;

typedef struct {
	celula* inicio;
	celula* fim;
} Fila;

void inicializarFdinam(Fila *f)
{
	f->inicio = NULL;
	f->fim = NULL;
}

void emfila (Fila *f, int n) {
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

void imprime (Fila *f) {
    celula *p;
    for (p = f->inicio ; p != NULL ; p = p->prox) {
        printf("%d\n", p->conteudo);
    }
}

int main(){
	Fila f;

	inicializarFdinam(&f);

	emfila(&f, 2);
	emfila(&f, 3);
	emfila(&f, 6);
	emfila(&f, 9);
	emfila(&f, 8);


		
	getchar();
	return 0;
}