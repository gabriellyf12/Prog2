#include <stdio.h>
#include <stdlib.h>

typedef struct{
int hora, minuto;
} t_Momento;

void tempoatual(int percorrido, t_Momento *momento);
int converteMinutos(t_Momento momento);
t_Momento horaMaisProxima(t_Momento momento1, t_Momento momento2, t_Momento atual);

int main (int argc, char *argv[]){

    if (argc < 2) {
        printf("Uso: %s <numero de testes>\n", argv[0]);
        return 1;
    }

    int numTestes = atoi(argv[1]);

    for(int i = 0; i < numTestes; i++){
        t_Momento momento1, momento2, momentoAtual;
        int percorrido;

        scanf("%d %d", &momento1.hora, &momento1.minuto);
        scanf("%d %d", &momento2.hora, &momento2.minuto);
        scanf("%d", &percorrido);

        tempoatual(percorrido, &momentoAtual);

        t_Momento maisProximo = horaMaisProxima(momento1, momento2, momentoAtual);

        printf("%02d:%02d\n", maisProximo.hora, maisProximo.minuto);
    }
}
void tempoatual(int percorrido, t_Momento *momento) {
    momento->hora = percorrido / 60;
    momento->minuto = percorrido % 60;
}

t_Momento horaMaisProxima(t_Momento momento1, t_Momento momento2, t_Momento atual) {
    int minutosAtual = converteMinutos(atual);
    int minutos1 = converteMinutos(momento1);
    int minutos2 = converteMinutos(momento2);

    if (momento1.hora == momento2.hora){
        return momento1;
    }
    if (abs(minutos1 - minutosAtual) <= abs(minutos2 - minutosAtual)) {
        return momento1; 
    } else {
        return momento2;
    }
}

int converteMinutos(t_Momento momento) {
    return momento.hora * 60 + momento.minuto;
}