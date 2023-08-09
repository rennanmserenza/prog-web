#ifndef PILHA_H
#define PILHA_H

// Definição da estrutura do nó
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definição da estrutura da pilha
typedef struct {
    Node* top;
} Pilha;

// Funções da pilha
Pilha* criarPilha();
int pilhaVazia(Pilha* pilha);
void empilhar(Pilha* pilha, int valor);
int desempilhar(Pilha* pilha);
void destruirPilha(Pilha* pilha);

#endif  // PILHA_H
