#include <stdio.h>

int main(void) {
    int n;
    int count[8] = {0};
    
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
         for (int j = 2; j <= 9; j++) {
            if (i % j == 0) {
				count[j - 2]++;
            }
         }
    }
    for (int j = 2; j <= 9; j++) {
		printf("%d %d\n", j, count[j-2]);
	}
    return 0;
}
