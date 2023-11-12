#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "projeto.h"

int main() {
    struct Tarefa t[100];
    FILE *arquivo_binario = fopen("tarefas.txt", "rb");
    int cont = 0;

    if (arquivo_binario) {
        while (fread(&t[cont], sizeof(struct Tarefa), 1, arquivo_binario) == 1) {
            cont++;
        }
        fclose(arquivo_binario);
    }

    int posicao = 0;

    while (1) {
        printf(" 1 - Criar\n");
        printf(" 2 - Excluir\n");
        printf(" 3 - Listar\n");
        printf(" 4 - Alterar\n");
        printf(" 5 - Filtrar por Prioridade\n");
        printf(" 6 - Filtrar por Estado\n");
        printf(" 7 - Filtrar por Categoria\n");
        printf(" 8 - Filtrar por Prioridade e Categoria\n");
        printf(" 9 - Exportar por Prioridade\n");
        printf("10 - Sair\n");
        printf("Digite o numero da opcao que deseja usar: ");

        char *p, s_opcao[100];
        char *p_posicao, s_posicao[100];
        int opcao;
        fgets(s_opcao, sizeof(s_opcao), stdin);
        opcao = strtol(s_opcao, &p, 10);

        switch (opcao) {
            case 1:
                ler(&t[cont]);
                printf("Tarefa criada!\n\n");
                cont++;
                break;
            case 2:
                printf("Digite o numero da tarefa que deseja excluir: ");
                fgets(s_posicao, sizeof(s_posicao), stdin);
                posicao = strtol(s_posicao, &p_posicao, 10);

                if (p_posicao == s_posicao || *p_posicao != '\n') {
                    printf("Valor inválido!\n\n");
                } else {
                    excluir_tarefa(t, &cont, posicao);
                }
                break;
            case 3:
                printf("Lista ordenada por prioridade (da maior para a menor):\n\n");
                qsort(t, cont, sizeof(struct Tarefa), comparar_prioridades);
                for (int x = 0; x < cont; x++) {
                    imprimir_tarefa(t[x]);
                }
                break;
            case 4:
                posicao = menu_alterar();
                if (posicao >= 1 && posicao <= cont) {
                    imprimir_tarefa(t[posicao - 1]);
                    alterar_tarefa(t, cont, posicao);
                    printf("Tarefa alterada!\n\n");
                } else {
                    printf("Posição inválida!\n\n");
                }
                break;
            case 5:
                printf("Digite a prioridade para filtrar: ");
                fgets(s_posicao, sizeof(s_posicao), stdin);
                int prioridade = strtol(s_posicao, &p_posicao, 10);

                if (p_posicao == s_posicao || *p_posicao != '\n') {
                    printf("Valor inválido!\n\n");
                } else {
                    filtrar_por_prioridade(t, cont, prioridade);
                }
                break;
            case 6:
                printf("Digite o estado para filtrar (0 - Não Iniciado, 1 - Em Andamento, 2 - Completo): ");
                fgets(s_posicao, sizeof(s_posicao), stdin);
                int estado = strtol(s_posicao, &p_posicao, 10);

                if (p_posicao == s_posicao || *p_posicao != '\n') {
                    printf("Valor inválido!\n\n");
                } else {
                    filtrar_por_estado(t, cont, estado);
                }
                break;
            case 7:
                printf("Digite a categoria para filtrar: ");
                fgets(t[cont].categoria, sizeof(t[cont].categoria), stdin);
                t[cont].categoria[strcspn(t[cont].categoria, "\n")] = '\0';
                filtrar_por_categoria(t, cont, t[cont].categoria);
                break;
            case 8:
                printf("Digite a prioridade para filtrar: ");
                fgets(s_posicao, sizeof(s_posicao), stdin);
                prioridade = strtol(s_posicao, &p_posicao, 10);
                printf("Digite a categoria para filtrar: ");
                fgets(t[cont].categoria, sizeof(t[cont].categoria), stdin);
                t[cont].categoria[strcspn(t[cont].categoria, "\n")] = '\0';
                filtrar_por_prioridade_e_categoria(t, cont, prioridade, t[cont].categoria);
                break;
            case 9:
                printf("Digite a prioridade para exportar: ");
                fgets(s_posicao, sizeof(s_posicao), stdin);
                int prioridade_export = strtol(s_posicao, &p_posicao, 10);

                if (p_posicao == s_posicao || *p_posicao != '\n') {
                    printf("Valor inválido!\n\n");
                } else {
                    char nome_arquivo_export[100];
                    printf("Digite o nome do arquivo de exportacao: ");
                    fgets(nome_arquivo_export, sizeof(nome_arquivo_export), stdin);
                    nome_arquivo_export[strcspn(nome_arquivo_export, "\n")] = '\0';
                    exportar_por_prioridade(t, cont, prioridade_export, nome_arquivo_export);
                    printf("Tarefas exportadas!\n\n");
                }
                break;
            case 10:
                arquivo_binario = fopen("tarefas.txt", "wb");
                if (arquivo_binario) {
                    fwrite(t, sizeof(struct Tarefa), cont, arquivo_binario);
                    fclose(arquivo_binario);
                }
                printf("Saindo\n");
                return 0;
            default:
                printf("Valor inválido!\n\n");
        }
    }

    return 0;
}
