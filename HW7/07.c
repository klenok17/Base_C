#include <stdio.h>

void print_from_n(int n)
{
    if (n == 0)
        return;

    printf("%d ", n);
    print_from_n(n - 1);
}

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n < 1)
        return 0;

    print_from_n(n);
    printf("\n");
    return 0;
}
