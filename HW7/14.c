#include <stdio.h>

void print_odd(void)
{
    int number;

    if (scanf("%d", &number) != 1 || number == 0)
        return;

    if (number % 2 != 0)
        printf("%d ", number);

    print_odd();
}

int main(void)
{
    print_odd();
    printf("\n");
    return 0;
}
