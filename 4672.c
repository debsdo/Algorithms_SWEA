#include <stdio.h>
#include <string.h>
#include <malloc.h>

// 팰린드롬 체크
int plndrmChecker(char* str) {
	// 거꾸로 뒤집은 숫자 담을 temp 동적 할당
	char* temp;
	temp = (char*)malloc(sizeof(char)*(strlen(str) + 1));

	// str이 10+1자리라면, temp[0]에 str[9], temp[1]에 str[8]... temp[9]에 str[0]
	for (int i = 0; i < strlen(str); i++) {
		temp[i] = str[strlen(str)-1 - i];
	}
	temp[strlen(str)] = '\0';

	if (strcmp(temp, str) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

// 팰린드롬 최댓값 구하기
int plndrmExpander(char* str) {
	int cnt = 0;
	int tempCnt = 0;

	char *tempStr;
	tempStr = (char*)malloc(sizeof(char)*(strlen(str) + 1));

	for (int i = 0; i < strlen(str); i++) {
		
	}

	if (tempCnt > cnt) {
		cnt = tempCnt;
	}

	return cnt;
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		char inStr[10 + 1];
		scanf("%s", inStr);
		
		// 각각의 부분문자열을 일시적으로 담아둘 공간 할당
		char **list;
		list = (char**)malloc(sizeof(char*) * 10);
		for (int i = 0; i < 10; i++) {
			list[i] = (char*)malloc(sizeof(char)*(i + 2));
		}

		int cnt = 0;
		for (int i = 0; i < strlen(inStr); i++) {
			for (int j = 0; j < strlen(inStr); j++) {
				list[i][j] = inStr[j];
				list[i][i + 1] = '\0';
				if (plndrmChecker(list[i]) == 1) {
					cnt += 1;
				}
			}
		}

		printf("#%d %d\n", t + 1, cnt);
	}

	return 0;
}