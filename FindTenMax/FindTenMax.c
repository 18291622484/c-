#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


int main() {

	int arr[10] = { 0 };

	printf("请输入十个数\n");

	for (int i = 0; i < 10; i++) {

		scanf("%d", &arr[i]);

	}

	/*for (int i = 0; i < 10; i++) {

	printf("%d ", arr[i]);

	}*/



	for (int j = 0; j < 9; j++) {

		if (arr[j] >= arr[j + 1]) {

			int t = 0;

			t = arr[j];

			arr[j] = arr[j + 1];

			arr[j + 1] = t;

		}

	}

	printf("%d\n", arr[9]);

	return 0;

}