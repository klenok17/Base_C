#include <stdio.h>

int main(void) {
    FILE *in = fopen("input_G12.txt", "r");
    FILE *out = fopen("output_G12.txt", "w");
    if (!in || !out) {
        if (in) fclose(in);
        if (out) fclose(out);
        return 1;
    }
    int ch, inWord = 0;
    while ((ch = fgetc(in)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\r') {
            if (inWord) fputc('\n', out);
            inWord = 0;
        } else {
            fputc(ch, out);
            inWord = 1;
        }
    }
    if (inWord) fputc('\n', out);
    fclose(in);
    fclose(out);
    return 0;
}
