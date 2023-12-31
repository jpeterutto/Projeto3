#include "projeto.h"
#include <stdio.h>

//Função responsável por limpar as informações salvas na variável para poder armazenar novas informações
void limpa() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

//Função que lê as informações dadas pelo usuário e armazena no arquivo
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

//Função responsável por excluir as tarefas
void excluir_tarefa(struct Tarefa *tarefas, int *cont, int posicao) {
    if (posicao >= 1 && posicao <= *cont) {
        for (int i = posicao - 1; i < *cont - 1; i++) {
            tarefas[i] = tarefas[i + 1];
        }
        (*cont)--;
        printf("Tarefa deletada\n\n");
    } else {
        printf("Posição inválida!\n\n");
    }
}

//Função responsável por alterar as tarefas
void alterar_tarefa(struct Tarefa *tarefas, int cont, int posicao) {
    int opcao;
    char *p;
    char s_opcao[100];

    printf("Escolha o campo que deseja alterar:\n");
    printf("1 - Prioridade\n");
    printf("2 - Descrição\n");
    printf("3 - Categoria\n");
    printf("4 - Status\n");
    printf("Digite o número da opção: ");
    fgets(s_opcao, sizeof(s_opcao), stdin);
    opcao = strtol(s_opcao, &p, 10);

    switch (opcao) {
        case 1:
            printf("Nova Prioridade: ");
            scanf("%d", &tarefas[posicao - 1].prioridade);
            limpa();
            break;
        case 2:
            printf("Nova Descrição: ");
            scanf("%299[^\n]", tarefas[posicao - 1].descricao);
            limpa();
            break;
        case 3:
            printf("Nova Categoria: ");
            scanf("%99[^\n]", tarefas[posicao - 1].categoria);
            limpa();
            break;
        case 4:
            printf("Novo Status (0 - Não Iniciado, 1 - Em Andamento, 2 - Completo): ");
            scanf("%d", (int*)&tarefas[posicao - 1].status);
            limpa();
            break;
        default:
            printf("Opção inválida\n");
    }
}

//Menu para escolher o que vai ser alterado na tarefa
int menu_alterar() {
    char *p;
    char s_opcao[100];
    int opcao;

    printf("Digite o número da tarefa que deseja alterar: ");
    fgets(s_opcao, sizeof(s_opcao), stdin);
    opcao = strtol(s_opcao, &p, 10);

    return opcao;
}

//Função responsável por imprimir as tarefas
void imprimir_tarefa(struct Tarefa tarefa) {
    printf("Prioridade: %d\n", tarefa.prioridade);
    printf("Categoria: %s\n", tarefa.categoria);
    printf("Descricao: %s\n", tarefa.descricao);

    
    printf("Status: ");
    switch (tarefa.status) {
        case NAO_INICIADO:
            printf("Não Iniciado\n");
            break;
        case EM_ANDAMENTO:
            printf("Em Andamento\n");
            break;
        case COMPLETO:
            printf("Completo\n");
            break;
        default:
            printf("Desconhecido\n");
    }

    printf("\n");
}

//Função responsável por filtrar tarefas por prioridade
void filtrar_por_prioridade(struct Tarefa *tarefas, int cont, int prioridade) {
    printf("Tarefas com Prioridade %d:\n", prioridade);

    for (int i = 0; i < cont; i++) {
        if (tarefas[i].prioridade == prioridade) {
            imprimir_tarefa(tarefas[i]);
        }
    }

    printf("\n");
}

//Função responsável por filtrar tarefas por estado
void filtrar_por_estado(struct Tarefa *tarefas, int cont, enum Status estado) {
    printf("Tarefas com Estado %d:\n", estado);

    for (int i = 0; i < cont; i++) {
        if (tarefas[i].status == estado) {
            imprimir_tarefa(tarefas[i]);
        }
    }

    printf("\n");
}

//Função responsável por filtrar tarefas por categoria
void filtrar_por_categoria(struct Tarefa *tarefas, int cont, const char *categoria) {
    printf("Tarefas na Categoria \"%s\":\n", categoria);

    for (int i = 0; i < cont; i++) {
        if (strcmp(tarefas[i].categoria, categoria) == 0) {
            imprimir_tarefa(tarefas[i]);
        }
    }

    printf("\n");
}

//Função responsável por filtrar tarefas por prioridade e categoria
void filtrar_por_prioridade_e_categoria(struct Tarefa *tarefas, int cont, int prioridade, const char *categoria) {
    printf("Tarefas com Prioridade %d e Categoria \"%s\":\n", prioridade, categoria);

    for (int i = 0; i < cont; i++) {
        if (tarefas[i].prioridade == prioridade && strcmp(tarefas[i].categoria, categoria) == 0) {
            imprimir_tarefa(tarefas[i]);
        }
    }

    printf("\n");
}

//Função responsável por comparar o nível das prioridades
int comparar_prioridades(const void *a, const void *b) {
    return ((struct Tarefa*)b)->prioridade - ((struct Tarefa*)a)->prioridade;
}

//Função responsável por exportar tarefas por prioridade
void exportar_por_prioridade(struct Tarefa *tarefas, int cont, int prioridade, const char *nome_arquivo) {
    FILE *arquivo_export = fopen(nome_arquivo, "w");

    if (!arquivo_export) {
        printf("Erro ao criar o arquivo de exportacao.\n");
        return;
    }

    fprintf(arquivo_export, "Prioridade, Categoria, Estado, Descricao\n");

    for (int i = 0; i < cont; i++) {
        if (tarefas[i].prioridade == prioridade) {
            fprintf(arquivo_export, "%d, %s, %d, %s\n", tarefas[i].prioridade, tarefas[i].categoria, tarefas[i].status, tarefas[i].descricao);
        }
    }

    fclose(arquivo_export);
}

//Função responsável por exportar tarefas por categoria
void exportar_por_categoria(struct Tarefa *tarefas, int cont, const char *categoria, const char *nome_arquivo) {
    FILE *arquivo_export = fopen(nome_arquivo, "w");

    if (!arquivo_export) {
        printf("Erro ao criar o arquivo de exportacao.\n");
        return;
    }

    // Ordenar as tarefas por prioridade
    qsort(tarefas, cont, sizeof(struct Tarefa), comparar_prioridades);

    fprintf(arquivo_export, "Prioridade, Categoria, Estado, Descricao\n");

    for (int i = 0; i < cont; i++) {
        if (strcmp(tarefas[i].categoria, categoria) == 0) {
            fprintf(arquivo_export, "%d, %s, %d, %s\n", tarefas[i].prioridade, tarefas[i].categoria, tarefas[i].status, tarefas[i].descricao);
        }
    }

    fclose(arquivo_export);
}

//Função responsável por exportar tarefas por prioridade e categoria
void exportar_por_prioridade_e_categoria(struct Tarefa *tarefas, int cont, int prioridade, const char *categoria, const char *nome_arquivo) {
    FILE *arquivo_export = fopen(nome_arquivo, "w");

    if (!arquivo_export) {
        printf("Erro ao criar o arquivo de exportacao.\n");
        return;
    }

    fprintf(arquivo_export, "Prioridade, Categoria, Estado, Descricao\n");

    for (int i = 0; i < cont; i++) {
        if (tarefas[i].prioridade == prioridade && strcmp(tarefas[i].categoria, categoria) == 0) {
            fprintf(arquivo_export, "%d, %s, %d, %s\n", tarefas[i].prioridade, tarefas[i].categoria, tarefas[i].status, tarefas[i].descricao);
        }
    }

    fclose(arquivo_export);
}
