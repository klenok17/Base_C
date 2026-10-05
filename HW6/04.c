#include <stdio.h>

int f(int x)
{
    if (x < -2)
        return 4;
    else if (x < 2)
        return x * x;
    else
        return x * x + 4 * x + 5;
}

int main()
{
    int x;
    int value;
    int max = 0;

    scanf("%d", &x);

    while (x != 0)
    {
        value = f(x);

        if (value > max)
            max = value;

        scanf("%d", &x);
    }

    printf("%d", max);

    return 0;
}
