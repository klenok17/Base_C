#include <stdio.h>

int sum(int n)
{
    int s = 0;

    for (int i = 1; i <= n; i++)
        s = s + i;

    return s;
}

int main()
{
    int n;

    scanf("%d", &n);

    printf("%d", sum(n));

    return 0;
}
