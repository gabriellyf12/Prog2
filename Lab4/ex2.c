#include <stdio.h>
#include <string.h>

void converteMaiuscula(char *linha, FILE *pout){
    int comprimento = strlen(linha);

    for(int i = 0; i < comprimento; i++){
        if (linha[i] >= 'a' && linha[i] <= 'z') {
            linha[i] = linha[i] - ('a' - 'A');
        }
    }
    fprintf(pout, "%s", linha);
}

int main (int argc, char *argv[]) {

    if (argc != 3){
        printf("Uso: %s <arquivo_entrada> <arquivo_saida>\n", argv[0]);
        return 1;
    }

    char *nome = argv[1], *saida = argv[2];
    FILE *pin, *pout;
    char linha[200];

    if (( pin = fopen(nome, "r")) == NULL) {
	    printf("Nao foi possivel abrir o arquivo.\n");
	    return 1;
    }

    if (( pout = fopen(saida, "w")) == NULL) {
	    printf("Nao foi possivel abrir o arquivo.\n");
        fclose(pin);
	    return 1;
    }

    while(fgets(linha, sizeof(linha), pin) != NULL){
        converteMaiuscula(linha, pout);
    }


    fclose(pin);
    fclose(pout);

    return 0;
}