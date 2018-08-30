#include <stdio.h>

int monthChecker(int num) {
	if (num >= 1 && num <= 12) {
		return 1;
	}
	else {
		return 0;
	}
}

int monthGroupFinder(int month) {
	char months30[4] = { 4,6,9,11 };
	char months31[7] = { 1,3,5,7,8,10,12 };
	char months28[1] = { 2 };
	char monthCheck = monthChecker(month);

	if (monthCheck == 1) {
		for (int i = 0; i < 4; i++) {
			if (month == months30[i]) {
				return 30;
			}
		}

		for (int i = 0; i < 7; i++) {
			if (month == months31[i]) {
				return 31;
			}
		}

		return 28;
	}
	else {
		return 0;
	}
}

int dateChecker(int month, int date) {
	char monthGroup = monthGroupFinder(month);
	if (monthGroup == 30) {
		if (date >= 1 && date <= 30) {
			return 1;
		}
	}
	else if (monthGroup == 31) {
		if (date >= 1 && date <= 31) {
			return 1;
		}
	}
	else if (monthGroup == 28) {
		if (date >= 1 && date <= 28) {
			return 1;
		}
	}
	else {
		return 0;
	}
}

int formatter(int num) {
	int year, month, date;

	year = num / 10000;
	month = (num % 10000) / 100;
	date = (num % 10000) % 100;
	printf("%04d/%02d/%02d\n", year, month, date);

	return 1;
}

int main() {
	int tc, inNum;

	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		int year, month, date;

		scanf("%d", &inNum);

		year = inNum / 10000;
		month = (inNum % 10000) / 100;
		date = (inNum % 10000) % 100;

		char monthCheck = monthChecker(month);
		char dateCheck = dateChecker(month, date);

		if (monthCheck == 1 && dateCheck == 1) {
			printf("#%d ", i + 1);
			formatter(inNum);
		}
		else {
			printf("#%d -1\n", i + 1);
		}
	}

	return 0;
}