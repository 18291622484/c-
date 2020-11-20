#include<stdio.h>
#include<stdlib.h>

void* myMemcpy(void* destin, void* source, int num) {
	if (destin == NULL || source == NULL) {
		return NULL;
	}
	char* dest = (char*)destin;
	char* sour = (char*)source;
	for (int i = 0; i < num; i++) {
		*(dest + i) = *(sour + i);
	}
	return destin;
}

int main() {
	int arr[4] = { 5,6,7,8 };
	int arr1[4] = { 0 };
	myMemcpy(arr1, arr, 16);
	for (int i = 0; i < 4; i++) {
		printf("%d ", arr1[i]);
	}printf("\n");
	return 0;
}