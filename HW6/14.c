#include <stdio.h>

int even_sum(int n)
{
    int sum = 0;

    while (n > 0)
    {
        sum = sum + n % 10;
        n = n / 10;
    }

    if (sum % 2 == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int n;

    scanf("%d", &n);

    if (even_sum(n))
        printf("YES");
    else
        printf("NO");

    return 0;
}
