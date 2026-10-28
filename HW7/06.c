#include <stdio.h>

void reverse_string(void)
{
    char ch;

    if (scanf("%c", &ch) != 1 || ch == '.')
        return;

    reverse_string();
    printf("%c", ch);
}

int main(void)
{
    reverse_string();
    printf("\n");
    return 0;
}
