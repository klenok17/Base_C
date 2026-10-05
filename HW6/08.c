#include <stdio.h>

char upper(char c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 'a' + 'A';

    return c;
}

int main()
{
    char c;

    scanf("%c", &c);

    while (c != '.')
    {
        printf("%c", upper(c));
        scanf("%c", &c);
    }

    return 0;
}
