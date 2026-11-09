#include <stdio.h>

int compression(int a[], int b[], int N)
{
    if (N <= 0) {
        return 0;
    }

    int k = 0;
    int current = 0;
    int count = 0;

    if (a[0] == 1) {
        b[k++] = 0;
        current = 1;
    }

    for (int i = 0; i < N; i++) {
        if (a[i] == current) {
            count++;
        } else {
            b[k++] = count;
            current = a[i];
            count = 1;
        }
    }
    b[k++] = count;
    return k;
}
