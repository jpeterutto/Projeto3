#ifndef PROJETO_H
#define PROJETO_H

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
void filtrar_por_estado(struct Tarefa *tarefas, int cont, enum Status estado);
void filtrar_por_categoria(struct Tarefa *tarefas, int cont, const char *categoria);
int comparar_prioridades(const void *a, const void *b);

#endif // PROJETO_H
