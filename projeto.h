#ifndef PROJETO_H
#define PROJETO_H

struct Tarefa {
    int prioridade;
    char categoria[100];
    char descricao[300];
};
//Espaço responsável por definir a estrutura da tarefa

void limpa();
//cabeçalho da função responsável por limpar as informações salvas na variável para poder armazenar novas informações
void ler(struct Tarefa *armazena);
//cabeçalho da função que lê as informações dadas pelo usuário e armazena no arquivo
void excluir_tarefa(struct Tarefa *tarefas, int *cont, int posicao);
//cabeçalho da função que vai excluir as tarefas

#endif//PROJETO_H
