#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // De estimação já s2

typedef struct aluno{
    int mat;
    char nome[30];
    float n1;
}Aluno;

typedef struct lista Lista;

Lista *criar();
void limpar(Lista *l);

int inserirInicio(Lista *l,Aluno it); //ok
int inserirFim(Lista *l,Aluno it); //ok
int inserirPosicao(Lista *l, Aluno it, int pos);

int removerInicio(Lista *l);
int removerPosicao(Lista *l,int pos);//ok
int removerItem(Lista *l, int it);//ok

int buscarItemChave(Lista *l,int chave);//
int buscarPosicao(Lista *l,int posicao,Aluno *retorno);//

int listaVazia(Lista *l);//ok

int listaCheia(Lista *l);//ok
int tamanho(Lista *l);//ok

void maiorNota (Lista *l); 
int troca(Lista *l, int pos1, int pos2); //
int equivalente(Lista *l, Lista *l2); //
int removerRepts(Lista *l);

int intersec(Lista *l1, Lista *l2, Lista *l3);
int contemItem(Lista *l, Aluno it);

void mostrar(Lista *l);


//Lista *concatena(Lista *l1, Lista *l2);

int removerNos(Lista *l, int n);
int retornaMat(Lista *l, int pos);

//void maiorNota (Lista *l);

