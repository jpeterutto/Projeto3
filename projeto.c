#include "projeto.h"
#include <stdio.h>


void limpa() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void ler(struct Tarefa *armazena) {
    printf("Prioridade: ");
    scanf("%d", &armazena->prioridade);
    limpa();
    printf("Descricao: ");
    scanf("%299[^\n]", armazena->descricao);
    limpa();
    printf("Categoria: ");
    scanf("%99[^\n]", armazena->categoria);
    limpa();
    printf("Status (0 - Não Iniciado, 1 - Em Andamento, 2 - Completo): ");
    scanf("%d", (int*)&armazena->status);
    limpa();
}

void excluir_tarefa(struct Tarefa *tarefas, int *cont, int posicao) {
    if (posicao >= 1 && posicao <= *cont) {
        for (int i = posicao - 1; i < *cont - 1; i++) {
            tarefas[i] = tarefas[i + 1];
        }
        (*cont)--;
        printf("Tarefa deletada\n\n");
    } else {
        printf("Posição inválida!\n\n", *cont);
    }
}
