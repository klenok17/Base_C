#include <stdio.h>

double diagonal_average(int a[5][5])
{
    double sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += a[i][i];
    }
    return sum / 5;
}

int main(void)
{
    int a[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (scanf("%d", &a[i][j]) != 1) return 0;
        }
    }

    double avg = diagonal_average(a);
    int count = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (a[i][j] > 0 && a[i][j] > avg) {
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
