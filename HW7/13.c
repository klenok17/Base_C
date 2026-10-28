#include <stdio.h>

void print_div(int n, int delitel)
{
    if (n == 1)
        return;

    if (delitel > n / delitel)
    {
        printf("%d ", n);
        return;
    }

    if (n % delitel == 0)
    {
        printf("%d ", delitel);
        print_div(n / delitel, delitel);
    }
    else
    {
        print_div(n, delitel + 1);
    }
}

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n < 1)
        return 0;

    print_div(n, 2);
    printf("\n");
    return 0;
}
