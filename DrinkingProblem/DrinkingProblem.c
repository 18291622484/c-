#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//�����кܶ���Σ���������ƿ�ӻ�һƿ��ˮ���ĸ�ƿ�ӻ�һƿ��ˮ�ȵ�
#define Exchange 2

int DrinkingProblem(int bottle) {
	int ret = bottle;
	while (bottle >= Exchange) {
		ret += bottle / Exchange;
		bottle = bottle / Exchange + bottle % Exchange;
	}
	return ret;
}


//����Կ�����һ���Ȳ�����
int DrinkingProblem1(int bottle) {
	if (bottle <= 0) {
		return 0;
	}
	else {
		int ret1 = 0;
		return bottle * 2 - 1;
	}
}

int main() {
	//���û������ö���Ǯ������ˮ
	printf("����Ǯ����");
	int money = 0;
	scanf("%d", &money);
	int ret = DrinkingProblem(money);
	int ret1 = DrinkingProblem1(money);
	printf("%d %d\n", ret, ret1);
	return 0;
}