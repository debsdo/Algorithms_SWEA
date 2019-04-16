//양의 정수가 주어질 때, 이 수가 홀수인지 짝수인지 판별하는 프로그램을 작성하라.

//[입력]
//첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
//각 테스트 케이스의 첫 번째 줄에는 100자리 이하의 양의 정수가 주어진다.

//[출력]
//각 테스트 케이스마다 첫 번째 줄에는‘#T’(T는 테스트케이스 번호를 의미하며 1부터 시작한다.)를 출력하고,
//주어진 수가 홀수이면 “Odd”를, 짝수이면 “Even”을 출력한다.

#include <stdio.h>
#include <string.h>

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		char n[101];
		scanf("%s", &n);
		int len = strlen(n);
		printf("#%d ", t + 1);
		if (n[len - 1] % 2 == 0) {
			printf("Even\n");
		}
		else {
			printf("Odd\n");
		}
	}
	return 0;
}