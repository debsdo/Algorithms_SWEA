//������ ������ ������ 8�ڸ��� ��¥�� �Է����� �־�����.
//�ش� ��¥�� ��ȿ���� �Ǵ��� ��, ��¥�� ��ȿ�ϴٸ�
//[�׸�1] �� ���� ��YYYY / MM / DD���������� ����ϰ�,
//��¥�� ��ȿ���� ���� ���, -1 �� ����ϴ� ���α׷��� �ۼ��϶�.
//�����Ϸ� ������ �Է¿��� ���� 1~12 ���� ���� ������ �ϸ�
//����[ǥ1] �� ����, 1�� ~������ �޿� �ش��ϴ� ��¥������ ���� ���� �� �ִ�.
//�� 2���� ���, 28���� ��츸 ����Ѵ�. (������ ������� �ʴ´�.)

//[�Է�]
//�Է��� ù �ٿ� �� �׽�Ʈ ���̽��� ���� T�� �´�.
//���� �ٺ��� �� �׽�Ʈ ���̽��� �־�����.

//[���]
//�׽�Ʈ ���̽� t�� ���� ����� ��#t���� ���, �� ĭ ���, ������ ����Ѵ�.
//(t�� �׽�Ʈ ���̽��� ��ȣ�� �ǹ��ϸ� 1���� �����Ѵ�.)

#include <stdio.h>

int mChker(int num) {
	if (num >= 1 && num <= 12) {
		return 1;
	}
	else {
		return 0;
	}
}

int mGrpFnder(int mt) {
	char m30[4] = { 4,6,9,11 };
	char m31[7] = { 1,3,5,7,8,10,12 };
	char m28[1] = { 2 };
	char mChk = mChker(mt);

	if (mChk == 1) {
		for (int i = 0; i < 4; i++) {
			if (mt == m30[i]) {
				return 30;
			}
		}

		for (int i = 0; i < 7; i++) {
			if (mt == m31[i]) {
				return 31;
			}
		}

		return 28;
	}
	else {
		return 0;
	}
}

int dChker(int mt, int dt) {
	char mGrp = mGrpFnder(mt);
	if (mGrp == 30) {
		if (dt >= 1 && dt <= 30) {
			return 1;
		}
	}
	else if (mGrp == 31) {
		if (dt >= 1 && dt <= 31) {
			return 1;
		}
	}
	else if (mGrp == 28) {
		if (dt >= 1 && dt <= 28) {
			return 1;
		}
	}
	else {
		return 0;
	}
}

int main() {
	int tc, inNum;

	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		int yr, mt, dt;

		scanf("%d", &inNum);

		yr = inNum / 10000;
		mt = (inNum % 10000) / 100;
		dt = (inNum % 10000) % 100;

		char mChk = mChker(mt);
		char dChk = dChker(mt, dt);

		if (mChk == 1 && dChk == 1) {
			printf("#%d ", i + 1);
			printf("%04d/%02d/%02d\n", yr, mt, dt);
		}
		else {
			printf("#%d -1\n", i + 1);
		}
	}

	return 0;
}