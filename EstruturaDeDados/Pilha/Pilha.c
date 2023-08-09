#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"

// Estrutura que representa um nó da pilha
typedef struct Node {
    int data;           // Dado armazenado no nó
    struct Node* next;  // Ponteiro para o próximo nó
} Node;

// Estrutura que representa a pilha
typedef struct {
    Node* top;          // Ponteiro para o topo da pilha
} Pilha;

// Função para criar uma nova pilha vazia
Pilha* criarPilha() {
    Pilha* novaPilha = (Pilha*)malloc(sizeof(Pilha));  // Aloca memória para a estrutura da pilha
    if (novaPilha != NULL) {
        novaPilha->top = NULL;  // Inicializa o topo da pilha como nulo (vazia)
    }
    return novaPilha;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha* pilha) {
    return (pilha->top == NULL);  // Retorna verdadeiro se o topo da pilha for nulo (vazia)
}

// Função para empilhar um elemento na pilha
void empilhar(Pilha* pilha, int valor) {
    Node* novoNo = (Node*)malloc(sizeof(Node));  // Aloca memória para um novo nó
    if (novoNo != NULL) {
        novoNo->data = valor;       // Atribui o valor ao novo nó
        novoNo->next = pilha->top;  // Faz o próximo do novo nó apontar para o antigo topo
        pilha->top = novoNo;        // Atualiza o topo da pilha para o novo nó
    }
}

// Função para desempilhar um elemento da pilha
int desempilhar(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Erro: Pilha vazia\n");
        return -1;  // Valor de erro quando a pilha está vazia
    }

    int valorDesempilhado = pilha->top->data;  // Obtém o valor do topo da pilha
    Node* temp = pilha->top;                  // Guarda o endereço do nó a ser desempilhado
    pilha->top = pilha->top->next;            // Atualiza o topo para o próximo nó
    free(temp);                               // Libera a memória do nó desempilhado
    return valorDesempilhado;                 // Retorna o valor desempilhado
}

// Função para liberar a memória ocupada pela pilha
void destruirPilha(Pilha* pilha) {
    while (!pilhaVazia(pilha)) {
        desempilhar(pilha);  // Desempilha elementos até que a pilha esteja vazia
    }
    free(pilha);  // Libera a memória da estrutura da pilha
}
