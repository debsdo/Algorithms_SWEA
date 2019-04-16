//1부터 주어진 횟수까지 2를 곱한 값(들)을 출력하시오.
//주어질 숫자는 30을 넘지 않는다.

#include <stdio.h>

int main() {
	int time, start = 1;
	scanf("%d", &time);

	printf("%d ", start);

	for (int i = 0; i < time; i++) {
		start *= 2;
		printf("%d ", start);
	}

	return 0;
}