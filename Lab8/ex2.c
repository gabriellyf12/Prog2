#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    // outros campos...
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
} LISTA;

// Initialize the list
void inicializarLista(LISTA *l)
{
    l->inicio = NULL;
}

// Get the size of the list
int tamanho(LISTA *l)
{
    PONT end = l->inicio;
    int tam = 0;
    while (end != NULL)
    {
        tam++;
        end = end->prox;
    }
    return tam;
}

// Display the list
void exibirLista(LISTA *l)
{
    PONT end = l->inicio;
    printf("Lista: \" ");
    while (end != NULL)
    {
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

// Insert an element into the list
bool insere(LISTA *l, REGISTRO reg, int pos)
{
    if (pos < 0 || pos > tamanho(l))
        return false;
    ELEMENTO *novo = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    int i;
    ELEMENTO *p;
    if (pos == 0)
    {
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    else
    {
        p = l->inicio;
        for (i = 0; i < pos - 1; i++)
            p = p->prox;
        novo->prox = p->prox;
        p->prox = novo;
    }
    return true;
}

// Concatenate two lists: l2 is appended to the end of l1
void concatenaListas(LISTA *l1, LISTA *l2)
{
    if (l1->inicio == NULL)
    {
        l1->inicio = l2->inicio;
    }
    else
    {
        PONT p = l1->inicio;
        while (p->prox != NULL)
        {
            p = p->prox;
        }
        p->prox = l2->inicio;
    }
}

// Check if two lists are equal (same size, same elements)
bool iguaisListas(LISTA *l1, LISTA *l2)
{
    PONT p1 = l1->inicio;
    PONT p2 = l2->inicio;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->reg.chave != p2->reg.chave)
        {
            return false;
        }
        p1 = p1->prox;
        p2 = p2->prox;
    }

    // Both lists should be exhausted at the same time
    return p1 == NULL && p2 == NULL;
}

// Modify an element at a specific position in the list
bool modificaElem(LISTA *l, REGISTRO reg, int pos)
{
    if (pos < 0 || pos >= tamanho(l))
        return false;

    PONT p = l->inicio;
    for (int i = 0; i < pos; i++)
    {
        p = p->prox;
    }
    p->reg = reg;
    return true;
}

// Main function to test the implementations
int main()
{
    LISTA l1, l2;
    REGISTRO r;

    inicializarLista(&l1);
    inicializarLista(&l2);

    // Insert elements into l1
    r.chave = 1;
    insere(&l1, r, 0);
    r.chave = 2;
    insere(&l1, r, 1);
    r.chave = 3;
    insere(&l1, r, 2);
    printf("Lista 1: ");
    exibirLista(&l1);

    // Insert elements into l2
    r.chave = 4;
    insere(&l2, r, 0);
    r.chave = 5;
    insere(&l2, r, 1);
    printf("Lista 2: ");
    exibirLista(&l2);

    // Concatenate l1 and l2
    concatenaListas(&l1, &l2);
    printf("Lista após concatenação: ");
    exibirLista(&l1);

    // Modify an element in the list
    r.chave = 99;
    modificaElem(&l1, r, 2);
    printf("Lista 1 após modificação: ");
    exibirLista(&l1);

    // Check if lists are equal
    printf("Listas iguais? %s\n", iguaisListas(&l1, &l2) ? "Sim" : "Não");

    return 0;
}
