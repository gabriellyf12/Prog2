#include <stdio.h>
#include <string.h>
#define MAX 201

void invertida(char *linha, FILE *psaida){
    int comprimento = strlen(linha);
    char linha_invertida[MAX];

    if(comprimento > 0 && linha[comprimento - 1] == '\n'){
		comprimento--;
    }
    
    for(int i = 0; i < comprimento; i++){
        linha_invertida[i] = linha[comprimento - 1 - i];
    }
    linha_invertida[comprimento] = '\0';
    fprintf(psaida, "%s\n", linha_invertida);

}

int main (int argc, char *argv[]){
    
    if (argc != 3) {
        printf("Uso: %s <arquivo_entrada> <arquivo_saida>\n", argv[0]);
        return 1;
    }

    char *nome = argv[1], *saida = argv[2];
    FILE *pa, *psaida;
    char linha[MAX];

    if (( pa = fopen(nome, "r")) == NULL) {
	    printf("Nao foi possivel abrir o arquivo.\n");
	    return 1;
    }

    if (( psaida = fopen(saida, "w")) == NULL) {
	    printf("Nao foi possivel abrir o arquivo.\n");
	    return 1;
    }

    while(fgets(linha, MAX, pa) != NULL){
        invertida(linha, psaida);
    }

    fclose(pa);
    fclose(psaida);

    return 0;
}