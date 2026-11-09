#include <stdio.h>

int main(void) {
    int a[10];
    for (int i = 0; i < 10; i++) scanf("%d", &a[i]);

    int first, second;
    if (a[0] >= a[1]) {
        first = a[0];
        second = a[1];
    } else {
        first = a[1];
        second = a[0];
    }

    for (int i = 2; i < 10; i++) {
        if (a[i] >= first) {
            second = first;
            first = a[i];
        } else if (a[i] > second) {
            second = a[i];
        }
    }

    printf("%d\n", first + second);
    return 0;
}
