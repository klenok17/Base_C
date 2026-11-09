#include <stdio.h>

int digit_product(int number, int parity)
{
    long long x = number;
    if (x < 0) x = -x;

    int product = 1;
    int found = 0;
    do {
        int digit = x % 10;
        if (digit % 2 == parity) {
            product *= digit;
            found = 1;
        }
        x /= 10;
    } while (x > 0);

    return found ? product : 0;
}

int main(void)
{
    int a[10];
    int even = 0;
    for (int i = 0; i < 10; i++) {
        if (scanf("%d", &a[i]) != 1) return 0;
        if (a[i] % 2 == 0) even++;
    }

    int replace_parity = (even > 5) ? 1 : 0;
    for (int i = 0; i < 10; i++) {
        if ((a[i] % 2 == 0 && replace_parity == 0) ||
            (a[i] % 2 != 0 && replace_parity == 1)) {
            a[i] = digit_product(a[i], replace_parity);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}
