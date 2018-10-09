#include <stdio.h>

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		
		int breads = 0;
		int x = 0;
		int y = 0;

		if (a < b) {
			x = c / a;
			y = (c%a) / b;
		}
		else {
			y = c / b;
			x = (c%b) / a;
		}
		breads = x + y;
		printf("#%d %d\n", t + 1, breads);
	}

	return 0;
}