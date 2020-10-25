#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int isPrimeNum(int num) {
	if (num == 0 || num == 1) {
		return 0;
	}
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	printf("������һ������\n");
	int num = 0;
	scanf("%d", &num);
	if (isPrimeNum(num) == 0) {
		printf("����������\n");
	}
	else {
		printf("��������\n");
	}
	for (int i = 100; i <= 200; i++) {
		if (isPrimeNum(i) == 1) {
			printf("%d ",i);
		}
	}
	return 0;
}