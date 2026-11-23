#include <stdio.h>

int main(void) {
    FILE *in = fopen("input.txt", "r");
    if (!in) return 1;
    int lower = 0, upper = 0, ch;
    while ((ch = fgetc(in)) != EOF) {
        if (ch >= 'a' && ch <= 'z') lower++;
        else if (ch >= 'A' && ch <= 'Z') upper++;
    }
    fclose(in);
    FILE *out = fopen("output.txt", "w");
    if (!out) return 1;
    fprintf(out, "%d %d\n", lower, upper);
    fclose(out);
    return 0;
}
