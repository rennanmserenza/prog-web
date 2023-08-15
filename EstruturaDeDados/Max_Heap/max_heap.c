// max_heap.c
#include <stdio.h>
#include <stdlib.h>
#include "max_heap.h"

// Cria uma nova heap máxima com a capacidade especificada
MaxHeap *criarMaxHeap(int capacidade) {
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->arr = (int *)malloc(sizeof(int) * (capacidade + 1)); // +1 para índices baseados em 1
    heap->tamanho = 0;
    heap->capacidade = capacidade;
    return heap;
}

// Libera a memória associada à heap
void destruirMaxHeap(MaxHeap *heap) {
    free(heap->arr);
    free(heap);
}

// Troca os valores de dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Corrige a propriedade de heap máxima para um nó específico
void ajustarHeap(MaxHeap *heap, int idx) {
    int maior = idx;
    int esquerda = 2 * idx;
    int direita = 2 * idx + 1;

    // Verifica se o nó à esquerda é maior que o nó atual
    if (esquerda <= heap->tamanho && heap->arr[esquerda] > heap->arr[maior])
        maior = esquerda;

    // Verifica se o nó à direita é maior que o nó atual
    if (direita <= heap->tamanho && heap->arr[direita] > heap->arr[maior])
        maior = direita;

    // Se o nó atual não é o maior, troca com o maior filho e ajusta recursivamente
    if (maior != idx) {
        trocar(&heap->arr[idx], &heap->arr[maior]);
        ajustarHeap(heap, maior);
    }
}

// Insere um novo valor na heap
void inserir(MaxHeap *heap, int valor) {
    if (heap->tamanho >= heap->capacidade)
        return; // A heap está cheia

    heap->tamanho++;
    int idx = heap->tamanho;
    heap->arr[idx] = valor;

    // Ajusta a propriedade de heap máxima para cima
    while (idx > 1 && heap->arr[idx] > heap->arr[idx / 2]) {
        trocar(&heap->arr[idx], &heap->arr[idx / 2]);
        idx /= 2;
    }
}

// Extrai e remove o elemento máximo da heap
int extrairMaximo(MaxHeap *heap) {
    if (heap->tamanho == 0)
        return -1; // A heap está vazia

    int maximo = heap->arr[1]; // O máximo está na raiz (índice 1)
    heap->arr[1] = heap->arr[heap->tamanho]; // Substitui pelo último elemento
    heap->tamanho--;

    // Ajusta a propriedade de heap máxima para baixo
    ajustarHeap(heap, 1);

    return maximo;
}
