#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void Hanoi(int n,char a,char b,char c) {
	if (n == 1) {
		printf("%c-->%c\n",a,c);
	}
	else {
		Hanoi(n - 1,a,c,b);
		printf("%c-->%c\n",a,c);
		Hanoi(n - 1,b,a,c);
	}
}

int main() {
	printf("输入想要游戏的个数：\n");
	int n = 0;
	scanf("%d", &n);
	Hanoi(n, 'a', 'b', 'c');
	return 0;
}