
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
int inserir_lista(ListaSequencial* lista, Aluno aluno);
int remover_lista(ListaSequencial* lista, int matricula);
Aluno* buscar_lista(ListaSequencial* lista, int matricula);
int imprimir_lista(ListaSequencial* lista);
int tamanho_lista(ListaSequencial* lista);
