//Programa que cria e inicializa três variáveis e salva seus valores em um arquivo texto
#include <stdio.h>
#include <string.h>

int main (){

    int aux1;
	char str [50];
	double aux2;
	
	FILE *arq;
	
    strcpy(str, "ola mundo!");
	
	if ((arq = fopen("meu_texto.txt", "r")) == NULL){
		printf("Erro na abertura do arquivo.");
		return -1;
	}
	
    //fprintf(arq, "%d\n%s\n%lf\n", aux1, str, aux2);
	fscanf (arq, "%d %[^\n] %lf", &aux1, str, &aux2);
	fclose(arq);
    printf("%d, %s, %lf\n", aux1, str, aux2);
	return 0;
}