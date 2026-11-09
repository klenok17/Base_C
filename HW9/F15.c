#include <stdio.h>

int count_bigger_abs(int n, int a[])
{
    if (n <= 0) return 0;

    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        long long value = a[i];
        if (value < 0) value = -value;
        if (value > (long long)max) count++;
    }
    return count;
}

