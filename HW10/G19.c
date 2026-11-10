#include <stdio.h>

void make_palindrome(const char s[], char out[]) {
    int freq[26] = {0};
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'a' && s[i] <= 'z') freq[s[i] - 'a']++;
    int k = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < freq[i] / 2; j++) out[k++] = 'a' + i;
    }
    int half = k;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) { out[k++] = 'a' + i; break; }
    }
    for (int i = half - 1; i >= 0; i--) out[k++] = out[i];
    out[k] = '\0';
}

int main(void) {
    FILE *in = fopen("input_G19.txt", "r");
    if (!in) return 1;
    char s[1002], result[1002];
    if (!fgets(s, sizeof(s), in)) { fclose(in); return 1; }
    fclose(in);
    make_palindrome(s, result);
    FILE *out = fopen("output_G19.txt", "w");
    if (!out) return 1;
    fprintf(out, "%s\n", result);
    fclose(out);
    return 0;
}
