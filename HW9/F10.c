#include <stdio.h>

int main(void)
{
    char s[1002];
    if (scanf("%1001s", s) != 1) {
        return 0;
    }

    for (int i = 0; s[i] != '.' && s[i] != '\0'; ) {
        char letter = s[i];
        int count = 0;
        while (s[i] == letter) {
            count++;
            i++;
        }
        printf("%c%d", letter, count);
    }
    printf("\n");
    return 0;
}
