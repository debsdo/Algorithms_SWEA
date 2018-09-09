//주어진 N 길이의 숫자열을 오름차순으로 정렬하여 출력하라.

//[제약 사항]
//N 은 5 이상 50 이하이다.

//[입력]
//가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
//각 테스트 케이스의 첫 번째 줄에 N 이 주어지고, 다음 줄에 N 개의 숫자가 주어진다.

//[출력]
//출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.
//(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

#include <stdio.h>
#include <malloc.h>

int bubbleSort(int a[], int size) {
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
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		int n;
		scanf("%d", &n);

		int *numBox;
		numBox = (int*)malloc(sizeof(int)*n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &numBox[i]);
		}

		bubbleSort(numBox, n);

		printf("#%d", t + 1);
		for (int i = 0; i < n; i++) {
			printf(" %d", numBox[i]);
		}
		printf("\n");
	}

	return 0;
}