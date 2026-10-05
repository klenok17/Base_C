#include <stdio.h>

int digit_to_num(char c)
{
    return c - '0';
}

int main()
{
    char c;
    int sum = 0;

    scanf("%c", &c);

    while (c != '.')
    {
        if (c >= '0' && c <= '9')
            sum = sum + digit_to_num(c);

        scanf("%c", &c);
    }

    printf("%d", sum);

    return 0;
}
