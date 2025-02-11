
#define TAM_INICIAL 10

typedef struct {
    int matricula;
    char nome[50];
    int nota1, nota2, nota3;
} Aluno;

typedef struct {
    Aluno *dados;
    int tamanho;
    int capacidade;
} ListaSequencial;

ListaSequencial* criar_lista();
void destruir_lista(ListaSequencial* lista);
void inserir_lista(ListaSequencial* lista, Aluno aluno);
void remover_lista(ListaSequencial* lista, int matricula);
Aluno* buscar_lista(ListaSequencial* lista, int matricula);
void imprimir_lista(ListaSequencial* lista);

