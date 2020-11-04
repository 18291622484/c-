#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void NoTempChange(int* a, int* b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void NoTempChange1(int* a, int* b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int main() {
	printf("请输入两个数：");
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	//NoTempChange(&a, &b);
	NoTempChange1(&a, &b);
	printf("a=%d\nb=%d", a, b);
	return 0;
}