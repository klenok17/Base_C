#include <stdio.h>
#include <string.h>

void remove_extra_spaces(char s[]) {
    int read = 0, write = 0;
    while (s[read] != '\0') {
        if (s[read] != ' ' || (write > 0 && s[write - 1] != ' '))
            s[write++] = s[read];
        read++;
    }
    if (write > 0 && s[write - 1] == ' ') write--;
    s[write] = '\0';
}

int main(void) {
    FILE *in = fopen("input_G18.txt", "r");
    if (!in) return 1;
    char s[1002];
    if (!fgets(s, sizeof(s), in)) { fclose(in); return 1; }
    fclose(in);
    s[strcspn(s, "\r\n")] = '\0';
    remove_extra_spaces(s);
    FILE *out = fopen("output_G18.txt", "w");
    if (!out) return 1;
    fprintf(out, "%s\n", s);
    fclose(out);
    return 0;
}
