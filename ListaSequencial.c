#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencial.h"

ListaSequencial* criar_lista() {
    ListaSequencial* lista = (ListaSequencial*)malloc(sizeof(ListaSequencial));
    lista->capacidade = TAM_INICIAL;
    lista->tamanho = 0;
    lista->dados = (Aluno*)malloc(lista->capacidade * sizeof(Aluno));
    return lista;
}

void destruir_lista(ListaSequencial* lista) {
    free(lista->dados);
    free(lista);
}

void inserir_lista(ListaSequencial* lista, Aluno aluno) {
    if (lista->tamanho == lista->capacidade) {
        lista->capacidade += lista->capacidade / 2; // Aumenta 50%
        lista->dados = (Aluno*)realloc(lista->dados, lista->capacidade * sizeof(Aluno));
    }
    lista->dados[lista->tamanho++] = aluno;
}

void remover_lista(ListaSequencial* lista, int matricula) {
    int i;
    for (i = 0; i < lista->tamanho; i++) {
        if (lista->dados[i].matricula == matricula) {
            lista->dados[i] = lista->dados[lista->tamanho - 1];
            lista->tamanho--;
            return;
        }
    }
}

Aluno* buscar_lista(ListaSequencial* lista, int matricula) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->dados[i].matricula == matricula) {
            return &lista->dados[i];
        }
    }
    return NULL;
}

void imprimir_lista(ListaSequencial* lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("Matricula: %d, Nome: %s, Notas: %d %d %d\n",
               lista->dados[i].matricula, lista->dados[i].nome,
               lista->dados[i].nota1, lista->dados[i].nota2, lista->dados[i].nota3);
    }
}
