#include <stdio.h>

int recurs_power(int n, int p)
{
    if (p == 0)
        return 1;

    return n * recurs_power(n, p - 1);
}

int main(void)
{
    int n, p;

    if (scanf("%d %d", &n, &p) != 2)
        return 0;

    if (n < -100 || n > 100 || p < 0 || p > 100)
        return 0;

    printf("%d\n", recurs_power(n, p));
    return 0;
}



//#include <stdio.h>

//void multiply_digits(int digits[], int *length, int factor)
//{
    //int carry = 0;

    //for (int i = 0; i < *length; i++)
    //{
        //int value = digits[i] * factor + carry;
        //digits[i] = value % 10;
        //carry = value / 10;
    //}

    //while (carry > 0)
    //{
        //digits[*length] = carry % 10;
        //(*length)++;
        //carry /= 10;
    //}
//}

//void power_digits(int base, int p, int digits[], int *length)
//{
    //if (p == 0)
    //{
        //digits[0] = 1;
        //*length = 1;
        //return;
    //}

    //power_digits(base, p - 1, digits, length);
    //multiply_digits(digits, length, base);
//}

//int main(void)
//{
    //int n, p;
    //int digits[201];
    //int length;

    //if (scanf("%d %d", &n, &p) != 2)
        //return 0;

    //if (n < -100 || n > 100 || p < 0 || p > 100)
        //return 0;

    //int base = n < 0 ? -n : n;
    //power_digits(base, p, digits, &length);

    //if (n < 0 && p % 2 != 0)
        //printf("-");

    //for (int i = length - 1; i >= 0; i--)
        //printf("%d", digits[i]);

    //printf("\n");
    //return 0;
//}
