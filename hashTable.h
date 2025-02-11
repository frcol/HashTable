
#include "ListaSequencial.h"

#define TABLE_SIZE 101

typedef struct {
    ListaSequencial* tabela[TABLE_SIZE];
} TabelaHash;

TabelaHash* criar_tabela();
void destruir_tabela(TabelaHash* tabela);
int funcao_hash(int matricula);

void inserir_tabela(TabelaHash* tabela, Aluno aluno);
void remover_tabela(TabelaHash* tabela, int matricula);

Aluno* buscar_tabela(TabelaHash* tabela, int matricula);

void imprimir_tabela(TabelaHash* tabela);
