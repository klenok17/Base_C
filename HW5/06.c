
/* вариант1 без флага */

#include <stdio.h>

int main(void)
{
    int n;
    int digit;

    scanf("%d", &n);

    digit = n % 10;
    n /= 10;

    while (n != 0)
    {
        if (digit == n % 10)
        {
            printf("YES");
            return 0;
        }

        digit = n % 10;
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
    int digit;
    int flag = 0;

    scanf("%d", &n);

    digit = n % 10;
    n /= 10;

    while (n != 0 && flag == 0)
    {
        if (digit == n % 10)
        {
            flag = 1;
            break;
        }

        digit = n % 10;
        n /= 10;
    }

    if (flag == 1)
        printf("YES");
    else
        printf("NO");

    return 0;
} 
 *  */

