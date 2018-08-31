#include <stdio.h>
#include <stdlib.h>

// 코드 정리 필요

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		if (i < 10) {
			if (i == 3 || i == 6 || i == 9) {
				printf("- ");
			}
			else {
				printf("%d ", i);
			}
		}
		else if (i < 100) {
			char charNum[3];
			sprintf(charNum, "%d", i);
			if (charNum[0] == '3' || charNum[0] == '6' || charNum[0] == '9') {
				if (charNum[1] == '3' || charNum[1] == '6' || charNum[1] == '9') {
					printf("-- ");
				}
				else {
					printf("- ");

				}
			} else if (charNum[1] == '3' || charNum[1] == '6' || charNum[1] == '9') {
				printf("- ");
			}
			else {
				printf("%d ", i);
			}
		}
		else if (i < 1000) {
			char charNum[4];
			sprintf(charNum, "%d", i);
			if (charNum[0] == '3' || charNum[0] == '6' || charNum[0] == '9') {
				if (charNum[1] == '3' || charNum[1] == '6' || charNum[1] == '9') {
					if (charNum[2] == '3' || charNum[2] == '6' || charNum[2] == '9') {
						printf("--- ");
					}
					else {
						printf("-- ");
					}
				}
				else if (charNum[2] == '3' || charNum[2] == '6' || charNum[2] == '9') {
					printf("-- ");
				}
				else {
					printf("- ");

				}
			}
			else if (charNum[1] == '3' || charNum[1] == '6' || charNum[1] == '9') {
				if (charNum[2] == '3' || charNum[2] == '6' || charNum[2] == '9') {
					printf("-- ");
				}
				else {
					printf("- ");
				}
			}
			else if (charNum[2] == '3' || charNum[2] == '6' || charNum[2] == '9') {
				printf("- ");
			}
			else {
				printf("%d ", i);
			}
		}
		else {
			printf("%d", i);
		}
	}
	
	return 0;
}