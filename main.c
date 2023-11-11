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
        printf(" 5 - Sair\n");
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
                printf("Lista:\n\n");
                for (int x = 0; x < cont; x++) {
                    printf("Tarefa %d\n", x + 1);
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
