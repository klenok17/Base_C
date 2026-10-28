#include <stdio.h>

int acounter(void)
{
    char ch;

    if (scanf("%c", &ch) != 1 || ch == '.')
        return 0;

    if (ch == 'a')
        return 1 + acounter();

    return acounter();
}

int main(void)
{
    printf("%d\n", acounter());
    return 0;
}
