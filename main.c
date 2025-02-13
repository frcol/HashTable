// main.c
#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"


void ler_arquivo(TabelaHash* tabela, const char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Aluno aluno;
    while (fscanf(arquivo, "%d %49s %d %d %d", &aluno.matricula, aluno.nome, &aluno.nota1, &aluno.nota2, &aluno.nota3) != EOF) {
        inserir_tabela(tabela, aluno);
    }
    
    fclose(arquivo);
}

void ler_vetor(ListaSequencial* lista) {
    Aluno al, a[4] = {{12352,"Andre",9.5,7.8,8.5},//64
                    {7894,"Ricardo",7.5,8.7,6.8},//726
                    {3451,"Bianca",9.7,6.7,8.4},//379
                    {5293,"Ana",5.7,6.1,7.4}};//173

    int i;
    for(i=0; i < 4; i++){
        inserir_lista(lista, a[i]);
    }
}

void buscaAluno(TabelaHash* tabela, int matricula_busca) {
    Aluno* encontrado = buscar_tabela(tabela, matricula_busca);

    if (encontrado) {
        printf("Aluno encontrado: %s\n", encontrado->nome);
    } else {
        printf("Aluno com matricula %d nao encontrado.\n", matricula_busca);
    }
}

// int main() {
//     int tamanho = 1001;
    
//     // ListaSequencial* lista = criar_lista();
//     // ler_vetor(lista);

//     // imprimir_lista(lista);

//     // destruir_lista(lista);


//     TabelaHash* tabela = criar_tabela(tamanho);

//     ler_arquivo(tabela, "dados.txt");

//     printf("Tabela Hash Populada:\n");
//     imprimir_relatorio(tabela);

//     buscaAluno(tabela, 234234243);
//     buscaAluno(tabela, 30856);
    
//     destruir_tabela(tabela);
//     return 0;
// }

void menu() {
    printf("\n===== MENU =====\n");
    printf("1 - Inserir aluno\n");
    printf("2 - Buscar aluno\n");
    printf("3 - Remover aluno\n");
    printf("4 - Imprimir tabela hash\n");
    printf("5 - Imprimir relatório\n");
    printf("6 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    int tamanho, opcao, matricula;
    char nome[50];

    printf("Digite o tamanho da tabela hash: ");
    scanf("%d", &tamanho);

    TabelaHash *tabela = criar_tabela(tamanho);
    if (!tabela) {
        printf("Erro ao criar a tabela hash!\n");
        return 1;
    }

    while (1) {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Aluno aluno;
                printf("Digite a matricula do aluno: ");
                scanf("%d", &aluno.matricula);
                printf("Digite o nome do aluno: ");
                scanf("%s", aluno.nome);

                inserir_tabela(tabela, aluno);
                printf("Aluno inserido com sucesso!\n");
                break;
            }
            case 2:
                printf("Digite a matricula do aluno a ser buscado: ");
                scanf("%d", &matricula);
                Aluno *resultado = buscar_tabela(tabela, matricula);
                if (resultado)
                    printf("Aluno encontrado: Matricula %d, Nome %s\n", resultado->matricula, resultado->nome);
                else
                    printf("Aluno nao encontrado!\n");
                break;
            case 3:
                printf("Digite a matricula do aluno a ser removido: ");
                scanf("%d", &matricula);
                remover_tabela(tabela, matricula);
                printf("Aluno removido!\n");
                break;
            case 4:
                imprimir_tabela(tabela);
                break;
            case 5:
                imprimir_relatorio(tabela);
                break;
            case 6:
                destruir_tabela(tabela);
                printf("Encerrando programa...\n");
                return 0;
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}