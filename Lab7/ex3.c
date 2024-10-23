#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define true 1
#define false 0

typedef int bool;

typedef struct aux {
    char caractere;
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

// Função para empilhar um caractere
bool empilhar(PILHA *p, char caractere) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    if (novo == NULL) return false;
    novo->caractere = caractere;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

// Função para desempilhar um caractere
bool desempilhar(PILHA *p, char *caractere) {
    if (p->topo == NULL) return false;
    PONT apagar = p->topo;
    *caractere = apagar->caractere;
    p->topo = p->topo->prox;
    free(apagar);
    return true;
}

// Função para verificar se uma palavra é um palíndromo usando uma pilha
bool verificarPalindromo(char* palavra) {
    PILHA pilha;
    inicializarPilha(&pilha);
    int tamanho = strlen(palavra);
    
    // Empilha os caracteres da palavra
    for (int i = 0; i < tamanho; i++) {
        if (isalpha(palavra[i])) {
            empilhar(&pilha, tolower(palavra[i]));  // Ignora maiúsculas/minúsculas
        }
    }

    // Verifica se a palavra é um palíndromo
    for (int i = 0; i < tamanho; i++) {
        if (isalpha(palavra[i])) {
            char caractereTopo;
            desempilhar(&pilha, &caractereTopo);
            if (tolower(palavra[i]) != caractereTopo) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char palavra[100];

    printf("Digite uma palavra ou frase: ");
    fgets(palavra, 100, stdin);

    // Remover o '\n' do final da string
    palavra[strcspn(palavra, "\n")] = 0;

    if (verificarPalindromo(palavra)) {
        printf("'%s' é um palíndromo.\n", palavra);
    } else {
        printf("'%s' não é um palíndromo.\n", palavra);
    }

    return 0;
}
