#include <stdio.h>

void pares(int *v, int *n){ 
    int cont = 0;

    for (int i = 0; i < *n; i++) {
        if (v[i] % 2 == 0) {
            cont++;
        }
    }
    *n = cont;
}


int main() {
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 5;

    pares(vetor, &n);

    printf("Quantidade de números pares: %d\n", n);

    return 0;
}