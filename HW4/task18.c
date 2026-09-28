#include <stdio.h>

int main(void)
{
    int a, b;

    scanf("%d %d", &a, &b);

    printf("%s", a > b ? "Above" : a < b ? "Less" : "Equal");

    return 0;
}
