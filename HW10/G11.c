#include <stdio.h>

int main(void) {
    FILE *in = fopen("input.txt", "r");
    if (!in) return 1;
    int ch, last = ' ', count = 0;
    while ((ch = fgetc(in)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\r') {
            if (last == 'a') count++;
        }
        last = ch;
    }
    if (last == 'a') count++;
    fclose(in);
    FILE *out = fopen("output.txt", "w");
    if (!out) return 1;
    fprintf(out, "%d\n", count);
    fclose(out);
    return 0;
}
