#include <stdio.h>

int main(void) {
    int a[10];
    for (int i = 0; i < 10; i++) scanf("%d", &a[i]);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            int d1 = a[j] % 10;
            int d2 = a[j + 1] % 10;
            if (d1 < 0) d1 = -d1;
            if (d2 < 0) d2 = -d2;
            if (d1 > d2) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++) printf("%d%c", a[i], i == 9 ? '\n' : ' ');
    return 0;
}
