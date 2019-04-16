//주어진 숫자만큼 # 을 출력해보세요.
//주어질 숫자는 100, 000 이하다.

#include <stdio.h>

int main() {
	int pn;
	scanf("%d", &pn);
	for (int i = 0; i < pn; i++) {
		printf("#");
	}

	return 0;
}