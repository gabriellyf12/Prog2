#include <stdio.h>
#include <stdlib.h>

int *f(int x, int y, int *p, int *z) // x = a = 10, y = b = 7, *p = c = 50, z* = d[1, 2, 3]
{
    int *w;
    (*p)++;  // p = 51
    *p = y;  // p = 7
    x += 10; // x = 20
    w = (int *)malloc(sizeof(int));
    (*p) += y;   // p = 14, c = 14
    *w = *p + 5; // w = 19
    *z++ = x;    // z[0] = x = 20, z++( prox z a ser mexido é z[1])
    x -= 50;     // x = -30
    p = &x;      // p = aponta x
    p = &y;      // p = aponta y= 7
    (*p)--;      // p = 6, y = 6
    *z += y;     // z[1] = 2 + 6 = 8
    y *= 10;     // y = 60 , p = 60
    *++z = *p;   // z[2]= 60
    return w;    // w = 19
}

int main()
{
    int a = 10, b = 7, c = 50, d[3] = {1, 2, 3};
    int *e = f(a, b, &c, d);

    printf("a=%d b=%d c=%d *e=%d\n", a, b, c, *e); // a = 10, b = 7, c = 14, e = 19
    for (int i = 0; i < 3; i++)
        printf("d[%i]=%d\n", i, d[i]); // d[0] = 20 d[1] = 8, d[2]= 60

    free(e);
    return 0;
}