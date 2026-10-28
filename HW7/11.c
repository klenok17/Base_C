#include <stdio.h>

int count_ones(unsigned int n)
{
    if (n == 0)
        return 0;

    return (int)(n % 2) + count_ones(n / 2);
}

int main(void)
{
    unsigned int n;

    if (scanf("%u", &n) != 1)
        return 0;

    printf("%d\n", count_ones(n));
    return 0;
}
