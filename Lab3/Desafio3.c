#include <stdio.h>
#include <stdlib.h>

int **alocacao(int l, int c){
    int **matriz = (int**)malloc(l * sizeof(int *));
    if(!matriz){
        printf("Erro na alocação de memória.");
        return NULL;
    }
    for (int i = 0; i < l; i++){
        *(matriz + i) = (int *)malloc(c * sizeof(int));
        if(!(*(matriz + i))){
            printf("Erro na alocação de memória.");
            for (int j = 0; j < i; j++){
                free(matriz[j]);
            }
            free(matriz);
            return NULL;            
        }
    }
    return matriz;
}

int maximo( int **matriz, int m, int n, int l, int c){
    int count = 0;
    
    for(int i = 0; i < (l / m); i++){
        for (int j = 0; j < (c / n); j++){
            int countAtual = 0;
            for (int x = 0; x < m; x++){
                for (int y = 0; y < n; y++){
                    countAtual += matriz[i * m + x][j * n + y];
                }
            }
            if(countAtual > count)
                count = countAtual;
        } 
    }
    return count;
}

int main () {

    int m, n, c, l, **matriz;

    scanf("%d %d %d %d", &l, &c, &m, &n);

    if(l < 1 || c < 1 || m > l || n > c) {
        printf("Valor inválido.");
        return -1;
    }


    matriz = alocacao(l, c);
    if (!matriz)
        return -1;

    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
            scanf("%d", *(matriz + i) + j);
        }
    }
    int maxMargaridas = maximo(matriz, m, n, l, c);

    printf("%d \n", maxMargaridas);

    for (int i = 0; i < l; i++){
        free(matriz[i]);
    }
    free(matriz);
    
    return 0;
}
