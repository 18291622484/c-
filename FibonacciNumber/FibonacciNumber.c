#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int FibNum(int num) {
	if (num <= 1) {
		return num;
	}
	else {
		return FibNum(num - 1) + FibNum(num - 2);
	}
}

int main() {
	int num = 0;
	printf("输入要打印数列的个数:\n");
	scanf("%d", &num);
	for (int i = 0; i <= num; i++) {
		printf("%d ", FibNum(i));
	}
	return 0;
}