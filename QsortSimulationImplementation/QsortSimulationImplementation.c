#include<stdio.h>
#include<stdlib.h>

typedef void(*CMP)(int*, int*);

CMP Bubbup(int* m, int* n) {
	if (*m > * n) {
		int t = 0;
		t = *m;
		*m = *n;
		*n = t;
		}
}
CMP Bubbdown(int* m, int* n) {
	if (*m < * n) {
		int t = 0;
		t = *m;
		*m = *n;
		*n = t;
	}
}

void BubbleSort(int* arr,int size,CMP cmp) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			cmp(&arr[j], &arr[j + 1]);
		}
	}
}

int main() {
	int arr[10] = { 56,23,48,51,27,19,36,67,92,40 };
	int size = sizeof(arr) / sizeof(arr[0])-1;
	for (int i = 0; i <= size; i++) {
		printf("%d ", arr[i]);
	}printf("\n");
	//ÉýÐòÅÅÐò
	BubbleSort(arr, size, Bubbup);
	for (int i = 0; i <= size; i++) {
		printf("%d ", arr[i]);
	}printf("\n");
	//½µÐòÅÅÐò
	BubbleSort(arr, size, Bubbdown);
	for (int i = 0; i <= size; i++) {
		printf("%d ", arr[i]);
	}printf("\n");
	return 0;
}