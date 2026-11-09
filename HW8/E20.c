#include <stdio.h>

int main(void) {
    unsigned int n;
    scanf("%u", &n);

    int count[10] = {0};
    do {
        count[n % 10]++;
        n /= 10;
    } while (n > 0);

    for (int digit = 9; digit >= 0; digit--) {
        for (int i = 0; i < count[digit]; i++)
            printf("%d", digit);
    }
    printf("\n");
    return 0;
}
