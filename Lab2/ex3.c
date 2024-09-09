#include <stdio.h>
#include <stdlib.h>

int k=0;
int main(int argc, char *argv[]) {

    if(argc==1)
        return -1;

    k=atoi(argv[1]);
    
    int vetor[]={10,20,30,40,50,60};
    int *p1, *p2, *p3;
    int i = 100, j;
    p1 = &vetor[2];
    p2 = &i;

    printf("%d, %d\n",*p1,*p2);

    p3=malloc(sizeof(int));

    for (j=3;j>0;j--){
        int k;
        if (j%2!=0){
            k=j*5;
            printf("%d, %d\n",j,k);
        }

        *p3=k;
        *p2=*p3;
        p1++;
    }

    printf("%d, %d, %d\n",*p1,*p2,*p3);
    printf("%d, %d, %d\n", i, j, k);
    free(p3);

    return 0;
}