//N x N 행렬이 주어질 때,
//시계 방향으로 90도, 180도, 270도 회전한 모양을 출력하라.

//[제약 사항]
//N은 3 이상 7 이하이다.

//[입력]
//가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
//각 테스트 케이스의 첫 번째 줄에 N이 주어지고,
//다음 N 줄에는 N x N 행렬이 주어진다.

//[출력]
//출력의 첫 줄은 '#t'로 시작하고,
//다음 N줄에 걸쳐서 90도, 180도, 270도 회전한 모양을 출력한다.
//입력과는 달리 출력에서는 회전한 모양 사이에만 공백이 존재함에 유의하라.
//(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

#include <stdio.h>
#include <malloc.h>

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		int n;
		scanf("%d", &n);

		// 배열 할당 및 값 입력
		int** arr;
		arr = (int**)malloc(sizeof(int*)*n);
		for (int i = 0; i < n; i++) {
			arr[i] = (int*)malloc(sizeof(int)*n);
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		// 90도 회전 배열
		int **arr90;
		arr90 = (int**)malloc(sizeof(int*)*n);
		for (int i = 0; i < n; i++) {
			arr90[i] = (int*)malloc(sizeof(int)*n);
			for (int j = 0; j < n; j++) {
				arr90[i][j] = arr[n - 1 - j][i];
			}
		}

		// 180도 회전 배열
		int **arr180;
		arr180 = (int**)malloc(sizeof(int*)*n);
		for (int i = 0; i < n; i++) {
			arr180[i] = (int*)malloc(sizeof(int)*n);
			for (int j = 0; j < n; j++) {
				arr180[i][j] = arr[n - 1 - i][n - 1 - j];
			}
		}

		// 360도 회전 배열
		int **arr360;
		arr360 = (int**)malloc(sizeof(int*)*n);
		for (int i = 0; i < n; i++) {
			arr360[i] = (int*)malloc(sizeof(int)*n);
			for (int j = 0; j < n; j++) {
				arr360[i][j] = arr[j][n - 1 - i];
			}
		}

		printf("#%d\n", t + 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d", arr90[i][j]);
			}
			printf(" ");
			for (int j = 0; j < n; j++) {
				printf("%d", arr180[i][j]);
			}
			printf(" ");
			for (int j = 0; j < n; j++) {
				printf("%d", arr360[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}