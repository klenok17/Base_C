#include <stdio.h>

void print_to_n(int n)
{
    if (n == 0)
        return;

    print_to_n(n - 1);
    printf("%d ", n);
}

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n < 1)
        return 0;

    print_to_n(n);
    printf("\n");
    return 0;
}
