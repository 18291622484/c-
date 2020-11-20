#include<stdio.h>
#include<stdlib.h>

void* myMemmove(void* destin, const void* source,size_t num) {
	if (destin == NULL || source == NULL) {
		return NULL;
	}
	char* sour = (char*)source;
	char* dest = (char*)destin;
	if (dest > sour && dest < (sour + num)) {
		for (int i = num - 1; i >= 0; i--) {
			*(dest + i)= *(sour + i);
		}
	}
	else {
		for (int i = 0; i < num; i++) {
			*(dest + i) = *(sour + i);
		}
	}
	return destin;
}

int main() {
	int arr[4] = { 1,2,3,4 };
	int arr1[4] = { 0 };
	myMemmove(arr1, arr, sizeof(arr));
	for (int i = 0; i < 4; i++) {
		printf("%d ", arr1[i]);
	}printf("\n");
	return 0;
}