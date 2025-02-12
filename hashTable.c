// TabelaHash.c
#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"

TabelaHash* criar_tabela(int tamanho) {
    TabelaHash* tabela = (TabelaHash*)malloc(sizeof(TabelaHash));
    if (!tabela) return NULL;

    tabela->TABLE_SIZE = tamanho;
    tabela->qtd = 0;
    
    // Aloca um array de ponteiros para listas sequenciais
    tabela->itens = (ListaSequencial**)malloc(tamanho * sizeof(ListaSequencial*));
    if (!tabela->itens) {
        free(tabela);
        return NULL;
    }

    // Inicializa cada posição com NULL
    for (int i = 0; i < tamanho; i++) {
        tabela->itens[i] = NULL;
    }

    return tabela;
}


void destruir_tabela(TabelaHash* tabela) {
    for (int i = 0; i < tabela->TABLE_SIZE; i++) {
        if (tabela->itens[i] != NULL) {
            destruir_lista(tabela->itens[i]);
        }
    }
    free(tabela->itens);
    free(tabela);
}

int funcao_hash(TabelaHash* tabela, int matricula) {
    return matricula % tabela->TABLE_SIZE;
}

void inserir_tabela(TabelaHash* tabela, Aluno aluno) {
    int pos = funcao_hash(tabela, aluno.matricula);

    if(tabela->itens[pos] == NULL) { // Se ainda não foi alocado a Lista para essa posição da tabela
        tabela->itens[pos] = criar_lista();
    }

    inserir_lista(tabela->itens[pos], aluno);
}

void remover_tabela(TabelaHash* tabela, int matricula) {
    int pos = funcao_hash(tabela, matricula);

    if (tabela->itens[pos] != NULL) {
        remover_lista(tabela->itens[pos], matricula);

        // Se a lista estiver vazia após remoção, podemos liberá-la para economizar memória
        if (tabela->itens[pos]->tamanho == 0) {
            destruir_lista(tabela->itens[pos]);
            tabela->itens[pos] = NULL; // Libera a referência na tabela hash
        }

        tabela->qtd--;
    }
}

Aluno* buscar_tabela(TabelaHash* tabela, int matricula) {
    int pos = funcao_hash(tabela, matricula);

    // Se não houver lista na posição, o aluno não existe
    if (tabela->itens[pos] == NULL) {
        return NULL;
    }

    return buscar_lista(tabela->itens[pos], matricula);
}

void imprimir_tabela(TabelaHash* tabela) {
    for (int i = 0; i < tabela->TABLE_SIZE; i++) {
        if (tabela->itens[i]->tamanho > 0) {
            printf("Posicao %d:\n", i);
            imprimir_lista(tabela->itens[i]);
        }
    }
}

void imprimir_tabela_Qtde(TabelaHash* tabela) {
    for (int i = 0; i < tabela->TABLE_SIZE; i++) {
        if (tabela->itens[i]->tamanho > 0) {
            printf("Posicao %d: ", i);
            tamanho_lista(tabela->itens[i]);
        }
    }
}
