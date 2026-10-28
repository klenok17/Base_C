#include <stdio.h>

int sum_digits(int n)
{
    if (n < 10)
        return n;

    return n % 10 + sum_digits(n / 10);
}

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n < 0)
        return 0;

    printf("%d\n", sum_digits(n));
    return 0;
}
