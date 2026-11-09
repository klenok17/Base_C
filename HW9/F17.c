#include <stdio.h>

int trace_5x5(int a[5][5])
{
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += a[i][i];
    }
    return sum;
}

int main(void)
{
    int a[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (scanf("%d", &a[i][j]) != 1) return 0;
        }
    }
    printf("%d\n", trace_5x5(a));
    return 0;
}
