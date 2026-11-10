#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *in = fopen("input_G10.txt", "r");
    if (!in) return 1;
    char s[1002];
    if (!fgets(s, sizeof(s), in)) { fclose(in); return 1; }
    fclose(in);
    int bestStart = 0, bestLen = 0;
    for (int i = 0; s[i] != '\0' && s[i] != '\n'; ) {
        if (s[i] == ' ') { i++; continue; }
        int start = i;
        while (s[i] != '\0' && s[i] != '\n' && s[i] != ' ') i++;
        int len = i - start;
        if (len > bestLen) { bestLen = len; bestStart = start; }
    }
    FILE *out = fopen("output_G10.txt", "w");
    if (!out) return 1;
    fprintf(out, "%.*s\n", bestLen, s + bestStart);
    fclose(out);
    return 0;
}
