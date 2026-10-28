#include <stdio.h>

void to_bin(unsigned int n)
{
    if (n < 2)
    {
        printf("%u", n);
        return;
    }

    to_bin(n / 2);
    printf("%u", n % 2);
}

int main(void)
{
    unsigned int n;

    if (scanf("%u", &n) != 1)
        return 0;

    to_bin(n);
    printf("\n");
    return 0;
}
