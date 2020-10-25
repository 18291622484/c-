#include<stdio.h>
#include<stdlib.h>

int main() {

	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };

	for (int i = 1; i < 10; i++) {

		for (int j = 1; j <= i; j++) {

			printf("%d * %d = %d\t", arr[i], arr[j], arr[i] * arr[j]);

			if (j == i) {

				printf("\n");

			}

		}

	}

	return 0;

}