typedef struct arv Arv;

Arv* criar_vazia();
Arv* criar(char c, Arv* sae, Arv* sad);
int vazia(Arv* a);
void imprime(Arv* a);
void imprime_arvore(Arv*a);
Arv* liberar(Arv* a);
int busca(Arv* a, char c);