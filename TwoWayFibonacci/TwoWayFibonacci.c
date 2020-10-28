#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int fib1(int n) {
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 1;
	}
	else {
		return fib1(n - 1) + fib1(n - 2);
	}
}

int fib2(int n) {
	//第n-2个数
	int last1 = 1;
	//第n-1个数
	int last2 = 1;
	int ret = 0;
	if (n == 1||n==2) {
		return 1;
	}
	for (int i = 3; i <= n; i++) {
		ret = last1 + last2;
		last1 = last2;
		last2 = ret;
	}
	return ret;
}

int main() {
	printf("要求第几个斐波那契数列：\n");
	int n = 0;
	scanf("%d", &n);
	int ret1 = fib1(n);
	int ret2 = fib2(n);
	printf("%d %d\n", ret1,ret2);
	return 0;
}