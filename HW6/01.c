#include <stdio.h>

int abs_number(int x)
{
    if (x < 0)
        x = -x;

    return x;
}

int main()
{
    int a;

    scanf("%d", &a);

    printf("%d", abs_number(a));

    return 0;
}
