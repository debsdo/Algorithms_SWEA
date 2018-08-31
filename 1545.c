//주어진 숫자부터 0까지 순서대로 찍어보세요
//아래는 입력된 숫자가 N일 때 거꾸로 출력하는 예시입니다

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = n; i >= 0; i--) {
		printf("%d ", i);
	}
	return 0;
}