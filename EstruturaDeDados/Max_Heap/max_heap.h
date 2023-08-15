// max_heap.h
#ifndef MAX_HEAP_H
#define MAX_HEAP_H

// Definição da estrutura MaxHeap para representar a heap máxima
typedef struct {
    int *arr;        // Array para armazenar os elementos da heap
    int tamanho;     // Tamanho atual da heap
    int capacidade;  // Capacidade máxima da heap
} MaxHeap;

// Protótipos das funções públicas da heap
MaxHeap *criarMaxHeap(int capacidade);     // Cria uma nova heap máxima
void destruirMaxHeap(MaxHeap *heap);       // Libera a memória da heap
void inserir(MaxHeap *heap, int valor);    // Insere um elemento na heap
int extrairMaximo(MaxHeap *heap);          // Extrai e remove o elemento máximo da heap

#endif // MAX_HEAP_H
