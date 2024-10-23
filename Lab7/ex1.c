#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    int resto;
    //outros campos
} REGISTRO;

typedef struct aux {
    int reg;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT topo;
} PILHA;

void inicializarPilha (PILHA *p){
    p -> topo = NULL;
}

bool estaVazia(PILHA *p){
    if (p->topo == NULL)
        return true;
    return false;
}

bool inserirElemPilha (PILHA *p, int reg){
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;

    return true;
}

bool excluirElemPilha (PILHA *p) {
    if(p->topo == NULL)
        return false;
    int reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);

    return true;
}

void decParaBinario(int n){
    PILHA p;
    inicializarPilha(&p);

    while (n > 0) {
        inserirElemPilha(&p, n % 2);
        n = n / 2;
    }
    
    printf("Número em binário: ");
    while (!estaVazia(&p)){
        printf("%d", p.topo->reg);
        excluirElemPilha(&p);
    }
    printf("\n");

}

void reinicializarPilha (PILHA *p){
    PONT apagar;
    PONT posicao = p->topo;
    while (posicao != NULL) {
        apagar = posicao;
        posicao = posicao->prox;
        free(apagar);
    }
    p->topo = NULL;
}

int main () {
    int n;

    printf("Digte um número decimal: ");
    scanf("%d", &n);

    decParaBinario(n);

    return 0;
}