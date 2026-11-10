#include <stdio.h>

int main(void) {
    FILE *in = fopen("input_G9.txt", "r");
    FILE *out = fopen("output_G9.txt", "w");
    if (!in || !out) {
        if (in) fclose(in);
        if (out) fclose(out);
        return 1;
    }
    int seen[256] = {0}, ch;
    while ((ch = fgetc(in)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\r') continue;
        if (!seen[(unsigned char)ch]) {
            fputc(ch, out);
            seen[(unsigned char)ch] = 1;
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}
