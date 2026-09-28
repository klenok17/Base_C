#include <stdio.h>

int main(void)
{
    int n;
    int a, b, c;
    int max;

    scanf("%d", &n);

    a = n / 100;
    b = n / 10 % 10;
    c = n % 10;

    max = a;

    if (b > max) max = b;
    if (c > max) max = c;

    printf("%d", max);

    return 0;
}
