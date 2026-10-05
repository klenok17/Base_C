/* вариант 1*/

#include <stdio.h>

int main(void)
{
    int n;

    scanf("%d", &n);

    while (n != 0)
    {
        if ((n % 10) % 2 != 0)
        {
            printf("NO");
            return 0;
        }

        n /= 10;
    }

    printf("YES");

    return 0;
}

/* 
 * вариант 1
#include <stdio.h>

int main(void)
{
    int n, digit;

    scanf("%d", &n);

    while (n != 0)
    {
        digit = n % 10;

        if (digit % 2 != 0)
        {
            printf("NO");
            return 0;
        }

        n /= 10;
    }

    printf("YES");

    return 0;
}
 * */
