#include <stdio.h>
#define true 1
#define false 0

typedef int bool;

bool buscaR(int v[], int n, int procurado, int esq, int dir)
{
    int meio = (esq + dir) / 2;
    if (esq <= dir)
    {
        if (v[meio] == procurado)
            return true;
        else if (v[meio] > procurado)
            return buscaR(v, n, procurado, esq, meio - 1);
        else if (v[meio] < procurado)
            return buscaR(v, n, procurado, meio + 1, dir);
    }
    return false;
}

int main()
{
    int n;
    int procurado;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &n);

    int v[n];

    printf("Digite os elementos do vetor: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    printf("Digite o elemento a ser buscado: ");
    scanf("%d", &procurado);

    if (buscaR(v, n, procurado, 0, n - 1))
    {
        printf("Elemento encontrado!\n");
    }
    else
    {
        printf("Elemento não encontrado.\n");
    }

    return 0;
}
