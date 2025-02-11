// TabelaHash.c
#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"

TabelaHash* criar_tabela() {
    TabelaHash* tabela = (TabelaHash*)malloc(sizeof(TabelaHash));
    for (int i = 0; i < TABLE_SIZE; i++) {
        tabela->tabela[i] = criar_lista();
    }
    return tabela;
}

void destruir_tabela(TabelaHash* tabela) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        destruir_lista(tabela->tabela[i]);
    }
    free(tabela);
}

int funcao_hash(int matricula) {
    return matricula % TABLE_SIZE;
}

void inserir_tabela(TabelaHash* tabela, Aluno aluno) {
    int pos = funcao_hash(aluno.matricula);
    inserir_lista(tabela->tabela[pos], aluno);
}

void remover_tabela(TabelaHash* tabela, int matricula) {
    int pos = funcao_hash(matricula);
    remover_lista(tabela->tabela[pos], matricula);
}

Aluno* buscar_tabela(TabelaHash* tabela, int matricula) {
    int pos = funcao_hash(matricula);
    return buscar_lista(tabela->tabela[pos], matricula);
}

void imprimir_tabela(TabelaHash* tabela) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (tabela->tabela[i]->tamanho > 0) {
            printf("Posicao %d:\n", i);
            imprimir_lista(tabela->tabela[i]);
        }
    }
}
