#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define true 1
#define false 0

typedef int bool;

typedef struct aux {
    int valor;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT topo;
} PILHA;

// Função para inicializar a pilha
void inicializarPilha(PILHA *p) {
    p->topo = NULL;
}

// Função para verificar se a pilha está vazia
bool estaVazia(PILHA *p) {
    return (p->topo == NULL);
}

// Função para empilhar um valor
bool empilhar(PILHA *p, int valor) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    if (novo == NULL) return false;
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

// Função para desempilhar um valor
bool desempilhar(PILHA *p, int *valor) {
    if (estaVazia(p)) return false;
    PONT apagar = p->topo;
    *valor = apagar->valor;
    p->topo = p->topo->prox;
    free(apagar);
    return true;
}

// Função para calcular uma operação
int calcularOperacao(int operando1, int operando2, char operador) {
    switch (operador) {
        case '+': return operando1 + operando2;
        case '-': return operando1 - operando2;
        case '*': return operando1 * operando2;
        case '/': return operando1 / operando2;
        default: return 0;
    }
}

// Função que processa a expressão pós-fixada a partir de um arquivo
int processarExpressao(char* nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return -1;
    }

    PILHA pilha;
    inicializarPilha(&pilha);
    char c;
    while ((c = fgetc(arquivo)) != EOF) {
        if (isdigit(c)) {  // Se for um número, empilha
            int num = c - '0';
            empilhar(&pilha, num);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {  // Se for um operador, realiza a operação
            int operando1, operando2, resultado;
            desempilhar(&pilha, &operando2);  // Pop o segundo operando
            desempilhar(&pilha, &operando1);  // Pop o primeiro operando

            resultado = calcularOperacao(operando1, operando2, c);

            printf("%d %c %d = %d\n", operando1, c, operando2, resultado);
            empilhar(&pilha, resultado);  // Empilha o resultado
        }
    }

    int resultadoFinal;
    desempilhar(&pilha, &resultadoFinal);
    fclose(arquivo);
    return resultadoFinal;
}

int main() {
    char nomeArquivo[100];

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    int resultado = processarExpressao(nomeArquivo);
    printf("Resultado: %d\n", resultado);

    return 0;
}
