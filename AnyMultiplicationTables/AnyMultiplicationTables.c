#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void setMulTab(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d  *  %d  = %d   ", i, j, i * j);
		}
		printf("\n");
	}
}

int main() {
	printf("�����������ӡ�˷��ھ����������\n");
	int n = 0;
	scanf("%d", &n);
	setMulTab(n);
	return 0;
}