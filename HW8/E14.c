#include <stdio.h>

int main(void) {
    int a[10], b[10], count = 0;
    for (int i = 0; i < 10; i++) scanf("%d", &a[i]);

    for (int i = 0; i < 10; i++) {
        int occurrences = 0;
        for (int j = 0; j < 10; j++)
            if (a[j] == a[i]) occurrences++;

        if (occurrences > 1) {
            int exists = 0;
            for (int j = 0; j < count; j++)
                if (b[j] == a[i]) exists = 1;
            if (!exists) b[count++] = a[i];
        }
    }

    for (int i = 0; i < count; i++)
        printf("%d%c", b[i], i == count - 1 ? '\n' : ' ');
    if (count == 0) printf("\n");
    return 0;
}
