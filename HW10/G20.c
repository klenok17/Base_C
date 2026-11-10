#include <stdio.h>
#include <stdbool.h>

bool is_palindrom(const char s[]) {
    int freq[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') freq[s[i] - 'a']++;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] % 2 != 0) odd++;
    return odd <= 1;
}

int main(void) {
    FILE *in = fopen("input_G20.txt", "r");
    if (!in) return 1;
    char s[1002];
    if (!fgets(s, sizeof(s), in)) { fclose(in); return 1; }
    fclose(in);
    printf("%s\n", is_palindrom(s) ? "YES" : "NO");
    return 0;
}
