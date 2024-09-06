//função que concatena duas strings e o programa principal parar testar a função implementada.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatena(char *s1, char *s2){
    int tam_s1 = strlen(s1);
    int tam_s2 = strlen(s2);

    char *resultado = (char *)malloc((tam_s1 + tam_s2 + 1) * sizeof(char));
    if(!resultado){
        printf("Erro ao alocar memória. \n");
        return NULL;
    }

    strcpy(resultado, s1);
    strcat(resultado, s2);

    return resultado;
}

int main (){

    char s1[100], s2[100];

    printf("Primeira string: ");
    scanf("%s", s1);
    printf("Segunda string: ");
    scanf("%s", s2);

    char *resultado = concatena(s1, s2);

    if (resultado){
        printf("String concatenada: %s \n", resultado);
        free(resultado);
    }
    
    return 0;
}