// main.c
#include <stdio.h>
#include "max_heap.h"

int main() {
    MaxHeap *heap = criarMaxHeap(10); // Cria uma heap máxima com capacidade 10

    inserir(heap, 5);
    inserir(heap, 10);
    inserir(heap, 7);
    inserir(heap, 3);
    inserir(heap, 8);

    printf("Valor máximo extraído: %d\n", extrairMaximo(heap));
    printf("Valor máximo extraído: %d\n", extrairMaximo(heap));

    destruirMaxHeap(heap);

    return 0;
}
