#include <stdio.h>

int main(void) {
    FILE *in = fopen("input_G4.txt", "r");
    if (!in) return 1;
    char a[101], b[101];
    if (fscanf(in, "%100s %100s", a, b) != 2) { fclose(in); return 1; }
    fclose(in);
    int ca[26] = {0}, cb[26] = {0};
    for (int i = 0; a[i] != '\0'; i++) ca[a[i] - 'a']++;
    for (int i = 0; b[i] != '\0'; i++) cb[b[i] - 'a']++;
    FILE *out = fopen("output_G4.txt", "w");
    if (!out) return 1;
    int first = 1;
    for (int i = 0; i < 26; i++) {
        if (ca[i] == 1 && cb[i] == 1) {
            if (!first) fputc(' ', out);
            fputc('a' + i, out);
            first = 0;
        }
    }
    fputc('\n', out);
    fclose(out);
    return 0;
}
