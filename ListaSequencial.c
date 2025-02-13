#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencial.h"

ListaSequencial *criar_lista()
{
    ListaSequencial *lista = (ListaSequencial *)malloc(sizeof(ListaSequencial));
    if (lista == NULL)
        return 0;

    lista->capacidade = TAM_INICIAL;
    lista->tamanho = 0;
    lista->dados = (Aluno *)malloc(lista->capacidade * sizeof(Aluno));
    if (lista->dados == NULL)
        return 0;

    return lista;
}

void destruir_lista(ListaSequencial *lista)
{
    if (lista != NULL)
    {
        free(lista->dados);
        free(lista);
    }
}

int inserir_lista(ListaSequencial *lista, Aluno aluno)
{
    if (lista == NULL)
        return 0;

    if (lista->tamanho == lista->capacidade)
    {
        lista->capacidade += lista->capacidade / 2; // Aumenta 50%
        Aluno *novo_dados = (Aluno *)realloc(lista->dados, lista->capacidade * sizeof(Aluno));
        if (novo_dados == NULL)
        {
            return 0; // Falha na realocação
        }
        lista->dados = novo_dados;
    }

    lista->dados[lista->tamanho++] = aluno;
    return 1;
}

int remover_lista(ListaSequencial *lista, int mat)
{
    if (lista == NULL || lista->tamanho == 0)
        return 0;

    int i = 0;
    while (i < lista->tamanho && lista->dados[i].matricula != mat)
        i++;

    if (i == lista->tamanho) // elemento nao encontrado
        return 0;

    lista->tamanho--;
    lista->dados[i] = lista->dados[lista->tamanho];

    return 1;
}

Aluno *buscar_lista(ListaSequencial *lista, int matricula)
{
    if (lista == NULL)
        return NULL;

    for (int i = 0; i < lista->tamanho; i++)
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
            for (int i = 0; i < lista->tamanho; i++)
            {
                printf("   Matricula: %d, Nome: %s, Notas: %d %d %d\n",
                       lista->dados[i].matricula, lista->dados[i].nome,
                       lista->dados[i].nota1, lista->dados[i].nota2, lista->dados[i].nota3);
            }
        }
}

int tamanho_lista_ocupado(ListaSequencial *lista)
{
    if (lista == NULL)
        return 0;

    return lista->tamanho;
}

int tamanho_lista_ocioso(ListaSequencial *lista)
{
    if (lista == NULL)
        return 0;

    return lista->capacidade - lista->tamanho;
}

int capacidade(ListaSequencial *lista)
{
    if (lista == NULL)
        return 0;

    return lista->capacidade;
}