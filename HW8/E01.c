#include <stdio.h>

int main(void) {
    int a[5];
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    printf("%.3f\n", (double)sum / 5);
    return 0;
}
