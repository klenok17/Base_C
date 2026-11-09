#include <stdio.h>

int main(void) {
    int a[10], sum = 0;
    for (int i = 0; i < 10; i++) scanf("%d", &a[i]);

    for (int i = 0; i < 10; i++) {
        if (a[i] > 0) sum += a[i];
    }

    printf("%d\n", sum);
    return 0;
}
