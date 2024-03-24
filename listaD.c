#include "listaD.h"

typedef struct no {
    Aluno valor;
    struct no *prox;
    struct no *ant;
}No;

typedef struct lista {
    No *inicio;
}Lista;

Lista *criar(){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

void limpar(Lista *l){
    while (listaVazia(l) != 0)
        removerInicio(l);

    free(l);
    l = NULL;
}

int inserirInicio(Lista *l, Aluno it){
    if (l == NULL) return 2;
    No *no = (No*)malloc(sizeof(No));
    no->valor = it;
    no->prox = l->inicio;
    no->ant = NULL;
    if(l->inicio != NULL)
        l->inicio->ant = no;
    l->inicio= no;

    return 0;
}

int inserirFim(Lista *l, Aluno it){
    if (l == NULL) return 2;
    if(listaVazia(l) == 0) return inserirInicio(l, it);
    No *noLista = l->inicio;
    while (noLista->prox != NULL)
        noLista = noLista->prox;
    No *no = (No*)malloc(sizeof(No));
    no->valor =it;
    no->prox = NULL;
    no->ant = noLista;
    noLista->prox = no;

    return 0;
}

int inserirPosicao(Lista *l, Aluno it, int pos){
    if (l == NULL) return 2;
    if (pos < 0) return 3;
    if ((listaVazia(l) == 0)||(pos == 0))return inserirInicio(l,it);
    
    No *auxiliar = l->inicio;
    while ((auxiliar->prox != auxiliar)&&(pos > 1)){
        auxiliar = auxiliar->prox;
        pos--;
    }
    if(auxiliar == NULL) return inserirFim(l,it);
    else {
        No *no = (No*)malloc(sizeof(No));
        no->valor = it;
        no->prox = auxiliar;
        no->ant= auxiliar->ant;
        auxiliar->ant = no;
        no->ant->prox = no;
    }
    
    return 0;
}

int removerInicio(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    No *noLista = l->inicio;
    l->inicio = noLista->prox;
    
    if(l->inicio != NULL)
        l->inicio->ant = NULL;
    
    free(noLista);
    return 0;
}

int removerFim(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    No *noLista = l->inicio;
    
    while (noLista->prox != NULL)
        noLista = noLista->prox;
    
    if(noLista->ant == NULL)
        l->inicio = NULL;
    else
        noLista->ant->prox = NULL;
    free(noLista);
    return 0;
}

int removerPosicao(Lista *l, int pos){
    if (l == NULL) return 2;
    if (pos < 0) return 3;
    if ((listaVazia(l) == 0)) return 2;
    
    No *noLista = l->inicio;
    
    while ((noLista->prox != NULL) && (pos > 0)){
        noLista = noLista->prox;
        pos--;
    }

    
    if ( noLista->prox == NULL) return removerFim(l);
    if ( noLista->ant == NULL) return removerInicio(l);

    noLista->ant->prox = noLista->prox;
    noLista->prox->ant = noLista->ant;
    
    free(noLista);
    return 0;
} 


int removerItem(Lista *l, int it){
    int pos = buscarItemChave (l,it);
    removerPosicao(l,pos);

    return 0;
}

int buscarItemChave(Lista *l, int chave){
    if (l == NULL) return 2;
    if(listaVazia(l) == 0) return -1;
    No *noLista = l->inicio;
    int pos = 0;
    while (noLista != NULL ){
        if (noLista->valor.mat == chave){
            return pos;
        }
        pos++;
        noLista = noLista->prox;
    }
    
    return -1;
}

int buscarPosicao(Lista *l, int posicao, Aluno *retorno){
    if (l == NULL) return 2;
    No *noLista = l->inicio;
    int p = 0;
    if(posicao > tamanho(l)) return 3;

    while (p != posicao ){
        noLista = noLista->prox;
        p++;
    }
    *retorno = noLista->valor;
    return 0;
}

int listaVazia(Lista *l) {
    if (l == NULL) return 2;
    if (l->inicio == NULL) return 0;
    return 1;
}

int listaCheia(Lista *l){
    if(tamanho(l) == MAX) return 1;
    return 0;
}

int tamanho(Lista *l){
    if (l == NULL) return -1;
    No *noLista = l->inicio;
    int tam = 0;
    while (noLista != NULL ){
        tam++;
        noLista = noLista->prox;
    }
    return tam;
}


void mostrar(Lista *l){
    if (l != NULL){
        printf("[");
        No *noLista = l->inicio;
        while (noLista != NULL) {
            printf(" {%d, ",noLista->valor.mat);
            printf("%s, ",noLista->valor.nome);
            printf("%.2f} ",noLista->valor.n1);
            noLista = noLista->prox;
        }
        printf("]\n");
    }
}
 
int contemItem(Lista *l, Aluno it){
    if (l == NULL) return -1;
    int quant = 0;
    No *noLista = l->inicio;
    while (noLista != NULL ){
        if (noLista->valor.mat == it.mat){
            quant ++;
        }
        noLista = noLista->prox;
    }
    return quant;
}

void maiorNota (Lista *l){
    Aluno it;
    it.n1 = 0;
    No *noLista = l->inicio;
    while ((noLista != NULL)){
        if (noLista->valor.n1 >= it.n1){
            it = noLista->valor;
        }
        noLista = noLista->prox;
    }
    printf("Aluno com a maior nota:\n");
    printf("Matricula: %d\nNome: %s\nNota: %f\n", it.mat, it.nome, it.n1);
}

int inserirOrdenadamente(Lista *l, Aluno it){// SE QUISER PODE FAZER MAIS GERAL
    if (l == NULL) return 2;               
    if(listaVazia(l) == 0 ) return inserirInicio(l, it); // NOQUIERO
    int pos = 0;

    No *n = l-> inicio;
    while((n != NULL) && (n->valor.mat <= it.mat)){
        n = n->prox;
        pos++;
    }

    return inserirPosicao(l, it, pos);

}

int troca(Lista *l,  int pos1, int pos2){
    if (l == NULL) return 2;               
    if(listaVazia(l) == 0 ) return 1;

    No *a = l-> inicio;
    No *d = l-> inicio;
    
    int p1 = pos1;
    int p2 = pos2;
    while((a != NULL) && (pos1 > 0)){
        a = a->prox;
        pos1--;
    }
    while((d != NULL) && (pos2 > 0)){
        d = d->prox;
        pos2--;
    }

    if((p1+1) != p2 && (p2+1) != p1){
        No *antA = a->ant;
        No *proxA = a->prox;
        No *antD = d->ant;
        No *proxD = d->prox;

        if(antA != NULL)
            antA->prox = d;
        else
            l->inicio = d;

        if(proxA != NULL)
            proxA->ant = d;

        if(antD != NULL)
            antD->prox = a;

        if(proxD != NULL)
            proxD->ant = a;

        a->ant = antD;
        a->prox = proxD;
        d->ant = antA;
        d->prox = proxA;
    } else { 
        

        if(a->ant != NULL)
            a->ant->prox = d;
        else 
            l->inicio = d;

        if(d->prox != NULL)
            d->prox->ant = a;

        a->prox = d->prox;
        d->ant = a->ant;
        d->prox = a;
        a->ant = d;
    }
    
    return 0;
}

int removerNos(Lista *l, int n){
    if (l == NULL) return 2;
    if (n < 0) return 3;
    for(int i = 0; i < n; i++){
        removerInicio(l);
    }
    return 0;
}

int equivalente(Lista *l , Lista *l2){
    if(tamanho(l) != tamanho(l2)) return 1;
    Aluno e; 
    for(int i = 0; i < tamanho(l); i++){
        buscarPosicao(l, i, &e);
        if(contemItem(l, e) != contemItem(l2,e)){
            return 1;
        }
    }
    return 0;
}

int removerRepts(Lista *l){
    Aluno e;
    int tam = tamanho(l);
    for(int i = 0; i < tam; i++){
        buscarPosicao(l, i, &e);
        if(contemItem(l, e) > 1){
            removerItem(l, retornaMat(l, i));
            i--;
            tam--;
        }
    }
    return 0;
}

int retornaMat(Lista *l, int pos){
    if (l == NULL) return 2;
    if(listaVazia(l) == 0) return 3;
    
    No *noLista = l->inicio;
    while (noLista->prox != NULL && pos > 0){
        noLista = noLista->prox;
        pos--;
    }
    return noLista->valor.mat;
        
}