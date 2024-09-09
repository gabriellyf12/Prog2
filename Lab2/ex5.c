#include <stdio.h>

int comprimento(char *str){
    int cont = 0;

    while (str[cont] != '\0'){
        cont++;
    }
    return cont;
}

int compara(char *str1, char *str2, int cont){
    for (int i = 0; i < cont; i++){
        if (str1[i] != str2[i]){
            return 0;
        }
    }
    return 1;    
}

int posicao(char *substr, char *str){
    int tamSubString = comprimento(substr);
    int tamString = comprimento(str);

    for (int i = 0; i <= tamString - tamSubString; i++){
        if (compara(&str[i], substr, tamSubString)){
            return i;
        }
    }    
    return -1;
}

int main (){
    
    char str[100], substr[100];

    fgets(str, sizeof(str), stdin);

    int tamString = comprimento(str);
    if (str[tamString - 1] == '\n'){
        str[tamString - 1] = '\0';
    }

    fgets(substr, sizeof(substr), stdin);

    int tamSubString = comprimento(substr);
    if (substr[tamSubString - 1] == '\n'){
        substr[tamSubString - 1] = '\0';
    }

    int pos = posicao(substr, str);

    if (pos != -1) {
        printf("Substring encontrada na posicao: %d\n", pos);
    } else {
        printf("Substring nao encontrada.\n");
    }
}