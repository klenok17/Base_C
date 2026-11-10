#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *in = fopen("input_G13.txt", "r");
    if (!in) return 1;
    char path[1100];
    if (!fgets(path, sizeof(path), in)) { fclose(in); return 1; }
    fclose(in);
    path[strcspn(path, "\r\n")] = '\0';
    char *slash = strrchr(path, '/');
    char *name = (slash == NULL) ? path : slash + 1;
    char *dot = strrchr(name, '.');
    if (dot != NULL) *dot = '\0';
    FILE *out = fopen("output_G13.txt", "w");
    if (!out) return 1;
    fprintf(out, "%s.html\n", path);
    fclose(out);
    return 0;
}
