#include <stdio.h>

int summer(int nums[], int start, int n) {
	int sum = 0;
	for (int i = start; i < start + n; i++) {
		sum += nums[i];
	}
	return sum;
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		int n;
		scanf("%d", &n);
		
		int nums[100000];

		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i]);
		}

		int max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - i; j++) {
				int temp;
				temp = summer(nums, j, i + 1);
				if (temp > max) {
					max = temp;
				}
			}
		}
		printf("#%d %d\n", t + 1, max);
	}
	return 0;
}
