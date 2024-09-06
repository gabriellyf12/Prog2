/*O programa recebe uma string como entrada, que supostamente contém dois nomes separados por um espaço em branco. 
A função misterio percorre essa string até encontrar o primeiro espaço em branco. 
Após encontrar o espaço, ela avança um caractere e, em seguida, imprime o restante da string a partir desse ponto.*/

#include <stdio.h>

void misterio (char *n);

int main (void) {
    char nome [41];

    if (fgets(nome, sizeof(nome), stdin) != NULL) 
        nome[strcspn(nome, "\n")] = '\0'; // Remove o caractere de nova linha '\n' que fgets adiciona
    
    misterio(nome);
    return 0;
}

void misterio (char *n) {
    while (*n != ' ' && *n != '\0')
        n++;
    
    if (*n == ' ')
        n++;
    puts(n);
}