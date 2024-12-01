#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo tipoNo;

typedef struct tipoNo{
    int info;
    tipoNo* prox;
    tipoNo* ant;
}tipoNo;

typedef struct tipoFila{
    tipoNo* comeco;
    tipoNo* fim;
}tipoFila;

/*função que cria, alocando dinamicamente, uma fila do tipo 'tipoFila', onde todos os seus ponteiros
recebem NULL, que indica que a fila está vazia, e depois retorna o ponteiro apontando para a fila
criada
Não recebe nada como parâmetro
Retorna um ponteiro que aponta para a nova fila que foi criada*/
tipoFila* criarFila();

/*função que insere elementos no final da fila, criando um nó com o elemento, caso a fila esteja vazia,
ele se torna o primeiro e o último elemento, se ela estiver ocupada, ele é inserido no fim da fila
Recebe um ponteiro que aponta para fila do tipo tipoFila e um inteiro info
Não retorna nada*/
void inserirFila(tipoFila* fila, int info);

/*função que imprime os dados de uma fila de maneira organizada, checando inicialmente se ela esta
vazia ou possui elementos
Recebe um inteiro idade como parâmetro 
Não retorna nada*/
void mostrarFila(tipoFila* fila);

/*função que retira elementos de uma fila, ele remove o primeiro elemento da fila e depois retorna 
o valor que permaneceu armazenado, caso a fila fique vazia, os ponteiros comeco e fim apontam para
NULL
Recebe um ponteiro que aponta para fila do tipo tipoFila
Retorna o valor que permaneceu armazenado*/
int retirar(tipoFila* fila);

/*função que libera a memória que foi alocada para os nós da fila e a própria estrutura da fila
Recebe um ponteiro que aponta para fila do tipo tipoFila
Não retorna nada*/
void liberarFila(tipoFila* fila);
