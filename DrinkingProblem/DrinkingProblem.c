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

int main() {
	//���û������ö���Ǯ������ˮ
	printf("����Ǯ����");
	int money = 0;
	scanf("%d", &money);
	int ret = DrinkingProblem(money);
	printf("%d\n", ret);
	return 0;
}