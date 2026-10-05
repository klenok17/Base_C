#include <stdio.h>

int main(void)
{
    int n;
    int result = 0;

    scanf("%d", &n);

    while (n != 0)
    {
        result = result * 10 + n % 10;
        n /= 10;
    }

    printf("%d", result);

    return 0;
}
