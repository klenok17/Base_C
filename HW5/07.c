
/* вариант1 без флага */

#include <stdio.h>

int main(void)
{
    int n;

    scanf("%d", &n);

    while (n != 0)
    {
        int digit = n % 10;
        int m = n / 10;

        while (m != 0)
        {
            if (digit == m % 10)
            {
                printf("YES");
                return 0;
            }

            m /= 10;
        }

        n /= 10;
    }

    printf("NO");

    return 0;
}

/* вариант 2 с флагом
 * 
#include <stdio.h>

int main(void)
{
    int n;
    int flag = 0;

    scanf("%d", &n);

    while (n != 0 && flag == 0)
    {
        int digit = n % 10;
        int m = n / 10;

        while (m != 0)
        {
            if (digit == m % 10)
            {
                flag = 1;
                break;
            }

            m /= 10;
        }

        n /= 10;
    }

    if (flag == 1)
        printf("YES");
    else
        printf("NO");

    return 0;
}
 *  */

