#include <stdio.h>

int buscaBin(int arr[], int tam, int el)
{
    int fim = tam - 1;
    int ini = 0;
    int interacao = 0;

    while (ini <= fim)
    {
        int meio = (fim + ini) / 2;
        int descartados = fim - ini;

        printf("%dª iteração: %d \n", interacao, descartados);
        interacao++;

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

int main()
{
    int tam, el;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &tam);

    int arr[tam];

    printf("Digite os elementos do vetor: ");
    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Digite o elemento a ser buscado: ");
    scanf("%d", &el);

    int resultado = buscaBin(arr, tam, el);

    if (resultado != -1)
        printf("resultado encontrado no indice %d\n", resultado);
    else
        printf("resultado não encontrado.");

    return 0;
}