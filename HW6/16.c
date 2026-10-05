#include <stdio.h>

int is_prime(int n)
{
    int d;

    if (n < 2)
        return 0;

    for (d = 2; d < n; d++)
    {
        if (n % d == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int n;

    scanf("%d", &n);

    if (is_prime(n))
        printf("YES");
    else
        printf("NO");

    return 0;
}
