﻿//10개의 수를 입력 받아, 그 중에서 가장 큰 수를 출력하는 프로그램을 작성하라.

//[제약 사항]
//각 수는 0 이상 10000 이하의 정수이다.

//[입력]
//가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
//각 테스트 케이스의 첫 번째 줄에는 10개의 수가 주어진다.

//[출력]
//출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.
//(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

#include <stdio.h>

int bubbleSort(int a[]) {
	int i, j, t, temp;

	for (i = 9; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main() {
	int tc;
	int numBox[10];
	
	scanf("%d", &tc);
	
	for (int i = 0; i < tc; i++) {
		for (int k = 0; k < 10; k++) {
			scanf("%d", &numBox[k]);
		}
		bubbleSort(numBox);
		printf("#%d %d\n", i + 1, numBox[9]);
	}

}