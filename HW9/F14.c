#include <stdio.h>

int sum_between_ab(int from, int to, int size, int a[])
{
    if (from > to) {
        int temp = from;
        from = to;
        to = temp;
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] >= from && a[i] <= to) {
            sum += a[i];
        }
    }
    return sum;
}

