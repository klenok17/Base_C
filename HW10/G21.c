#include <stdio.h>

int main(void) {
    FILE *in = fopen("input.txt", "r");
    if (!in) return 1;
    int ch, stones = 0;
    while ((ch = fgetc(in)) != EOF)
        if (ch == '*') stones++;
    fclose(in);
    int rows = 0, total = 0;
    while (total < stones) {
        rows++;
        total += rows;
    }
    FILE *out = fopen("output.txt", "w");
    if (!out) return 1;
    if (stones == 0 || total != stones) {
        fputs("NO\n", out);
    } else {
        for (int i = 1; i <= rows; i++) {
            for (int j = 0; j < rows - i; j++) fputc(' ', out);
            for (int j = 0; j < i; j++) {
                if (j > 0) fputc(' ', out);
                fputc('*', out);
            }
            fputc('\n', out);
        }
    }
    fclose(out);
    return 0;
}
