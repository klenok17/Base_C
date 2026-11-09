#include <stdio.h>

int main(void) {
    int a[12];
    for (int i = 0; i < 12; i++) scanf("%d", &a[i]);

    for (int part = 0; part < 3; part++) {
        int start = part * 4;
        for (int i = 0; i < 2; i++) {
            int temp = a[start + i];
            a[start + i] = a[start + 3 - i];
            a[start + 3 - i] = temp;
        }
    }

    for (int i = 0; i < 12; i++) printf("%d%c", a[i], i == 11 ? '\n' : ' ');
    return 0;
}
