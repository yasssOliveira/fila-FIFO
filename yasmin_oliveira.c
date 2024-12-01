#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/*função que ordena valores de maneira decrescente utilizando bubble sort e trocando
os valores dos nós sem alterar os ponteiros
Recebe um ponteiro que aponta para fila do tipo tipoFila
Não retorna nada*/
void organiza_bubbleSort(tipoFila* fila){
    if(fila->comeco == NULL || fila->comeco->prox == NULL){
        return;
    }

    int flagTroca;
    
    do{
        flagTroca = 0;
        tipoNo* p1 = fila->comeco;
        tipoNo* p2 = p1->prox;

        while(p2 != NULL){
            if(p1->info < p2->info){
                int troca = p1->info;
                p1->info = p2->info;
                p2->info = troca;
                flagTroca = 1;
            }
        p1 = p2;
        p2 = p2->prox;
        }
    }while(flagTroca);
}

/*função que remove primeiros elementos da fila. Após a organização do bubble sort, os primeiros
elementos são os maiores, então ela os remove simulando a fila de atendimento por prioridade de 
idade. Cada vez que um elemento é retirado, imprime a mensagem 'idade atentdida: (idade)' e caso
a fila fique vazia, imprime a mensagem 'fila vazia! todos os clientes ja foram atendidos!'
Recebe um ponteiro que aponta para fila do tipo tipoFila
Não retorna nada*/
void atendimento(tipoFila* fila){
    while(fila->comeco != NULL){
        int atendido = retirar(fila);
        printf("idade atendida: %d\n", atendido);
    }
    printf("\n");
    if(fila->comeco == NULL){
        printf("fila vazia! todos os clientes ja foram atendidos!\n");
    }
}

int main(void){
    tipoFila* fila;
    fila = criarFila(); //cria a fila
    FILE* arq = fopen("clientes.txt", "r"); //lê o arquivo de teste

    if(arq == NULL){
        printf("erro na abertura do arquivo!\n"); //informa se ouve algum erro durante a abertura do arquivo
        return 1;
    }

    int idade;
    while(fscanf(arq, "%d", &idade) != EOF){
        printf("idade inserida: %d\n", idade); //lê as informações do arquivo
        inserirFila(fila, idade); //armazena as informações na fila
    }
    fclose(arq); //fecha o arquivo

    printf("\nfila na ordem original: \n");
    mostrarFila(fila); //imprime a fila na ordem em que as informações apareciam no arquivo original

    organiza_bubbleSort(fila); //organiza as informações em ordem decrescente na fila

    printf("\nfila organizada por prioridade de idade: \n");
    mostrarFila(fila);// imprime as informações na ordem de tamanho decrescente 
    printf("\n");

    atendimento(fila); //retira os dados a cada atendimento 
    
    liberarFila(fila); //libera memoria alocada para os nós e para a fila
    
    return 0;
}
