#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *in = fopen("input_G1.txt", "r");
    if (in == NULL) return 1;
    char s[102];
    if (fgets(s, sizeof(s), in) == NULL) { fclose(in); return 1; }
    fclose(in);
    s[strcspn(s, "\r\n")] = '\0';

    FILE *out = fopen("output_G1.txt", "w");
    if (out == NULL) return 1;
    fprintf(out, "%s, %s, %s %zu\n", s, s, s, strlen(s));
    fclose(out);
    return 0;
}
