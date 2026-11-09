#include <stdio.h>

int main(void) {
    unsigned int n;
    int digits[10];
    int count = 0;
    
    scanf("%u", &n);

    while (n > 0) {
		digits[count] = n % 10;
		count++;
		n /= 10;
	}
	for (int i = count - 1; i >= 0; i--) {
		printf("%u", digits[i]);
        if (i > 0) {
			printf(" ");
        }
	}
    printf("\n");
    return 0;
}
