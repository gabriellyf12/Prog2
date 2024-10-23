#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    // outros campos
} REGISTRO;

typedef struct aux
{
    REGISTRO reg;
    struct aux *prox;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct
{
    PONT topo;
} PILHA;

void inicializarPilha(PILHA *p)
{
    p->topo = NULL;
}

int tamanho(PILHA *p)
{
    PONT end = p->topo;
    int tam = 0;
    while (end != NULL)
    {
        tam++;
        end = end->prox;
    }
    return tam;
}

bool estaVazia(PILHA *p)
{
    if (p->topo == NULL)
        return true;
    return false;
}

void exibirPilha(PILHA *p)
{
    PONT end = p->topo;
    printf("Pilha: \"");
    while (end != NULL)
    {
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

bool inserirElemPilha(PILHA *p, REGISTRO reg)
{
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;

    return true;
}

bool excluirElemPilha(PILHA *p, REGISTRO *reg)
{
    if (p->topo == NULL)
        return false;
    *reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);

    return true;
}

reinicializarPilha(PILHA *p)
{
    PONT apagar;
    PONT posicao = p->topo;
    while (posicao != NULL)
    {
        apagar = posicao;
        posicao = posicao->prox;
        free(apagar);
    }
    p->topo = NULL;
}