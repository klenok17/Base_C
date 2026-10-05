#include <stdio.h>

float sinus(float x)
{
    float sum = 0;
    float term = x;
    int n = 1;

    while (term > 0.001 || term < -0.001)
    {
        sum = sum + term;

        term = -term * x * x / ((2 * n) * (2 * n + 1));

        n++;
    }

    return sum;
}

int main()
{
    float x;

    scanf("%f", &x);

    x = x * 3.1415926 / 180;

    printf("%.3f", sinus(x));

    return 0;
}
