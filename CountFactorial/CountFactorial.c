#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//�ݹ鷽����
int setFactor1(int num) {
	if (num == 1) {
		return 1;
	}
	else {
		return num * setFactor1(num - 1);
	}
}
//�ǵݹ鷽����
int setfactor2(int num) {
	int value = 1;
	for (int i = 1; i <= num; i++) {
		value = value * i;
	}
	return value;
}

int main() {
	printf("����Ҫ��׳˵�����\n");
	int num = 0;
	scanf("%d", &num);
	printf("�ݹ鷽����ã� %d\n", setFactor1(num));
	printf("�ǵݹ鷽����ã� %d\n", setfactor2(num));
	return 0;
}