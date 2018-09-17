#include <stdio.h>

int main() {
	char* bishops[3] = { "D5", "G2", "A3" };
	int board[8][8] = { 0, };
	int answer = 0;

	for (int t = 0; t < 3; t++) {
		// 좌상향 대각선
		int row = bishops[t][1] - 49;
		int col = bishops[t][0] - 65;
		for (int i = 0; i < 8; i++) {
			board[row][col] = 1;
			row -= 1;
			col -= 1;
			if (row < 0 || col < 0) {
				break;
			}
		}

		//우하향 대각선
		row = bishops[t][1] - 49;
		col = bishops[t][0] - 65;
		for (int i = 0; i < 8; i++) {
			board[row][col] = 1;
			row += 1;
			col += 1;
			if (row > 7 || col > 7) {
				break;
			}
		}

		//우상향 대각선
		row = bishops[t][1] - 49;
		col = bishops[t][0] - 65;
		for (int i = 0; i < 8; i++) {
			board[row][col] = 1;
			row -= 1;
			col += 1;
			if (row < 0 || col>7) {
				break;
			}
		}

		//좌하향 대각선
		row = bishops[t][1] - 49;
		col = bishops[t][0] - 65;
		for (int i = 0; i < 8; i++) {
			board[row][col] = 1;
			row += 1;
			col -= 1;
			if (row > 7 || col < 0) {
				break;
			}
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == 0) {
				answer += 1;
			}
		}
	}

	printf("%d\n", answer);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}

	return 0;
}