#include <stdio.h>

void altera (float *salario, float percentual){

    *salario += (*salario * (percentual/100));

}
int main () {
    
    float salario, percentual;

    printf("Digite o salário atual e o percentual de aumento: ");
    scanf("%f %f", &salario, &percentual);

    altera(&salario, percentual);

    printf("O salário alterado é: %.2f ", salario);
}
