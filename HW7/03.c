#include <stdio.h>

void print_reverse(int n)
{
    printf("%d ", n % 10);

    if (n >= 10)
        print_reverse(n / 10);
}

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n < 0)
        return 0;

    print_reverse(n);
    printf("\n");
    return 0;
}
