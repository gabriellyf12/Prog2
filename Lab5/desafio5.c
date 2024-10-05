#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 101

int main (){
    int A, C, h, m, s;
    int melhorTempo = 10000000;
    FILE *arq;
    char nome[MAX], atleta[MAX], melhorAtleta[MAX];

    scanf("%s", nome);

    if(!(arq = fopen(nome, "r"))){
        printf("Erro na abertura de arquivo.\n");
        return -1;
    }

    fscanf(arq, "%d %d \n", &A, &C);
    if(A < 1 || C < 1){
        printf("Valores de entrada inválidos.");
        fclose(arq);
        return -1;
    }

    for(int i = 0; i < A; i++){
        fscanf(arq, "%s", atleta);
        int tempoTotal = 0;

        for(int j = 0; j < C; j++){
            fscanf(arq, "%d %d %d", &h, &m, &s);
            tempoTotal += h*3600 + m*60 + s;
        }

        if (tempoTotal < melhorTempo){
            melhorTempo = tempoTotal;
            strcpy(melhorAtleta, atleta);
        }
    }

    printf("%s = %d segundos \n", melhorAtleta, melhorTempo);
    fclose(arq);
}