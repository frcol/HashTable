// main.c
#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"

#define NOME_ARQUIVO "dados2297.txt"

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

void menu()
{
    printf("\n\n===== MENU =====\n");
    printf("1 - Inserir aluno\n");
    printf("2 - Carregar registros do arquivo\n");
    printf("3 - Buscar aluno\n");
    printf("4 - Remover aluno\n");
    printf("5 - Imprimir tabela hash\n");
    printf("6 - Imprimir relatorio\n");
    printf("7 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main()
{
    system("cls");
    int tamanho, opcao, matricula;
    char nome[50];

    printf("Digite o tamanho da tabela hash (dobra): ");
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
            printf("\nDigite a matricula do aluno: ");
            scanf("%d", &aluno.matricula);
            printf("Digite o nome do aluno: ");
            scanf("%s", aluno.nome);
            aluno.nota1 = 0;
            aluno.nota2 = 0;
            aluno.nota3 = 0;
            
            inserir_tabela(tabela, aluno);
            printf("\nAluno inserido com sucesso!\n");
            break;
        }
        case 2:
        {
            int ler = ler_arquivo(tabela, NOME_ARQUIVO);
            if (ler == 0)
            {
                printf("Houve um erro ao tentar ler o arquivo.\n");
            }
            else
            {
                printf("\n\nArquivo carregado com Sucesso\n");
            }
            break;
        }
        case 3:
            printf("Digite a matricula do aluno a ser buscado: ");
            scanf("%d", &matricula);
            Aluno *resultado = buscar_tabela(tabela, matricula);
            if (resultado)
                printf("\n\nAluno encontrado: Matricula %d, Nome %s\n", resultado->matricula, resultado->nome);
            else
                printf("\n\nAluno nao encontrado!\n");
            break;
        case 4:
            printf("\nDigite a matricula do aluno a ser removido: ");
            scanf("%d", &matricula);
            remover_tabela(tabela, matricula)==1?printf("\nAluno removido!"):printf("\nAluno nao encontrado!\n");
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