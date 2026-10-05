#include <stdio.h>

void print_simple(int n)
{
    int d = 2;

    while (n > 1)
    {
        if (n % d == 0)
        {
            printf("%d ", d);
            n = n / d;
        }
        else
        {
            d++;
        }
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    print_simple(n);

    return 0;
}
