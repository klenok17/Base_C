#include <stdio.h>

int main(void) {
    int a[10], b[10], count = 0;
    for (int i = 0; i < 10; i++) scanf("%d", &a[i]);

    for (int i = 0; i < 10; i++) {
        if ((a[i] / 10) % 10 == 0) {
            b[count] = a[i];
            count++;
        }
    }

    for (int i = 0; i < count; i++)
        printf("%d%c", b[i], i == count - 1 ? '\n' : ' ');
    if (count == 0) printf("\n");
    return 0;
}
