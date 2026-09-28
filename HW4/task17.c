#include <stdio.h>

int main(void)
{
    int month;

    scanf("%d", &month);

    if (month == 12 || month <= 2)
    {
        printf("winter");
    }
    else if (month <= 5)
    {
        printf("spring");
    }
    else if (month <= 8)
    {
        printf("summer");
    }
    else
    {
        printf("autumn");
    }

    return 0;
}
