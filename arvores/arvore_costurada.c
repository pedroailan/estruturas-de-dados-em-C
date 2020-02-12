#include <stdlib.h>
#include <stdio.h>
#define true 1
#define false 0

typedef int TIPOCHAVE;
typedef int bool;

typedef struct reg {
      TIPOCHAVE chave;
      struct reg *esq;
      struct reg *dir;
      bool dirCostura, esqCostura;
} noh; // nó

typedef noh* pont;

pont buscaNohParaInserir(pont raiz, TIPOCHAVE ch);

pont inicializarArvore(){
	return NULL;
}


bool arvoreVazia(pont raiz)
{
	if(raiz == NULL) return true;
	else return false;
}

pont inserir(pont raiz, pont p){
    //se a raiz for null, inserimos la
    if(arvoreVazia(raiz)) return p;
    pont no;
    no = buscaNohParaInserir(raiz, p->chave);
    if(no == NULL) return NULL;
    //se a chave do elemento a ser inserido for menor que a da raiz, insere na subarvore a esquerda
    else if(p->chave < no->chave){
        p->esq = no->esq;
        p->dir = no;
        no->esqCostura = false;
        no->esq = p;
    } else {
        p->esq = no;
        p->dir = no->dir;
        no->dirCostura = false;
        no->dir = p;
    }
    
    return raiz;    
}

pont criaNovoNoh(TIPOCHAVE ch){
    //aloca um espaco na memoria
    pont novoNoh = (pont)malloc(sizeof(noh));
    //seta que o ponteido da esquerda e null
    novoNoh->esq = NULL;
    //seta que o ponteiro da direito e null
    novoNoh->dir = NULL;
    //seta o valor a chave
    novoNoh->chave = ch;
    //seta o valor do verificador esquerda e direita com true
    novoNoh->dirCostura = true;
    novoNoh->esqCostura = true;
    //retorna o noh
    return novoNoh;
}
pont buscar(pont raiz, TIPOCHAVE chave){
    //verifica se a raiz e null
    if(raiz == NULL) return NULL;
    //verifica se o valor da raiz e igual ao valor passado, se for retorna a raiz
    if(raiz->chave == chave) return raiz;
    //verifica se o valor da chave da raiz e maior que o passado, se for faz a recursividade e chama a subarvore esquerda
    if(raiz->chave > chave) return buscar(raiz->esq, chave);
    //retorna a arvore direita
    return buscar(raiz->dir, chave);
}

pont buscaNoh(pont raiz, TIPOCHAVE ch, pont *pai){
    pont atual = raiz;

    *pai = NULL;

    while (atual){

        if(atual->chave == ch) return atual;

        *pai = atual;

        if(ch < atual->chave) atual = atual->esq;
        else atual = atual->dir;

    }

    return NULL;

}

//Nesta funcao e buscado onde sera inserido o novoNoh
//Ele retorna o pai do no q sera inserido
pont buscaNohParaInserir(pont raiz, TIPOCHAVE ch){
    pont pai = NULL;

    //while para percorrer a arvore
    while(raiz != NULL){
        //primeiro teste para evitar q haja chaves iguais na arvore
        if(raiz->chave == ch) {
            printf("Chave Duplicada nao pode ser inserida");
            //retorna NULL para ser tratado na funcao que o chamou
            return NULL;
        }

        //atualiza o ponteiro "pai"
        pai = raiz;

        //realiza a primeira comparacao de chaves
        //caso a chave inserida seja menor que a da raiz, ele entra nesse if
        //para poder andar pela subarvore da esquerda
        if(ch < raiz->chave){
            
            if(raiz->esqCostura == false) raiz = raiz->esq;
            else break;
        }else {
            if(raiz->dirCostura == false) raiz = raiz->dir;
            else break;
        }
    }

    return pai;
}
pont removeNoh(pont raiz, TIPOCHAVE ch) {
    pont pai, no, paiDaDireita, maisADireita;
    //busca o noh a ser removido e marca o pai dele
    no = buscaNoh(raiz, ch, &pai);
    //verifica se o no e null
    if(no == NULL) return raiz;

    //verifica se ele possui apenas um descendente
    if(!no->esq || !no->dir) {
        if(!no->esq) maisADireita = no->dir;
        else maisADireita = no->esq;
    //caso tenha dois descendentes
    }else {
        //marca pai da direita no noh
        paiDaDireita = no;
        //marca o mais a direita do esquerdo 
        maisADireita = no->esq;

        //repeticao para marcar o pai do mais a direita do elemento mais a direita da esquerda do no a ser removido
        while(maisADireita->dir){
            paiDaDireita = maisADireita;
            maisADireita = maisADireita->dir;
        }

        //verifica se o pai mais a direita e diferente do no a ser removido
        if(paiDaDireita != no){
            //faz o pai dda direita apontas para o filho mais a direita
            paiDaDireita->dir = maisADireita->esq;
            //aponta para o filho esquerdo do no a ser removido
            maisADireita->esq = no->esq;
        }

        //aponta para o noh a direita do que sera removido
        maisADireita->dir = no->dir;
    }

    //verifica se o que sera removido e a raiz
    if(!pai){
        //remove o noh desejado
        free(no);
        //retorna o mais a direita
        return maisADireita;
    }

    if(ch < pai->chave) pai->esq = maisADireita;
    else pai->dir = maisADireita;

    free(no);

    return raiz;
}

pont emOrdemSucessor(pont p){
    if(p->dirCostura == true) return p->dir;
    p = p->dir;
    while(p->esqCostura == false) p = p->esq;

    return p;
}

//imprime esquerda, raiz, direita
void emOrdem(pont raiz){
    if(arvoreVazia(raiz)) printf("Arvore vazia");
    pont p = raiz;
    while(p->esqCostura == false) p = p->esq;

    while(p != NULL){
        printf("%d ", p->chave);
        p = emOrdemSucessor(p);
    }
}

int contagemNumeroNohs(pont raiz){
    if(!raiz) return 0;
    return contagemNumeroNohs(raiz->esq) + 1 + contagemNumeroNohs(raiz->dir);
}

//imprime raiz, esquesda, direita
void imprimePreOrdem(pont raiz){ 
    printf("%d ",raiz->chave);
    if(raiz->esq != NULL) imprimePreOrdem(raiz->esq);
    if(raiz->dir != NULL) imprimePreOrdem(raiz->dir);
}

//imprime esquerda, direita, raiz
void imprimePosOrdem(pont raiz){ 
    if(raiz->esq != NULL) imprimePosOrdem(raiz->esq);
    if(raiz->dir != NULL) imprimePosOrdem(raiz->dir);
    printf("%d ",raiz->chave);
}

void main(){

    pont r = inicializarArvore();
    pont noh = criaNovoNoh(23);
    r = inserir(r, noh);
    noh = criaNovoNoh(15);
    r = inserir(r, noh);
    noh = criaNovoNoh(28);
    r = inserir(r, noh);
    noh = criaNovoNoh(2);
    r = inserir(r, noh);
    noh = criaNovoNoh(3);
    r = inserir(r, noh);
    noh = criaNovoNoh(1);
    r = inserir(r, noh);
    noh = criaNovoNoh(27);
    r = inserir(r, noh);
    noh = criaNovoNoh(30);
    r = inserir(r, noh);

    /* //removeNoh(r, 10);
    //printf("%d\n", contagemNumeroNohs(r));
    imprimeOrdem(r);
    printf("\n");
    imprimePreOrdem(r);
    printf("\n");
    imprimePosOrdem(r);   */

    emOrdem(r);
    
}