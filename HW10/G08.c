#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

int main(void) {
    FILE *in = fopen("input_G8.txt", "r");
    if (!in) return 1;
    char s[1002];
    if (!fgets(s, sizeof(s), in)) { fclose(in); return 1; }
    fclose(in);
    int values[1001], count = 0;
    for (size_t i = 0; s[i] != '\0'; ) {
        if (isdigit((unsigned char)s[i])) {
            int x = 0;
            while (isdigit((unsigned char)s[i])) {
                int digit = s[i] - '0';
                if (x > (2147483647 - digit) / 10) return 1;
                x = x * 10 + digit;
                i++;
            }
            values[count++] = x;
        } else i++;
    }
    qsort(values, count, sizeof(values[0]), cmp);
    FILE *out = fopen("output_G8.txt", "w");
    if (!out) return 1;
    for (int i = 0; i < count; i++)
        fprintf(out, "%s%d", i ? " " : "", values[i]);
    fputc('\n', out);
    fclose(out);
    return 0;
}
