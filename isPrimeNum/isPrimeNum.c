#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int isPrimeNum(int num) {
	if (num == 0 || num == 1) {
		return 0;
	}
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	printf("请输入一个数：\n");
	int num = 0;
	scanf("%d", &num);
	if (isPrimeNum(num) == 0) {
		printf("不是素数！\n");
	}
	else {
		printf("是素数！\n");
	}
	for (int i = 100; i <= 200; i++) {
		if (isPrimeNum(i) == 1) {
			printf("%d ",i);
		}
	}
	return 0;
}