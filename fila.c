#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//função que cria uma fila
tipoFila* criarFila(){
    tipoFila* fila = (tipoFila*) malloc(sizeof(tipoFila));
    if (fila == NULL) {
        printf("erro ao alocar a fila.\n");
        exit(1);
    }
    fila->comeco = NULL;
    fila->fim = NULL;

    return fila;
}

//função que insere informações na fila
void inserirFila(tipoFila* fila, int idade){
    tipoNo* no;
    no = (tipoNo*) malloc(sizeof(tipoNo));
    if (no == NULL) {
        printf("erro ao alocar o nó.\n");
        exit(1);
    }
    no->info = idade;
    no->prox = NULL;
    no->ant = fila->fim;
    fila->fim = no;


    if(fila->comeco == NULL){
        fila->comeco = no;
    }
    else{
        fila->fim->ant->prox = no;
    }

}

//funçao que imprime a fila no terminal
void mostrarFila(tipoFila* fila){
    if(fila->comeco == NULL){
        printf("a fila esta vazia!\n");
        return;
    }
    tipoNo* troca = fila->comeco;
    while(troca){
        printf("idade: %d\n", troca->info);
        troca = troca->prox;
    }
}

//função que retira informações da fila
int retirar(tipoFila* fila){
    tipoNo* troca;
    int dado;

    troca = fila->comeco;
    fila->comeco = fila->comeco->prox;
    if(fila->comeco == NULL){
        fila->fim = NULL;
    }
    dado = troca->info;
    free(troca);

    return dado;
}

//função que libera memoria da fila
void liberarFila(tipoFila* fila){
    tipoNo* atual;
    tipoNo* prox;
    
    atual = fila->comeco;
    while(atual != NULL){
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    free(fila);
}
