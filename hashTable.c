#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"

int numListas = 0; // numero total de listas criadas
int numColisoes = 0; // numero total de colisoes

TabelaHash *criar_tabela(int tamanho)
{
    TabelaHash *tabela = (TabelaHash *)malloc(sizeof(TabelaHash));
    if (!tabela)
        return NULL;

    tabela->TABLE_SIZE = tamanho;
    tabela->qtd = 0;

    // Aloca um array de ponteiros para listas sequenciais
    tabela->itens = (ListaSequencial **)malloc(tamanho * sizeof(ListaSequencial *));
    if (!tabela->itens)
    {
        free(tabela);
        return NULL;
    }

    // Inicializa cada posição com NULL
    for (int i = 0; i < tamanho; i++)
    {
        tabela->itens[i] = NULL;
    }

    return tabela;
}

void destruir_tabela(TabelaHash *tabela)
{
    for (int i = 0; i < tabela->TABLE_SIZE; i++)
    {
        if (tabela->itens[i] != NULL)
        {
            destruir_lista(tabela->itens[i]);
        }
    }
    free(tabela->itens);
    free(tabela);
}

// =====================================================
int valorString(char *str)
{
    int i, valor = 7;
    int tam = strlen(str);
    for (i = 0; i < tam; i++)
        valor = 31 * valor + (int)str[i];
    return (valor & 0x7FFFFFFF);
}

// Hash Divisao
// int chave = valorString(nome);
// pos = chaveDivisao(chave, TABLE_SIZE)
int chaveDivisao(int chave, int TABLE_SIZE)
{
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

//==============================================
// Hash Dobra
// int chave = valorString(nome);
// pos = chaveDobra(chave, TABLE_SIZE)
int chaveDobra(int chave, int TABLE_SIZE)
{
    int num_bits = 10;
    int parte1 = chave >> num_bits;
    int parte2 = chave & (TABLE_SIZE - 1);
    return (parte1 ^ parte2);
}

//==============================================
// Hash Multiplicação
// int chave = valorString(nome);
// pos = chaveDobra(chave, TABLE_SIZE)
int chaveMultiplicacao(int chave, int TABLE_SIZE)
{
    double A = 0.6180339887; // constante: 0 < A < 1
    double val = chave * A;
    val = val - (int)val;
    return (int)(TABLE_SIZE * val);
}

// =====================================================
void inserir_tabela(TabelaHash *tabela, Aluno aluno)
{
    int pos = chaveDivisao(aluno.matricula, tabela->TABLE_SIZE); // <-- alterar a chave para fazer testes de performance

    if (tabela->itens[pos] == NULL)
    {
        tabela->itens[pos] = criar_lista();
        numListas++;
    }
    else { // houve colisão
        numColisoes++;
    }

    inserir_lista(tabela->itens[pos], aluno);
}

void remover_tabela(TabelaHash *tabela, int matricula)
{
    int pos = chaveDivisao(matricula, tabela->TABLE_SIZE); // <-- alterar a chave para fazer testes de performance

    if (tabela->itens[pos] != NULL)
    {
        remover_lista(tabela->itens[pos], matricula);

        // Se a lista estiver vazia após remoção, podemos liberá-la para economizar memória
        if (tabela->itens[pos]->tamanho == 0)
        {
            destruir_lista(tabela->itens[pos]);
            tabela->itens[pos] = NULL;
        }

        tabela->qtd--;
    }
}

Aluno *buscar_tabela(TabelaHash *tabela, int matricula)
{
    int pos = chaveDivisao(matricula, tabela->TABLE_SIZE); // <-- alterar a chave para fazer testes de performance

    // Se não houver lista na posição, o aluno não existe
    if (tabela->itens[pos] == NULL)
    {
        return NULL;
    }

    return buscar_lista(tabela->itens[pos], matricula);
}

// =====================================================
void imprimir_tabela(TabelaHash *tabela)
{
    for (int i = 0; i < tabela->TABLE_SIZE; i++)
    {
        if (tabela->itens[i] != NULL)
        {
            printf("Posicao %d: (%d)\n", i, tamanho_lista(tabela->itens[i]));
            imprimir_lista(tabela->itens[i]);
        }
        else {
            printf("Posicao %d: (NULL)\n", i);
        }
    }
}

void imprimir_tabela_Qtde(TabelaHash *tabela)
{
    int tamanhoTotalLista = 0; // soma total dos itens nas listas

    printf("=======================================\n");
    printf("Numero de listas criadas: %d/%d\n", numListas, tabela->TABLE_SIZE);

    for (int i = 0; i < tabela->TABLE_SIZE; i++)
    {
        if (tabela->itens[i] != NULL)
        {
            tamanhoTotalLista += tamanho_lista(tabela->itens[i]);
        }
    }

    printf("Tamanho medio das listas: %d\n", tamanhoTotalLista / numListas);
    printf("Numero de colisoes: %d\n", numColisoes);
    printf("=======================================\n");
}
