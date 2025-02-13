
#define TAM_INICIAL 10

typedef struct {
    int matricula;
    char nome[50];
    int nota1, nota2, nota3;
} Aluno;

typedef struct {
    Aluno *dados;
    int qtde;
    int tamanho;
} ListaSequencial;

ListaSequencial* criar_lista();
void destruir_lista(ListaSequencial* lista);

int inserir_lista(ListaSequencial* lista, Aluno aluno);
int remover_lista(ListaSequencial* lista, int matricula);
Aluno* buscar_lista(ListaSequencial* lista, int matricula);

void imprimir_lista(ListaSequencial* lista);
int qtde_lista_ocupado(ListaSequencial* lista);
int qtde_lista_ocioso(ListaSequencial* lista);
int tamanho(ListaSequencial* lista);
