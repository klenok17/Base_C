#include <stdio.h>

int main(void)
{
    int n;
    int digit;
    int min, max;

    scanf("%d", &n);

    min = max = n % 10;
    n /= 10;

    while (n != 0)
    {
        digit = n % 10;

        if (digit < min)
            min = digit;

        if (digit > max)
            max = digit;

        n /= 10;
    }

    printf("%d %d", min, max);

    return 0;
}
