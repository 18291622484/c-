#include<stdio.h>
#include<stdlib.h>

void print(int* p) {
	for (int i = 0; i < 10; i++,p++) {
		printf("%d ", *p);
	}
	printf("\n");
}

int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	print(arr);
	return 0;
}