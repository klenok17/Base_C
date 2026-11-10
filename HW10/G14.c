#include <stdio.h>

int main(void) {
    FILE *in = fopen("input_G14.txt", "r");
    if (!in) return 1;
    char last[101], first[101], middle[101];
    if (fscanf(in, "%100s %100s %100s", last, first, middle) != 3) {
        fclose(in);
        return 1;
    }
    fclose(in);
    FILE *out = fopen("output_G14.txt", "w");
    if (!out) return 1;
    fprintf(out, "Hello, %s %s!\n", first, last);
    fclose(out);
    return 0;
}
