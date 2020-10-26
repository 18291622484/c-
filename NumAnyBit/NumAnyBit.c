#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void NumBit(int num) {
	if (num <= 9) {
		printf("%d ", num);
	}
	else {
		int remainder = 0;
		remainder = num % 10;
		num = num / 10;
		NumBit(num);
		printf("%d ", remainder);
	}
}

int main(){
	printf("输入一个数:\n");
	int num = 0;
	scanf("%d", &num);
	NumBit(num);
	return 0;
}