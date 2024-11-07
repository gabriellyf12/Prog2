#include <stdio.h>

void bolha(int v[], int tam)
{
    int ult, i, aux;
    int troca;

    for (ult = tam - 1; ult > 0; ult--)
    {
        troca = 0;

        for (i = 0; i < ult; i++)
            if (v[i] > v[i + 1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                troca = 1;
            }
        if (troca == 0)
            break;
    }
}

void imprimirVetor(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main()
{

    int tam;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &tam);

    int v[tam];

    printf("Digite os elementos do vetor: ");
    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &v[i]);
    }

    bolha(v, tam);
    imprimirVetor(v, tam);

    return 0;
}