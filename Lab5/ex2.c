#include <stdio.h>
#define MAX 100

int main () {

    FILE *arq_entrada, *arq_saida;
    char nome_arq_entrada[MAX], nome_arq_saida[MAX], nome[MAX];
    float p1, p2, T, media;
    int linha[MAX];

    scanf("%s", nome_arq_entrada);
    scanf("%s", nome_arq_saida);

    if (!(arq_entrada = fopen(nome_arq_entrada, "r"))){
        printf("Erro na abertura do arquivo de entrada.");
        return -1;
    }
    if (!(arq_saida = fopen(nome_arq_saida, "w"))){
        printf("Erro na abertura do arquivo de saida.");
        return -1;
    }

    while(fscanf(arq_entrada, "%s %f %f %f", nome, &p1, &p2, &T) == 4){
        media=(((p1+p2)/2)*0.8)+(T*0.2);
        fprintf(arq_saida, "%s: %f\n", nome, media);
    }
    

    fclose(arq_entrada);
    fclose(arq_saida);
    return 0;
}