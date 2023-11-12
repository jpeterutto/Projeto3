#ifndef PROJETO_H
#define PROJETO_H


//Responsável por enumerar o Status da Tarefa
enum Status {
    NAO_INICIADO,
    EM_ANDAMENTO,
    COMPLETO
};

//Responsável por definir a estrutura da tarefa
struct Tarefa {
    int prioridade;
    char categoria[100];
    char descricao[300];
    enum Status status;
};

//Função responsável por limpar as informações salvas na variável para poder armazenar novas informações
void limpa();

//Função que lê as informações dadas pelo usuário e armazena no arquivo
void ler(struct Tarefa *armazena);

//Função responsável por excluir as tarefas
void excluir_tarefa(struct Tarefa *tarefas, int *cont, int posicao);

//Função responsável por alterar as tarefas
void alterar_tarefa(struct Tarefa *tarefas, int cont, int posicao);

//Menu para escolher o que vai ser alterado na tarefa
int menu_alterar();

//Função responsável por imprimir as tarefas
void imprimir_tarefa(struct Tarefa tarefa);

//Função responsável por filtrar tarefas por prioridade
void filtrar_por_prioridade(struct Tarefa *tarefas, int cont, int prioridade);

//Função responsável por filtrar tarefas por estado
void filtrar_por_estado(struct Tarefa *tarefas, int cont, enum Status estado);

//Função responsável por filtrar tarefas por categoria
void filtrar_por_categoria(struct Tarefa *tarefas, int cont, const char *categoria);

//Função responsável por filtrar tarefas por prioridade e categoria
void filtrar_por_prioridade_e_categoria(struct Tarefa *tarefas, int cont, int prioridade, const char *categoria);

//Função responsável por comparar o nível das prioridades
int comparar_prioridades(const void *a, const void *b);

//Função responsável por exportar tarefas por prioridade
void exportar_por_prioridade(struct Tarefa *tarefas, int cont, int prioridade, const char *nome_arquivo);

//Função responsável por exportar tarefas por categoria
void exportar_por_categoria(struct Tarefa *tarefas, int cont, const char *categoria, const char *nome_arquivo);

//Função responsável por exportar tarefas por prioridade e categoria
void exportar_por_prioridade_e_categoria(struct Tarefa *tarefas, int cont, int prioridade, const char *categoria, const char *nome_arquivo);

#endif // PROJETO_H
