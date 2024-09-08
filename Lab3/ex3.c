#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _func {
char nome[40];
int ano_nasc;
float renda;
} Tfunc;

Tfunc * inicializa (Tfunc *, int);
Tfunc * inclui_novos(Tfunc *, int, int);
void imprime (Tfunc *, int, int);

int main(void){

    Tfunc *cadastro;
    int funcionarios, adicionais;

    printf("Quantos funcionarios? ");
    scanf("%d",&funcionarios);

    cadastro=inicializa(cadastro, funcionarios);
    
    if (!cadastro)
        return -1;

    printf("Quantos funcionarios a mais deseja adicionar? ");
    scanf("%d",&adicionais);

    cadastro = inclui_novos(cadastro, funcionarios, adicionais);
    
    if (!cadastro)
        return -1;

    printf("\nLista de funcionarios cadastrados\n");

    imprime(cadastro, 0, funcionarios+adicionais);
    free(cadastro);

    return 0;
}

Tfunc *inicializa(Tfunc *cadastro, int funcionarios){
    cadastro = (Tfunc *)malloc(funcionarios * sizeof(Tfunc));
    
    if(!cadastro) {
        puts("Erro na alocação de memória. \n");
        return NULL;
    }

    for (int i = 0; i < funcionarios; i++){
        puts("Nome: ");
        getchar();
        fgets((cadastro+i)-> nome, 39, stdin);
        puts ("Ano de nascimento: ");
        scanf("%d",&(cadastro+i)-> ano_nasc);
        puts("Renda: ");
        scanf("%f",&(cadastro+i)-> renda);
    }
    return cadastro;
}

Tfunc *inclui_novos(Tfunc *cadastro, int funcionarios, int adicionais){
    cadastro = (Tfunc *)realloc(cadastro, (funcionarios + adicionais) * sizeof(Tfunc));
    if (!cadastro){
        puts("Erro na realocação de memória. \n");
        return NULL;
    }
    
    for (int i = funcionarios; i < funcionarios + adicionais; i++){
        printf("\nFuncionário %d: \n", i + 1);
        puts("Nome: ");
        getchar();
        fgets((cadastro+i)-> nome, 39, stdin);
        puts ("Ano de nascimento: ");
        scanf("%d",&(cadastro+i)-> ano_nasc);
        puts("Renda: ");
        scanf("%f", &(cadastro+i)-> renda);
    }
    return cadastro;    
}

void imprime(Tfunc *cadastro, int inicio, int fim){
    for (int i = inicio; i < fim; i++){
        printf("\nFuncionario %d:\n", i + 1);
        printf("Nome: %s", (cadastro+i)-> nome);
        printf("Ano de nascimento: %d\n", (cadastro+i)-> ano_nasc);
        printf("Renda: %.2f\n", (cadastro+i)-> renda);
    }
}