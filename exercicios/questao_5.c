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

int tamanho_fila (Fila *f) {
	celula *p;
	int i = 0;
	for (p = f->inicio ; p != NULL ; p = p->prox) {
		i += 1;
	}
	return i;
}

void teste_tamanho (Fila *p, Fila *k) {
	int x, z;
	x = tamanho_fila(p);
	z = tamanho_fila(k);

	if (x == z && x != 0){
        printf("Filas Iguais\n");
     } else if ( x > z) {
        printf("\nFila 1 possui mais elementos\n");
        printf("Fila 1 possui %d elementos\n", x);
        printf("Fila 2 possui %d elementos\n", z);
     } else if (x < z) {
        printf("\nFilas 2 possui mais elementos\n");
        printf("Fila 1 possui %d elementos\n", x);
        printf("Fila 2 possui %d elementos\n", z);
     } else {
        printf("\nFilas vazias\n");
     }
}

int main(){
	Fila f, k;

	inicializarFdinam(&f);
	inicializarFdinam(&k);

	emfila(&f, 2);
	emfila(&f, 3);
	emfila(&f, 6);
	emfila(&f, 9);
	emfila(&f, 8);

	emfila(&k, 2);
	emfila(&k, 3);
	emfila(&k, 6);
	emfila(&k, 9);


	teste_tamanho(&f, &k);


		
	getchar();
	return 0;
}