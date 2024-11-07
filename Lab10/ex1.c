#include <stdio.h>

void bolha(int v[], int tam)
{
    int ult, i, aux;

    for (ult = tam - 1; ult > 0; ult--)
        for (i = 0; i < ult; i++)
            if (v[i] < v[i + 1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
            }
}

void insercao(int v[], int tam)
{
    int i, aux, j;
    for (i = 0; i < tam; i++)
    {
        aux = v[i];
        j = i;
        while ((j > 0) && (aux > v[j - 1]))
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = aux;
    }
}

void selecao(int v[], int tam)
{
    int i, p, aux, posMenor;
    for (i = 0; i < tam - 1; i++)
    {
        posMenor = i;
        for (p = i + 1; p < tam; p++)
            if (v[p] > v[posMenor])
                posMenor = p;
        aux = v[i];
        v[i] = v[posMenor];
        v[posMenor] = aux;
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
    insercao(v, tam);
    selecao(v, tam);
    imprimirVetor(v, tam);

    return 0;
}