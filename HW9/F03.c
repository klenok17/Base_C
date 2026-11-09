#include <stdio.h>

void print_number_digits(char number[])
{
    int count[10] = {0};
    for (int i = 0; number[i] != '\0'; i++) {
        int digit = number[i] - '0';
        count[digit]++;
    }
    for (int digit = 0; digit < 10; digit++) {
        if (count[digit] > 0) {
            printf("%d %d\n", digit, count[digit]);
        }
    }
}

int main(void)
{
    char number[1001];
    if (scanf("%1000s", number) == 1) {
        print_number_digits(number);
    }
    return 0;
}
