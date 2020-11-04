#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int DifferentDigits(int m, int n) {
	int ret = 0;
	int flag = 0;
	int num = 1;
	//int flagm = 0;
	//int flagn = 0;
	flag = m ^ n;
	for (int i = 0; i < 32; i++,num=num<<1) {
		if ((flag & num) == num) {
			ret++;
		}
	}
	return ret;
}

int main() {
	int m = 0;
	int n = 0;
	printf("请输入两个数：\n");
	scanf("%d %d", &m, &n);
	int ret = DifferentDigits(m, n);
	/*int ret = 1;
	ret=ret << 1;*/
	printf("%d\n", ret);
	return 0;
}