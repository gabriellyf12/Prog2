#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // Para usar funções de manipulação de caracteres

int main() {
    int *i, j;
    float *notas;
    char *nome;
    
    // a) Duas formas distintas de atribuir o valor 10 para *i
    // Forma 1: Atribuindo valor após alocar memória para o ponteiro
    i = (int *)malloc(sizeof(int));  // Alocando memória
    if (i == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    *i = 10;  // Atribuindo valor ao endereço alocado
    printf("Forma 1 - Valor de *i: %d\n", *i);

    // Forma 2: Atribuindo o endereço de uma variável
    j = 10;
    i = &j;  // Ponteiro aponta para a variável 'j'
    printf("Forma 2 - Valor de *i: %d\n", *i);

    // b) Alocação de 5 notas (float)
    notas = (float *)malloc(5 * sizeof(float));  // Alocando memória para 5 floats
    if (notas == NULL) {
        printf("Erro ao alocar memoria para notas.\n");
        return 1;
    }

    // Leitura das 5 notas
    for (int k = 0; k < 5; k++) {
        printf("Digite a nota %d: ", k + 1);
        scanf("%f", &notas[k]);
    }

    // Imprimindo as notas
    printf("Notas digitadas:\n");
    for (int k = 0; k < 5; k++) {
        printf("Nota %d: %.1f\n", k + 1, notas[k]);
    }

    return 0;
}
