#include <stdio.h>
#include <string.h>

int main () {

    FILE *parq;
    int lidos;
    float real, maior;
    char nome_arquivo[101];
    
    fgets(nome_arquivo,100,stdin); //nome do arquivo a ser criado
    nome_arquivo[strlen(nome_arquivo)-1]='\0';

    parq = fopen (nome_arquivo , "rb");
    if (!parq){ 
        printf("Erro na abertura do arquivo.");
        return -1;
    }

    lidos = fread(&maior, sizeof(float), 1, parq);
    if (lidos == 0){
        printf("Erro na leitura dos dados.");
        fclose(parq);
        return -1;
    }

    while ((lidos = fread(&real, sizeof(float), 1, parq))== 1){
        if (real > maior){
            maior = real;
        }
    }
    
    printf("O maior numero armazenado no arquivo eh %f\n", maior);
    fclose(parq);
    
    return 0;
}