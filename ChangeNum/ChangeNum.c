#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void ChangeNum(int* x,int* y) {
	int temp = 0;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main() {
	int* a = 0;
	int* b = 0;
	printf("输入两个数啊a,b:\n");
	scanf("%d %d", &a, &b);
	ChangeNum(&a, &b);
	printf("a=%d\nb=%d\n", a, b);
	return 0;
}