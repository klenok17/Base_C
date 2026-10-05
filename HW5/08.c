#include <stdio.h>

int main(void)
{
    int n;
    int count = 0;

    scanf("%d", &n);

    while (n != 0)
    {
        if (n % 10 == 9)
            count++;

        n /= 10;
    }

    if (count == 1)
        printf("YES");
    else
        printf("NO");

    return 0;
}
