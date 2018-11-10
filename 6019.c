#include <stdio.h>

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		int d, a, b, f;
		scanf("%d%d%d%d", &d, &a, &b, &f);

		double x = d / (a + b);

		printf("#%d %lf\n", t + 1, (double)f*x);

	}

	return 0;
}