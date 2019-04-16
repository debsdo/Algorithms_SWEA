//10개의 수를 입력 받아, 최대 수와 최소 수를 제외한 나머지의 평균값을 출력하는 프로그램을 작성하라.
//(소수점 첫째 자리에서 반올림한 정수를 출력한다.)

//[제약 사항]
//각 수는 0 이상 10000 이하의 정수이다.

//[입력]
//가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
//각 테스트 케이스의 첫 번째 줄에는 10개의 수가 주어진다.

//[출력]
//출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.
//(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

#include <stdio.h>
#include <math.h>

int bubbleSort(float a[], int size) {
	int i, j, t, temp;

	for (i = size - 1; i > 0; i--) {
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
	float numBox[10];
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		for (int i = 0; i < 10; i++) {
			scanf("%f", &numBox[i]);
		}

		bubbleSort(numBox, 10);

		float avg, sum = 0;

		for (int j = 1; j < 9; j++) {
			sum += numBox[j];
		}

		avg = sum / 8;
		avg = floor(avg + 0.5);
		
		printf("#%d %.0f\n", t + 1, avg);
	}

	return 0;
}