#include <stdio.h>

int convert(int n, int p)
{
    int result = 0;
    int k = 1;

    while (n > 0)
    {
        result = result + (n % p) * k;
        n = n / p;
        k = k * 10;
    }

    return result;
}

int main()
{
    int n, p;

    scanf("%d %d", &n, &p);

    printf("%d", convert(n, p));

    return 0;
}
