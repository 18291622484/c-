#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int isPrimeNum(int num,int nums) {
	if (num == 0 || num == 1) {
		return 0;
	}
	for (int i = 2; i <= nums; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	printf("请输入一个数：\n");
	int num = 0;
	int nums = 0;
	scanf("%d", &num);
	nums = (int)sqrt((double)num);
	if (isPrimeNum(num,nums) == 0) {
		printf("不是素数！\n");
	}
	else {
		printf("是素数！\n");
	}
	for (int i = 100; i <= 200; i++) {
		nums = (int)sqrt((double)i);
		if (isPrimeNum(i,nums) == 1) {
			printf("%d ",i);
		}
	}
	return 0;
}