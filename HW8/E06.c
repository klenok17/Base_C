#include <stdio.h>

int main(void) {
    int a[12], sum = 0;
    for (int i = 0; i < 12; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    printf("%.2f\n", (double)sum / 12);
    return 0;
}
