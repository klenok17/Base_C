#include <stdio.h>

int main(void)
{
    int n;
    int sum = 0;

    scanf("%d", &n);

    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }

    if (sum == 10)
        printf("YES");
    else
        printf("NO");

    return 0;
}
