#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//递归方法求
int setFactor1(int num) {
	if (num == 1) {
		return 1;
	}
	else {
		return num * setFactor1(num - 1);
	}
}
//非递归方法求
int setfactor2(int num) {
	int value = 1;
	for (int i = 1; i <= num; i++) {
		value = value * i;
	}
	return value;
}

int main() {
	printf("输入要求阶乘的数：\n");
	int num = 0;
	scanf("%d", &num);
	printf("递归方法求得： %d\n", setFactor1(num));
	printf("非递归方法求得： %d\n", setfactor2(num));
	return 0;
}