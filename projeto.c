#include "projeto.h"
#include <stdio.h>

void limpa() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
//função responsável por limpar as informações da variável para poder armazenar novas informações

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
}
//função responsável por ler as informações do usuário e salvar no arquivo binário

void excluir_tarefa(struct Tarefa *tarefas, int *cont, int posicao) {
    if (posicao >= 1 && posicao <= *cont) {
        for (int i = posicao - 1; i < *cont - 1; i++) {
            tarefas[i] = tarefas[i + 1];
        }
        (*cont)--;
        printf("Tarefa deletada\n\n");
    } else {
        printf("Posição inválida!\n\n",*cont);
        }
}
//função responsável por excluir alguma tarefa que está armazenada no arquivo binário
