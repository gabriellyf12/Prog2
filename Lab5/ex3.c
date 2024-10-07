#include <stdio.h>
#define MAX 50

char converteMinuscula(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int comparaStrings(char str1[], char str2[]) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (converteMinuscula(str1[i]) != converteMinuscula(str2[i])) {
            return 0; 
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 1;
    } else {
        return 0;  
    }
}

int main() {

    FILE *arq;
    char palavra[MAX], nome_arq[MAX], string[MAX];
    int count = 0;

    scanf("%s", nome_arq);
    scanf("%s", palavra);

    if(!(arq = fopen(nome_arq, "r"))){
        printf("Erro na abertura do arquivo.");
        fclose(arq);
        return -1;
    }

    while(fscanf(arq, "%s", string)!= EOF){
        if (comparaStrings(palavra, string))
            count++;
    }

    printf("Aparece %d vezes. \n", count);

    fclose(arq);
    return 0;
}