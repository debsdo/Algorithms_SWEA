//스도쿠는 숫자퍼즐로, 가로 9칸 세로 9칸으로 이루어져 있는 표에 1 부터 9 까지의 숫자를 채워넣는 퍼즐이다.
//같은 줄에 1 에서 9 까지의 숫자를 한번씩만 넣고,
//3 x 3 크기의 작은 격자 또한, 1 에서 9 까지의 숫자가 겹치지 않아야 한다.
//입력으로 9 X 9 크기의 스도쿠 퍼즐의 숫자들이 주어졌을 때,
//위와 같이 겹치는 숫자가 없을 경우, 1을 정답으로 출력하고 그렇지 않을 경우 0 을 출력한다.

//[제약 사항]
//1. 퍼즐은 모두 숫자로 채워진 상태로 주어진다.
//2. 입력으로 주어지는 퍼즐의 모든 숫자는 1 이상 9 이하의 정수이다.

//[입력]
//입력은 첫 줄에 총 테스트 케이스의 개수 T가 온다.
//다음 줄부터 각 테스트 케이스가 주어진다.
//테스트 케이스는 9 x 9 크기의 퍼즐의 데이터이다.

//[출력]
//테스트 케이스 t에 대한 결과는 “#t”을 찍고, 한 칸 띄고, 정답을 출력한다.
//(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

#include <stdio.h>

void bubbleSort(int arr[], int size) {
	int temp;
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return;
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		int flag = 1;
		int temp[9];

		// 스도쿠 생성 및 값 입력
		int sudoku[9][9];
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				scanf("%d", &sudoku[i][j]);
			}
		}

		// 가로 세로 라인 체크
		for (int k = 0; k < 2; k++) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (k == 0) {
						temp[j] = sudoku[i][j];
					}
					else {
						temp[j] = sudoku[j][i];
					}
				}
				bubbleSort(temp, 9);
				for (int j = 0; j < 9; j++) {
					if (temp[j] != j + 1) {
						flag = 0;
					}
				}
			}
		}

		// 블록 체크
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				temp[j] = sudoku[j/3][j % 3];
			}
			bubbleSort(temp, 9);
			for (int j = 0; j < 9; j++) {
				if (temp[j] != j + 1) {
					flag = 0;
				}
			}
		}

		printf("#%d ", t + 1);
		if (flag == 1) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}

	return 0;
}
