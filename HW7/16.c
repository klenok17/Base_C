#include <stdio.h>

int is2pow(int n)
{
    if (n == 1)
        return 1;

    if (n < 1 || n % 2 != 0)
        return 0;

    return is2pow(n / 2);
}

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n < 1)
        return 0;

    if (is2pow(n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
