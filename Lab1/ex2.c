#include <stdio.h>

//versao1
int contaVogal (char string[50]){
    int cont = 0;
    for(int i = 0; string[i] != '\0'; i++){
        if( string[i] == 'a' || string[i] == 'A' || string[i] == 'e' || string[i] == 'E' || string[i] == 'i' || string[i] == 'I' || string[i] == 'o' || string[i] == 'O' || string[i] == 'u' || string[i] == 'U'){
            cont++;
        }
    }

    return cont;
}

//versao2

int contaVogal (char *string){
    int cont = 0;
    while(*string != '\0'){
        if(*string == 'a' || *string == 'A' || *string == 'e' || *string == 'E' || *string == 'i' || *string == 'I' || *string == 'o' || *string == 'O' || *string == 'u' || *string == 'U'){
            cont++;
        }
        string++;
    }

    return cont;
}

