#include <stdio.h>

int main(void) {
    FILE *in = fopen("input_G2.txt", "r");
    if (in == NULL) return 1;
    int n;
    if (fscanf(in, "%d", &n) != 1) { fclose(in); return 1; }
    fclose(in);
    if (n < 0 || n > 26 || n % 2 != 0) return 1;

    char s[27];
    for (int i = 0; i < n / 2; i++) {
        s[2 * i] = (char)('A' + i);
        s[2 * i + 1] = (char)('0' + 2 * (i % 4 + 1));
    }
    s[n] = '\0';
    FILE *out = fopen("output_G2.txt", "w");
    if (out == NULL) return 1;
    fprintf(out, "%s\n", s);
    fclose(out);
    return 0;
}
