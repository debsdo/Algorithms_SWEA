#include <stdio.h>

int main() {
	int tc, i, k, sum, num;
	scanf("%d", &tc);

	for (i = 0; i < tc; i++) {
		sum = 0;

		for (k = 0; k < 10; k++) {
			scanf("%d", &num);

			if (num % 2 != 0) {
				sum += num;
			}
		}

		printf("#%d %d\n", i + 1, sum);
	}

	return 0;
}