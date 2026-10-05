#include <stdio.h>

int main(void)
{
    int a, b, r;

    scanf("%d %d", &a, &b);

    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    printf("%d", a);

    return 0;
}
