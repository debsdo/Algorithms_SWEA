//다음과 같이 Encoding 을 한다.
//1. 우선 24비트 버퍼에 위쪽(MSB)부터 한 byte씩 3 byte의 문자를 집어넣는다.
//2. 버퍼의 위쪽부터 6비트씩 잘라 그 값을 읽고, 각각의 값을 아래[표 - 1] 의 문자로 Encoding 한다.
//입력으로 Base64 Encoding 된 String 이 주어졌을 때,
//해당 String 을 Decoding 하여, 원문을 출력하는 프로그램을 작성하시오.

//[제약사항]
//문자열의 길이는 항상 4의 배수로 주어진다.
//그리고 문자열의 길이는 100000을 넘지 않는다.

//[입력]
//입력은 첫 줄에 총 테스트 케이스의 개수 T가 온다.
//다음 줄부터 각 테스트 케이스가 주어진다.
//테스트 케이스는 Encoding 된 상태로 주어지는 문자열이다.

//[출력]
//테스트 케이스 t에 대한 결과는 “#t”을 찍고, 한 칸 띄고, 정답을 출력한다.
//(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

#include <stdio.h>
#include <string.h>

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		char e[100000];
		scanf("%s", e);
		int len = strlen(e)/4;
		unsigned int encoded[100000];
		for (int i = 0; i < 100000; i++) {
			encoded[i] = (unsigned int)e[i];
		}
	
		printf("#%d ", t + 1);
		unsigned int idx = 0;
		for (int i = 0; i < len; i++) {
			unsigned int buffer = 0x00;
			for (int j = idx; j < idx + 4; j++) {
				if (encoded[j] >= 48 && encoded[j] <= 57) {
					encoded[j] += 0x04;
				}
				else if (encoded[j] >= 65 && encoded[j] <= 90) {
					encoded[j] -= 0x41;
				}
				else if (encoded[j] >= 97 && encoded[j] <= 122) {
					encoded[j] -= 0x47;
				}
				else if (encoded[j] == 32) {
					encoded[j] += 0x13;
				}
				else if (encoded[j] == 47) {
					encoded[j] += 0x10;
				}
				else if (encoded[j] == 0) {
					break;
				}

				buffer = buffer << 6;
				buffer = buffer | encoded[j];
			}

			unsigned int decoded[4] = { 0,0,0,0 };
			unsigned int mask = 0xff0000;
			for (int j = 0; j < 3; j++) {
				decoded[j] = buffer & mask;
				decoded[j] = decoded[j] >> 16;
				buffer = buffer << 8;
				printf("%c", decoded[j]);
			}

			idx += 4;
		}
		printf("\n");
	}
	return 0;
}