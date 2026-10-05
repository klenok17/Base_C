/* вариант 1 */

#include <stdio.h>

int main(void)
{
    int n;
    int digit;
    int even = 0;
    int odd = 0;

    scanf("%d", &n);

    while (n != 0)
    {
        digit = n % 10;

        if (digit % 2 == 0)
            even++;
        else
            odd++;

        n /= 10;
    }

    printf("%d %d", even, odd);

    return 0;
}

/* вариант 2 с обработкой нуля
 #include <stdio.h>

int main(void)
{
    int n;
    int digit;
    int even = 0;
    int odd = 0;

    scanf("%d", &n);

    if (n == 0)
        even = 1;

    while (n != 0)
    {
        digit = n % 10;

        if (digit % 2 == 0)
            even++;
        else
            odd++;

        n /= 10;
    }

    printf("%d %d", even, odd);

    return 0;
} 
   */
