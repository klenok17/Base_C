#include <stdio.h>

int grow_up(int n)
{
    int last = n % 10;

    n = n / 10;

    while (n > 0)
    {
        int digit = n % 10;

        if (digit >= last)
            return 0;

        last = digit;
        n = n / 10;
    }

    return 1;
}

int main()
{
    int n;

    scanf("%d", &n);

    if (grow_up(n))
        printf("YES");
    else
        printf("NO");

    return 0;
}
