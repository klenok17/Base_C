#include <stdio.h>

int main(void) {
    int a[10], positive[10], negative[10];
    int p = 0, n = 0;
    for (int i = 0; i < 10; i++) scanf("%d", &a[i]);

    for (int i = 0; i < 10; i++) {
        if (a[i] > 0) positive[p++] = a[i];
        else if (a[i] < 0) negative[n++] = a[i];
    }

    int printed = 0;
    for (int i = 0; i < p; i++) {
        if (printed) printf(" ");
        printf("%d", positive[i]);
        printed = 1;
    }
    for (int i = 0; i < n; i++) {
        if (printed) printf(" ");
        printf("%d", negative[i]);
        printed = 1;
    }
    printf("\n");
    return 0;
}
