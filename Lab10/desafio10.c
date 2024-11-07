#include <stdio.h>

void bubbleSort(int v[], int tam) {
    if (tam == 1) {
        return;
    }
    for (int i = 0; i < tam - 1; i++) {
        if (v[i] > v[i + 1]) {
            int aux = v[i];
            v[i] = v[i + 1];
            v[i + 1] = aux;
        }
    }

    bubbleSort(v, tam - 1);
}

void insertionSort(int v[], int tam) {
    if (tam <= 1) {
        return;
    }
    
    insertionSort(v, tam - 1);

    int aux = v[tam - 1];
    int j = tam - 2;

    while (j >= 0 && v[j] > aux) {
        v[j + 1] = v[j];
        j--;
    }
    v[j + 1] = aux;
}

void selectionSort(int v[], int tam, int inicio) {
    if (inicio >= tam - 1) {
        return;
    }

    int posMenor = inicio;
    for (int i = inicio + 1; i < tam; i++) {
        if (v[i] < v[posMenor]) {
            posMenor = i;
        }
    }

    int aux = v[inicio];
    v[inicio] = v[posMenor];
    v[posMenor] = aux;

    selectionSort(v, tam, inicio + 1);
}

void imprimirVetor(int v[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int v1[] = {9, 8, 7, 6, 5, 4, 3};
    int v2[] = {4, 7, 3, 2, 9, 5, 1};
    int v3[] = {2, 1, 6, 2, 8, 4, 7};
    int tam = sizeof(v1) / sizeof(v1[0]);

    printf("Vetor original:\n");
    imprimirVetor(v1, tam);
    bubbleSort(v1, tam);
    printf("\nVetor ordenado com Bubble Sort Recursivo:\n");
    imprimirVetor(v1, tam);

    printf("\nVetor original:\n");
    imprimirVetor(v2, tam);
    insertionSort(v2, tam);
    printf("\nVetor ordenado com Insertion Sort Recursivo:\n");
    imprimirVetor(v2, tam);

    printf("\nVetor original:\n");
    imprimirVetor(v3, tam);
    selectionSort(v3, tam, 0);
    printf("\nVetor ordenado com Selection Sort Recursivo:\n");
    imprimirVetor(v3, tam);

    return 0;
}