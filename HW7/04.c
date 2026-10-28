#include <stdio.h>

void print_num(int num)
{
    if (num >= 10)
        print_num(num / 10);

    printf("%d ", num % 10);
}

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n < 0)
        return 0;

    print_num(n);
    printf("\n");
    return 0;
}
