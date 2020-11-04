#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//void PrintOE(int num,int arro[16],int arre[16]) {
//	int num1 = 1;
//	int num2 = 2;
//	for (int i = 0; i < 16; i++,num1=num1<<2) {
//		if ((num & num1) == num1) {
//			arro[i] = 1;
//		}
//		else {
//			arro[i] = 0;
//		}
//	}
//	for (int i = 0; i < 16; i++, num2 = num2 << 2) {
//		if ((num & num2) == num2) {
//			arre[i] = 1;
//		}
//		else {
//			arre[i] = 0;
//		}
//	}
//}
//
//void Print(int arro[16], int arre[16]) {
//	for (int i = 15; i >= 0; i--) {
//		printf("%d", arro[i]);
//	}
//	printf("\n");
//	for (int i = 15; i >= 0; i--) {
//		printf("%d", arre[i]);
//	}
//}

void PrintEO(int num) {
	for (int i = 31; i > 0; i-=2) {
		printf("%d", (num >> i) & 1);
	}
	printf("\n");
	for (int i = 30; i >= 0; i-=2) {
		printf("%d", (num >> i) & 1);
	}
}

int main() {
	/*int arro[16] = { 0 };
	int arre[16] = { 0 };*/
	printf("请输入一个数：");
	int num = 0;
	scanf("%d", &num);
	//PrintOE(num,arro,arre);
	//Print(arro, arre);
	PrintEO(num);
	return 0;
}