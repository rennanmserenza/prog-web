#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"  // Inclui o header da pilha

int main() {
    Pilha* minhaPilha = criarPilha();  // Cria uma nova pilha vazia

    empilhar(minhaPilha, 10);  // Empilha valores na pilha
    empilhar(minhaPilha, 20);
    empilhar(minhaPilha, 30);

    printf("Elementos desempilhados: %d, %d, %d\n", desempilhar(minhaPilha), desempilhar(minhaPilha), desempilhar(minhaPilha));

    destruirPilha(minhaPilha);  // Libera a memória da pilha ao final

    return 0;
}