#include <stdio.h>

char code(char c) {
    if (c == 'b' || c == 'f' || c == 'p' || c == 'v') return '1';
    if (c == 'c' || c == 'g' || c == 'j' || c == 'k' ||
        c == 'q' || c == 's' || c == 'x' || c == 'z') return '2';
    if (c == 'd' || c == 't') return '3';
    if (c == 'l') return '4';
    if (c == 'm' || c == 'n') return '5';
    if (c == 'r') return '6';
    return '0';
}

int main(void) {
    FILE *in = fopen("input.txt", "r");
    if (!in) return 1;
    char word[21];
    if (fscanf(in, "%20s", word) != 1) { fclose(in); return 1; }
    fclose(in);
    char result[5] = {word[0], '\0', '\0', '\0', '\0'};
    int pos = 1;
    char previous = '\0';
    for (int i = 1; word[i] != '\0'; i++) {
        char d = code(word[i]);
        if (d == '0') continue;
        if (d != previous) {
            if (pos < 4) result[pos++] = d;
        }
        previous = d;
    }
    while (pos < 4) result[pos++] = '0';
    result[4] = '\0';
    FILE *out = fopen("output.txt", "w");
    if (!out) return 1;
    fprintf(out, "%s\n", result);
    fclose(out);
    return 0;
}
