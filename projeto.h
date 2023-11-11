#ifndef PROJETO_H
#define PROJETO_H


// Adicionando um enum para representar o status da tarefa
enum Status {
    NAO_INICIADO,
    EM_ANDAMENTO,
    COMPLETO
};

struct Tarefa {
    int prioridade;
    char categoria[100];
    char descricao[300];
    enum Status status;  // Novo campo para representar o status da tarefa
};

void limpa();
void ler(struct Tarefa *armazena);
void excluir_tarefa(struct Tarefa *tarefas, int *cont, int posicao);

#endif // PROJETO_H
