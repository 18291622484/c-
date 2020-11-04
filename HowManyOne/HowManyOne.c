#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int HowManyOne(int num) {
	int ret = 0;
	for (int i = 31; i >= 0; i--) {
		if (((num >> i) & 1) == 1) {
			ret++;
		}
	}
	return ret;
}

int main() {
	printf("请输入一个数：");
	int num = 0;
	scanf("%d", &num);
	int ret = HowManyOne(num);
	printf("%d\n", ret);
	return 0;
}