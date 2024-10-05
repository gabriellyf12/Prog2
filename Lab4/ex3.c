#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Verifica se o número correto de argumentos foi fornecido
    if (argc != 3) {
        printf("Uso: %s <nome_do_arquivo> <padrao_a_buscar>\n", argv[0]);
        return 1;
    }

    // Abre o arquivo para leitura
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    const char *pattern = argv[2];
    char line[81]; // Buffer para armazenar cada linha do arquivo (80 chars + '\0')
    int line_number = 0;

    // Lê o arquivo linha por linha
    while (fgets(line, sizeof(line), file)) {
        line_number++; // Incrementa o contador de linhas
        // Verifica se o padrão existe na linha lida
        if (strstr(line, pattern) != NULL) {
            printf("Linha %d: %s", line_number, line); // Imprime o número da linha e a linha
        }
    }

    // Fecha o arquivo
    fclose(file);

    return 0;
}
