#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char nome[MAX];
    int gols;
} tTimeGols;

typedef struct {
    tTimeGols time1;
    tTimeGols time2;
} tPlacarJogo;

typedef struct {
    char nome[MAX];
    int jogos;
    int saldo;
    int pontos;
} tPontos;

int grava_pontos_time(FILE *parq, tPontos time_grava){
    tPontos temp;
    long pos = 0;
    int encontrado = 0;

    // Busca o time no arquivo
    while (fread(&temp, sizeof(tPontos), 1, parq) == 1) {
        if (strcmp(temp.nome, time_grava.nome) == 0) {
            // Time encontrado, atualiza
            encontrado = 1;
            break;
        }
        pos += sizeof(tPontos);
    }

    // Se o time foi encontrado, volta para a posição e atualiza
    if (encontrado) {
        fseek(parq, pos, SEEK_SET);
        fwrite(&time_grava, sizeof(tPontos), 1, parq);
    } else {
        // Se o time não foi encontrado, adiciona no final do arquivo
        fseek(parq, 0, SEEK_END);
        fwrite(&time_grava, sizeof(tPontos), 1, parq);
    }

    return 0; // Sucesso
}
int contabiliza_pontuacao(tPlacarJogo *placar, tPontos *time_grava){
    if (strcmp(placar->time1.nome, time_grava->nome) == 0){
        time_grava->jogos++;
        time_grava->saldo += placar->time1.gols - placar->time2.gols;

        if (placar->time1.gols > placar->time2.gols) {
            time_grava->pontos += 3; 
        } 
        else if (placar->time1.gols == placar->time2.gols) {
            time_grava->pontos += 1;        
        }
    }

    else if (strcmp(placar->time2.nome, time_grava->nome) == 0){
        time_grava->jogos++;
        time_grava->saldo += placar->time2.gols - placar->time1.gols;
        
        if (placar->time2.gols > placar->time1.gols) {
            time_grava->pontos += 3; 
        } 
        else if (placar->time2.gols == placar->time1.gols) {
            time_grava->pontos += 1;        
        }
    }

    return 0;
}

int ler_gravar_resultados(FILE *parq, FILE *parq2, char *time_desejado)
{
    tPlacarJogo placar;
    tPontos time;
    strcpy(time.nome, time_desejado); // Inicializa o nome do time
    time.jogos = 0;
    time.saldo = 0;
    time.pontos = 0;

    fseek(parq, 0, SEEK_SET); // Volta ao início do arquivo de jogos
    while (fscanf(parq, "%s %d x %d %s", placar.time1.nome, &placar.time1.gols, &placar.time2.gols, placar.time2.nome) == 4)
    {
        // Verifica se o time está envolvido no jogo
        if (strcmp(placar.time1.nome, time_desejado) == 0 || strcmp(placar.time2.nome, time_desejado) == 0)
        {
            contabiliza_pontuacao(&placar, &time); // Atualiza os dados do time
        }
    }

    grava_pontos_time(parq2, time); // Grava os dados no arquivo binário
    return 0;
}

void mostra_pontuacao_time(FILE *parq)
{
    tPontos time;

    fseek(parq, 0, SEEK_SET); // Volta ao início do arquivo
    while (fread(&time, sizeof(tPontos), 1, parq) == 1)
    {
        printf("time: %s - jogos: %d, saldo de gols: %d, pontos: %d\n", time.nome, time.jogos, time.saldo, time.pontos);
    }
}

int main() {
    FILE *parq, *parq2;
    char time_buscado[MAX];

    parq=fopen("jogos.txt","r");
    if(parq==NULL)
        return -1;

    parq2=fopen("pontos.dat","w+");
    if(parq2==NULL) {
        fclose(parq);
        return -1;
    }

    printf("Digite o time desejado: ");
    fgets(time_buscado,MAX,stdin);

    while (time_buscado[0]!='\n') {
        time_buscado[strlen(time_buscado)-1]='\0';
        ler_gravar_resultados(parq, parq2, time_buscado);
        mostra_pontuacao_time(parq2);
        printf("Digite o time desejado: ");
        fgets(time_buscado,MAX,stdin); 
    }

    fclose(parq);
    fclose(parq2);
    return 0; 
}
