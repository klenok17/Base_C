#include <stdio.h>

int main(void) {
    int a[12], last[4];
    for (int i = 0; i < 12; i++) scanf("%d", &a[i]);

    for (int i = 0; i < 4; i++) last[i] = a[8 + i];
    for (int i = 11; i >= 4; i--) a[i] = a[i - 4];
    for (int i = 0; i < 4; i++) a[i] = last[i];

    for (int i = 0; i < 12; i++) printf("%d%c", a[i], i == 11 ? '\n' : ' ');
    return 0;
}
