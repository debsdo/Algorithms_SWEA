//삼성 1:1 프로그래밍 리그의 시즌이 끝났다.앨리스는 B전 A승, 밥은 D전 C승이다.누구의 승률이 더 높은가 ?

//[입력]
//첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
//각 테스트 케이스의 첫 번째 줄에는 네 자연수 A, B, C, D(1 ≤ A ≤ B ≤ 100, 1 ≤ C ≤ D ≤ 100)이 공백로 구분되어 주어진다.

//[출력]
//각 테스트 케이스마다 앨리스의 승률이 더 높으면 “ALICE”, 밥의 승률이 더 높으면 “BOB”, 둘의 승률이 같으면 “DRAW”를 출력한다.

//[힌트]
//첫 번째 Testcase를 예로 들면 엘리스는 2전 1승, 밥은 4전 2승이다.
//엘리스의 승률은 1 / 2 밥의 승률은 2 / 4로 서로 같으므로 “DRAW”를 출력한다.

#include <stdio.h>

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		float a, b, c, d;
		scanf("%f%f%f%f", &a, &b, &c, &d);
		float alice = a / b;
		float bob = c / d;
		if (alice > bob) {
			printf("#%d ALICE\n", t + 1);
		}
		else if (alice < bob) {
			printf("#%d BOB\n", t + 1);
		}
		else {
			printf("#%d DRAW\n", t + 1);
		}
	}

	return 0;
}