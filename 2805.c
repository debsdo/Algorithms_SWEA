#include <stdio.h>
#include <malloc.h>

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		int n;
		scanf("%d", &n);
		
		// 보드 생성
		int **board;
		board = (int**)malloc(sizeof(int*)*n);
		for (int i = 0; i < n; i++) {
			board[i] = (int*)malloc(sizeof(int)*n);
		}
		
		// 보드값 입력
		char temp[50];
		for (int i = 0; i < n; i++) {
			scanf("%s", temp);
			for (int j = 0; j < n; j++) {
				board[i][j] = (int)temp[j] - '0';
			}
		}

		int idx = n / 2;
		int benefit = 0;
		int row = 0;
		int cnt = 1;

		if (n == 1) {
			benefit += board[0][0];
		}
		else {
			while (1) {
				int col = idx;
				for (int i = 0; i < cnt; i++) {
					benefit += board[row][col];
					col += 1;
				}
				if (cnt == n) {
					break;
				}
				else {
					row += 1;
					cnt += 2;
					idx -= 1;
				}
			}
			while (1) {
				row += 1;
				cnt -= 2;
				idx += 1;
				int col = idx;
				for (int i = 0; i < cnt; i++) {
					benefit += board[row][col];
					col += 1;
				}
				if (cnt == 1) {
					break;
				}
			}
		}
		printf("#%d %d\n", t + 1, benefit);
	}
	return 0;
}