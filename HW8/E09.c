#include <stdio.h>

int main(void) {
    int a[10];
    for (int i = 0; i < 10; i++) scanf("%d", &a[i]);

    int last = a[9];
    for (int i = 9; i > 0; i--) a[i] = a[i - 1];
    a[0] = last;

    for (int i = 0; i < 10; i++) printf("%d%c", a[i], i == 9 ? '\n' : ' ');
    return 0;
}
