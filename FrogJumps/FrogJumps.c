#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//f(1) = 1;
//f(2) = f(1) + 1 = f(1) + f(1) = 2 * f(1) = 2;
//f(3) = f(2) + f(1) + 1 = f(2) + f(1) + f(1)= f(2) + 2 * f(1) = f(2) + f(2) = 2 * f(2) = 2 * 2;
//f(k) = f(k - 1) + f(k - 2) + … + f(2) + f(1) + 1
//  = f(k - 1) + f(k - 2) + … + f(3) + f(2) + f(1) + f(1)
//  = f(k - 1) + f(k - 2) + … + f(3) + f(2) + f(2）
//	= f(k - 1) + f(k - 2) + f(k - 3) + … + f(3) + f(3)
//	= 2 * f(k - 1)

int FrogJumps(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return 2*FrogJumps(n - 1);
	}
}

int main() {
	int n = 0;
	printf("输入青蛙一次最多可以跳几个台阶：\n");
	scanf("%d", &n);
	int m = n;
	int ret = FrogJumps(n,m);
	printf("%d\n", ret);
	return 0;
}