#include <stdio.h>
#define MAX 200

void contaVogal (char *string, int *contA, int *contE, int *contI, int *contO, int *contU){

    while(*string != '\0'){
        if(*string == 'a' || *string == 'A'){
            (*contA)++;
        } 
        if(*string == 'e' || *string == 'E'){
            (*contE)++;
        }
        if(*string == 'i' || *string == 'I'){
            (*contI)++;
        }
        if(*string == 'o' || *string == 'O'){
            (*contO)++;
        }
        if(*string == 'u' || *string == 'U'){
            (*contU)++;
        }
        string++;
    }
}

int main () {

    char nome[MAX], linha[MAX];
    FILE *pa;

    printf("Nome do arquivo?\n");
    scanf("%s", nome);

    if (( pa = fopen(nome, "r")) == NULL) {
	    printf("Nao foi possivel abrir o arquivo.\n");
	    return 1;
    }

    int totalA = 0, totalE = 0, totalI = 0, totalO = 0, totalU = 0;

    while(fgets(linha, MAX, pa) != NULL){
        contaVogal(linha, &totalA, &totalE, &totalI, &totalO, &totalU);
    }

    fclose(pa);

    printf("a %d\n", totalA);
    printf("e %d\n", totalE);
    printf("i %d\n", totalI);
    printf("o %d\n", totalO);
    printf("u %d\n", totalU);

    return 0;
}