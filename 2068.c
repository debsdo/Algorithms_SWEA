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