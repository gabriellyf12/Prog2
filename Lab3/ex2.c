#include <stdio.h>
#include <stdlib.h>

int **aloca_linhas(int );
void aloca_colunas (int **, int, int);
void le_dados(int **, int, int );
void imprime_matriz(int **, int, int );
void troca_linhas (int **, int, int);

int main (void) {
    int **matriz;
    int lin, col;
    int linha1, linha2;

    puts("Qual o numero de linhas?");
    scanf("%d",&lin);

    matriz = aloca_linhas(lin);

    puts("Qual o numero de colunas?");
    scanf("%d",&col);

    printf("Alocando eApresentaçãospaço para linhas.\n");
    aloca_colunas(matriz, lin, col);
    le_dados(matriz, lin, col);
    imprime_matriz(matriz, lin, col);

    puts("Qual a primeira linha a ser trocada?");
    scanf("%d",&linha1);

    puts("Qual a segunda linha a ser trocada?");
    scanf("%d",&linha2);

    troca_linhas(matriz, linha1, linha2);
    imprime_matriz(matriz, lin, col);

    return 0;
}

int **aloca_linhas(int l){
    int **matriz = (int **)malloc(l *sizeof(int *));
    if (!matriz){
        printf("Erro na alocação de memória para as linhas. \n");
        return NULL;
    }
    return matriz;
}

void aloca_colunas(int **matriz, int l, int c){
    for (int i = 0; i < l; i++){
        *(matriz + i) = (int *)malloc(c * sizeof(int));
        if (!*(matriz +i)){
            printf("Erro na alocação de memória para as colunas. \n");
            for(int j = 0; j < i; j++){
                free(*(matriz + j));
            }
            free(matriz);
            exit(1);
        }
    }
}

void le_dados(int **matriz, int l, int c){
    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
            scanf("%d",*(matriz + i) + j);
        }
    }
}

void imprime_matriz(int **matriz, int l, int c){
    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
            printf("Elemento [%d][%d] = %d \n", i, j, *(*(matriz + i) + j));
        }
    }
}

void troca_linhas(int **matriz, int l1, int l2){
    int *temp = *(matriz + l1);
    *(matriz + l1) = *(matriz + l2);
    *(matriz + l2) = temp;   
}