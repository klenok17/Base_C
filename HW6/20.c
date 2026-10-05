#include <stdio.h>

int main()
{
    char c;
    int balance = 0;
    int flag = 1;

    scanf("%c", &c);

    while (c != '.')
    {
        if (c == '(')
            balance++;
        else if (c == ')')
        {
            balance--;

            if (balance < 0)
                flag = 0;
        }

        scanf("%c", &c);
    }

    if (balance != 0)
        flag = 0;

    if (flag)
        printf("YES");
    else
        printf("NO");

    return 0;
}
