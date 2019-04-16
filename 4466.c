//당신은 N개의 과목에 대한 시험을 쳤다.각 과목의 점수는 정수이고 만점은 100점이다.
//성적표에는 이 중에서 정확히 K개의 과목을 선택하여 넣을 수 있다.
//당신은 기왕이면 성적표에 나타나는 총점이 가장 크도록 성적표를 만들고 싶다.
//최대로 만들 수 있는 총점은 몇점인지 구하여라.

//[입력]
//첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
//각 테스트 케이스의 첫 번째 줄에는 N, K(1≤K≤N≤100)이 공백 하나로 구분되어 주어진다.
//두 번째 줄에는 N개의 정수가 공백 하나로 구분되어 주어진다.각 정수는 0 이상 100이하이다.

//[출력]
//각 줄마다 "#T" (T는 테스트 케이스 번호)를 출력한 뒤, 성적표에 표시될 총점의 최댓값을 출력한다.

#include <stdio.h>

void bubbleSortDesc(int arr[], int size) {
	int temp;
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return;
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		int n, k;
		scanf("%d %d", &n, &k);

		int arr[100];
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		bubbleSortDesc(arr, n);

		int sum = 0;
		for (int i = 0; i < k; i++) {
			sum += arr[i];
		}

		printf("#%d %d\n", t + 1, sum);
	}

	return 0;
}