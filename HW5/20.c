/* Вариант 1 - проверка до делителей n-1 */

#include <stdio.h>

int main(void)
{
    int n;
    int i;

    scanf("%d", &n);

    if (n < 2)
    {
        printf("NO");
        return 0;
    }

    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            printf("NO");
            return 0;
        }
    }

    printf("YES");

    return 0;
}

/* Вариант 2 - проверка до квадратного корня
#include <stdio.h>

int main(void)
{
    int n;

    scanf("%d", &n);

    if (n < 2)
    {
        printf("NO");
        return 0;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            printf("NO");
            return 0;
        }
    }

    printf("YES");

    return 0;
} 
 */
