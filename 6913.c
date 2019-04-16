#include <stdio.h>

int main() {
	int tc;
	scanf("%d", &tc);
	
	int table[20][20];
	for (int t = 0; t < tc; t++) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &table[i][j]);
			}
		}

		int highest = 0;
		int scores[20];
		for (int i = 0; i < n; i++) {
			int temp = 0;
			for (int j = 0; j < m; j++) {
				if (table[i][j] == 1) {
					temp += 1;
				}
			}
			scores[i] = temp;
			if (temp > highest) {
				highest = temp;
			}
		}

		int winners = 0;
		for (int i = 0; i < n; i++) {
			if (scores[i] == highest) {
				winners += 1;
			}
		}
		
		printf("#%d %d %d\n", t + 1, winners, highest);
	}

	return 0;
}