#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *in = fopen("input_G3.txt", "r");
    if (!in) return 1;
    char s[1002];
    if (!fgets(s, sizeof(s), in)) { fclose(in); return 1; }
    fclose(in);
    s[strcspn(s, "\r\n")] = '\0';
    size_t n = strlen(s);
    FILE *out = fopen("output_G3.txt", "w");
    if (!out) return 1;
    if (n > 0) {
        int first = 1;
        for (size_t i = 0; i + 1 < n; i++) {
            if (s[i] == s[n - 1]) {
                if (!first) fputc(' ', out);
                fprintf(out, "%zu", i);
                first = 0;
            }
        }
    }
    fputc('\n', out);
    fclose(out);
    return 0;
}
