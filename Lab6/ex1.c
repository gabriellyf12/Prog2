#include <stdio.h>
#include <stdlib.h>

int grava(FILE *pFile, int N){
    int gravados = 0;

    for (int i = N; i >= 1; i--){
        if(fwrite(&i, sizeof(int), 1, pFile) != 1) {
            return -1;
        }
        gravados++;
    }

    return gravados;
}

int* recupera(FILE *pFile){
    int *vetor;
    long tamanho;

    fseek(pFile, 0, SEEK_END);
    tamanho = ftell(pFile);
    rewind(pFile);

    vetor = (int *)malloc(tamanho);
    if (vetor == NULL){
        return 0;
    }

    if(fread(vetor, sizeof(int), tamanho / sizeof(int), pFile) != tamanho / sizeof(int)){
        free(vetor);
        return 0;
    }

    return vetor;
}

void exibe_vetor(int *vetor, int N){
    for(int i = 0; i < N; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int modifica(FILE *pFile, int M){
    int num;
    long posicao;

    fseek(pFile, -M * sizeof(int), SEEK_END);

    for (int i = 0; i < M; i++) {
        posicao = ftell(pFile);
        if (fread(&num, sizeof(int), 1, pFile) != 1) {
            return -1; 
        }
        if (num % 2 == 0) {
            num *= 2;
            fseek(pFile, posicao, SEEK_SET); 
            if (fwrite(&num, sizeof(int), 1, pFile) != 1) {
                return -1; // Erro na gravação
            }
        }
    }

    return M;
}

void recupera_exibe(FILE *pFile){
    int num;

    rewind(pFile);
    while(fread(&num, sizeof(int), 1, pFile) == 1){
        printf("%d ", num);
    }
    printf("\n");

}

int main() {

    FILE *pFile;
    int i, N, M, num, mod, *vetor;
    char nome_arquivo[100];

    printf("Informe o nome do arquivo a ser criado: ");
    scanf("%s", nome_arquivo);

    printf("Informe um numero positivo: ");
    scanf("%d", &N);
    
    pFile = fopen (nome_arquivo, "wb+");
    
    if (!pFile){ 
        printf("Erro na criacao do arquivo...");
        return -1;
    }

    if (grava(pFile, N)!=N){
        printf("Erro na gravacao do arquivo...");
        return -1;
    }
    
    vetor=recupera(pFile);
    if(vetor==NULL){
        printf("Erro na recuperacao de dados do arquivo...");
        return -1;
    }

    exibe_vetor(vetor,N);
    printf("Informe um numero positivo M correspondente a quantidade de valores a partir do final do arquivo que deseja alterar: "); 
    scanf("%d",&M);

    mod=modifica(pFile,M);
    if(mod==-1){
        printf("Valor de M fora do intervalo permitido...");
        return -1;
    }

    if(mod!=M){ 
        printf("Erro de leitura e/ou gravacao no arquivo...");
        return -1;
    }

    recupera_exibe(pFile);
    fclose(pFile);
    return 0;
}