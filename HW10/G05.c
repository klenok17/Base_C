#include <stdio.h>

int main(void) {
    FILE *in = fopen("input_G5.txt", "r");
    FILE *out = fopen("output_G5.txt", "w");
    if (!in || !out) {
        if (in) fclose(in);
        if (out) fclose(out);
        return 1;
    }
    int ch;
    while ((ch = fgetc(in)) != EOF) {
        if (ch == 'a') ch = 'b';
        else if (ch == 'b') ch = 'a';
        else if (ch == 'A') ch = 'B';
        else if (ch == 'B') ch = 'A';
        fputc(ch, out);
    }
    fclose(in);
    fclose(out);
    return 0;
}
 
