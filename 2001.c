#include <stdio.h>
#include <malloc.h>

int killCounter(char **row, int rowStart, int colStart, int m) {
	int killNum = 0;
	
	for (int i = rowStart; i < rowStart + m; i++) {
		for (int j = colStart; j < colStart + m; j++) {
			killNum += row[i][j];
		}
	}

	return killNum;
}

int main() {
	int tc;

	scanf("%d", &tc);
	
	for (int t = 0; t < tc; t++) {
		int n, m, temp;
		int kill = 0;
		char **row;

		scanf("%d %d", &n, &m);

		row = (char **)malloc(sizeof(char)*n);

		for (int i = 0; i < n; i++) {
			row[i] = (char*)malloc(sizeof(char)*n);
			for (int j = 0; j < n; j++) {
				scanf("%d", &row[i][j]);
			}
		}

		for (int i = 0; i < n - m + 1; i++) {
			for (int j = 0; j < n - m + 1; j++) {
				temp = killCounter(row, i, j, m);
				if (temp > kill) {
					kill = temp;
				}
			}
		}

		printf("#%d %d\n", t+1, kill);
	}

	return 0;
}