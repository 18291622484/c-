#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 4

void exchangeArray(int arr1[], int arr2[]) {
	for (int i = 0; i < MAX_SIZE; i++) {
		int t = 0;
		t = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = t;
	}
}

void print(int arr[]) {
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr1[MAX_SIZE] = { 9,5,2,7 };
	int arr2[MAX_SIZE] = { 8,4,1,6 };
	print(arr1);
	print(arr2);
	exchangeArray(arr1, arr2);
	print(arr1);
	print(arr2);
	return 0;
}