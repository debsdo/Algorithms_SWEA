//하나의 자연수를 입력 받아 각 자릿수의 합을 계산하는 프로그램을 작성하라.
//
//
//[제약 사항]
//
//자연수 N은 1부터 9999까지의 자연수이다. (1 ≤ N ≤ 9999)
//
//
//[입력]
//
//입력으로 자연수 N이 주어진다.
//
//
//[출력]
//
//각 자릿수의 합을 출력한다.

#include <stdio.h>

int main() {
	int n, one, ten, hndrd, thsnd;

	scanf("%d", &n);
	
	if (n < 10) {
		printf("%d", n);
	}
	else if (n >= 10 && n < 100) {
		ten = n / 10;
		one = n % 10;
		printf("%d", ten + one);
	}
	else if (n >= 100 && n < 1000) {
		hndrd = n / 100;
		ten = (n%100) / 10;
		one = n % 10;
		printf("%d", hndrd + ten + one);
	}
	else if (n >= 1000) {
		thsnd = n / 1000;
		hndrd = (n % 1000) / 100;
		ten = (n % 100) / 10;
		one = n % 10;
		printf("%d", thsnd + hndrd + ten + one);
	}
}