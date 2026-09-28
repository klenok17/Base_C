#include <stdio.h>

int main(void)
{
    int a, b, c, d, e;
    int max, min;

    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    max = a;
    min = a;

    if (b > max) max = b;
    if (b < min) min = b;

    if (c > max) max = c;
    if (c < min) min = c;

    if (d > max) max = d;
    if (d < min) min = d;

    if (e > max) max = e;
    if (e < min) min = e;

    printf("%d", max + min);

    return 0;
}
