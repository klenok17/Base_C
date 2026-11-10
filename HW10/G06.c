#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrom(const char s[]) {
    size_t n = strlen(s);
    for (size_t i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

int main(void) {
    FILE *in = fopen("input_G6.txt", "r");
    if (!in) return 1;
    char s[1002];
    if (!fgets(s, sizeof(s), in)) { fclose(in); return 1; }
    fclose(in);
    s[strcspn(s, "\r\n")] = '\0';
    FILE *out = fopen("output_G6.txt", "w");
    if (!out) return 1;
    fprintf(out, "%s\n", is_palindrom(s) ? "YES" : "NO");
    fclose(out);
    return 0;
}
