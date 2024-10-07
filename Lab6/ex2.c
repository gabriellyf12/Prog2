#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct {
    char nome[100];
    double nota[3];
    double media;
} Taluno;

int main () {

    FILE *arq;
    Taluno *p;
    int i = 0;

    
    p = (Taluno*)malloc( MAX * sizeof(Taluno));

    if (!p){
        printf("erro ao alocar memória.");
        return -1;
    }
    if(!(arq = fopen("alunos.dat", "wb"))){
        printf("Erro na abertura no arquivo.");
        free(p);
        return -1;
    }

    while (1){
        fgets(p[i].nome, 100, stdin);
        p[i].nome[strcspn(p[i].nome, "\n")] = 0;

        if (strlen(p[i].nome) == 0) {
            break;
        }
        
        scanf("%lf %lf %lf", &p[i].nota[0], &p[i].nota[1], &p[i].nota[2]);
        getchar();

        p[i].media = (p[i].nota[0] + p[i].nota[1]+ p[i].nota[2])/3;
        
        fwrite(&p[i], sizeof(Taluno), 1, arq);
        i++;
    }

    fclose(arq);
    free(p);
    return 0;
}