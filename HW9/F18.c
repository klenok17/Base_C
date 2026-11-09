#include <stdio.h>

int max_in_row(int row[10])
{
    int max = row[0];
    for (int j = 1; j < 10; j++) {
        if (row[j] > max) max = row[j];
    }
    return max;
}

int main(void)
{
    int a[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (scanf("%d", &a[i][j]) != 1) return 0;
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += max_in_row(a[i]);
    }
    printf("%d\n", sum);
    return 0;
}
