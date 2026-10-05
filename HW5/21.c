#include <stdio.h>

int main(void)
{
    char c;

    scanf("%c", &c);

    while (c != '.')
    {
        if (c >= 'A' && c <= 'Z')
            c = c + ('a' - 'A');

        printf("%c", c);

        scanf("%c", &c);
    }

    return 0;
}
