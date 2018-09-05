#include <stdio.h>
#include <string.h>

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		char word[10 + 1];
		scanf("%s", word);
		char cmp[10 + 1];
		int len = strlen(word);

		for (int i = 0; i < len; i++) {
			cmp[i] = word[len - 1 - i];
		}
		
		cmp[len] = '\0';

		if (strcmp(cmp, word) == 0) {
			printf("#%d 1\n", t+1);
		}
		else {
			printf("#%d 0\n", t+1);
		}
	}
}