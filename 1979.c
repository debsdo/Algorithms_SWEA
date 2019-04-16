//N X N 크기의 단어 퍼즐을 만들려고 한다.입력으로 단어 퍼즐의 모양이 주어진다.
//주어진 퍼즐 모양에서 특정 길이 K를 갖는 단어가 들어갈 수 있는 자리의 수를 출력하는 프로그램을 작성하라.

//[예제]
//N = 5, K = 3 이고, 퍼즐의 모양이 아래 그림과 같이 주어졌을 때
//길이가 3 인 단어가 들어갈 수 있는 자리는 2 곳(가로 1번, 가로 4번)이 된다.

//[제약 사항]
//1. N은 5 이상 15 이하의 정수이다. (5 ≤ N ≤ 15)
//2. K는 2 이상 N 이하의 정수이다. (2 ≤ K ≤ N)

//[입력]
//입력은 첫 줄에 총 테스트 케이스의 개수 T가 온다.
//다음 줄부터 각 테스트 케이스가 주어진다.
//테스트 케이스의 첫 번째 줄에는 단어 퍼즐의 가로, 세로 길이 N 과, 단어의 길이 K 가 주어진다.
//테스트 케이스의 두 번째 줄부터 퍼즐의 모양이 2차원 정보로 주어진다.
//퍼즐의 각 셀 중, 흰색 부분은 1, 검은색 부분은 0 으로 주어진다.

//[출력]
//테스트 케이스 t에 대한 결과는 “#t”을 찍고, 한 칸 띄고, 정답을 출력한다.
//(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

#include <stdio.h>
#include <malloc.h>

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		int n, k;
		scanf("%d %d", &n, &k);
		
		// 2차원 배열 공간 할당
		char** array;
		array = (char**)malloc(sizeof(char*)*n);
		for (int i = 0; i < n; i++) {
			array[i] = (char*)malloc(sizeof(char)*n);
		}

		// 2차원 배열 값 입력
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &array[i][j]);
			}
		}

		int checker = 0, counter = 0, flag = 1;

		// 가로줄 체크
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (array[i][j] == 1) {
					checker += 1;
				}
				else {
					if (checker == k) {
						counter += 1;
					}
					checker = 0;
				}
			}
			if (checker == k) {
				counter += 1;
			}
			checker = 0;
		}

		// 세로줄 체크
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {
				if (array[i][j] == 1) {
					checker += 1;
				}
				else {
					if (checker == k) {
						counter += 1;
					}
					checker = 0;
				}
			}
			if (checker == k) {
				counter += 1;
			}
			checker = 0;
		}

		printf("#%d %d\n", t+1, counter);

		free(array);
	}
	
	return 0;
}