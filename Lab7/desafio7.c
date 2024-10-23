#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef int bool; //tornar o codigo mais legivel para o uso de booleanos

typedef int TIPOCHAVE; //permite alterar o tipo de chave facilmente se necessario

typedef struct {
    int numero;
    char naipe;
} tCarta;

typedef struct aux {
    tCarta reg;
    struct aux* prox;
} ELEMENTO; //representa um no na pilha cada no tem um 'REGISTRO' e um ponteiro para o prox elemento

typedef ELEMENTO* PONT; //ponteiro para 'ELEMENTO' para facilitar manipular nos

typedef struct {
    PONT topo;
} PILHA; //contem um ponteiro para o topo da pilha

void inicializarPilha (PILHA* p) {
    p->topo = NULL;
} //inicializa a pilha indicando que está vazia

int tamanho (PILHA* p) {
    PONT end = p->topo;
    int tam = 0;
    while (end != NULL) {
        tam++;
        end = end->prox;
    }
    return tam;
} //calcula e retorna o numero de elementos na pilha percorrendo todos os nos a partir do topo

bool estaVazia (PILHA* p) {
    if (p->topo == NULL)
        return true;
return false;
}

void exibeCarta(tCarta carta) {
    if(carta.numero >=2 && carta.numero <= 10)
        printf("%d", carta.numero);
    else {
        switch(carta.numero) {
            case 11:
                printf("Valete");
                break;

            case 12:
                printf("Dama");
                break;
            case 13:
                printf("Rei");
                break;
            case 1:
                printf("As");
                break;
            default: // 14
                printf("Invalida");
}
    }
    printf(" de ");
    switch(carta.naipe){
        case 'o':
            printf("Ouros\n");
            break;
        case 'c':
            printf("Copas\n");
            break;
        case 'p':
            printf("Paus\n");
            break;
        case 'e':
            printf("Espadas\n");
    }
}

bool inserirElemPilha (PILHA* p, tCarta reg) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
} //insere um novo elemento no topo, aloca memoria para um novo no, atribui o registro a esse no e ajusta o ponteiro prox para apontar para o antigo topo

void empilhaBaralho (PILHA *p) {
    tCarta carta;
    char naipes[] = {'o', 'c', 'p', 'e'};

    for(int i = 0; i < 4; i++) {
        for(int numero = 1; numero <= 13; numero++) {
            carta.numero = numero;
            carta.naipe = naipes[i];
            inserirElemPilha(p, carta);
        }
    }
}

bool excluirElemPilha (PILHA* p, tCarta* reg) {
    if ( p->topo == NULL)
        return false;

    *reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;

    free(apagar);

    return true;
} //Remove o elemento do topo da pilha. Se a pilha estiver vazia, retorna false. Caso contrario, atualiza o ponteiro do topo e libera a memoria do no removido

int buscaCarta(PILHA *p, tCarta cartaBuscada) {
    tCarta cartaTopo;
    int descartadas = 0;

    while(!estaVazia(p)) {
        excluirElemPilha(p, &cartaTopo);
        if(cartaTopo.numero == cartaBuscada.numero && cartaTopo.naipe == cartaBuscada.naipe) {
            return descartadas;
        }
        descartadas++;
    }

    return -1;
}
void reinicializarPilha (PILHA* p) {
    PONT apagar;
    PONT posicao = p->topo;

    while (posicao != NULL) {
        apagar = posicao;
        posicao = posicao->prox;
        free(apagar);
    }

    p->topo = NULL;
} //remove todos os elementos da pilha liberando a memoria de cada no e define o topo como NULL

int main ( ) {
    tCarta carta;
    PILHA p;

    inicializarPilha(&p);
    empilhaBaralho(&p);

    printf("Informe o numero e naipe da carta: ");
    scanf("%d %c", &carta.numero, &carta.naipe);

    int descartadas = buscaCarta(&p, carta);

    if (descartadas != -1) {
        exibeCarta(carta);
        printf("%d\n", descartadas);
    } else {
        printf("Carta nao encontrada!\n");
    }

    return 0;
}
