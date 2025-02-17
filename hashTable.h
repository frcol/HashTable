
#include "ListaSequencial.h"

typedef struct {
    int TABLE_SIZE;             // Tamanho da tabela (pode ser variável)
    int qtd;                    // Número total de alunos armazenados
    ListaSequencial** itens;    // Array de listas sequenciais
} TabelaHash;


TabelaHash* criar_tabela();
void destruir_tabela(TabelaHash* tabela);

// Funções Hash
int chaveDivisao(int chave, int TABLE_SIZE);
int chaveDobra(int chave, int TABLE_SIZE);
int chaveMultiplicacao(int chave, int TABLE_SIZE);

// CRUD
void inserir_tabela(TabelaHash* tabela, Aluno aluno);
int remover_tabela(TabelaHash* tabela, int matricula);
Aluno* buscar_tabela(TabelaHash* tabela, int matricula);

// Relatório
void imprimir_tabela(TabelaHash* tabela);
void imprimir_relatorio(TabelaHash* tabela);