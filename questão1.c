#include <stdlib.h>
#include <stdio.h>


#define MAX 7
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} RegistroEstat;

typedef struct
{
    int topo, aux;
    RegistroEstat A[MAX];
} PESTAT;

void inicializarPEstat(PESTAT *p)
{
    p->topo = -1;
}

int status_pilha (PESTAT *p) {
  if(p->topo == -1) return 1;
  if(p->topo <= MAX) return 0;
  if(p->topo >= MAX) return 2;
}

int inserir_pilha (PESTAT *p, TIPOCHAVE n) {
  if(p->topo == -1){
  	p->topo++;
    p->A[p->topo].chave = n; //Insere na primeira posição do vetor
  }   else {
      p->A[p->topo].chave = n;
      p->topo++;
      inserir_pilha(p, n);
  }
  
}

int length (PESTAT *p) {
   p->topo++;
}


int main(){
    PESTAT p;
    int x, k;

    inicializarPEstat(&p);
    
    
    inserir_pilha(&p, 12);
    inserir_pilha(&p, 15);
    inserir_pilha(&p, 20);
    inserir_pilha(&p, 60);
    inserir_pilha(&p, 100);
    inserir_pilha(&p, 1);
    
    x = status_pilha(&p);
    //k = length(&p);


    printf("%d\n", p.topo);
    if (x == 1) printf("Pilha vazia");
    else if (x == 0) printf("Pilha Cheia");
    else printf("A pilha possui %d elementos", k);

        
    getchar();
    return 0;
}