#include <stdio.h>
#include <stdlib.h>

int BuscaBin(int arr[], int tam, int el)
{
    int fim = tam - 1;
    int ini = 0;
    while (ini <= fim)
    {
        int meio = (fim + ini) / 2;
        if (arr[meio] < el)
            ini = meio + 1;
        else
        {
            if (arr[meio] > el)
                fim = meio - 1;
            else
                return meio;
        }
    }
    return -1;
}
void buscaMenorMaiorBin(int arr[], int tam, int el, int *menor, int *maior)
{
    int fim = tam - 1;
    int ini = 0;
    while (ini <= fim)
    {
        int meio = (fim + ini) / 2;
        if (*(arr + meio) < el)
        {
            *menor = meio + 1;
            ini = meio + 1;
        }
        else
        {
            if (*(arr + meio) > el)
            {
                *maior = tam - meio;
                fim = meio - 1;
            }
            else
            {
                *menor = meio;
                *maior = tam - meio - 1;
                break;
            }
        }
    }
    printf("Menor: %d - Maior: %d\n", *menor, *maior);
}

int main()
{

    int el, tam, *arr, menor = 0, maior = 0;

    scanf("%d %d", &tam, &el);

    arr = (int *)malloc(tam * sizeof(int));

    for (int i = 0; i < tam; i++)
    {
        scanf("%d", arr + i);
    }

    buscaMenorMaiorBin(arr, tam, el, &menor, &maior);
    free(arr);

    return 0;
}