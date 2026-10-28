#include <stdio.h>

long long sum_to_n(int n)
{
    if (n == 0)
        return 0;

    return n + sum_to_n(n - 1);
}

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n < 1)
        return 0;

    printf("%lld\n", sum_to_n(n));
    return 0;
}
