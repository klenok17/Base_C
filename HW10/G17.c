#include <stdio.h>
#include <string.h>

void swap_pairs(char s[]) {
    int prev = -1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ' || s[i] == '\n' || s[i] == '\r') continue;
        if (prev == -1) prev = i;
        else {
            char t = s[prev];
            s[prev] = s[i];
            s[i] = t;
            prev = -1;
        }
    }
}

int main(void) {
    FILE *in = fopen("input_G17.txt", "r");
    if (!in) return 1;
    char s[1002];
    if (!fgets(s, sizeof(s), in)) { fclose(in); return 1; }
    fclose(in);
    s[strcspn(s, "\r\n")] = '\0';
    swap_pairs(s);
    FILE *out = fopen("output_G17.txt", "w");
    if (!out) return 1;
    fprintf(out, "%s\n", s);
    fclose(out);
    return 0;
}
