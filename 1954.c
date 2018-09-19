// 달팽이는 1부터 N*N까지의 숫자가 시계방향으로 이루어져 있다.
// 다음과 같이 정수 N을 입력 받아 N크기의 달팽이를 출력하시오.

// [예제]
// N이 3일 경우,
// N이 4일 경우,

// [제약사항]
// 달팽이의 크기 N은 1 이상 10 이하의 정수이다. (1 ≤ N ≤ 10)

// [입력]
// 가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
// 각 테스트 케이스에는 N이 주어진다.
// [출력]
// 각 줄은 '#t'로 시작하고, 다음 줄부터 빈칸을 사이에 두고 달팽이 숫자를 출력한다.
// (t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

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

		int num = 0, row = 0, col = -1, cnt = n;
		// right down left up
		int way[4] = { 1,0,0,0 };

		for (int k = 0; k < n - 1; k++) {
			for (int i = 0; i < cnt; i++) {
				if (way[0] == 1) {
					col += 1;
				}
				else if (way[1] == 1) {
					row += 1;
				}
				else if (way[2] == 1) {
					col -= 1;
				}
				else if (way[3] == 1) {
					row -= 1;
				}
				num += 1;
				snail[row][col] = num;
			}

			if (way[0] == 1) {
				way[0] = 0;
				way[1] = 1;
			}
			else if (way[1] == 1) {
				way[1] = 0;
				way[2] = 1;
			}
			else if (way[2] == 1) {
				way[2] = 0;
				way[3] = 1;
			}
			else if (way[3] == 1) {
				way[3] = 0;
				way[0] = 1;
			}

			for (int i = 0; i < cnt - 1; i++) {
				if (way[0] == 1) {
					col += 1;
				}
				else if (way[1] == 1) {
					row += 1;
				}
				else if (way[2] == 1) {
					col -= 1;
				}
				else if (way[3] == 1) {
					row -= 1;
				}
				num += 1;
				snail[row][col] = num;
			}

			if (way[0] == 1) {
				way[0] = 0;
				way[1] = 1;
			}
			else if (way[1] == 1) {
				way[1] = 0;
				way[2] = 1;
			}
			else if (way[2] == 1) {
				way[2] = 0;
				way[3] = 1;
			}
			else if (way[3] == 1) {
				way[3] = 0;
				way[0] = 1;
			}
			cnt -= 1;
		}

		if (way[0] == 1) {
			col += 1;
		}
		else if (way[1] == 1) {
			row += 1;
		}
		else if (way[2] == 1) {
			col -= 1;
		}
		else if (way[3] == 1) {
			row -= 1;
		}
		num += 1;
		snail[row][col] = num;

		printf("#%d\n", t + 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", snail[i][j]);
			}
			printf("\n");
		}
		free(snail);
	}
	return 0;
}