#include <stdio.h>

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		// N을 입력받는다
		int n;
		scanf("%d", &n);

		int adder = n;
		// 0~9 숫자를 체크할 배열 초기화
		int num[10] = {0, };

		int timer = 0;
		while (1) {
			timer += 1;
			int nBlower = n;
			// 각 자리 숫자를 담을 배열 생성 및 초기화
			int broken[100];
			for (int i = 0; i < 100; i++) {
				broken[i] = 11;
			}

			// 숫자 쪼개기
			int idx = 0;
			while (1) {
				if (nBlower == 0) {
					break;
				}
				broken[idx] = nBlower % 10;
				nBlower /= 10;
				idx += 1;
			}

			for (int i = 0; i < 100; i++) {
				for (int j = 0; j < 10; j++) {
					if (broken[i] == j) {
						num[j] = 1;
					}
				}
			}

			int checker = 0;
			for (int i = 0; i < 10; i++) {
				if (num[i] == 1) {
					checker += 1;
				}
			}

			if (checker == 10) {
				break;
			}
			n += adder;
		}

		printf("#%d %d\n", t+1, timer*adder);
	}
	return 0;
}