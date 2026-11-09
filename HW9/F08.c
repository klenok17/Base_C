#include <stdio.h>

int main(void)
{
    int seen[1001] = {0};
    int x;
    int min = 1001;
    int max = 0;

    while (scanf("%d", &x) == 1 && x != 0) {
        seen[x] = 1;
        if (x < min) min = x;
        if (x > max) max = x;
    }

    for (int i = min; i <= max; i++) {
        if (seen[i] == 0) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
