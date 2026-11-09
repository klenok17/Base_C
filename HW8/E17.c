#include <stdio.h>

int main(void) {
    int a[10];
    for (int i = 0; i < 10; i++) scanf("%d", &a[i]);

    int printed = 0;
    for (int i = 0; i < 10; i++) {
        int count = 0;
        for (int j = 0; j < 10; j++)
            if (a[i] == a[j]) count++;
        if (count == 1) {
            if (printed) printf(" ");
            printf("%d", a[i]);
            printed = 1;
        }
    }
    printf("\n");
    return 0;
}
