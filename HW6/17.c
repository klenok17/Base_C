#include <stdio.h>

int is_happy_number(int n)
{
    int sum = 0;
    int product = 1;

    while (n > 0)
    {
        sum = sum + n % 10;
        product = product * (n % 10);

        n = n / 10;
    }

    if (sum == product)
        return 1;
    else
        return 0;
}

int main()
{
    int n;

    scanf("%d", &n);

    if (is_happy_number(n))
        printf("YES");
    else
        printf("NO");

    return 0;
}
