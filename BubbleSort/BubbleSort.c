#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

void BubbleSort(int arr[]) {
	for (int i = 0; i < MAX_SIZE;i++) {
		for (int j = 0; j < MAX_SIZE - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int t = 0;
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

int main() {
	int arr[MAX_SIZE] = { 2,5,7,9,6,4,10,1,8,3 };
	BubbleSort(arr);
	for (int i = 0; i < 10; i++) {
		printf("%4d", arr[i]);
	}
	return 0;
}