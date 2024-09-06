#include <stdio.h>

int max_index(const int *v, int N) {
    int max_idx = 0;

    for(int i = 1; i < N; i++) {
        if(v[i] > v[max_idx]) {
            max_idx = i;
        }
    }
    return max_idx;
}

int main(void) {
    int N;

    printf("Insira um valor inteiro: ");
    scanf("%d", &N);

    int v[N];

    printf("Insira %d valores inteiros: ", N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    printf("%d\n", max_index(v, N));

    return 0;
}
