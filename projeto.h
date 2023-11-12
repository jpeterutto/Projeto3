#ifndef PROJETO_H
#define PROJETO_H

// João Pedro Lopes - RA: 24.123.071-3
// João Pedro Peterutto - RA: 24.123.045-7
// Gabriel Koiama - RA: 24.123.051-5

enum Status {
    NAO_INICIADO,
    EM_ANDAMENTO,
    COMPLETO
};

struct Tarefa {
    int prioridade;
    char categoria[100];
    char descricao[300];
    enum Status status;
};

void limpa();
void ler(struct Tarefa *armazena);
void excluir_tarefa(struct Tarefa *tarefas, int *cont, int posicao);
void alterar_tarefa(struct Tarefa *tarefas, int cont, int posicao);
int menu_alterar();
void imprimir_tarefa(struct Tarefa tarefa);
void filtrar_por_prioridade(struct Tarefa *tarefas, int cont, int prioridade);

#endif // PROJETO_H
