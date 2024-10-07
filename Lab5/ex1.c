#include <stdio.h>
#define MAX 100

int main () {

    FILE *arq;
    char nome_arq[MAX], nome[MAX];
    float p1, p2, T;
    int numAlunos;

    scanf("%s", nome_arq);
    scanf("%d", &numAlunos);


    if (!(arq = fopen(nome_arq, "w"))){
        printf("Erro na abertura do arquivo.");
        return -1;
    }

    for (int i = 0; i < numAlunos; i++){
        scanf("%s", nome);
        scanf("%f %f %f", &p1, &p2, &T);
        fprintf(arq, "%s %.1f %.1f %.1f\n", nome, p1, p2, T);
    }
    
    

    fclose(arq);
    return 0;
}