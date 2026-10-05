#include <stdio.h>

float cosinus(float x)
{
    float sum = 0;
    float term = 1;
    int n = 1;

    while (term > 0.001 || term < -0.001)
    {
        sum = sum + term;

        term = -term * x * x / ((2 * n - 1) * (2 * n));

        n++;
    }

    return sum;
}

int main()
{
    float x;

    scanf("%f", &x);

    x = x * 3.1415926 / 180;

    printf("%.3f", cosinus(x));

    return 0;
}
