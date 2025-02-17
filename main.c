// main.c
#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"

int ler_arquivo(TabelaHash *tabela, const char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    Aluno aluno;
    while (fscanf(arquivo, "%d %49s %d %d %d", &aluno.matricula, aluno.nome, &aluno.nota1, &aluno.nota2, &aluno.nota3) != EOF)
    {
        inserir_tabela(tabela, aluno);
    }

    fclose(arquivo);

    return 1;
}

void buscaAluno(TabelaHash *tabela, int matricula_busca)
{
    Aluno *encontrado = buscar_tabela(tabela, matricula_busca);

    if (encontrado)
    {
        printf("Aluno encontrado: %s\n", encontrado->nome);
    }
    else
    {
        printf("Aluno com matricula %d nao encontrado.\n", matricula_busca);
    }
}

void menu()
{
    printf("\n===== MENU =====\n");
    printf("1 - Inserir aluno\n");
    printf("2 - Carregar tabela teste com 2287 registros\n");
    printf("3 - Buscar aluno\n");
    printf("4 - Remover aluno\n");
    printf("5 - Imprimir tabela hash\n");
    printf("6 - Imprimir relatorio\n");
    printf("7 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main()
{
    int tamanho, opcao, matricula;
    char nome[50];

    printf("Digite o tamanho da tabela hash: ");
    scanf("%d", &tamanho);

    TabelaHash *tabela = criar_tabela(tamanho);
    if (!tabela)
    {
        printf("Erro ao criar a tabela hash!\n");
        return 1;
    }

    while (1)
    {
        menu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            Aluno aluno;
            printf("Digite a matricula do aluno: ");
            scanf("%d", &aluno.matricula);
            printf("Digite o nome do aluno: ");
            scanf("%s", aluno.nome);
            aluno.nota1 = 0;
            aluno.nota2 = 0;
            aluno.nota3 = 0;
            
            inserir_tabela(tabela, aluno);
            printf("Aluno inserido com sucesso!\n");
            break;
        }
        case 2:
        {
            int ler = ler_arquivo(tabela, "dados.txt");
            if (ler == 0)
            {
                printf("Houve um erro ao tentar ler o arquivo.\n");
            }
            else
            {
                printf("Arquivo carregado com Sucesso\n");
            }
            break;
        }
        case 3:
            printf("Digite a matricula do aluno a ser buscado: ");
            scanf("%d", &matricula);
            Aluno *resultado = buscar_tabela(tabela, matricula);
            if (resultado)
                printf("Aluno encontrado: Matricula %d, Nome %s\n", resultado->matricula, resultado->nome);
            else
                printf("Aluno nao encontrado!\n");
            break;
        case 4:
            printf("Digite a matricula do aluno a ser removido: ");
            scanf("%d", &matricula);
            remover_tabela(tabela, matricula)==1?printf("Aluno removido!"):printf("Aluno nao encontrado!\n");
            break;
        case 5:
            imprimir_tabela(tabela);
            break;
        case 6:
            imprimir_relatorio(tabela);
            break;
        case 7:
            destruir_tabela(tabela);
            printf("Encerrando programa...\n");
            return 0;
        default:
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}