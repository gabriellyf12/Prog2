#include <stdio.h>

void buscaSeqOrdRep(int arr[], int tam, int el, int *pos, int *quant)
{
    *pos = -1;  // Inicializa posição como -1, caso o elemento não seja encontrado
    *quant = 0; // Inicializa a quantidade de ocorrências como 0

    for (int i = 0; i < tam; i++)
    {
        if (arr[i] == el)
        {
            if (*pos == -1)
            {
                *pos = i; // Guarda a posição da primeira ocorrência
            }
            (*quant)++; // Conta a quantidade de ocorrências
        }
        else if (arr[i] > el)
        {
            // Como o vetor está ordenado, se o valor atual for maior que o elemento, pode parar
            break;
        }
    }
}

int main()
{
    int n;
    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &n);

    int arr[n];
    printf("Digite os elementos do vetor: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int el;
    printf("Digite o elemento procurado: ");
    scanf("%d", &el);

    int pos, quant;
    buscaSeqOrdRep(arr, n, el, &pos, &quant);

    if (pos != -1)
    {
        printf("Posição da primeira ocorrência: %d\n", pos);
        printf("Quantidade de ocorrências: %d\n", quant);
    }
    else
    {
        printf("Elemento não encontrado.\n");
    }

    return 0;
}
