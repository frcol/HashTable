#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencial.h"

ListaSequencial *criar_lista()
{
    ListaSequencial *lista = (ListaSequencial *)malloc(sizeof(ListaSequencial));
    if (lista == NULL)
        return 0;

    lista->tamanho = TAM_INICIAL;
    lista->qtde = 0;
    lista->dados = (Aluno *)malloc(lista->tamanho * sizeof(Aluno));
    if (lista->dados == NULL)
        return 0;

    return lista;
}

void destruir_lista(ListaSequencial **lista)
{
    if (*lista != NULL)
    {
        free((*lista)->dados);
        free(*lista);
        *lista = NULL; // Atualiza o ponteiro original para NULL
    }
}

int inserir_lista(ListaSequencial *lista, Aluno aluno)
{
    if (lista == NULL)
        return 0;

    if (lista->qtde == lista->tamanho)
    {
        lista->tamanho += lista->tamanho / 2; // Aumenta 50%
        Aluno *novo_dados = (Aluno *)realloc(lista->dados, lista->tamanho * sizeof(Aluno));
        if (novo_dados == NULL)
        {
            printf("Erro: Falha ao alocar memória para mais alunos.\n");
            return 0;
        }
        lista->dados = novo_dados;
    }

    lista->dados[lista->qtde++] = aluno;
    return 1;
}

int remover_lista(ListaSequencial *lista, int mat)
{
    if (lista == NULL || lista->qtde == 0)
        return 0;

    int i = 0;
    while (i < lista->qtde && lista->dados[i].matricula != mat)
        i++;

    if (i == lista->qtde) // elemento nao encontrado
        return 0;

    lista->qtde--;
    lista->dados[i] = lista->dados[lista->qtde];

    return 1;
}

Aluno *buscar_lista(ListaSequencial *lista, int matricula)
{
    if (lista == NULL)
        return NULL;

    for (int i = 0; i < lista->qtde; i++)
    {
        if (lista->dados[i].matricula == matricula)
        {
            return &lista->dados[i];
        }
    }

    return NULL;
}

void imprimir_lista(ListaSequencial *lista)
{
    if (lista != NULL)
    {
        for (int i = 0; i < lista->qtde; i++)
        {
            printf("   Matricula: %d, Nome: %s, Notas: %d %d %d\n",
                   lista->dados[i].matricula, lista->dados[i].nome,
                   lista->dados[i].nota1, lista->dados[i].nota2, lista->dados[i].nota3);
        }
    }
}

int qtde_lista_ocupado(ListaSequencial *lista)
{
    if (lista == NULL)
        return 0;

    return lista->qtde;
}

int qtde_lista_ocioso(ListaSequencial *lista)
{
    if (lista == NULL)
        return 0;

    return lista->tamanho - lista->qtde;
}

int tamanho(ListaSequencial *lista)
{
    if (lista == NULL)
        return 0;

    return lista->tamanho;
}