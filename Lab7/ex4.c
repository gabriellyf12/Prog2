#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da pilha
#define true 1
#define false 0

typedef int bool;
typedef char TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    // Outros campos, caso necessário
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

// Funções da pilha
void inicializarPilha(PILHA *p)
{
    p->topo = NULL;
}

bool estaVazia(PILHA *p)
{
    return (p->topo == NULL);
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
    if (estaVazia(p))
        return false;
    *reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
    return true;
}

// Função para verificar se os caracteres de abertura e fechamento correspondem
bool eh_correspondente(char abertura, char fechamento)
{
    return (abertura == '(' && fechamento == ')') || (abertura == '[' && fechamento == ']') || (abertura == '{' && fechamento == '}');
}

// Função para verificar se a expressão está balanceada
bool verificar_balanceamento(char *expressao)
{
    PILHA pilha;
    inicializarPilha(&pilha);
    REGISTRO reg;

    for (int i = 0; i < strlen(expressao); i++)
    {
        char atual = expressao[i];

        if (atual == '(' || atual == '[' || atual == '{')
        {
            // Empilha os caracteres de abertura
            reg.chave = atual;
            inserirElemPilha(&pilha, reg);
        }
        else if (atual == ')' || atual == ']' || atual == '}')
        {
            // Verifica se há correspondência com o topo da pilha
            if (estaVazia(&pilha))
                return false; // Se a pilha está vazia, não está balanceada
            excluirElemPilha(&pilha, &reg);
            if (!eh_correspondente(reg.chave, atual))
                return false;
        }
    }

    // Se a pilha estiver vazia, está balanceada
    return estaVazia(&pilha);
}

int main()
{
    char expressao[100];

    printf("Digite a expressão matemática: ");
    fgets(expressao, 100, stdin);

    if (verificar_balanceamento(expressao))
    {
        printf("A expressão está balanceada.\n");
    }
    else
    {
        printf("A expressão NÃO está balanceada.\n");
    }

    return 0;
}
