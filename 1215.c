//"기러기" 또는 "level" 과 같이 거꾸로 읽어도 앞에서부터 읽은 것과 같은 문장이나 낱말을 회문(回文, palindrome)이라 한다.
//주어진 8x8 평면 글자판에서 가로, 세로를 모두 보아 제시된 길이를 가진 회문의 총 개수를 구하는 문제이다.
//위와 같은 글자판이 주어졌을 때, 길이가 5인 회문은 붉은색 테두리로 표시된 4개가 있으며 따라서 4를 반환하면 된다.

//[제약 사항]
//각 칸의 들어가는 글자는 c언어 char type으로 주어지며 'A', 'B', 'C' 중 하나이다.
//글자 판은 무조건 정사각형으로 주어진다.
//ABA도 회문이며, ABBA도 회문이다.A또한 길이 1짜리 회문이다.
//가로, 세로 각각에 대해서 직선으로만 판단한다.
//즉, 아래 예에서 노란색 경로를 따라가면 길이 7짜리 회문이 되지만 직선이 아니기 때문에 인정되지 않는다.

//[입력]
//각 테스트 케이스의 첫 번째 줄에는 찾아야 하는 회문의 길이가 주어지며, 다음 줄에 테스트 케이스가 주어진다.
//총 10개의 테스트 케이스가 주어진다.

//[출력]
//#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 찾은 회문의 개수를 출력한다.

#include <stdio.h>
#include <string.h>

int main() {
	for (int t = 0; t < 10; t++) {
		int n;
		scanf("%d", &n);
		char board[8][8];
		for (int i = 0; i < 8; i++) {
			char row[8];
			scanf("%s", row);
			for (int j = 0; j < 8; j++) {
				board[i][j] = row[j];
			}
		}

		int cnt = 0;
		char temp[8];
		char tempReverse[8];

		// 가로줄 체크
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8 - n + 1; j++) {
				for (int k = 0; k < n; k++) {
					temp[k] = board[i][j + k];
				}
				temp[n] = '\0';
				for (int k = 0; k < n; k++) {
					tempReverse[k] = temp[n - 1 - k];
				}
				tempReverse[n] = '\0';
				if (strcmp(temp, tempReverse) == 0) {
					cnt += 1;
				}
			}
		}

		// 세로줄 체크
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8 - n + 1; j++) {
				for (int k = 0; k < n; k++) {
					temp[k] = board[j+k][i];
				}
				temp[n] = '\0';
				for (int k = 0; k < n; k++) {
					tempReverse[k] = temp[n - 1 - k];
				}
				tempReverse[n] = '\0';
				if (strcmp(temp, tempReverse) == 0) {
					cnt += 1;
				}
			}
		}

		printf("#%d %d\n", t + 1, cnt);

	}

	return 0;
}