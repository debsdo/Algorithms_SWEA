#include <stdio.h>
#include <malloc.h>

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		int n;
		scanf("%d", &n);

		// 달팽이 공간 할당
		int **snail;
		snail = (int**)malloc(sizeof(int*)*n);
		for (int i = 0; i < n+1; i++) {
			snail[i] = (int*)malloc(sizeof(int)*n);
		}

		// 달팽이 초기화 n*n
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				snail[i][j] = 0;
			}
		}

		int num = 0, row = 0, col = -1;
		int right = 1, down = 0, left = 0, up = 0;

		while (num < n*n) {
			num += 1;
			
			if (right) {
				col += 1;
			}
			else if (down) {
				row += 1;
			}
			else if (left) {
				col -= 1;
			}
			else if (up) {
				row -= 1;
			}

			if (snail[row][col] == 0) {
				snail[row][col] = num;
			}
			else {
				if (right) {
					right = 0;
					down = 1;
					num -= 1;
					col -= 1;
				}
				else if (down) {
					down = 0;
					left = 1;
					num -= 1;
					row -= 1;
				}
				else if (left) {
					left = 0;
					up = 1;
					num -= 1;
					col += 1;
				}
				else if (up) {
					up = 0;
					right = 1;
					num -= 1;
					row += 1;
				}
			}
		}

		printf("#%d\n", t + 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", snail[i][j]);
			}
			printf("\n");
		}

		for (int i = 0; i < n+1; i++) {
			free(snail[i]);
		}
		free(snail);
	}

	return 0;
}
