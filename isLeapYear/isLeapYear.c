#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int isLeapYear(int year) {
	if ((year % 100 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
		printf("�����꣡\n");
	}
	else {
		printf("�������꣡\n");
	}
}

int main() {
	printf("����һ����ݣ�\n");
	int year = 0;
	scanf("%d", &year);
	isLeapYear(year);
	return 0;
}