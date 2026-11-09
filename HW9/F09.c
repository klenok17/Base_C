#include <stdio.h>

void swap_negmax_last(int size, int a[])
{
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (a[i] < 0 && (index == -1 || a[i] > a[index])) {
            index = i;
        }
    }
    if (index != -1) {
        int temp = a[index];
        a[index] = a[size - 1];
        a[size - 1] = temp;
    }
}

