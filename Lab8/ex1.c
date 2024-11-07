#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    // Outros campos...
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

// Funções da Fila
void inicializarFila(FILA *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

bool estaVazia(FILA *f)
{
    return (f->inicio == NULL);
}

bool inserirNaFila(FILA *f, REGISTRO reg)
{
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = NULL;
    if (f->inicio == NULL)
    {
        f->inicio = novo;
    }
    else
    {
        f->fim->prox = novo;
    }
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
    PONT apagar, end = f->inicio;
    while (end != NULL)
    {
        apagar = end;
        end = end->prox;
        free(apagar);
    }
    f->inicio = NULL;
    f->fim = NULL;
}

int main()
{
    FILA filaPar, filaImpar;
    REGISTRO reg;
    int numero;

    // Inicializa as filas
    inicializarFila(&filaPar);
    inicializarFila(&filaImpar);

    // Leitura dos números
    printf("Digite valores inteiros (0 para encerrar):\n");
    while (1)
    {
        scanf("%d", &numero);
        if (numero == 0)
            break; // Finaliza a leitura quando o número for zero

        // Verifica se é par ou ímpar e insere na fila correspondente
        reg.chave = numero;
        if (numero % 2 == 0)
        {
            inserirNaFila(&filaPar, reg);
        }
        else
        {
            inserirNaFila(&filaImpar, reg);
        }
    }

    // Remove e exibe os elementos alternadamente das filas (começando pela ímpar)
    printf("Elementos retirados das filas:\n");
    while (!estaVazia(&filaPar) || !estaVazia(&filaImpar))
    {
        // Remove da fila ímpar, se houver
        if (!estaVazia(&filaImpar))
        {
            excluirDaFila(&filaImpar, &reg);
            printf("%d (Impar)\n", reg.chave);
        }

        // Remove da fila par, se houver
        if (!estaVazia(&filaPar))
        {
            excluirDaFila(&filaPar, &reg);
            printf("%d (Par)\n", reg.chave);
        }
    }

    return 0;
}
