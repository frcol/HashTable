/*
Avalie o desempenho da Tabela Hash na inserção desses dados quando diferentes configurações são usadas: 
- tamanho inicial da tabela (int tamanho = 101; main.c), 
- tamanho ser primo ou não (int tamanho = 101; main.c), 
- função de espalhamento (chaveDivisao, chaveDobra, chaveMultiplicacao)
- etc

Alguns parâmetros a serem avaliados:
- Número de listas criadas
- Tamanho médio das listas
- Número de colisões
- Desperdício de memória nas listas (posições ociosas)
- Etc
*/

#include "ListaSequencial.h"

typedef struct {
    int TABLE_SIZE;       // Tamanho da tabela (pode ser variável)
    int qtd;              // Número total de alunos armazenados
    ListaSequencial** itens; // Array de listas sequenciais
} TabelaHash;


TabelaHash* criar_tabela();
void destruir_tabela(TabelaHash* tabela);

int chaveDivisao(int chave, int TABLE_SIZE);
int chaveDobra(int chave, int TABLE_SIZE);
int chaveMultiplicacao(int chave, int TABLE_SIZE);

void inserir_tabela(TabelaHash* tabela, Aluno aluno);
int remover_tabela(TabelaHash* tabela, int matricula);
Aluno* buscar_tabela(TabelaHash* tabela, int matricula);

void imprimir_tabela(TabelaHash* tabela);
void imprimir_relatorio(TabelaHash* tabela);