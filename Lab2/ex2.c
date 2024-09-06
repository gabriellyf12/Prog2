/*Este programa inicializa um matriz, mostra uma matriz, e inclui um elemento a ela*/

#include <stdio.h>
#define DIM 3

void inicM (int s [] [DIM]) {
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++)
           *(s[i]+j) = 0;
    }
}

void mostraM (int s [DIM] [DIM]) {
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++)
            printf("[%d]",*(s[i]+j));
        
        printf("\n");
    }
}
void incluiElem (int s[DIM][DIM], int i, int j, int num){
    if (i >= 0 && i < DIM && j >= 0 && j < DIM) {
            s[i][j] = num;
        } else {
            printf("Índices fora dos limites da matriz!\n");
        }
}

int main () {
    int s[DIM] [DIM];
    inicM(s);
    mostraM(s);
    incluiElem(s, 1, 2, 10);
    printf("Matriz com elemento: \n");
    mostraM(s);

    return 0;

}