#include <stdio.h>

int max_find(int max)
{
    int number;

    if (scanf("%d", &number) != 1 || number == 0)
        return max;

    if (number > max)
        max = number;

    return max_find(max);
}

int main(void)
{
    int first;

    if (scanf("%d", &first) != 1 || first == 0)
        return 0;

    printf("%d\n", max_find(first));
    return 0;
}
