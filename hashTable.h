/*
    Pensando em uma tabela grande e precisando economizar memória
    Por isso, só estamos alocando a ListaSequencial no momento da inserção
*/

#include "ListaSequencial.h"

typedef struct {
    int TABLE_SIZE;       // Tamanho da tabela (pode ser variável)
    int qtd;              // Número total de alunos armazenados
    ListaSequencial** itens; // Array de listas sequenciais
} TabelaHash;


TabelaHash* criar_tabela();
void destruir_tabela(TabelaHash* tabela);

int funcao_hash(TabelaHash* tabela, int matricula);

void inserir_tabela(TabelaHash* tabela, Aluno aluno);
void remover_tabela(TabelaHash* tabela, int matricula);
Aluno* buscar_tabela(TabelaHash* tabela, int matricula);

void imprimir_tabela(TabelaHash* tabela);
void imprimir_tabela_Qtde(TabelaHash* tabela);