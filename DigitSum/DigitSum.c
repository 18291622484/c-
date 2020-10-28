#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int DigitSum(int n) {
	if (n < 10) {
		return n;
	}
	else {
		int num = n % 10;
		n = n / 10;
		return num+DigitSum(n);
	}
}

int main() {
	printf("输入一个数：\n");
	int n = 0;
	scanf("%d", &n);
	int ret = DigitSum(n);
	printf("%d\n", ret);
	return 0;
}