#include <stdio.h>

void print_sequence(int n, int k, int left)
{
    if (n == 0)
        return;

    printf("%d ", k);

    if (left > 1)
        print_sequence(n - 1, k, left - 1);
    else
        print_sequence(n - 1, k + 1, k + 1);
}

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n < 1)
        return 0;

    print_sequence(n, 1, 1);
    printf("\n");
    return 0;
}
