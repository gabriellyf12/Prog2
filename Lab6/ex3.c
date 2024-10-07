#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    char nome[100];
    double nota[3];
    double media;
} Taluno;

void mediaPonderada(Taluno *aluno){
    aluno->media = 0.25 * aluno->nota[0] + 0.35 * aluno->nota[1] + 0.4 * aluno->nota[2];
}

int main() {
    FILE *arq;
    Taluno aluno;
    int alunosAtualizados = 0, totalAlunos = 0;

    if (!(arq = fopen("alunos.dat", "rb+"))) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }

    while (fread(&aluno, sizeof(Taluno), 1, arq) == 1) {
        double mediaAntiga = aluno.media;
        totalAlunos++;
        
        mediaPonderada(&aluno);

        if (aluno.media != mediaAntiga){
            alunosAtualizados++;
        }

        fseek(arq, -sizeof(Taluno), SEEK_CUR);
        fwrite(&aluno, sizeof(Taluno), 1, arq);
        fflush(arq);
    }

    double percentual_atualizados = ((double) alunosAtualizados / totalAlunos) * 100;
        
    printf("Percentual de médias atualizadas: %2.f%%\n", percentual_atualizados);

    rewind(arq);
    printf("Dados dos alunos após atualização: \n");

    while (fread(&aluno, sizeof(Taluno), 1, arq) == 1){
        printf("Nome: %s\n", aluno.nome);
        printf("Notas: %.2f, %.2f, %.2f\n", aluno.nota[0], aluno.nota[1], aluno.nota[2]);
        printf("Média: %.2f\n", aluno.media);
        }

    fclose(arq);
    return 0;
}
