#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int NumPower(int n,int k) {
	if (k==1) {
		return n;
	}
	else {
		return n * NumPower(n,--k);
	}
	return 0;
}

int main() {
	printf("����һ������n������Ҫ���k�η���\n");
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	int ret = NumPower(n, k);
	printf("%d\n", ret);
	return 0;
}