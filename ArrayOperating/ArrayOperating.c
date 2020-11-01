#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

void init(int arr[]) {
	for (int i = 0; i < MAX_SIZE; i++) {
		arr[i] = 0;
	}
}

void print(int arr[]) {
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void reverse(int arr[]) {
	for (int i = 0, j = MAX_SIZE - 1; i < j; i++, j--) {
		int t = 0;
		t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}
}

int main() {
	int arr[MAX_SIZE];
	init(arr);
	reverse(arr);
	print(arr);
	return 0;
}