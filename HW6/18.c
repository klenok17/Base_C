#include <stdio.h>

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

int main()
{
    char c;
    int count = 0;

    scanf("%c", &c);

    while (c != '.')
    {
        if (is_digit(c))
            count++;

        scanf("%c", &c);
    }

    printf("%d", count);

    return 0;
}
