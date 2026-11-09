#include <stdio.h>

int main(void) {
    int a[10];
    for (int i = 0; i < 10; i++) scanf("%d", &a[i]);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j]; a[j] = a[j + 1]; a[j + 1] = temp;
            }
            if (a[5 + j] < a[6 + j]) {
                int temp = a[5 + j]; a[5 + j] = a[6 + j]; a[6 + j] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++) printf("%d%c", a[i], i == 9 ? '\n' : ' ');
    return 0;
}
