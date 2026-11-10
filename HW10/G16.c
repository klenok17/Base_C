#include <stdio.h>
#include <string.h>

int letter(int c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main(void) {
    FILE *in = fopen("input_G16.txt", "r");
    FILE *out = fopen("output_G16.txt", "w");
    if (!in || !out) {
        if (in) fclose(in);
        if (out) fclose(out);
        return 1;
    }
    char s[1002];
    if (!fgets(s, sizeof(s), in)) { fclose(in); fclose(out); return 1; }
    size_t n = strlen(s);
    for (size_t i = 0; i < n; ) {
        if (i + 4 <= n && strncmp(s + i, "Ling", 4) == 0 &&
            (i == 0 || !letter((unsigned char)s[i-1])) &&
            (i + 4 == n || !letter((unsigned char)s[i+4]))) {
            fputs("Cao", out);
            i += 4;
        } else fputc(s[i++], out);
    }
    fclose(in);
    fclose(out);
    return 0;
}
