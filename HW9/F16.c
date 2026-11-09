#include <stdio.h>

int main(void)
{
    char column, row;
    if (scanf(" %c%c", &column, &row) != 2) return 0;

    int x = column - 'A';
    int y = row - '1';
    if ((x + y) % 2 == 0) {
        printf("BLACK\n");
    } else {
        printf("WHITE\n");
    }
    return 0;
}
