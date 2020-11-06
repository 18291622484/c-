#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void init(int* p,int num) {
	for (int i = 0; i < MAX; i++,p++) {
		int ret = 1;
		for (int j = 0; j < i; j++) {
			ret = ret * 10 + 1;
		}
		*p = num * ret;
	}
}

int sum(int* p) {
	int ret = 0;
	for (int i = 0; i < MAX; i++,p++) {
		ret = ret + *p;
	}
	return ret;
}

int main() {
	int arr[MAX] = { 0 };
	printf("请输入0~9的一个数：");
	int num = 0;
	scanf("%d", &num);
	init(arr,num);
	/*for (int i = 0; i < MAX; i++) {
		printf("%d \n", arr[i]);
	}*/
	int ret = sum(arr);
	printf("%d\n", ret);
	return 0;
}