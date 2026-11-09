#include <stdio.h>

void print_min_sum_pair(int a[])
{
    int first = 0;
    int second = 1;
    long long min_sum = (long long)a[0] + a[1];

    for (int i = 0; i < 30; i++) {
        for (int j = i + 1; j < 30; j++) {
            long long sum = (long long)a[i] + a[j];
            if (sum < min_sum) {
                min_sum = sum;
                first = i;
                second = j;
            }
        }
    }
    printf("%d %d\n", first, second);
}

int main(void)
{
    int a[30];
    for (int i = 0; i < 30; i++) {
        if (scanf("%d", &a[i]) != 1) return 0;
    }
    print_min_sum_pair(a);
    return 0;
}
