#include <stdio.h>

int main(void)
{
    int n;

    scanf("%d", &n);

    for (int i = 10; i <= n; i++)
    {
        int x = i;
        int sum = 0;
        int product = 1;

        while (x != 0)
        {
            sum += x % 10;
            product *= x % 10;
            x /= 10;
        }

        if (sum == product)
            printf("%d ", i);
    }

    return 0;
}
