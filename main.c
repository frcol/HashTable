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


void buscaAluno(TabelaHash* tabela, int matricula_busca) {
    Aluno* encontrado = buscar_tabela(tabela, matricula_busca);

    if (encontrado) {
        printf("Aluno encontrado: %s\n", encontrado->nome);
    } else {
        printf("Aluno com matricula %d nao encontrado.\n", matricula_busca);
    }
}

int main() {
    int tamanho = 1001;
    TabelaHash* tabela = criar_tabela(tamanho);

    ler_arquivo(tabela, "dados.txt");

    printf("Tabela Hash Populada:\n");
    imprimir_tabela_Qtde(tabela);

    buscaAluno(tabela, 234234243);
    buscaAluno(tabela, 30856);
    
    destruir_tabela(tabela);
    return 0;
}
