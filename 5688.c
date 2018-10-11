//양의 정수 N에 대해 N = X3가 되는 양의 정수X 를 구하여라.

//[입력]
//첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
//각 테스트 케이스의 첫 번째 줄에는 하나의 정수 N(1≤N≤1018) 이 주어진다.

//[출력]
//각 테스트 케이스마다 첫 번째 줄에는‘#T’(T는 테스트케이스 번호를 의미하며 1부터 시작한다.)를 출력하고,
//N = X3가 되는 양의 정수 X를 출력한다.
//만약 이런 X가 존재하지 않으면 - 1을 출력한다.

#include <stdio.h>
#include <math.h>

int main() {
	int tc;
	scanf("%d", &tc);

	static long long troots[1000000];
	for (long long i = 0; i < 1000000; i++) {
		troots[i] = (i + 1)*(i + 1)*(i + 1);
	}

	for (int t = 0; t < tc; t++) {
		long long n;
		scanf("%lld", &n);
		int flag = 0;
		for (long long i = 0; i < 1000000; i++) {
			if (troots[i] == n) {
				flag = 1;
				printf("#%d %lld\n", t + 1, i + 1);
				break;
			}
		}
		if (flag == 0) {
			printf("#%d -1\n", t + 1);
		}
	}
	return 0;
}