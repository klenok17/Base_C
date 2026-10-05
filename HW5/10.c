#include <stdio.h>

int main(void)
{
    int n;
    int digit;

    scanf("%d", &n);

    digit = n % 10;
    n /= 10;

    while (n != 0)
    {
        if (n % 10 >= digit)
        {
            printf("NO");
            return 0;
        }

        digit = n % 10;
        n /= 10;
    }

    printf("YES");

    return 0;
}
