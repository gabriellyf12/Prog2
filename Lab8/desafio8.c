#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    char nome[50];
    int tempo;
    int produtos;
} REGISTRO;

typedef struct aux
{
    REGISTRO reg;
    struct aux *prox;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct
{
    PONT inicio;
    PONT fim;
} FILA;

void inicializarFila(FILA *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

bool inserirNaFila(FILA *f, REGISTRO reg)
{
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = NULL;
    if (f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;
    f->fim = novo;
    return true;
}

bool excluirDaFila(FILA *f, REGISTRO *reg)
{
    if (f->inicio == NULL)
        return false;
    *reg = f->inicio->reg;
    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
    if (f->inicio == NULL)
        f->fim = NULL;
    return true;
}
void reinicializarFila(FILA *f)
{
    PONT end = f->inicio;
    while (end != NULL)
    {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    f->inicio = NULL;
    f->fim = NULL;
}

int main()
{
    FILA f;
    REGISTRO *cadastro;
    int k, c;
    int espera;
    int saida[c];
    cadastro = malloc(sizeof(REGISTRO) * c);

    scanf("%d", &k);
    scanf("%d", &c);

    inicializarFila(&f);

    for (int i = 0; i < c; i++)
    {
        scanf("%s %d %d", cadastro[i].nome, &cadastro[i].tempo, &cadastro[i].produtos);
        inserirNaFila(&f, *cadastro);
    }

    for (int i = 0; i < c; i++)
    {
        excluirDaFila(&f, cadastro);
        saida[i] = cadastro[i].tempo + (cadastro[i].produtos * k) + 10;
        if ((saida[i] - cadastro[i + 1].tempo) > 0 && i < c)
        {
            espera += saida[i] - cadastro[i + 1].tempo;
        }

        printf("\n%s %d %d \n", cadastro[i].nome, cadastro[i].tempo, saida[i]);
        espera = 0;
    }

    return 0;
}