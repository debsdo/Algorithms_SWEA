//패턴에서 반복되는 부분을 마디라고 부른다.문자열을 입력 받아 마디의 길이를 출력하는 프로그램을 작성하라.

//[제약 사항]
//각 문자열의 길이는 30이다.마디의 최대 길이는 10이다.

//[입력]
//가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.
//각 테스트 케이스의 첫 번째 줄에는 길이가 30인 문자열이 주어진다.

//[출력]
//출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.
//(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

#include <stdio.h>
#include <string.h>
#include <malloc.h>

int groupChecker(char str[], int n) {
	char *strCut1, *strCut2;
	char flag = 0;
	strCut1 = (char*)malloc(sizeof(char)*(n+1));
	strCut2 = (char*)malloc(sizeof(char)*(n+1));

	for (int i = 0; i < n; i++) {
		strCut1[i] = str[i];
	}
	strCut1[n] = '\0';

	for (int i = 0; i < 30 / n; i++) {
		for (int j = 0; j < n; j++) {
			strCut2[j] = str[n * i + j];
		}
		strCut2[n] = '\0';

		if (strcmp(strCut1, strCut2) == 0) {
			flag = 1;
		}
		else {
			flag = 0;
			break;
		}
	}
	
	if (flag == 1) {
		return n;
	}
	else {
		return 0;
	}
}

int main() {
	int tc;
	char inStr[30 + 1];
	scanf("%d", &tc);
	
	for (int t = 0; t < tc; t++) {
		scanf("%s", inStr);
		int flag;
		for (int i = 0; i < 10; i++) {
			flag = groupChecker(inStr, i + 1);
			if (flag != 0) {
				printf("#%d %d\n", t+1, flag);
				break;
			}
		}
	}

	return 0;
}
