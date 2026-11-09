#include <stdio.h>

void print_digit(char s[])
{
    int count[10] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            count[s[i] - '0']++;
        }
    }
    for (int digit = 0; digit < 10; digit++) {
        if (count[digit] != 0) {
            printf("%d %d\n", digit, count[digit]);
        }
    }
}

int main(void)
{
    char s[1002];
    if (fgets(s, sizeof(s), stdin) == NULL) return 0;
    print_digit(s);
    return 0;
}
