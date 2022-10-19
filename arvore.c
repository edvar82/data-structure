#include <stdio.h>
#include <stdlib.h>





typedef struct no{
    int info;
    struct no *prox;
}No;

typedef struct arvore{
    int info;
    struct arvore *filho;
    struct arvore *irmao;
}Arvore;

Arvore *criarArvore(int info){
    Arvore *a = (Arvore*)malloc(sizeof(Arvore));
    a->info = info;
    a->filho = NULL;
    a->irmao = NULL;
    return a;
}

Arvore *concatenar(Arvore *a1, Arvore *a2){
    if(a1 == NULL){
        return a2;
    }
    if(a2 == NULL){
        return a1;
    }
    Arvore *aux = a1;
    while(aux->irmao != NULL){
        aux = aux->irmao;
    }
    aux->irmao = a2;
    return a1;
}

Arvore *concatenarArvores(Arvore *a1, Arvore *a2){
    if(a1 == NULL){
        return a2;
    }
    if(a2 == NULL){
        return a1;
    }
    Arvore *aux = a1;
    while(aux->irmao != NULL){
        aux = aux->irmao;
    }
    aux->irmao = a2;
    return a1;
}

void imprimirArvore(Arvore *a){
    if(a == NULL){
        return;
    }
    printf("%d ", a->info);
    imprimirArvore(a->filho);
    imprimirArvore(a->irmao);
}

void inserirFilho(Arvore *a, Arvore *filho){
    if(a == NULL){
        return;
    }
    if(a->filho == NULL){
        a->filho = filho;
    }else{
        Arvore *aux = a->filho;
        while(aux->irmao != NULL){
            aux = aux->irmao;
        }
        aux->irmao = filho;
    }
}

int main(){
     
}